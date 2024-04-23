//
// Created by zl on 2023/11/12.
//

#ifndef FLIGHT_AIRPORT_H
#define FLIGHT_AIRPORT_H

#include <QWidget>
#include "sql.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
	class airport;
}
QT_END_NAMESPACE

class Airport : public QWidget
{
Q_OBJECT

public:
	explicit Airport(QWidget *parent = nullptr);
	~Airport() override;

public slots:
	void backToParent();
	void queryDeparture();
	void queryArrival();

private:
	Ui::airport *ui;
};


#endif //FLIGHT_AIRPORT_H
