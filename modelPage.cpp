#include "modelPage.h"

modelPage::modelPage(QWidget *model)
{
    vLayout = new QVBoxLayout;
    OKButton = new QPushButton(tr("OK"));
    vLayout->addWidget(OKButton);
    model->setLayout(vLayout);
}
