#ifndef SHOWWINDOW_H
#define SHOWWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>

class ShowWindow : public QWidget
{
    Q_OBJECT
    QRect rec;          //Размер нашего виджета. ПО этому размеру выводится сетка
    uint startPosX=0;   //Начальная позиция по горизонтали для вывода засечек справа
    uint startPosY=0;   //Начальная позиция по вертикали для вывода засечек снизу
    size_t dateSize = 50;   //Начальная величина пикселей между которыми выводятся засечки
    QPoint mouse1;          //Точка, где произведен первый клик по мыши
    QPoint mouse2;          //Точка, куда зажатая мышь была переведена
    QPoint X,Y;             //Точки для изображения засечек(время/курс)
    bool isPressed = false; //Идентификатор зажатия кнопки
    int difX=0, difY=0;           //Начальная величина разности между первой и второй точкой мыши
public:
    explicit ShowWindow(QWidget *parent = nullptr);

signals:

public slots:

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);

    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event);

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // SHOWWINDOW_H
