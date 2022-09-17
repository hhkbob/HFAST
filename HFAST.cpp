#include "HFAST.h"
#include "ui_HFAST.h"
#include "foamInit.h"


HFAST::HFAST(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HFAST)
{
    ui->setupUi(this);

    //  初始化界面
    initApp();

    //  添加布局
    addLayout();

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
    //  保存项目
    pEvent = new printTool;

    //  创建菜单栏
    File = this->menuBar()->addMenu(tr("File(F)"));
    Tool = this->menuBar()->addMenu(tr("Tools(T)"));

    //  放置菜单--File
    fileBar = new fileToolBar(File);

}

void HFAST::addLayout()
{
    //  创建网格布局
    //gridLayout = new QGridLayout;
    vLayout = new QVBoxLayout;
    hLayout = new QHBoxLayout;
    viewLayout = new QHBoxLayout;
    stackLayout = new QStackedLayout;

    textEdit = new QTextBrowser;  //  增加一个QTexEdit窗口--显示文本
    view = new QDockWidget(tr("View Panel"));
    Splitter1 = new QSplitter(Qt::Horizontal);
    Splitter2 = new QSplitter(Qt::Vertical);
    viewGroup = new QGroupBox(tr("View"));
    mesView = new QTextBrowser;
    viewGroupLayout = new QVBoxLayout;

    runButton = new QPushButton(tr("Run"));  //  运行按钮-运行命令行
    checkButton = new QPushButton(tr("Check")); //  检查网格质量
    generalButton = new QPushButton(tr("General"));
    modelButton = new QPushButton(tr("Model"));
    materialButton = new QPushButton(tr("Materials"));

    //  设置页面属性
    //view->set

    //  创建panel页面，放置组件
    wholeWidget = new QWidget;
    gPanelPage = new QWidget;
    mPanelPage = new QWidget;
    gPanel = new generalPanel(pEvent, gPanelPage);
    mPanel = new modelPage(mPanelPage);

    //  在布局上添加控件 （组件名，行，列，行宽，列宽）
    Splitter2->addWidget(textEdit);
    Splitter2->addWidget(mesView);
    viewGroupLayout->addWidget(Splitter2);
    viewGroup->setLayout(viewGroupLayout);
    Splitter1->addWidget(view);
    Splitter1->addWidget(viewGroup);
    viewLayout->addWidget(Splitter1);

    vLayout->addWidget(generalButton);
    vLayout->addWidget(modelButton);
    vLayout->addWidget(materialButton);
    vLayout->addWidget(runButton);
    vLayout->addWidget(checkButton);

    //  设置布局距离页面左右距离
    //gridLayout->setContentsMargins(10,10,10,10);

    //  放置布局
    //viewLayout->addLayout(gridLayout);
    hLayout->addLayout(vLayout);
    hLayout->addLayout(viewLayout);

    //  链接页面槽函数
    connect(generalButton, SIGNAL(clicked(bool)), this, SLOT(setGeneralPanel()));
    connect(modelButton, SIGNAL(clicked(bool)), this, SLOT(setModelPanel()));
    connect(fileBar->savePr, SIGNAL(triggered()), gPanel, SLOT(saveProject()));

    //  在界面添加布局
    ui->centralWidget->setLayout(hLayout);
    wholeWidget->setLayout(stackLayout);
    view->setWidget(wholeWidget);

    //  放置页面
    stackLayout->addWidget(gPanelPage);
    stackLayout->addWidget(mPanelPage);

}

void HFAST::setGeneralPanel()
{
    stackLayout->setCurrentIndex(0);
}

void HFAST::setModelPanel()
{
    stackLayout->setCurrentIndex(1);
}
