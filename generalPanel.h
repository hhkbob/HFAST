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
#include <QStackedLayout>
#include "printTool.h"

class generalPanel : public QMainWindow
{
    Q_OBJECT
public:
    generalPanel(printTool *pEvent, QWidget *widget);
    ~generalPanel();

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
    QLineEdit *paraSimpleN[4];
    QLineEdit *paraHierarch[5];


private:
    void setGravityGroup();
    void setParaGroup();
    void saveGravity();

    QGroupBox *paraMG;
    QStackedLayout *paraStackLt;
    QHBoxLayout *simLayout;
    QHBoxLayout *simLayout2;
    QVBoxLayout *simVLayout;
    QHBoxLayout *hLayout[3];
    QVBoxLayout *hVLayout;
    QLabel *simpleN;
    QLabel *simpleDelta;
    QLabel *hierarchN;
    QLabel *hierarchDelta;
    QLabel *hierarchOrder;
    QWidget *simpleWidget;
    QWidget *hWidget;
    QPushButton *viewButton;


signals:

private slots:
    void saveProject();
    void viewTriggered();

};

#endif // GENERALPANEL_H
