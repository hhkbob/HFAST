#include "foamInit.h"
#include <QDir>

foamInit::foamInit()
{

}

int foamInit::newCase(QString casePath, QString loc)
{
    //  检测是否存在0, constant, system文件夹
    QString ZeroPath = casePath +"/0";
    QString conPath = casePath + "/constant";
    QString sysPath = casePath + "/system";
    Mess mes;
    mes.Fun = "int foamInit::newCase(QString casePath, QString loc)";
    mes.Head = "foamInit.h";
    mes.Loc = loc;
    mes.title = "Warning";
    if(! isExist(ZeroPath))
    {
A:      mes.Mess = "The path: " +casePath +"\n0 folder does not exist. Create or abort?";
        int mark = HFASTError.HFASTWarning(mes);
        if(mark == 1)
        {
            //  创建0文件夹
            int mark2 = mkdir(ZeroPath, mes);
            if(mark2 == 2)
                goto A;
        }
    }
    if(! isExist(conPath))
    {
B:      mes.Mess = "The path: " +casePath +"\nconstant folder does not exist. Create or abort?";
        int mark = HFASTError.HFASTWarning(mes);
        if(mark ==1)
        {
            //  创建constant文件夹
            int mark2 = mkdir(conPath, mes);
            if(mark2 == 2)
                goto B;
        }
    }
    if(! isExist(sysPath))
    {
C:      mes.Mess = "The path: " +casePath +"\nsystem folder does not exist. Create or abort?";
        int mark = HFASTError.HFASTWarning(mes);
        if(mark == 1)
        {
            //  创建system文件夹
            int mark2 = mkdir(sysPath, mes);
            if(mark2 == 2)
                goto C;
        }
    }
    return 0;
}

int foamInit::isExist(QString path)
{
    QDir dir(path);
    if(dir.exists())
        return 1;
    else   
        return 0;
}

int foamInit::mkdir(QString path, Mess mes)
{
    QDir dir(path);
    bool ismkdir = dir.mkdir(path);
    if(!ismkdir)
        return HFASTError.HFASTCritical(mes);
    else
        return 1;

}
