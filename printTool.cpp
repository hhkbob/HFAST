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
  *  This file is part of HFAST.                                                \n
  *  This program is free software; you can redistribute it and/or modify 		\n
  *  it under the terms of the GNU General Public License version 3 as 		    \n
  *  published by the Free Software Foundation.                               	\n
  *  You should have received a copy of the GNU General Public License   		\n
  *  along with OST. If not, see <http://www.gnu.org/licenses/>.       			\n
  *  Unless required by applicable law or agreed to in writing, software       	\n
  *  distributed under the License is distributed on an "AS IS" BASIS,         	\n
  *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  	\n
  *  See the License for the specific language governing permissions and     	\n
  *  limitations under the License.   											\n
  *   																			\n
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
    version = "9.0";
}

void printTool::printHeader(ofstream file, QString root, QString fileName, QString classV)
{
    file << "/*--------------------------------*- C++ -*----------------------------------*\\"<< endl;
    file << "| =========                 |                                                 |" << endl;
    file << "| \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox           |" << endl;
    file << "|  \\    /   O peration     | Version:  ";
    file << version.toLocal8Bit().data() << "                                     |" << endl;
    file << "|   \\  /    A nd           | Web:      www.OpenFOAM.org                      |" << endl;
    file << "|    \\/     M anipulation  |                                                 |" << endl;
    file << "\\*---------------------------------------------------------------------------*/" << endl;
    file << "FoamFile{\n" << endl;
    file << "    version	   2.0;\n";
    file << "    format	   ascii;\n";
    file << "    class	   "<<classV.toLocal8Bit().data()<<";\n";
    file << "    location	  \""<<root.toLocal8Bit().data()<<"\";\n";
    file << "    object	   "<<fileName.toLocal8Bit().data()<<";\n}\n";
    file << "//    author      Huakun Huang\n";
    file << "//    Email:      huanghuakun0902@163.com\n";
    file << "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //\n";
}

void printTool::printFoot(ofstream file)
{
    file<< "\n// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //\n";
}
