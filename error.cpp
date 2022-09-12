#include "error.h"

error::error(QWidget *parent) : QWidget(parent)
{

}

int error::HFASTWarning(Mess mes)
{
    QString MESSAGE = mes.Head + tr(" for ") + mes.Fun
            + tr(" function. Trigger location: ") + mes.Loc;
    MESSAGE = MESSAGE +"\n\n"+ mes.Mess + "\n\n";
    MESSAGE = MESSAGE + tr("Continue button: Ignore the current warning\n");
    MESSAGE = MESSAGE + tr("Abort/ESC button: Destroy the application and exit");
    QMessageBox box(QMessageBox::Warning, tr(mes.title.toLocal8Bit().data()),
                    MESSAGE, 0, this);
    box.addButton(tr("Continue"), QMessageBox::AcceptRole);
    box.addButton(tr("Abort"), QMessageBox::RejectRole);
    if(box.exec() == QMessageBox::RejectRole)
        abort();
    else
        return 1;
}

int error::HFASTInform(Mess mes)
{
    QString MESSAGE = mes.Head + tr(" for ") + mes.Fun
            + tr(" function. Trigger location: ") + mes.Loc;
    MESSAGE = MESSAGE +"\n\n"+ mes.Mess +"\n\n";
    MESSAGE = MESSAGE + tr("Click the OK/ESC button to close the window\n");
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this, tr(mes.title.toLocal8Bit().data()),
                                     MESSAGE);
    return 1;
}

int error::HFASTCritical(Mess mes)
{
    QString MESSAGE = mes.Head + tr(" for ") + mes.Fun
            + tr(" function. Trigger location: ") + mes.Loc;
    MESSAGE = MESSAGE +"\n\n"+ mes.Mess +"\n\n";
    MESSAGE = MESSAGE + tr("Retry  button: Try again the same action\n");
    MESSAGE = MESSAGE + tr("Ignore button: Still run\n");
    MESSAGE = MESSAGE + tr("Abort/Esc button: Destroy the application and exit");
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, tr(mes.title.toLocal8Bit().data()),
            MESSAGE,
            QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore);
    if(reply == QMessageBox::Abort)
        abort();
    else if(reply == QMessageBox::Ignore)
        return 2;
    else
        return 1;
}
