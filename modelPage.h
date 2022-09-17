#ifndef MODELPAGE_H
#define MODELPAGE_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>

class modelPage : public QMainWindow
{
    Q_OBJECT
public:
    explicit modelPage(QWidget *model);

private:
    QVBoxLayout *vLayout;
    QPushButton *OKButton;

signals:

public slots:
};

#endif // MODELPAGE_H
