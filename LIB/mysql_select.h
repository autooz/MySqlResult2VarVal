
#ifndef MYSQL_SELECT_H
#define MYSQL_SELECT_H

#ifdef __cplusplus
extern "C" {
#endif
    
typedef void *VARVALUESELECT;

extern VARVALUESELECT select;
/******
 * Function prototypes.
 ******/

VARVALUESELECT SelectCreate(void);
void SelectInsert(VARVALUESELECT plist, char *name, char *value);
char *SelectFind(VARVALUESELECT plist, char *name);
VARVALUESELECT SelectDestroy(VARVALUESELECT plist);
#ifdef DEBUG
void SelectDump(VARVALUESELECT plist, FILE *output);
#endif

typedef struct _Select
{
    char *var;
    char *value;
    struct _Select *next;
} Select;

//extern VARVALUEFRFDRIVERS refdrivers;
int selectINI(char *db_host, char *db_user, char *db_paswd, char *db_ds_name, unsigned int db_port, char *driverID_or_null, char *sign);
int getSelectByIdOrSign(char *db_ds_name, char *driverID_or_null, char *sign);
void SelectDump(VARVALUESELECT plist, FILE *output);
VARVALUESELECT SelectDestroy(VARVALUESELECT plist);
#define strsize(args...) snprintf(NULL, 0, args) + sizeof(char)


#ifdef __cplusplus
}
#endif

#endif /* MYSQL_SELECT_H */

