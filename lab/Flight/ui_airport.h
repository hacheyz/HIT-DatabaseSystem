/********************************************************************************
** Form generated from reading UI file 'airport.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRPORT_H
#define UI_AIRPORT_H

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

class Ui_airport
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
    QPushButton *dep_button;
    QPushButton *arv_button;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *airport)
    {
        if (airport->objectName().isEmpty())
            airport->setObjectName(QString::fromUtf8("airport"));
        airport->resize(400, 300);
        verticalLayout = new QVBoxLayout(airport);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        back_button = new QPushButton(airport);
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

        label = new QLabel(airport);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(airport);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        dep_button = new QPushButton(airport);
        dep_button->setObjectName(QString::fromUtf8("dep_button"));

        horizontalLayout_2->addWidget(dep_button);

        arv_button = new QPushButton(airport);
        arv_button->setObjectName(QString::fromUtf8("arv_button"));

        horizontalLayout_2->addWidget(arv_button);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);

        tableWidget = new QTableWidget(airport);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        QWidget::setTabOrder(lineEdit, dep_button);
        QWidget::setTabOrder(dep_button, arv_button);
        QWidget::setTabOrder(arv_button, tableWidget);
        QWidget::setTabOrder(tableWidget, back_button);

        retranslateUi(airport);

        QMetaObject::connectSlotsByName(airport);
    } // setupUi

    void retranslateUi(QWidget *airport)
    {
        airport->setWindowTitle(QCoreApplication::translate("airport", "airport", nullptr));
        back_button->setText(QCoreApplication::translate("airport", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("airport", "\350\257\267\350\276\223\345\205\245\346\234\272\345\234\272\344\273\243\345\217\267\357\274\232", nullptr));
        dep_button->setText(QCoreApplication::translate("airport", "\345\207\272\345\217\221\350\210\252\347\217\255\346\237\245\350\257\242", nullptr));
        arv_button->setText(QCoreApplication::translate("airport", "\345\210\260\350\276\276\350\210\252\347\217\255\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class airport: public Ui_airport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRPORT_H
