
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include "mysql_select_multy.h"
#include "db_mysql_threded.h"
#include "debug.h"
#include "../lib.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/**
 @brief   Function: makeQueryToDb.c
 *
 @detailed    Synopsis:
 *
 @param argv[]
 *
 @return Return 0 (OK) or 1 (ERROR)
 */
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

extern MYSQL *mysqlThread;

ROWSOFSELECT * makeQueryForResult(char *QUERY)
{
    char tag[] = "doOtherFunctions";
    MYSQL_RES *qresult = NULL;
    MYSQL_FIELD *fields;
    MYSQL_ROW row;
    unsigned int num_fields;
    unsigned int num_rows;

    VARVALUESELECT select = NULL;
    ROWSOFSELECT selectrdRows = NULL;
    int i = 0;

    selectrdRows = SelectedRowsCreate();

    debug("%s", mysqlThread->host);

    if (!get_result(mysqlThread, QUERY, &qresult) == 0 && qresult == NULL)
    {
        return (-1);
    }
    if (qresult == NULL)
    {
        printf("ERROR in %s: qresult == NULL", tag);
        return (-1);
    }

    num_rows = mysql_num_rows(qresult);


    //  selectrdRows = SelectedRowsCreate();

    while (num_rows >= i)
    {
        num_fields = mysql_num_fields(qresult);

        if (num_fields < 0 || num_fields <= 0)
        {
            printf("MySQL error %s SELECT QUERY=[%s]", tag, QUERY);

        }
#if (defined DEBUG)   
        debug("%s num_fields=[%i]", tag, num_fields);
#endif
        select = SelectCreate();

        while ((row = mysql_fetch_row(qresult)))
        {
            for (i = 0; i < num_fields; i++)
            {
                fields = mysql_fetch_fields(qresult);
#if (defined DEBUG)   
                debug("[%s]=[%s]\n", fields[i].name, row[i]);
#endif
                SelectInsert(select, fields[i].name, row[i] ? row[i] : "NULL");
            }
            #if (defined DEBUG)  
            debug("SelectFind=[%s] ",SelectFind(select,"Name"));
            #endif
        }
        debug("SelectedRowsInsert i=[%i]",i);
        SelectedRowsInsert(selectrdRows, fields[i].name, select);
        //SelectDestroy(select);




        i++;
        if (num_rows >= i)
        {
            break;
        }
    }


    SelectedRowsDestroy(selectrdRows);
    mysql_free_result(qresult);
    return num_rows;
    return (EXIT_SUCCESS);
}