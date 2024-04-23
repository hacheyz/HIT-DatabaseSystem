//
// Created by zl on 2023/11/12.
//

#ifndef FLIGHT_BOOKING_H
#define FLIGHT_BOOKING_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
	class booking;
}
QT_END_NAMESPACE

class Booking : public QWidget
{
Q_OBJECT

public:
	explicit Booking(QWidget *parent = nullptr);
	~Booking() override;

public slots:
	void backToParent();
	void queryFlight();
	void addBooking();

private:
	Ui::booking *ui;
};


#endif //FLIGHT_BOOKING_H
