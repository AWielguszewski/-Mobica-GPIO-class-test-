#include <QApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include "gpioclass.h"
#include "main.h"

#define QML_EXAMPLE_SURFACE_ID 3

GPIO pin4(4);
QObject *object;

int main(int argc, char *argv[])
{
    setenv("QT_QPA_PLATFORM", "wayland", 1); // force to use wayland plugin
    setenv("QT_WAYLAND_DISABLE_WINDOWDECORATION", "1", 1);

    QGuiApplication app(argc, argv);
    QQuickView view(QUrl(QStringLiteral("qrc:/main.qml")));
    object = (QObject *)view.rootObject();

    MyClass blink;
    QObject::connect(object, SIGNAL(qmlSignal(QString)),
                    &blink, SLOT(cppSlot(QString)));

    pin4.setDirection(OUT);

    view.setProperty("IVI-Surface-ID", QML_EXAMPLE_SURFACE_ID);
    view.show();

    return app.exec();
}


