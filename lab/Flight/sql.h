//
// Created by zl on 2023/11/12.
//

#ifndef FLIGHT_SQL_H
#define FLIGHT_SQL_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>

bool sqlConnect(QSqlDatabase& sql);

#endif //FLIGHT_SQL_H
