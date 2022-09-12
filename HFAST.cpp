#include "HFAST.h"
#include "ui_HFAST.h"
#include "foamInit.h"
#include "fileToolBar.h"

HFAST::HFAST(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HFAST)
{
    ui->setupUi(this);

    //  初始化界面
    initApp();

    //  检查算例是否存在
    foamInit init;
    init.newCase("E:\\case", "HFAST::HFAST(QWidget *parent) :QMainWindow(parent),ui(new Ui::HFAST)");
}

HFAST::~HFAST()
{
    delete ui;
}

void HFAST::initApp()
{
    //  创建菜单栏
    QMenu *File = this->menuBar()->addMenu(tr("File"));
    QMenu *Tool = this->menuBar()->addMenu(tr("Tools"));

    //  放置菜单--File
    fileToolBar *fileBar = new fileToolBar(File);
}
