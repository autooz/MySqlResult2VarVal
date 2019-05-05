
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <error.h>
#include "../LIB/debug.h"
#include "mysql_select_multy.h"
#include "../lib.h"


ROWSOFSELECT SelectedRowsCreate(void)
{
    Select *hdr = malloc(sizeof (Select));

    if (hdr == NULL)
        debug("Out of memory.");

    hdr->next = NULL;

    return (ROWSOFSELECT) hdr;
}


void SelectedRowsInsert(ROWSOFSELECT plist, char *name, VARVALUESELECT oneRow)
{
    RowsOfSelect *hdr = (RowsOfSelect *) plist;
    RowsOfSelect *newrec = malloc(sizeof (RowsOfSelect));
   
if (newrec == NULL || name == NULL || oneRow == NULL)
        debug("Out of memory");
    

    debug("here1");
    if (oneRow != NULL)
    {
       
        newrec->next = NULL;
        debug("here2");
        newrec->key = name;
        debug("here3");
       // strcpy(newrec->num_order, name); 
         debug("here4");
         newrec->row= oneRow;
    }
   
#ifdef DEBUG
    debug("newrec->name=[%s],newrec->value=[%s]", newrec->key, newrec->row);
#endif
    newrec->next = hdr->next;
    hdr->next = newrec;
}

char *SelectedRowsFind(ROWSOFSELECT plist, char *name)
{
    RowsOfSelect *hdr = (RowsOfSelect *) plist;

    while (hdr->next)
    {
        hdr = hdr->next;
        Select *st = (Select *) hdr->row;
        if (strcmp(st->var, name) == 0)
            return st->var;
    }

    return NULL;
}


ROWSOFSELECT SelectedRowsDestroy(ROWSOFSELECT plist)
{
    RowsOfSelect *hdr = (RowsOfSelect *) plist;

    while (hdr)
    {
        Select *next = (ROWSOFSELECT)hdr->next;
        free(hdr->key);
        //free(hdr->row);
        free(hdr);
        hdr = (ROWSOFSELECT)next;
    }

    return NULL;
}





void
SelectedRowsDump(ROWSOFSELECT plist, FILE *output)
{
    RowsOfSelect *hdr = (RowsOfSelect *) plist;

    if (output == NULL)
        output = stdout;

    while (hdr->next)
    {
        hdr = hdr->next;
        fprintf(output, "\n address: %p\n", hdr);
        fprintf(output, "----------------+-----------------\n");
        fprintf(output, " %p | %s\n", hdr->key, hdr->key);
        fprintf(output, " %p | %s\n", hdr->row, hdr->row);
        fprintf(output, "----------------+-----------------\n");
//        fprintf(output, " next: %p\n", hdr->next);
//        if(!strcmp(hdr->next,"(nil)"))
//        {
//            break;
//        }
    }
    debug("SelectDump FINISH OK");
}