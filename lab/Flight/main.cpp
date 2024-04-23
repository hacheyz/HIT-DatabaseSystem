#include <QApplication>
#include <QPushButton>

#include <mysql.h>
#include <iostream>
#include "parent.h"

using namespace std;

int main(int argc, char *argv[])
{
//	MYSQL mysql;
//	mysql_init(&mysql);
//
//	if (!mysql_real_connect(&mysql, "127.0.0.1", "root", "your_password", "flight", 3306, NULL, 0))
//	{
//		cout << "Error connecting to database: " << mysql_error(&mysql) << endl;
//		return -1;
//	}

//	mysql_close(&mysql);

	QApplication a(argc, argv);
	Parent parent;
	parent.resize(1200, 800);
	parent.show();
	return QApplication::exec();
}
