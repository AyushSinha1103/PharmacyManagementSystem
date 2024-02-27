#include "requirements.h"
#include "dbConfig.h"
#include "MenuFunctions.h"

MYSQL * conn;
MYSQL_RES *res_set;
MYSQL_ROW row;
stringstream stmt;
const char * q;
string query;

int main()
{	
	pass();
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, HOST, USER, PASS, DATABASE, PORT, NULL, 0);
	int choice;
	if(conn)
    {
		while(1)
		{
			system("cls");
			mainMenu();
		}
    }
	else
	{
	    system("cls");
		cout << "Error While connection to database." << endl << "Contact Tech Expert." << endl;
		getch();
	}
	return 0;
}

