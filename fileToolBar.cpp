#include "fileToolBar.h"
#include "error.h"

fileToolBar::fileToolBar(QMenu *File)
{
    //  初始化动作
    setWorkDir = new QAction(tr("Set working directory"));
    readProj = new QAction(tr("Read project (*.json)"));

    //  槽函数链接
    connect(setWorkDir, SIGNAL(triggered()), this, SLOT(setWDTrigger()));
    connect(readProj, SIGNAL(triggered()), this, SLOT(readProject()));

    //  放置动作按钮
    File->addAction(setWorkDir);
    File->addAction(readProj);
}

fileToolBar::~fileToolBar()
{

}

void fileToolBar::setWDTrigger()
{
    //  打开文件对话框，选择路径
    filePath = QFileDialog::getExistingDirectory(
                this, tr("Please choose a directorey")
                );
    basic bas;
    bas.saveProject(filePath);
}

void fileToolBar::readProject()
{
    //  打开文件对话框，选择路径
    QString path = QFileDialog::getExistingDirectory(
                this, tr("Please choose a work directorey")
                );
    //  判断是否存在userPro.json文件
    QString file = path +"/userPro.json";
    FILE *doc;
    doc = fopen(file.toLocal8Bit().data(),"r");
    if(doc==NULL)
    {
        error HFASTError;
        Mess mes;
        mes.Fun = "void fileToolBar::readProject()";
        mes.Head = "fileTooBar.h";
        mes.Loc = "Try to read the project";
        mes.title = "Warning";
        mes.Mess = "The " + file +" cannot be found. Reading project fails.";
        HFASTError.HFASTWarning(mes);
    }
    else
    {
        basic bas;
        bas.readProject(path);
    }
}
