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

    paraLayout1 = new QHBoxLayout;
    paraLayout2 = new QHBoxLayout;

    //  声明方法
    paraNSub = new QLabel(tr("parallel num"));
    paraMethod = new QLabel(tr("method"));
    paraNum = new QSpinBox;
    paraMet = new QComboBox;

    paraMet->addItem("simple");
    paraMet->addItem("hierarchical");
    paraMet->addItem("metis");
    paraMet->setCurrentIndex(0);

    //  放置组件
    paraLayout1->addWidget(paraNSub);
    paraLayout1->addWidget(paraNum);
    paraLayout1->addStretch();
    paraLayout2->addWidget(paraMethod);
    paraLayout2->addWidget(paraMet);
    paraLayout2->addStretch();

    //  设置布局
    pGroupLayout->addLayout(paraLayout1);
    pGroupLayout->addLayout(paraLayout2);
    paraGroup->setLayout(pGroupLayout);
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
