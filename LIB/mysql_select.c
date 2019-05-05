
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include "../LIB/debug.h"
#include "../lib.h"
#include "mysql_select.h"
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


static void error(char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);

    exit(1);
}


VARVALUESELECT SelectCreate(void)
{
    Select *hdr = calloc(1, sizeof (Select));

    if (hdr == NULL)
        error("Out of memory.");

    hdr->next = NULL;

    return (VARVALUESELECT) hdr;
}


void SelectInsert(VARVALUESELECT plist, char *name, char *value)
{
    Select *hdr = (Select *) plist;
    char *newvalue;



    Select *newrec = calloc(1, sizeof (Select));

    char *newname = malloc(strlen(name) + 1);
    if (value != 0x0 && strcmp(value, "(null)"))
    {
        newvalue = malloc(strlen(value) + 1);
    }
    else
    {
        newvalue = malloc(2);
    }
    if (newrec == NULL || newname == NULL || newvalue == NULL)
        error("Out of memory");

    strcpy(newname, name);
    if (value != 0x0 && strcmp(value, "(null)"))
    {
        strcpy(newvalue, value);
    }
    else
    {
        strcpy(newvalue, "-1");
    }
    newrec->next = NULL;
    newrec->var = newname;
    newrec->value = newvalue;
#ifdef DEBUG
    debug("newrec->name=[%s],newrec->value=[%s]", newrec->var, newrec->value);
#endif
    newrec->next = hdr->next;
    hdr->next = newrec;

}

char *SelectFind(VARVALUESELECT plist, char *name)
{
    Select *hdr = (Select *) plist;

    while (hdr->next)
    {
        hdr = hdr->next;
        if (strcmp(hdr->var, name) == 0)
            return hdr->value;
    }

    return NULL;
}


VARVALUESELECT SelectDestroy(VARVALUESELECT plist)
{
    Select *hdr = (Select *) plist;

    while (hdr)
    {
        Select *next = hdr->next;
        free(hdr->var);
        free(hdr->value);
        free(hdr);
        hdr = next;
    }

    return NULL;
}



void
SelectDump(VARVALUESELECT plist, FILE *output)
{
    Select *hdr = (Select *) plist;

    if (output == NULL)
        output = stdout;

    while (hdr->next)
    {
        hdr = hdr->next;
        fprintf(output, "\n address: %p\n", hdr);
        fprintf(output, "----------------+-----------------\n");
        fprintf(output, " %p | %s\n", hdr->var, hdr->var);
        fprintf(output, " %p | %s\n", hdr->value, hdr->value);
        fprintf(output, "----------------+-----------------\n");
//        fprintf(output, " next: %p\n", hdr->next);
//        if(!strcmp(hdr->next,"(nil)"))
//        {
//            break;
//        }
    }
    debug("SelectDump FINISH OK");
}