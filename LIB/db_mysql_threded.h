
#ifndef DB_MYSQL_THREDED_H
#define DB_MYSQL_THREDED_H

#ifdef __cplusplus
extern "C" {
#endif
#include <mysql/mysql.h>
#include <pthread.h>


#pragma once

#include <time.h>
#include <pthread.h>
#include <mysql/mysql.h>
#include <mysql/errmsg.h>
#include <mysql/mysqld_error.h>

    struct himysql {
        MYSQL *conn;
        size_t buf_size;
        char *sql;
        size_t len;

        int use_thread;
        pthread_t thread;
        int running;
        int pipefd[2];
        void *list;
        size_t list_max;

        MYSQL_RES *result;
        size_t num_fields;
        size_t num_rows;
        long num_affected;
        MYSQL_FIELD *fields;
        MYSQL_ROW row;

        void *fail_cb;
        pthread_mutex_t lock;
    };

    typedef struct himysql himysql_t;
    extern himysql_t *hm;
#define HM_USE_THREAD 0x1

    himysql_t *himysql_init(const char *host, int port, const char *db,
            const char *user, const char *passwd, const char *charset, int flag);

#define DB_UNIX_SOCKET NULL      /* Define unix socket default is "NULL"*/
#define MYSQL_FLAG 0             /* Define flag default is "NULL"*/

#define HM_OK 0
#define HM_ERROR (-1)
#define HM_LOST  (-2)

    int himysql(himysql_t *hm, const char *format, ...);

    int himysql_query(himysql_t *hm, const char *sql, size_t len);

    char *himysql_error(himysql_t *hm);

    unsigned int himysql_errno(himysql_t *hm);

    typedef void himysql_fail_cb(himysql_t *hm);
    int himysql_set_fail_cb(himysql_t *hm, himysql_fail_cb *cb);

    int himysql_set_list_max(himysql_t *hm, size_t max);

    int himysql_fetch_fields(himysql_t *hm);

    int himysql_fetch_row(himysql_t *hm);

    void himysql_free_result(himysql_t *hm);

    void himysql_fini(himysql_t *hm);

    MYSQL *mysql_start(const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long clientflag);
    int musql_library_start();
    void musql_library_close();
int get_result(MYSQL *mysql, char *QUERY, MYSQL_RES **sql_result) ;
    
#ifdef __cplusplus
}
#endif

#endif /* DB_MYSQL_THREDED_H */

