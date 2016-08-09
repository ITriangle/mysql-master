#include <iostream>
#include <vector>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mysql_master.h"

using namespace std;

/**
 * @param
 * @param
 * @return
 */
int main(int argc, char* argv[])
{

	printf("Hello world\n");

	MySQLConnection *sqlConn = new MySQLConnection();
	sqlConn->Connect("127.0.0.1", 3306, "root", "wanglong", "class");

	MySQLQuery* sqlQuery = new MySQLQuery(sqlConn,"insert student values(?,?,?)");

	sqlQuery->setInt(0,111);
	sqlQuery->setString(1,"Kaa");
	sqlQuery->setInt(2,100);
	cout << "Last inserted Line:" << sqlQuery->ExecuteQuery() << endl;

	sqlQuery = new MySQLQuery(sqlConn, "select * from student");

	sqlQuery->ExecuteQuery();

	printf("GetResultRowCount: %d\n", sqlQuery->GetResultRowCount());
	printf("GetFieldCount : %d\n", sqlQuery->GetFieldCount());


	


	for (int n = 0; n < sqlQuery->GetFieldCount(); n++)
	{
		cout << sqlQuery->getFieldName(n) << "\t\t";
	}
	cout << endl;

	for (unsigned int i = 0; i < sqlQuery->GetResultRowCount(); i++)
	{
		for (int n = 0; n < sqlQuery->GetFieldCount(); n++)
		{
			cout << sqlQuery->getString(i, n) << "\t\t";
		}
		cout << endl;
	}




	return 0;
}