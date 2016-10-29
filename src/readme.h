#ifndef README_H
#define README_H

#include <QDialog>

namespace Ui {
class readme;
}

class readme : public QDialog
{
    Q_OBJECT

public:
    explicit readme(QWidget *parent = 0);
    ~readme();

private:
    Ui::readme *ui;
};

#endif // README_H
