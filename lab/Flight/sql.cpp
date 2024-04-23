//
// Created by zl on 2023/11/12.
//

#include "sql.h"

bool sqlConnect(QSqlDatabase& sql)
{
	if (QSqlDatabase::contains("qt_sql_default_connection"))
		sql = QSqlDatabase::database("qt_sql_default_connection");
	else
		sql = QSqlDatabase::addDatabase("QMYSQL");
	sql.setHostName("127.0.0.1");
	sql.setUserName("root");
	sql.setPassword("your_password"); // TODO: mask password
	sql.setPort(3306);
	sql.setDatabaseName("flight");
	return true;
}