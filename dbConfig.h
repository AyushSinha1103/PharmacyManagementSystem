#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <conio.h>
#include <cstdlib>

using namespace std;

#define HOST "127.0.0.1"
#define USER "root"
#define PASS "ayush"
#define DATABASE "pharmacy"
#define PORT 3306
#define PASSWORD 1234

extern MYSQL * conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern stringstream stmt;
extern const char * q;
extern string query;



