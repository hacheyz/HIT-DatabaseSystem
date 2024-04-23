/********************************************************************************
** Form generated from reading UI file 'flight.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHT_H
#define UI_FLIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_flight
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *back_button;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *dep_arv_button;
    QPushButton *psg_button;
    QPushButton *staff_button;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *flight)
    {
        if (flight->objectName().isEmpty())
            flight->setObjectName(QString::fromUtf8("flight"));
        flight->resize(400, 300);
        verticalLayout = new QVBoxLayout(flight);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        back_button = new QPushButton(flight);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(back_button->sizePolicy().hasHeightForWidth());
        back_button->setSizePolicy(sizePolicy);
        back_button->setMinimumSize(QSize(40, 0));
        back_button->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(back_button);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(flight);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(flight);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        dep_arv_button = new QPushButton(flight);
        dep_arv_button->setObjectName(QString::fromUtf8("dep_arv_button"));

        horizontalLayout_2->addWidget(dep_arv_button);

        psg_button = new QPushButton(flight);
        psg_button->setObjectName(QString::fromUtf8("psg_button"));

        horizontalLayout_2->addWidget(psg_button);

        staff_button = new QPushButton(flight);
        staff_button->setObjectName(QString::fromUtf8("staff_button"));

        horizontalLayout_2->addWidget(staff_button);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);

        tableWidget = new QTableWidget(flight);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(flight);

        QMetaObject::connectSlotsByName(flight);
    } // setupUi

    void retranslateUi(QWidget *flight)
    {
        flight->setWindowTitle(QCoreApplication::translate("flight", "flight", nullptr));
        back_button->setText(QCoreApplication::translate("flight", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("flight", "\350\257\267\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267\357\274\232", nullptr));
        dep_arv_button->setText(QCoreApplication::translate("flight", "\350\265\267\351\231\215\344\277\241\346\201\257", nullptr));
        psg_button->setText(QCoreApplication::translate("flight", "\344\271\230\345\256\242\344\277\241\346\201\257", nullptr));
        staff_button->setText(QCoreApplication::translate("flight", "\346\234\272\347\273\204\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class flight: public Ui_flight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHT_H
