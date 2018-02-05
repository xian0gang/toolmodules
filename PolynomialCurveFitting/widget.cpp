#include "widget.h"
#include "ui_widget.h"
#include <QPoint>
#include <QDebug>
#include <qstringlist.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    paintLab = new PaintLab();
    ui->paintFrame->layout()->addWidget(paintLab);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addPoint_clicked()
{
    QString str = ui->input->text();
    QStringList l = str.split(" ", QString::SkipEmptyParts);
    if(l.count() != 2)
        return;
    bool ok;
    QPoint p;
    p.setX(l.at(0).toInt(&ok));
    if(!ok)
        return;
    p.setY(l.at(1).toInt(&ok));
    if(!ok)
        return;

    qDebug()<<"addpoint"<<p;
    paintLab->addPoint(p);
}

void Widget::on_export_2_clicked()
{
    QFile f("pos");
    f.open(QFile::WriteOnly);
}