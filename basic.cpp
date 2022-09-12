#include "basic.h"
#include "QTextStream"
#include "QFile"
#include "error.h"
#include "QDebug"

basic::basic(QObject *parent) : QObject(parent)
{

}

void basic::saveProject(QString path)
{
    //  保存当前路径以及版本信息
    savePath(path);

    //  定义根节点{}
    QJsonObject rootObj;
    rootObj.insert("pathAndVersion", pathAndVersion);

    //  实例化对象
    QJsonDocument doc;
    doc.setObject(rootObj);

    //  保存文件
    //  检查是否是一个已经存在json文件，否的话就创建，是的话就保存
    QString fileName = path + "/userPro.json";
    QFile file(fileName);
    int mark=0;
A:  if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        error HFASTError;
        Mess mes;
        mes.Fun = "void basic::saveProject(QString path)";
        mes.Head = "basic.h";
        mes.title = "Critical Error";
        mes.Loc = "Save the current project";
        mes.Mess = "Cannot create file in the current directory";
        mark = HFASTError.HFASTCritical(mes);
        if(mark == 1)
            goto A; // retry
    }
    if(mark != 2)
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream << doc.toJson();
        file.close();
    }
    else
    {
        //  没有保存文件
        error HFASTError;
        Mess mes;
        mes.Fun = "void basic::saveProject(QString path)";
        mes.Head = "basic.h";
        mes.title = "Informed news";
        mes.Loc = "Save the json file";
        mes.Mess = "The current project does not save";
        HFASTError.HFASTInform(mes);
    }
}

void basic::savePath(QString path)
{
    //  保存当前路径
    pathAndVersion.insert("workDir", path);
    pathAndVersion.insert("foamVersion", VERSION);
}

void basic::readProject(QString path)
{
    //  读取json文件
    QString fileName = path + "/userPro.json";
    QFile file(fileName);
    int mark=0;
B:  if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        error HFASTError;
        Mess mes;
        mes.Fun = "void basic::readProject(QString path)";
        mes.Head = "basic.h";
        mes.title = "Critical Error";
        mes.Loc = "Read the current project";
        mes.Mess = "Cannot open project in the current directory";
        mark = HFASTError.HFASTCritical(mes);
        if(mark == 1)
            goto B; // retry
    }
    if(mark!=2)
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        QString content = stream.readAll();
        file.close();

        //  解析成QJsonDocument
        QJsonParseError jsonError;
        QJsonDocument doc
                = QJsonDocument::fromJson(content.toUtf8(), &jsonError);
        if(jsonError.error != QJsonParseError::NoError && !doc.isNull())
        {
            error HFASTError;
            Mess mes;
            mes.Fun = "void basic::readProject(QString path)";
            mes.Head = "basic.h";
            mes.title = "Critical Error";
            mes.Loc = "Try to resolve the json file";
            mes.Mess = "Json file is error";
            HFASTError.HFASTCritical(mes);
            return;
        }

        //  获取根
        QJsonObject rootObj = doc.object();

        //  获取路径和版本号
        QJsonValue pathAndVersionV = rootObj.value("pathAndVersion");
        if(pathAndVersionV.type() == QJsonValue::Object)
        {
            pathAndVersion = pathAndVersionV.toObject();
            workPath = pathAndVersion.value("workDir");
            Version = pathAndVersion.value("foamVersion");
            qDebug() << workPath.toString().toLocal8Bit().data()<<endl;
            qDebug() << Version.toString().toLocal8Bit().data()<<endl;
        }
        else
        {
            error HFASTError;
            Mess mes;
            mes.Fun = "void basic::readProject(QString path)";
            mes.Head = "basic.h";
            mes.title = "Critical Error";
            mes.Loc = "Try to get the path and version";
            mes.Mess = "pathAndVersionV is not an object";
            HFASTError.HFASTCritical(mes);
            return;
        }
    }
}
