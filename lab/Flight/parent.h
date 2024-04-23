//
// Created by zl on 2023/11/12.
//

#ifndef FLIGHT_PARENT_H
#define FLIGHT_PARENT_H

#include <QWidget>
#include "airport.h"
#include "flight.h"
#include "passenger.h"
#include "booking.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
	class parent;
}
QT_END_NAMESPACE

class Parent : public QWidget
{
Q_OBJECT

public:
	explicit Parent(QWidget *parent = nullptr);
	~Parent() override;

public slots:
	void openAirport();
	void openFlight();
	void openPassenger();
	void openBooking();

private:
	Airport *a;
	Flight *f;
	Booking *b;
	Passenger *p;

private:
	Ui::parent *ui;
};



#endif //FLIGHT_PARENT_H
