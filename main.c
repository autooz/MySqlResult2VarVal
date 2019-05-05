
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include "LIB/debug.h"
#include "LIB/mysql_select_multy.h"
#include "lib.h"
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/**
 @brief   Function: main.c
 *
 @detailed    Synopsis:
 *
 @param argv[]
 *
 @return Return 0 (OK) or 1 (ERROR)
 */
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
MYSQL *mysqlThread;




int main(int argc, char** argv)
{
    musql_library_start();
    MYSQL_RES *qresult; 
    char db[]="td_vasilkov";
     mysql_thread_init();
    mysqlThread = get_db_MySql_new_connect(db);
    if (mysqlThread == NULL)
    {
        debug("No mysql");
         mysql_thread_end();
        mysql_library_end();
        
        return (-1);
       
    }

    ROWSOFSELECT *where_stored_var_val;
    char table_name[]="atda_Main_poligon";
    mysql_creat_var_val_Full_table(table_name, &where_stored_var_val);
//        debug ("%s",mysqlThread->host);
//    
//    char *QUERY = malloc(strlen("SELECT `num` FROM `drivershift`"));
//    sprintf(QUERY,"SELECT `num` FROM `drivershift`");
//    qresult =(MYSQL_RES*) get_result(mysqlThread, QUERY);
////    if(qresult != NULL)
////    {
////      //  debug("\n qresult row_count=[%lu]",qresult->row_count);
////    }
////    else
////    {
////         debug("\n No result");
////    }
    mysql_close(mysqlThread);
 mysql_thread_end();
mysql_library_end();
    return (EXIT_SUCCESS);
}
