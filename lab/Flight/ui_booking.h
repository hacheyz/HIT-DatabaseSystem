/********************************************************************************
** Form generated from reading UI file 'booking.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKING_H
#define UI_BOOKING_H

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
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_booking
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *back_button;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_8;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QLineEdit *arv_edit;
    QPushButton *query_button;
    QLabel *label_6;
    QLineEdit *dep_edit;
    QTimeEdit *time_edit;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QPushButton *add_button;
    QLabel *label_2;
    QLineEdit *flight_edit;
    QLineEdit *passenger_edit;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QTableWidget *tableWidget;

    void setupUi(QWidget *booking)
    {
        if (booking->objectName().isEmpty())
            booking->setObjectName(QString::fromUtf8("booking"));
        booking->resize(454, 539);
        verticalLayout = new QVBoxLayout(booking);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        back_button = new QPushButton(booking);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(back_button->sizePolicy().hasHeightForWidth());
        back_button->setSizePolicy(sizePolicy);
        back_button->setMinimumSize(QSize(40, 0));
        back_button->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(back_button);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_8 = new QLabel(booking);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(booking);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        label_7 = new QLabel(booking);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout_2->addLayout(horizontalLayout, 3, 3, 1, 1);

        arv_edit = new QLineEdit(booking);
        arv_edit->setObjectName(QString::fromUtf8("arv_edit"));

        gridLayout_2->addWidget(arv_edit, 1, 2, 1, 1);

        query_button = new QPushButton(booking);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(query_button->sizePolicy().hasHeightForWidth());
        query_button->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(query_button, 0, 3, 3, 1);

        label_6 = new QLabel(booking);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        dep_edit = new QLineEdit(booking);
        dep_edit->setObjectName(QString::fromUtf8("dep_edit"));

        gridLayout_2->addWidget(dep_edit, 0, 2, 1, 1);

        time_edit = new QTimeEdit(booking);
        time_edit->setObjectName(QString::fromUtf8("time_edit"));

        gridLayout_2->addWidget(time_edit, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        add_button = new QPushButton(booking);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(add_button->sizePolicy().hasHeightForWidth());
        add_button->setSizePolicy(sizePolicy2);
        add_button->setMinimumSize(QSize(40, 0));
        add_button->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(add_button, 0, 3, 2, 1);

        label_2 = new QLabel(booking);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        flight_edit = new QLineEdit(booking);
        flight_edit->setObjectName(QString::fromUtf8("flight_edit"));

        gridLayout->addWidget(flight_edit, 1, 2, 1, 1);

        passenger_edit = new QLineEdit(booking);
        passenger_edit->setObjectName(QString::fromUtf8("passenger_edit"));

        gridLayout->addWidget(passenger_edit, 0, 2, 1, 1);

        label = new QLabel(booking);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_3);

        tableWidget = new QTableWidget(booking);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        QWidget::setTabOrder(dep_edit, arv_edit);
        QWidget::setTabOrder(arv_edit, query_button);
        QWidget::setTabOrder(query_button, passenger_edit);
        QWidget::setTabOrder(passenger_edit, flight_edit);
        QWidget::setTabOrder(flight_edit, add_button);
        QWidget::setTabOrder(add_button, tableWidget);
        QWidget::setTabOrder(tableWidget, back_button);

        retranslateUi(booking);

        QMetaObject::connectSlotsByName(booking);
    } // setupUi

    void retranslateUi(QWidget *booking)
    {
        booking->setWindowTitle(QCoreApplication::translate("booking", "booking", nullptr));
        back_button->setText(QCoreApplication::translate("booking", "\350\277\224\345\233\236", nullptr));
        label_8->setText(QCoreApplication::translate("booking", "\350\257\267\350\276\223\345\205\245\345\207\272\345\217\221\345\237\216\345\270\202\345\222\214\345\210\260\350\276\276\345\237\216\345\270\202\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("booking", "\345\207\272\345\217\221\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("booking", "\346\234\200\346\231\232\345\210\260\350\276\276\346\227\266\351\227\264\357\274\210\345\217\257\351\200\211\357\274\211\357\274\232", nullptr));
        query_button->setText(QCoreApplication::translate("booking", "\346\237\245\350\257\242", nullptr));
        label_6->setText(QCoreApplication::translate("booking", "\345\210\260\350\276\276\357\274\232", nullptr));
        add_button->setText(QCoreApplication::translate("booking", "\351\242\204\350\256\242", nullptr));
        label_2->setText(QCoreApplication::translate("booking", "\350\257\267\350\276\223\345\205\245\351\242\204\350\256\242\347\232\204\350\210\252\347\217\255\345\217\267:", nullptr));
        label->setText(QCoreApplication::translate("booking", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\347\232\204ID\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class booking: public Ui_booking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKING_H
