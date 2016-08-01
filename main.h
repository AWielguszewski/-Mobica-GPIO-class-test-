#ifndef MAIN_H
#define MAIN_H

#include <QString>
#include <QApplication>
#include <QDebug>
#include "gpioclass.h"

extern GPIO pin4;
extern QObject *object;

class MyClass : public QObject
{
    Q_OBJECT

public slots:
    void cppSlot(const QString &msg){
        QObject *btn = object->findChild<QObject*>("btn");
        QObject *txt = object->findChild<QObject*>("txt");

        if(pin4.getValue() == HIGH)
        {
            pin4.setValue(LOW);
            btn->setProperty("color", "#DE260C");
            txt->setProperty("text", "Led OFF");
        }
        else
        {
            pin4.setValue(HIGH);
            btn->setProperty("color", "#3FF02A");
            txt->setProperty("text", "Led ON");
        }

        qDebug() << "Incoming command: " << msg;
    }
};

#endif // MAIN_H
