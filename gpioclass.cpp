#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "gpioclass.h"
#include <cstring>

using namespace std;

GPIO::GPIO()
{
    //nic
}

GPIO::GPIO(unsigned int num)
{
    this->pin_number = num;
    export_gpio();
}

GPIO::~GPIO()
{
    unexport_gpio();
    qDebug() << "Destruktor " << UNEXPORT_PATH;
}

void GPIO::export_gpio()
{
    QFile export_file(EXPORT_PATH);
    if (!export_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error: Cannot open file: " << EXPORT_PATH;
        return;
    }

    QTextStream streamToExportFile(&export_file);
    streamToExportFile << QString::number(pin_number);
}

void GPIO::unexport_gpio()
{
    QFile unexport_file(UNEXPORT_PATH);
    if (!unexport_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error: Cannot open file: " << UNEXPORT_PATH;
        return;
    }

    QTextStream streamToUnexportFile(&unexport_file);
    streamToUnexportFile << QString::number(pin_number);
}

void GPIO::setDirection(const char * direction)
{
    if(!(!strcmp(direction,OUT) || !strcmp(direction,IN)))
    {
        qDebug() << "Error: Bad direction: " << direction;
        return;
    }

    QString direction_path;
    direction_path.append(PIN_FOLDER_PATH).append(QString::number(pin_number)).append("/direction");

    QFile direction_file(direction_path);
    if (!direction_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error: Cannot open file: " << direction_path;
        return;
    }

    QTextStream streamToDirectionFile(&direction_file);
    streamToDirectionFile << direction;
}

QString GPIO::getDirection()
{
    QString direction_path;
    direction_path.append(PIN_FOLDER_PATH).append(QString::number(pin_number)).append("/direction");

    QFile direction_file(direction_path);
    if (!direction_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error: Cannot open file: " << direction_path;
        return;
    }

    QTextStream streamFromDirectionFile(&direction_file);
    return streamFromDirectionFile.readLine();
}


void GPIO::setValue(const unsigned int value)
{
    if(!(value == HIGH || value == LOW))
    {
        qDebug() << "Error: Bad value: " << value << "   //pick HIGH or LOW";
        return;
    }

    QString value_path;
    value_path.append(PIN_FOLDER_PATH).append(QString::number(pin_number)).append("/value");

    QFile value_file(value_path);
    if (!value_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error: Cannot open file: " << value_path;
        return;
    }

    QTextStream streamToValueFile(&value_file);
    streamToValueFile << QString::number(value);
}

unsigned int GPIO::getValue()
{
    QString value_path;
    value_path.append(PIN_FOLDER_PATH).append(QString::number(pin_number)).append("/value");

    QFile value_file(value_path);
    if (!value_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error: Cannot open file: " << value_path;
        return;
    }

    QTextStream streamFromValueFile(&value_file);
    QString numberRead = streamFromValueFile.readLine();
    return numberRead.toInt();
}

unsigned int GPIO::getPinNumber()
{
    return pin_number;
}
