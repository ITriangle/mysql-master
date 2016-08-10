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
	MySQLQuery* sqlQuery;

	printf("Hello world\n");

	MySQLConnection *sqlConn = new MySQLConnection();
	sqlConn->Connect("127.0.0.1", 3306, "root", "wanglong", "class");


	//insert
	sqlQuery = new MySQLQuery(sqlConn,"insert student values(?,?,?)");
	sqlQuery->setInt(0,118);
	sqlQuery->setString(1,"Kaa");
	sqlQuery->setInt(2,100);
	sqlQuery->ExecuteInsert();
	delete sqlQuery;

	//update
	sqlQuery = new MySQLQuery(sqlConn,"update student set age = ? where name = ?");
	sqlQuery->setInt(0,43);
	sqlQuery->setString(1,"Kaa");
	sqlQuery->ExecuteUpdate();
	delete sqlQuery;

	//select
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

	delete sqlQuery;


	delete sqlConn;


	return 0;
}