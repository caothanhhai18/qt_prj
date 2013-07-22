#include "mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget * window= new QWidget;
    window->setWindowTitle("Enter your age");
    QSpinBox * spinbox = new QSpinBox;
    QSlider * slider = new QSlider(Qt::Horizontal);
    spinbox->setRange(0,130);
    slider->setRange(0,130);
    QObject::connect(slider,SIGNAL(valueChanged(int)),spinbox,SLOT(setValue(int)));
    QObject::connect(spinbox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    spinbox->setValue(35);
    QHBoxLayout * layout= new QHBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(spinbox);
    window->setLayout(layout);
    window->show();
    return a.exec();
}
