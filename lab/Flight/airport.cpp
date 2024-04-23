//
// Created by zl on 2023/11/12.
//

// You may need to build the project (run Qt uic code generator) to get "ui_airport.h" resolved

#include "airport.h"
#include "ui_airport.h"
#include "parent.h"

Airport::Airport(QWidget *parent) :
		QWidget(parent), ui(new Ui::airport)
{
	ui->setupUi(this);
	this->setWindowTitle("机场航班信息");
	connect(ui->back_button, SIGNAL(clicked()), this, SLOT(backToParent())); // 返回按钮
	connect(ui->dep_button, SIGNAL(clicked()), this, SLOT(queryDeparture())); // 查询起飞的航班
	connect(ui->arv_button, SIGNAL(clicked()), this, SLOT(queryArrival())); // 查询降落的航班
}

Airport::~Airport()
{
	delete ui;
}

void Airport::backToParent()
{
	this->close();
	Parent *parent = new Parent();
	parent->resize(1200, 800);
	parent->show();
}

void Airport::queryDeparture()
{
	QSqlDatabase sql;
	sqlConnect(sql);
	QString qId = ui->lineEdit->text();
	if (sql.open()) {
		QSqlQuery query;
		query.prepare("select * from airport_dep where airport_id = :qId order by dep_time asc");
		query.bindValue(":qId", qId);
		query.exec();
		int columnCount = query.record().count(); // 查询结果的列数
		ui->tableWidget->setColumnCount(columnCount); // 设置表格控件的列数
		QStringList headers;
		headers << "机场代号" << "机场名称" << "航班代号" << "飞机型号" << "航司名称" << "起飞时间";
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

void Airport::queryArrival()
{
	QSqlDatabase sql;
	sqlConnect(sql);
	QString qId = ui->lineEdit->text();
	if (sql.open()) {
		QSqlQuery query;
		query.prepare("select * from airport_arv where airport_id = :qId order by arv_time asc");
		query.bindValue(":qId", qId);
		query.exec();
		int columnCount = query.record().count(); // 查询结果的列数
		ui->tableWidget->setColumnCount(columnCount); // 设置表格控件的列数
		QStringList headers;
		headers << "机场代号" << "机场名称" << "航班代号" << "客机型号" << "航司名称" << "降落时间";
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
