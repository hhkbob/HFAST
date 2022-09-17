#ifndef FILETOOLBAR_H
#define FILETOOLBAR_H

#include <QWidget>
#include <QMenu>
#include <QFileDialog>
#include <QAction>
#include "printTool.h"

class fileToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit fileToolBar(QMenu *File);
    ~fileToolBar();

    QString filePath;

    //  保存工程文件
    QAction *savePr;


private:
    //  设置工作目录
    QAction *setWorkDir;

    //  读取工程文件设置
    QAction *readProj;


signals:
    void triggered();

public slots:
    void setWDTrigger();
    void readProject();
};

#endif // FILETOOLBAR_H
