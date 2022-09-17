/**
  * @file     	printTool.h
  * @author   	Huakun Huang
  * @email   	huanghuakun0902@163.com
  * @version	V1.0
  * @date    	09-SEP-2022
  * @license  	GNU General Public License (GPL)
  * @brief   	专门处理各种OpenFOAM文档的头文件，版本控制等
  * @detail		详细
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

#ifndef PRINTTOOL_H
#define PRINTTOOL_H

#include <QString>
#include <fstream>
#include <iostream>
#include "basic.h"
#include "QLineEdit"
using namespace std;
struct GRAVITY
{
    QString gxyz[3];
};

class printTool
{
public:
    printTool();

    //  当前OpenFOAM版本
    QString version;

    /**
    * @brief  打印OpenFOAM文件的文件头
    */
    void printHeader(FILE *file, QString root, QString fileName, QString classV);

    /**
    * @brief 打印OpenFOAM文件的末尾
    */
    void printFoot(FILE *file);

    void printGravity(GRAVITY g);

public:
    basic saveTool;

private:
    void initBasic();

};

#endif // PRINTTOOL_H
