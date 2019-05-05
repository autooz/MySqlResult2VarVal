#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <mysql/mysql.h>
#include "db_mysql_threded.h"
#include "debug.h"
#include "../lib.h"



void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}


int musql_library_start()
{
    static char *server_options[] = \
       {"is_password_ok", "--defaults-file=atda.cnf", NULL};
    int num_elements = (sizeof (server_options) / sizeof (char *)) - 1;

    static char *server_groups[] = {"atda_server",
        "atda_client", NULL};

    if (mysql_library_init(num_elements, server_options, server_groups))
    {
        fprintf(stderr, "could not initialize MySQL client library\n");
        return -1;
    }
    return EXIT_SUCCESS;

}

void musql_library_close()
{
    mysql_library_end();
}

MYSQL *mysql_start(const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long clientflag)
{
MYSQL *mysqlThread;

    mysqlThread = mysql_init(NULL);
    mysql_options(mysqlThread, MYSQL_READ_DEFAULT_GROUP, "atda_client");
    mysql_options(mysqlThread, MYSQL_OPT_USE_EMBEDDED_CONNECTION, NULL);
    mysql_options(mysqlThread, MYSQL_SET_CHARSET_NAME, "utf8");
    mysql_options(mysqlThread, MYSQL_INIT_COMMAND, "SET NAMES utf8");

    if (!mysql_real_connect(mysqlThread, host, user, passwd, db, port, unix_socket, clientflag))
    {
#if (defined DEBUG)   
        printf("ERROR mysql_real_connect in is_password_ok error=[%s]", mysql_error(mysqlThread));
#endif
        return NULL;
    }
    #if (defined DEBUG)   
        printf("return mysql from mysql_start");
#endif
    return mysqlThread;
}

MYSQL *get_db_MySql_new_connect(char *db_ds_name)
{
    char tag[] = "get_db_MySql_new_connect";
    MYSQL *myMysql;
    debug("Do %s",tag);
    debug("1 %s",tag);
//        musql_library_start();
        debug("2 %s %s",tag,db_ds_name);
        
    if ((myMysql = mysql_start(DB_HOST, DB_USER, DB_PASWD, db_ds_name, DB_PORT, DB_UNIX_SOCKET, MYSQL_FLAG)) == NULL)
    {
//#if (defined DEBUG) 
        debug("ERROR mysql_start");
//#endif
        perror("ERROR get_db_MySql_new_connect:");
        goto exitfailure;
    }
//#if (defined DEBUG) 
        debug("OK in %s",tag);
//#endif
    //mysql_close(myMysql);
   // mysql_library_close();
     debug("End %s",tag);
    return (myMysql);
exitfailure:
    mysql_close(myMysql);
    musql_library_close();
debug("fail %s",tag);
    return (NULL);
}

int get_result(MYSQL *mysql, char *QUERY, MYSQL_RES **sql_result) 
{
    char tag[]="get_result";
  
  MYSQL_ROW row;
  if ( ( mysql == NULL ) || mysql_query( mysql, QUERY ) )
  {
    printf( "Can not display list of errors/warnings!\n" );
    return (-2);
  }
  
  
  *sql_result = mysql_store_result( mysql );
  
  
//  if ( ( sql_result == NULL ) || ( sql_result->row_count == 0 ) )
//  {
//    printf( "Can not display list of errors/warnings!\n" );
//    if ( sql_result )
//      mysql_free_result( sql_result );
//    return (-1);
//  }
printf( "OKKKKKK!\n" );
  return (0);
}


//int experemental(){
//    
//    MYSQL *conn;
//    
//    if ( (conn = mysql_init(NULL) ) == NULL )
//{
//printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
//exit(1);
//}
//
///* -----------------------------------------------
//Establishes a connection to the database
//----------------------------------------------- */
//if (mysql_real_connect(conn,server,user,passwd,database,0,NULL,0) == NULL )
//{
//fprintf(stderr, "%s\n", mysql_error(conn));
//exit(1);
//}
//
///* Allocate statement handler */
//MYSQL_STMT *stmt;
//stmt = mysql_stmt_init(conn);
//
//if (stmt == NULL)
//{
//printf("Could not initialize statement handler\n");
//exit(1);
//}
//
//
//// Prepare the statement
//// Output format: string, string, double
//const char *sql = "select fname, lname, salary from employee";
//
//if (mysql_stmt_prepare(stmt, sql, strlen(sql)) != 0)
//{
//printf("Could not prepare statement\n");
//exit(1);
//}
//
//
//// Bind variables
//// Output format: string, string, double
//
//MYSQL_BIND result[3]; // 3 variables
//
//char fn[100]; // fname
//char ln[100]; // lname
//double sal; // salary
//
//memset (result, 0, sizeof (result)); /* zero the structures */
//
//result[0].buffer = (void *) &fn; // first field in fn
//result[0].buffer_type = MYSQL_TYPE_STRING; // Return data as string
//result[0].buffer_length = 100;
//
//result[1].buffer = (void *) &ln; // Second field in ln
//result[1].buffer_type = MYSQL_TYPE_STRING; // Return data as string
//result[1].buffer_length = 100;
//
//result[2].buffer = (void *) &sal; // 3rd field in sal
//result[2].buffer_type = MYSQL_TYPE_DOUBLE; // Return data as double
//
//if (mysql_stmt_bind_result(stmt, result) != 0)
//{
//printf("Could not bind results");
//exit(1);
//}
//
//// Execute!!
//if (mysql_stmt_execute(stmt) != 0)
//{
//printf("Could not execute statement");
//exit(1);
//}
//
//// Prepare to retrieve the result
//if (mysql_stmt_store_result(stmt) != 0)
//{
//printf("Could not buffer result set");
//exit(1);
//}
//
//
///* ===========================================
//Fetch one row at a time....
//=========================================== */
//double totalSal = 0;
//
//while ( mysql_stmt_fetch (stmt) == 0 )
//{
//printf("%s %s: Salary = %lf\n", fn, ln, sal );
//totalSal += sal;
//}
//
//printf("\nTotal Salary = %lf\n\n", totalSal );
//
///* ===========================================
//Release memory space used by stmt
//=========================================== */
//mysql_stmt_free_result(stmt); /* deallocate result set */
//
///* ===========================================
//Close SQL connection
//=========================================== */
//mysql_close(conn);
//}