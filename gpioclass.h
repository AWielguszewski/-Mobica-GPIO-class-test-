#ifndef GPIO_CLASS_H
#define GPIO_CLASS_H

#include <QString>
using namespace std;

//stale
#define HIGH 1
#define LOW 0
#define OUT "out"
#define IN "in"
#define EXPORT_PATH "/sys/class/gpio/export"
#define UNEXPORT_PATH "/sys/class/gpio/unexport"
#define PIN_FOLDER_PATH "/sys/class/gpio/gpio"

class GPIO
{
public:
    GPIO(unsigned int num);
    ~GPIO();
    void setDirection(const char * direction);
    void setValue(const unsigned int value);
    unsigned int getPinNumber();
private:
    GPIO(); //blokuj konstruktor domyslny
    void export_gpio();
    void unexport_gpio();
    unsigned int pin_number;
};

#endif
