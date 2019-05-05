/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lib.h
 * Author: oleg
 *
 * Created on 19 марта 2019 г., 12:47
 */

#ifndef LIB_H
#define LIB_H

#ifdef __cplusplus
extern "C" {
#endif

    
    
#define DEBUG
    
    
#define FREE(ptr) do{ \
  if((ptr) != NULL){    \
    free((ptr));      \
    (ptr) = NULL;     \
    }                 \
  }while(0)
    
#define strsize(args...) snprintf(NULL, 0, args) + sizeof(char)

//#define DB_HOST "193.150.6.36"      /* Define host default is "localhost"*/
#define DB_HOST "localhost"      /* Define host default is "localhost"*/
#define DB_PORT 20033             /* Define port default is "3306"*/
#define DB_USER "username" 
#define DB_PASWD "userpasswd"          /* Define user password Desktop"*/


#define DB_UNIX_SOCKET NULL      /* Define unix socket default is "NULL"*/
#define MYSQL_FLAG 0             /* Define flag default is "NULL"*/


#include <mysql/mysql.h>

MYSQL *get_db_MySql_new_connect(char *db_ds_name);




#ifdef __cplusplus
}
#endif

#endif /* LIB_H */

