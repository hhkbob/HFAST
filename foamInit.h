/**
  * @file     	foamInit.h
  * @author   	Huakun Huang
  * @email   	huanghuakun0902@163.com
  * @version	V1.0
  * @date    	10-SEP-2022
  * @license  	GNU General Public License (GPL)
  * @brief   	程序启动时对算例文件进行检查、读取里面的设置，判断是否为就工程文件
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
  * V1.0|Huang Huakun|10-SEP-2022|Create File
  * <h2><center>&copy;COPYRIGHT 2017 WELLCASA All Rights Reserved.</center></h2>
  */

#ifndef FOAMINIT_H
#define FOAMINIT_H
#include <QString>
#include "error.h"

class foamInit
{
public:
    foamInit();
    error HFASTError;

    /**
    * @brief 程序开始时检测当前文件夹是否是典型的算例文件，不是则重新设置
    */
    int newCase(QString casePath, QString loc);

    /**
    * @brief 判断路径是否存在, mark是否创建
    */
    int isExist(QString path);

    /**
    * @brief 创建文件夹
    */
    int mkdir(QString path, Mess mes);

};

#endif // FOAMINIT_H
