/********************************************************************************
** Form generated from reading UI file 'passenger.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGER_H
#define UI_PASSENGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_passenger
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *back_button;
    QLabel *label_1;
    QLineEdit *lineEdit;
    QPushButton *query_button;
    QPushButton *delete_button;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *name_edit;
    QLineEdit *id_edit;
    QLabel *label_9;
    QLineEdit *gender_edit;
    QPushButton *add_button;
    QLineEdit *age_edit;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *passenger)
    {
        if (passenger->objectName().isEmpty())
            passenger->setObjectName(QString::fromUtf8("passenger"));
        passenger->resize(636, 613);
        verticalLayout_3 = new QVBoxLayout(passenger);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        back_button = new QPushButton(passenger);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(back_button->sizePolicy().hasHeightForWidth());
        back_button->setSizePolicy(sizePolicy);
        back_button->setMinimumSize(QSize(40, 0));
        back_button->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_5->addWidget(back_button);

        label_1 = new QLabel(passenger);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        horizontalLayout_5->addWidget(label_1);

        lineEdit = new QLineEdit(passenger);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);

        query_button = new QPushButton(passenger);
        query_button->setObjectName(QString::fromUtf8("query_button"));

        horizontalLayout_5->addWidget(query_button);

        delete_button = new QPushButton(passenger);
        delete_button->setObjectName(QString::fromUtf8("delete_button"));

        horizontalLayout_5->addWidget(delete_button);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        tableWidget = new QTableWidget(passenger);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(tableWidget);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        name_edit = new QLineEdit(passenger);
        name_edit->setObjectName(QString::fromUtf8("name_edit"));

        gridLayout->addWidget(name_edit, 2, 1, 1, 1);

        id_edit = new QLineEdit(passenger);
        id_edit->setObjectName(QString::fromUtf8("id_edit"));

        gridLayout->addWidget(id_edit, 1, 1, 1, 1);

        label_9 = new QLabel(passenger);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        gender_edit = new QLineEdit(passenger);
        gender_edit->setObjectName(QString::fromUtf8("gender_edit"));

        gridLayout->addWidget(gender_edit, 3, 1, 1, 1);

        add_button = new QPushButton(passenger);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(add_button->sizePolicy().hasHeightForWidth());
        add_button->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(add_button, 1, 2, 4, 1);

        age_edit = new QLineEdit(passenger);
        age_edit->setObjectName(QString::fromUtf8("age_edit"));

        gridLayout->addWidget(age_edit, 4, 1, 1, 1);

        label_10 = new QLabel(passenger);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_11 = new QLabel(passenger);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_11, 0, 0, 1, 2);

        label_8 = new QLabel(passenger);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_7 = new QLabel(passenger);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 175, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        QWidget::setTabOrder(lineEdit, query_button);
        QWidget::setTabOrder(query_button, delete_button);
        QWidget::setTabOrder(delete_button, tableWidget);
        QWidget::setTabOrder(tableWidget, id_edit);
        QWidget::setTabOrder(id_edit, name_edit);
        QWidget::setTabOrder(name_edit, gender_edit);
        QWidget::setTabOrder(gender_edit, age_edit);
        QWidget::setTabOrder(age_edit, add_button);
        QWidget::setTabOrder(add_button, back_button);

        retranslateUi(passenger);

        QMetaObject::connectSlotsByName(passenger);
    } // setupUi

    void retranslateUi(QWidget *passenger)
    {
        passenger->setWindowTitle(QCoreApplication::translate("passenger", "Passenger", nullptr));
        back_button->setText(QCoreApplication::translate("passenger", "\350\277\224\345\233\236", nullptr));
        label_1->setText(QCoreApplication::translate("passenger", "\350\257\267\350\276\223\345\205\245\344\271\230\345\256\242ID\357\274\232", nullptr));
        query_button->setText(QCoreApplication::translate("passenger", "\346\237\245\350\257\242", nullptr));
        delete_button->setText(QCoreApplication::translate("passenger", "\345\210\240\351\231\244", nullptr));
        label_9->setText(QCoreApplication::translate("passenger", " \345\271\264\351\276\204\357\274\232", nullptr));
        add_button->setText(QCoreApplication::translate("passenger", "\347\231\273\350\256\260", nullptr));
        label_10->setText(QCoreApplication::translate("passenger", "*ID\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("passenger", "\350\257\267\345\234\250\344\270\213\346\226\271\347\231\273\350\256\260\346\202\250\347\232\204\344\270\252\344\272\272\344\277\241\346\201\257\357\274\210*\344\270\272\345\277\205\345\241\253\351\241\271\357\274\211", nullptr));
        label_8->setText(QCoreApplication::translate("passenger", " \346\200\247\345\210\253\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("passenger", "*\345\247\223\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class passenger: public Ui_passenger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGER_H
