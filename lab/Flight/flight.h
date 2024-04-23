//
// Created by zl on 2023/11/12.
//

#ifndef FLIGHT_FLIGHT_H
#define FLIGHT_FLIGHT_H

#include <QWidget>
#include "sql.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
	class flight;
}
QT_END_NAMESPACE

class Flight : public QWidget
{
Q_OBJECT

public:
	explicit Flight(QWidget *parent = nullptr);
	~Flight() override;
public slots:
	void backToParent();
	void queryDepArv();
	void queryPassenger();
	void queryStaff();

private:
	Ui::flight *ui;
};


#endif //FLIGHT_FLIGHT_H
