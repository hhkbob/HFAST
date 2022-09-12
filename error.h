/**
  * @file     	error.h
  * @author   	Huakun Huang
  * @email   	huanghuakun0902@163.com
  * @version	V1.0
  * @date    	10-SEP-2022
  * @license  	GNU General Public License (GPL)
  * @brief   	专门处理软件出现的各种错误、提示以及警告等信息
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

#ifndef ERROR_H
#define ERROR_H

#include <QWidget>
#include <QMessageBox>

struct Mess{
    QString title;
    QString Loc;
    QString Fun;
    QString Head;
    QString Mess;
};

class error : public QWidget
{
    Q_OBJECT
public:
    explicit error(QWidget *parent = nullptr);

    //  警告信息
    int HFASTWarning(Mess mes);

    //  提示信息
    int HFASTInform(Mess mes);

    //  严重错误
    int HFASTCritical(Mess mes);

signals:

public slots:
};

#endif // ERROR_H
