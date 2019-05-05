# MySqlResult2VarVal

For UNIX like OS only.

Saving in the structure MySql requests result as char of variable: value

How to start


Add changes for your own values in lib.h file:

#define DB_HOST "localhost" / * Define host default is "localhost" * / 

#define DB_PORT 20033 / * Define port default is "3306" * / 

#define DB_USER "username"

#define DB_PASWD "userpasswd" / * Define user password * 


Specify the database name in the main.c file (char db [] = "dbname";) Line 29;

Then add  query that is in the file located tests/newsimpletest.c to MySql according to the changed database name (char db [] = "dbname";)


Use make command to compile script


