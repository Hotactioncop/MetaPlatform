#include "showwindow.h"

ShowWindow::ShowWindow(QWidget *parent) : QWidget(parent)
{
    this->setFocus();
    rec = QRect(this->rect().x(),this->rect().y(),this->rect().width()-30,this->rect().height()-30);
    X = QPoint(rec.x()+rec.width(),rec.y());
    Y = QPoint(rec.x(),rec.y()+rec.height());
}


void ShowWindow::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.setPen(QPen(Qt::darkCyan,1,Qt::SolidLine));
    pen.drawRect(rec);

    for(int i = (difX+startPosX)%dateSize;i<rec.height(); i+=dateSize){
        X= QPoint(rec.x()+rec.width(),rec.y()+i);
        pen.drawLine(X,QPoint(X.x()+10,X.y()));
    }
    for(int i = (difY+startPosY)%dateSize;i<rec.width(); i+=dateSize){
        Y= QPoint(rec.x()+i,rec.y()+rec.height());
        pen.drawLine(QPoint(Y.x(),Y.y()+10),Y);
    }

}


void ShowWindow::resizeEvent(QResizeEvent *event)
{
    rec = QRect(this->rect().x()+5,this->rect().y()+5,this->rect().width()-30,this->rect().height()-30);
    repaint();
}


void ShowWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        isPressed=true;
        mouse1 = QPoint(event->pos().x(),event->pos().y());
        mouse2 = QPoint(event->pos().x(),event->pos().y());
    }
}

void ShowWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(isPressed){
        mouse2 = QPoint(event->pos().x(),event->pos().y());
        if((mouse2.y()-mouse1.y())%dateSize<0){
            difX = ((mouse2.y()-mouse1.y())%dateSize+dateSize);
        }
        else if((mouse2.y()-mouse1.y())%dateSize>0){
            difX = (mouse2.y()-mouse1.y())%dateSize;
        }
        if((mouse2.x()-mouse1.x())%dateSize<0){
            difY =((mouse2.x()-mouse1.x())%dateSize+dateSize);
        }
        else if((mouse2.x()-mouse1.x())%dateSize>0){
            difY =(mouse2.x()-mouse1.x())%dateSize;
        }
        qDebug() << "dateSize=" << dateSize << "; startPosX=" << (difX+startPosX)%dateSize << "; startPosY=" << (difY+startPosY)%dateSize;
        repaint();
    }
}


void ShowWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isPressed=false;
    startPosX = difX;
    startPosY = difY;
    difX=0;
    difY=0;
}


void ShowWindow::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0 && (dateSize*2<rec.width() || dateSize*2<rec.height())){
        dateSize*=2;
    }
    else if (event->delta()<0 && (dateSize/2>10)){
        dateSize/=2;
    }
    repaint();
}
