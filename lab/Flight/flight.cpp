//
// Created by zl on 2023/11/12.
//

// You may need to build the project (run Qt uic code generator) to get "ui_flight.h" resolved

#include "flight.h"
#include "ui_flight.h"
#include "parent.h"

Flight::Flight(QWidget *parent) :
		QWidget(parent), ui(new Ui::flight)
{
	ui->setupUi(this);
	this->setWindowTitle("航班信息");
	connect(ui->back_button, SIGNAL(clicked()), this, SLOT(backToParent())); // 返回按钮
	connect(ui->dep_arv_button, SIGNAL(clicked()), this, SLOT(queryDepArv())); // 查询航班起降信息
	connect(ui->psg_button, SIGNAL(clicked()), this, SLOT(queryPassenger())); // 查询航班乘客信息
	connect(ui->staff_button, SIGNAL(clicked()), this, SLOT(queryStaff())); // 查询航班机组信息
}

Flight::~Flight()
{
	delete ui;
}

void Flight::backToParent()
{
	this->close();
	Parent *parent = new Parent();
	parent->resize(1200, 800);
	parent->show();
}

void Flight::queryDepArv()
{
	QSqlDatabase sql;
	sqlConnect(sql);
	QString qId = ui->lineEdit->text();
	if (sql.open()) {
		QSqlQuery query;
		query.prepare(
				"select departure, dep_city, arrival, arv_city, dpt_time, arv_time from flight_arv_dep where exists( select * from flight where flight.id = :qId and flight_arv_dep.flight_id = flight.id)"
		);
		query.bindValue(":qId", qId);
		query.exec();
		int columnCount = query.record().count(); // 查询结果的列数
		ui->tableWidget->setColumnCount(columnCount); // 设置表格控件的列数
		QStringList headers;
		headers << "出发机场代号" << "出发机场名称" << "到达机场代号" << "到达机场名称" << "出发时间" << "到达时间";
		ui->tableWidget->setHorizontalHeaderLabels(headers); // 设置表头
		ui->tableWidget->setRowCount(query.size()); // 设置表格控件的行数
		// 遍历查询结果，将数据填充到表格控件中
		int row = 0;
		while (query.next()) {
			for (int i = 0; i < columnCount; i++) {
				// 创建一个表格项
				QTableWidgetItem *item = new QTableWidgetItem(query.value(i).toString());
				// 将表格项添加到表格控件中
				ui->tableWidget->setItem(row, i, item);
			}
			row++;
		}
		sql.close();
	} else {
		// 连接失败，显示错误信息
		QMessageBox::critical(this, "错误", sql.lastError().text());
	}
}

void Flight::queryPassenger()
{
	QSqlDatabase sql;
	sqlConnect(sql);
	QString qId = ui->lineEdit->text();
	if (sql.open()) {
		QSqlQuery query;
		query.prepare(
				"select passenger_id, name, gender, age, seat, luggage_count from flight_passenger where exists(select * from flight where flight.id = :qId and flight_passenger.flight_id = flight.id) order by passenger_id"
		);
		query.bindValue(":qId", qId);
		query.exec();
		int columnCount = query.record().count(); // 查询结果的列数
		ui->tableWidget->setColumnCount(columnCount); // 设置表格控件的列数
		QStringList headers;
		headers << "乘客ID" << "姓名" << "性别" << "年龄" << "座位号" << "行李数目";
		ui->tableWidget->setHorizontalHeaderLabels(headers); // 设置表头
		ui->tableWidget->setRowCount(query.size()); // 设置表格控件的行数
		// 遍历查询结果，将数据填充到表格控件中
		int row = 0;
		while (query.next()) {
			for (int i = 0; i < columnCount; i++) {
				// 创建一个表格项
				QTableWidgetItem *item = new QTableWidgetItem(query.value(i).toString());
				// 将表格项添加到表格控件中
				ui->tableWidget->setItem(row, i, item);
			}
			row++;
		}
		sql.close();
	} else {
		// 连接失败，显示错误信息
		QMessageBox::critical(this, "错误", sql.lastError().text());
	}
}

void Flight::queryStaff()
{
	QSqlDatabase sql;
	sqlConnect(sql);
	QString qId = ui->lineEdit->text();
	if (sql.open()) {
		QSqlQuery query;
		query.prepare(
				"select staff_id, name, position from flight_staff where exists(select * from flight where flight.id = :qId and flight_staff.flight_id = flight.id order by staff_id)"
		);
		query.bindValue(":qId", qId);
		query.exec();
		int columnCount = query.record().count(); // 查询结果的列数
		ui->tableWidget->setColumnCount(columnCount); // 设置表格控件的列数
		QStringList headers;
		headers << "机组人员ID" << "姓名" << "职务";
		ui->tableWidget->setHorizontalHeaderLabels(headers); // 设置表头
		ui->tableWidget->setRowCount(query.size()); // 设置表格控件的行数
		// 遍历查询结果，将数据填充到表格控件中
		int row = 0;
		while (query.next()) {
			for (int i = 0; i < columnCount; i++) {
				// 创建一个表格项
				QTableWidgetItem *item = new QTableWidgetItem(query.value(i).toString());
				// 将表格项添加到表格控件中
				ui->tableWidget->setItem(row, i, item);
			}
			row++;
		}
		sql.close();
	} else {
		// 连接失败，显示错误信息
		QMessageBox::critical(this, "错误", sql.lastError().text());
	}
}
