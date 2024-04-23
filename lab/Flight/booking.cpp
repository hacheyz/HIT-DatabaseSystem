//
// Created by zl on 2023/11/12.
//

// You may need to build the project (run Qt uic code generator) to get "ui_booking.h" resolved

#include "booking.h"
#include "ui_booking.h"
#include "parent.h"
#include <random>

Booking::Booking(QWidget *parent) :
		QWidget(parent), ui(new Ui::booking)
{
	ui->setupUi(this);
	this->setWindowTitle("票务系统");
	connect(ui->back_button, SIGNAL(clicked()), this, SLOT(backToParent())); // 返回按钮
	connect(ui->query_button, SIGNAL(clicked()), this, SLOT(queryFlight())); // 查询航班信息
	connect(ui->add_button, SIGNAL(clicked()), this, SLOT(addBooking())); // 添加订票信息
}

Booking::~Booking()
{
	delete ui;
}

void Booking::backToParent()
{
	this->close();
	Parent *parent = new Parent();
	parent->resize(1200, 800);
	parent->show();
}

void Booking::queryFlight()
{
	QSqlDatabase sql;
	sqlConnect(sql);
	QString dep_city = ui->dep_edit->text();
	QString arv_city = ui->arv_edit->text();
	QTime arv_time = ui->time_edit->time();
	if (sql.open()) {
		QSqlQuery query;
		if (!(arv_time == QTime(0, 0, 0))) {
			query.prepare(
					"select * from booking_dep_arv where departure_city = :dep_city and arrival_city = :arv_city group by flight_id having arv_time < :arv_time order by arv_time asc"
			);
			query.bindValue(":arv_time", arv_time);
		} else {
			query.prepare(
					"select * from booking_dep_arv where departure_city = :dep_city and arrival_city = :arv_city order by arv_time asc"
			);
		}
		query.bindValue(":dep_city", dep_city);
		query.bindValue(":arv_city", arv_city);
		query.exec();
		int columnCount = query.record().count(); // 查询结果的列数
		ui->tableWidget->setColumnCount(columnCount); // 设置表格控件的列数
		QStringList headers;
		headers << "航班号" << "出发城市" << "出发机场" << "到达城市" << "到达机场" << "出发时间"
				<< "到达时间" << "预计飞行时间";
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

void Booking::addBooking()
{
	QSqlDatabase sql;
	sqlConnect(sql);
	QString flight_id = ui->flight_edit->text();
	QString passenger_id = ui->passenger_edit->text();
	QString state = "success";
	QString price = "0";
	QString seat = "Test Seat";
	bool ok_booking, ok_ticket;

	if (sql.open()) {
		QSqlQuery query;
		query.prepare(
				"insert into booking(passenger_id, flight_id, state, price) values(:passenger_id, :flight_id, :state, :price)"
		);
		query.bindValue(":passenger_id", passenger_id);
		query.bindValue(":flight_id", flight_id);
		query.bindValue(":state", state);
		query.bindValue(":price", price);
		ok_booking = query.exec();

		query.clear();
		query.prepare(
				"insert into ticket(passenger_id, flight_id, seat) values(:passenger_id, :flight_id, :seat)"
		);
		query.bindValue(":passenger_id", passenger_id);
		query.bindValue(":flight_id", flight_id);
		query.bindValue(":seat", seat);
		ok_ticket = query.exec();
		sql.close();
		if (ok_booking && ok_ticket)
			QMessageBox::information(this, "提示", "订票成功！");
		else
			QMessageBox::critical(this, "错误", "订票失败！");
	} else {
		// 连接失败，显示错误信息
		QMessageBox::critical(this, "错误", sql.lastError().text());
	}
}
