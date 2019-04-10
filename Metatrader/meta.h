#ifndef META_H
#define META_H

#include <QMainWindow>

namespace Ui {
class Meta;
}

class Meta : public QMainWindow
{
    Q_OBJECT

public:
    explicit Meta(QWidget *parent = nullptr);
    ~Meta();

private:
    Ui::Meta *ui;
};

#endif // META_H
