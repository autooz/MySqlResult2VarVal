
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debug.h"
#include "mysql_select_multy.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/**
 @brief   Function: mysql_creat_var_val_struct.c
 *
 @detailed    Synopsis:
 *
 @param argv[]
 *
 @return Return 0 (OK) or 1 (ERROR)
 */
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int mysql_creat_var_val_Full_table(char *table_name, ROWSOFSELECT **where_stored_var_val)
{
    char tag[] = "mysql_creat_var_val_struct";
    int numRows;
    char *QUERY = malloc(strsize("SELECT * FROM `%s`",table_name));
    sprintf(QUERY,"SELECT * FROM `%s`",table_name);
    debug("tag %s QUERY=[%s]",tag,QUERY);
    
    numRows = makeQueryForResult(QUERY);
    debug("tag %s numRows=[%i]",tag,numRows);
    return (EXIT_SUCCESS);
}