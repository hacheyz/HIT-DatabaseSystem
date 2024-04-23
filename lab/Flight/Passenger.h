//
// Created by zl on 2023/11/13.
//

#ifndef FLIGHT_PASSENGER_H
#define FLIGHT_PASSENGER_H

#include <QWidget>
#include "sql.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
	class passenger;
}
QT_END_NAMESPACE

class Passenger : public QWidget
{
Q_OBJECT

public:
	explicit Passenger(QWidget *parent = nullptr);
	~Passenger() override;

public slots:
	void backToParent();
	void queryPassenger();
	void addPassenger();
	void deletePassenger();

private:
	Ui::passenger *ui;
};


#endif //FLIGHT_PASSENGER_H
