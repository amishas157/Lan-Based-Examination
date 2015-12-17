#ifndef TEST_H
#define TEST_H

#include <QMainWindow>

namespace Ui {
class Test;
}

class Test : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test(int a, QWidget *parent = 0);
    ~Test();

public slots:
    void MySlot();

private slots:
    void on_timeEdit_timeChanged(const QTime &time);

    void on_label_windowIconTextChanged(const QString &iconText);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Test *ui;
};

#endif // TEST_H
