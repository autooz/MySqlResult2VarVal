
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../lib.h"
#include "debug.h"
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/**
 @brief   Function: debug.c
 *
 @detailed    Synopsis:
 *
 @param argv[]
 *
 @return Возвращает или 0 или ошибку
 */
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int debug(const char *format, ...)
{


#if (defined DEBUG)
#if (!defined CONTROL)
    va_list va;
    char *buf = malloc(40960 * 6);
    va_start(va, format);
    vsprintf(buf, format, va);
    va_end(va);
    printf("DEBUG: %s \n", buf);
    FREE(buf);
    //printf("%s\r\n", buf);

#endif
#endif

    return 0;
}

void set_debug_mode(int mode)
{
    FILE *g_dbg;
    if (mode == 1)
    {
        g_dbg = fopen("debug.txt", "a+");
    }
    else
    {
        fclose(g_dbg);
    }
}

void dbg_print(char *format)
{
    FILE *fp;

    fp = fopen("debug.txt", "a+");
    fprintf(fp, "%s\n", format);
    fclose(fp);
}