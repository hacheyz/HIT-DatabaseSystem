//
// Created by zl on 2023/11/12.
//

// You may need to build the project (run Qt uic code generator) to get "ui_parent.h" resolved

#include "parent.h"
#include "ui_parent.h"

Parent::Parent(QWidget *parent) :
		QWidget(parent), ui(new Ui::parent)
{
	ui->setupUi(this);
	this->setWindowTitle("飞行管理系统");
	connect(ui->airport_button, SIGNAL(clicked()), this, SLOT(openAirport()));
	connect(ui->flight_button, SIGNAL(clicked()), this, SLOT(openFlight()));
	connect(ui->booking_button, SIGNAL(clicked()), this, SLOT(openBooking()));
	connect(ui->passenger_button, SIGNAL(clicked()), this, SLOT(openPassenger()));
}

Parent::~Parent()
{
	delete ui;
}

void Parent::openAirport()
{
	a = new Airport();
	a->resize(1200, 800);
	a->show();
	this->hide();
}

void Parent::openFlight()
{
	f = new Flight();
	f->resize(1200, 800);
	f->show();
	this->hide();
}

void Parent::openPassenger()
{
	p = new Passenger();
	p->resize(1200, 800);
	p->show();
	this->hide();
}

void Parent::openBooking()
{
	b = new Booking();
	b->resize(1200, 800);
	b->show();
	this->hide();
}