#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include "notify.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *w = new QWidget();
    NotificationClient *nf = new NotificationClient;


    QHBoxLayout *hbox = new QHBoxLayout();
    QPushButton *happy = new QPushButton("happy");
    QPushButton *sad = new QPushButton("sad");

    QObject::connect(happy,&QPushButton::clicked,[=](){
        nf->setNotification("happy");
    });

    QObject::connect(sad,&QPushButton::clicked,[=](){
        nf->setNotification("sad");
    });


    hbox->addWidget(happy);
    hbox->addWidget(sad);
    w->setLayout(hbox);
    w->show();

    return a.exec();
}
