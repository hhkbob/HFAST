#ifndef GENERALPANEL_H
#define GENERALPANEL_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QComboBox>
#include <QSpinBox>
#include "printTool.h"

class generalPanel : public QMainWindow
{
    Q_OBJECT
public:
    generalPanel(printTool *pEvent, QWidget *widget);

private:
    printTool *pEvent;

    QVBoxLayout *vLayout;
    QHBoxLayout *gTLayout;

    QVBoxLayout *gGroupLayout;
    QVBoxLayout *pGroupLayout;
    QHBoxLayout *paraLayout1;
    QHBoxLayout *paraLayout2;


    QGroupBox *gravityGroup;
    QGroupBox *paraGroup;

    QLabel  *gDirection;
    QLabel  *paraNSub;
    QLabel  *paraMethod;

public:
    QLineEdit *gxLine;
    QLineEdit *gyLine;
    QLineEdit *gzLine;
    QSpinBox *paraNum;
    QComboBox *paraMet;

private:
    void setGravityGroup();
    void setParaGroup();
    void saveGravity();

signals:

private slots:
    void saveProject();

};

#endif // GENERALPANEL_H
