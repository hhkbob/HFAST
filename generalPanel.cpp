#include "generalPanel.h"

generalPanel::generalPanel(printTool *p, QWidget *widget)
{

    pEvent = p;

    vLayout = new QVBoxLayout;

    //  设置-重力组
    setGravityGroup();

    //  设置-并行组
    setParaGroup();

    vLayout->addWidget(gravityGroup);
    vLayout->addWidget(paraGroup);

    vLayout->addStretch();
    widget->setLayout(vLayout);
}

generalPanel::~generalPanel()
{
    delete pEvent;
    delete gDirection;
    delete paraNSub;
    delete paraMethod;
    delete gxLine;
    delete gyLine;
    delete gzLine;
    delete paraNum;
    delete paraMet;
    delete paraSimpleN;
    delete paraHierarch;
    delete simpleN;
    delete simpleDelta;
    delete hierarchN;
    delete hierarchDelta;
    delete hierarchOrder;
    delete paraMG;
    delete simLayout;
    delete simLayout2;
    delete simVLayout;
    delete hLayout;
    delete hVLayout;

    delete gravityGroup;
    delete paraGroup;
    delete paraLayout1;
    delete paraLayout2;
    delete pGroupLayout;
    delete gGroupLayout;
    delete gTLayout;
    delete vLayout;
}

void generalPanel::setGravityGroup()
{
    gravityGroup = new QGroupBox("Gravity");
    gGroupLayout = new QVBoxLayout;
    gTLayout = new QHBoxLayout;

    //--gravity group
    gDirection = new QLabel(tr("value (x, y, z)"));

    gxLine = new QLineEdit();
    gyLine = new QLineEdit();
    gzLine = new QLineEdit();

    gxLine->setText("0");
    gyLine->setText("0");
    gzLine->setText("9.8");

    gTLayout->addWidget(gDirection);
    gTLayout->addWidget(gxLine);
    gTLayout->addWidget(gyLine);
    gTLayout->addWidget(gzLine);
    gTLayout->addStretch();

    gGroupLayout->addLayout(gTLayout);

    gravityGroup->setLayout(gGroupLayout);
}

void generalPanel::setParaGroup()
{
    pGroupLayout = new QVBoxLayout;
    paraGroup = new QGroupBox(tr("Parallel"));

    viewButton = new QPushButton(tr("View cellDist"));

    paraLayout1 = new QHBoxLayout;
    paraLayout2 = new QHBoxLayout;
    paraStackLt = new QStackedLayout;

    simpleN = new QLabel("n");
    simpleDelta = new QLabel("delta");
    hierarchN = new QLabel("n");
    hierarchDelta = new QLabel("delta");
    hierarchOrder = new QLabel("order");

    simLayout = new QHBoxLayout;
    simLayout2 = new QHBoxLayout;
    simVLayout = new QVBoxLayout;
    hVLayout = new QVBoxLayout;

    for(int i=0; i<3; i++)
        hLayout[i] = new QHBoxLayout;

    for(int i=0; i<4; i++)
        paraSimpleN[i] = new QLineEdit;
    for(int i=0; i<5; i++)
        paraHierarch[i] = new QLineEdit;

    //  创建页面
    simpleWidget = new QWidget;
    hWidget = new QWidget;

    //  页面放置组件-simpleMethod
    simLayout->addWidget(simpleN);
    simLayout->addWidget(paraSimpleN[0]);
    simLayout->addWidget(paraSimpleN[1]);
    simLayout->addWidget(paraSimpleN[2]);
    simLayout->addStretch();
    simLayout2->addWidget(simpleDelta);
    simLayout2->addWidget(paraSimpleN[3]);
    simLayout2->addStretch();
    simVLayout->addLayout(simLayout);
    simVLayout->addLayout(simLayout2);
    simVLayout->addStretch();
    simpleWidget->setLayout(simVLayout);

    //  放置页面-hi
    hLayout[0]->addWidget(hierarchN);
    hLayout[0]->addWidget(paraHierarch[0]);
    hLayout[0]->addWidget(paraHierarch[1]);
    hLayout[0]->addWidget(paraHierarch[2]);
    hLayout[0]->addStretch();
    hLayout[1]->addWidget(hierarchDelta);
    hLayout[1]->addWidget(paraHierarch[3]);
    hLayout[1]->addStretch();
    hLayout[2]->addWidget(hierarchOrder);
    hLayout[2]->addWidget(paraHierarch[4]);
    hLayout[2]->addStretch();
    hVLayout->addLayout(hLayout[0]);
    hVLayout->addLayout(hLayout[1]);
    hVLayout->addLayout(hLayout[2]);
    hWidget->setLayout(hVLayout);

    //  声明方法
    paraNSub = new QLabel(tr("parallel num"));
    paraMethod = new QLabel(tr("method"));
    paraNum = new QSpinBox;
    paraMet = new QComboBox;
    paraMG = new QGroupBox("");

    paraMet->addItem("simple");
    paraMet->addItem("hierarchical");
    paraMet->addItem("metis");
    paraMet->addItem("scotch");
    paraMet->setCurrentIndex(0);

    //  放置组件
    paraLayout1->addWidget(paraNSub);
    paraLayout1->addWidget(paraNum);
    paraLayout1->addStretch();
    paraLayout2->addWidget(paraMethod);
    paraLayout2->addWidget(paraMet);
    paraLayout2->addWidget(viewButton);
    paraLayout2->addStretch();

    paraStackLt->addWidget(simpleWidget);
    paraStackLt->addWidget(hWidget);
    paraMG->setLayout(paraStackLt);

    //  设置布局
    pGroupLayout->addLayout(paraLayout1);
    pGroupLayout->addLayout(paraLayout2);
    pGroupLayout->addWidget(paraMG);
    pGroupLayout->addStretch();
    paraGroup->setLayout(pGroupLayout);

    //  槽链接
    connect(paraMet, SIGNAL(activated(int)), paraStackLt, SLOT(setCurrentIndex(int)));
    connect(viewButton, SIGNAL(clicked(bool)), this, SLOT(viewTriggered()));
}

void generalPanel::saveGravity()
{
    GRAVITY g;
    g.gxyz[0] = gxLine->text();
    g.gxyz[1] = gyLine->text();
    g.gxyz[2] = gzLine->text();

    pEvent->printGravity(g);
}

void generalPanel::saveProject()
{
    saveGravity();
}

void generalPanel::viewTriggered()
{
    system("bash -c \"decomposePar -cellDist\"");
}
