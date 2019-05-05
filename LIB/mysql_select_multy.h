
#ifndef MYSQL_SELECT_MULTY_H
#define MYSQL_SELECT_MULTY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mysql_select.h"
    
    
typedef void *ROWSOFSELECT;

extern ROWSOFSELECT selectedRows;
/******
 * Function prototypes.
 ******/

ROWSOFSELECT SelectedRowsCreate(void);
void SelectedRowsInsert(ROWSOFSELECT plist, char *name, VARVALUESELECT value);
char *SelectedRowsFind(ROWSOFSELECT plist, char *name);
ROWSOFSELECT SelectedRowsDestroy(ROWSOFSELECT plist);
#ifdef DEBUG
void SelectedRowsDump(ROWSOFSELECT plist, FILE *output);
#endif

typedef struct _RowsOfSelect
{
    char *key;
    VARVALUESELECT *row;
    struct _RowsOfSelect *next;
} RowsOfSelect;



#ifdef __cplusplus
}
#endif

#endif /* MYSQL_SELECT_MULTY_H */

