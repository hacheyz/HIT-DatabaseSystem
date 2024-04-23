//
// Created by zl on 2023/11/13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_passenger.h" resolved

#include "Passenger.h"
#include "ui_passenger.h"
#include "parent.h"

Passenger::Passenger(QWidget *parent) :
		QWidget(parent), ui(new Ui::passenger)
{
	ui->setupUi(this);
	this->setWindowTitle("乘客信息管理");
	connect(ui->back_button, SIGNAL(clicked()), this, SLOT(backToParent())); // 返回按钮
	connect(ui->query_button, SIGNAL(clicked()), this, SLOT(queryPassenger())); // 查询乘客信息
	connect(ui->add_button, SIGNAL(clicked()), this, SLOT(addPassenger())); // 添加乘客信息
	connect(ui->delete_button, SIGNAL(clicked()), this, SLOT(deletePassenger())); // 删除乘客信息
}

Passenger::~Passenger()
{
	delete ui;
}

void Passenger::backToParent()
{
	this->close();
	Parent *parent = new Parent();
	parent->resize(1200, 800);
	parent->show();
}

void Passenger::queryPassenger()
{
	QSqlDatabase sql;
	sqlConnect(sql);
	QString qId = ui->lineEdit->text();
	if (sql.open()) {
		QSqlQuery query;
		query.prepare(
				"select * from passenger where id = :qId"
		);
		query.bindValue(":qId", qId);
		query.exec();
		int columnCount = query.record().count(); // 查询结果的列数
		ui->tableWidget->setColumnCount(columnCount); // 设置表格控件的列数
		QStringList headers;
		headers << "ID" << "姓名" << "性别" << "年龄";
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

void Passenger::addPassenger()
{
	QSqlDatabase sql;
	sqlConnect(sql);
	QString id = ui->id_edit->text();
	QString name = ui->name_edit->text();
	QString gender = ui->gender_edit->text();
	QString age = ui->age_edit->text();
	if (id.isEmpty() || name.isEmpty()) {
		// 如果没有输入，弹出警告信息
		QMessageBox::warning(this, "警告", "ID和姓名不能为空！");
		sql.close();
		return;
	}
	if (sql.open()) {
		QSqlQuery query;
		if (!gender.isEmpty() && !age.isEmpty()) {
			query.prepare("INSERT INTO passenger (id, name, gender, age) VALUES (:id, :name, :gender, :age)");
			query.bindValue(":gender", gender);
			query.bindValue(":age", age);
		} else if (gender.isEmpty() && !age.isEmpty()) {
			query.prepare("INSERT INTO passenger (id, name, age) VALUES (:id, :name, :age)");
			query.bindValue(":age", age);
		} else if (!gender.isEmpty() && age.isEmpty()) {
			query.prepare("INSERT INTO passenger (id, name, gender) VALUES (:id, :name, :gender)");
			query.bindValue(":gender", gender);
		} else {
			query.prepare("INSERT INTO passenger (id, name) VALUES (:id, :name)");
		}
		query.bindValue(":id", id);
		query.bindValue(":name", name);
		if (query.exec()) {
			// 插入成功，弹出提示信息
			QMessageBox::information(this, "提示", "登记成功！");
		} else {
			// 插入失败，显示错误信息
			QMessageBox::critical(this, "错误", query.lastError().text());
		}
		// 关闭数据库连接
		sql.close();
	} else {
		// 连接失败，显示错误信息
		QMessageBox::critical(this, "错误", sql.lastError().text());
	}
}

void Passenger::deletePassenger()
{
	QSqlDatabase sql;
	sqlConnect(sql);
	QString id = ui->lineEdit->text();
	if (sql.open()) {
		QSqlQuery query;
		query.exec("select * from passenger where id = " + id);
		if (!query.next()) {
			// 如果没有查询到，弹出警告信息
			QMessageBox::warning(this, "警告", "没有该乘客！");
			sql.close();
			return;
		}
		query.clear();
		query.prepare("DELETE FROM passenger WHERE id = :id");
		query.bindValue(":id", id);
		if (query.exec()) {
			// 删除成功，弹出提示信息
			QMessageBox::information(this, "提示", "删除成功！");
		} else {
			// 删除失败，显示错误信息
			QMessageBox::critical(this, "错误", query.lastError().text());
		}
		// 关闭数据库连接
		sql.close();
	} else {
		// 连接失败，显示错误信息
		QMessageBox::critical(this, "错误", sql.lastError().text());
	}
}
