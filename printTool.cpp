/**
  * @file     	printTool.cpp
  * @author   	Huakun Huang
  * @email   	huanghuakun0902@163.com
  * @version	V1.0
  * @date    	09-SEP-2022
  * @license  	GNU General Public License (GPL)
  * @brief   	专门处理各种OpenFOAM文档的头文件，版本控制等
  * @detail		头文件定义可以参考printTool.h
  * @attention
  *  This file is part of HFAST.                                                                                              \n
  *  This program is free software; you can redistribute it and/or modify 		          \n
  *  it under the terms of the GNU General Public License version 3 as 		          \n
  *  published by the Free Software Foundation.                               	                              \n
  *  You should have received a copy of the GNU General Public License   		          \n
  *  along with OST. If not, see <http://www.gnu.org/licenses/>.       			          \n
  *  Unless required by applicable law or agreed to in writing, software       	                    \n
  *  distributed under the License is distributed on an "AS IS" BASIS,         	                    \n
  *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  	\n
  *  See the License for the specific language governing permissions and     	          \n
  *  limitations under the License.   									\n
  *   														\n
  * @htmlonly
  * <span style="font-weight: bold">History</span>
  * @endhtmlonly
  * Version|Auther|Date|Describe
  * ------|----|------|--------
  * V1.0|Huang Huakun|09-SEP-2022|Create File
  * <h2><center>&copy;COPYRIGHT 2017 WELLCASA All Rights Reserved.</center></h2>
  */

#include "printTool.h"

printTool::printTool()
{

}

void printTool::printHeader(FILE *file, QString rt, QString obj, QString clas)
{
    fprintf(file, "/*--------------------------------*- C++ -*----------------------------------*\\\n");
    fprintf(file, "| =========                 |                                                 |\n");
    fprintf(file, "| \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox           |\n");
    fprintf(file, "|  \\    /   O peration     | Version:  %s                                  |\n", version.toLocal8Bit().data());
    fprintf(file, "|   \\  /    A nd           | Web:      www.OpenFOAM.org                      |\n");
    fprintf(file, "|    \\/     M anipulation  |                                                 |\n");
    fprintf(file, "\\*---------------------------------------------------------------------------*/\n");
    fprintf(file, "%s\n{\n", "FoamFile");
    fprintf(file, "    version	   2.0;\n");
    fprintf(file, "    format	   ascii;\n");
    fprintf(file, "    class	   %s;\n", clas.toLocal8Bit().data());
    fprintf(file, "    location	  \"%s\";\n", rt.toLocal8Bit().data());
    fprintf(file, "    object	   %s;\n}\n", obj.toLocal8Bit().data());
    fprintf(file, "//    author      Huakun Huang\n");
    fprintf(file, "//    Email:      huanghuakun0902@163.com\n");
    //fprintf(file, "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //\n");
}

void printTool::printFoot(FILE *file)
{
    fprintf(file, "// ************************************************************************* //");
}

void printTool::printGravity(GRAVITY g)
{
    initBasic();
    QString workPath = QDir::currentPath();
    QString fileName = workPath + "/constant/g";
    bool OK[3];
    g.gxyz[0].toDouble(&OK[0]);
    g.gxyz[0].toDouble(&OK[1]);
    g.gxyz[2].toDouble(&OK[2]);
    for(int i=0; i<3; i++)
    {
        if(!OK[i])
        {
            error HFASTError;
            Mess mes;
            mes.Fun = "void printTool::printGravity()";
            mes.Head = "printTool.h";
            mes.title = "Critical Error";
            mes.Loc = "Save the gravity settings";
            mes.Mess = "Application found error inputs for gravity";
            int mark = HFASTError.HFASTCritical(mes);
            if(mark==1 || mark==2)
                return;
        }
    }
    saveTool.gravity[0] = g.gxyz[0];
    saveTool.gravity[1] = g.gxyz[1];
    saveTool.gravity[2] = g.gxyz[2];

    FILE *file2;
A:  file2 = fopen(fileName.toLocal8Bit().data(), "w");
    if(file2==NULL)
    {
        error HFASTError;
        Mess mes;
        mes.Fun = "void printTool::printGravity()";
        mes.Head = "printTool.h";
        mes.title = "Critical Error";
        mes.Loc = "Save the gravity settings";
        mes.Mess = "Cannot create g file in the constant directory";
        int mark = HFASTError.HFASTCritical(mes);
        if(mark==1)
            goto A;
        if(mark==2)
            return;
    }
    printHeader(file2,"constant","g","uniformDimensionedVectorField");
    printFoot(file2);
    fprintf(file2, "\n\ndimensions	[0 1 -2 0 0 0 0];\n");
    fprintf(file2, "value  (%s %s %s);\n\n\n\n", saveTool.gravity[0].toLocal8Bit().data(),
         saveTool.gravity[1].toLocal8Bit().data(),
         saveTool.gravity[2].toLocal8Bit().data());
    printFoot(file2);
    fclose(file2);
}

void printTool::initBasic()
{
    saveTool.readProject(QDir::currentPath());
    version = saveTool.Version;
}
