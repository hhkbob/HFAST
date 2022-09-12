/**
  * @file     	basic.h
  * @author   	Huakun Huang
  * @email   	huanghuakun0902@163.com
  * @version	V1.0
  * @date    	11-SEP-2022
  * @license  	GNU General Public License (GPL)
  * @brief   	专门存储和解析当前文件的所有项目信息
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

#ifndef BASIC_H
#define BASIC_H

#define VERSION "9.0"

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonParseError>

class basic : public QObject
{
    Q_OBJECT
public:
    explicit basic(QObject *parent = nullptr);

public:
    void saveProject(QString path);
    void savePath(QString path);
    void readProject(QString path);

    QJsonObject pathAndVersion;
    //QJsonObject paraObj;
private:
    QJsonValue workPath;
    QJsonValue Version;
signals:

public slots:
};

#endif // BASIC_H
