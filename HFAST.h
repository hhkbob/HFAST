/**
  * @file     	HFAST.h
  * @author   	Huakun Huang
  * @email   	huanghuakun0902@163.com
  * @version	V1.0
  * @date    	09-SEP-2022
  * @license  	GNU General Public License (GPL)
  * @brief   	主界面
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
#ifndef HFAST_H
#define HFAST_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QGridLayout>
#include "generalPanel.h"
#include "modelPage.h"
#include <QDockWidget>
#include <QStackedLayout>
#include <QSplitter>
#include "fileToolBar.h"

namespace Ui {
class HFAST;
}

class HFAST : public QMainWindow
{
    Q_OBJECT

public:
    explicit HFAST(QWidget *parent = 0);
    ~HFAST();
    error HFASTError;
    printTool *pEvent;
    fileToolBar *fileBar;

    /**
    * @brief 初始化界面
    */
    void initApp();

private:
    Ui::HFAST *ui;
    QMenu *File;
    QMenu *Tool;

    QGridLayout *gridLayout; //  网格布局
    QVBoxLayout *vLayout; //  水平布局--整体的
    QHBoxLayout *hLayout;  //  放置按钮
    QHBoxLayout *viewLayout; //  放置文本和视图窗口
    QStackedLayout *stackLayout; //  放置不同页面
    QVBoxLayout *viewGroupLayout;

    QWidget *wholeWidget;
    generalPanel *gPanel;
    modelPage *mPanel;
    QWidget *gPanelPage;
    QWidget *mPanelPage;

    QTextBrowser *textEdit; //  文本编辑控件
    QTextBrowser *mesView;  //  命令查看窗口
    QDockWidget  *view;  //  核心展示窗口
    QSplitter *Splitter1;
    QSplitter *Splitter2;

    QPushButton *runButton; //  运行按钮
    QPushButton *checkButton; //  检查网格质量按钮
    QPushButton *generalButton; //  常规按钮
    QPushButton *modelButton;  //  模型按钮
    QPushButton *materialButton;  //  材料按钮
    QGroupBox *viewGroup;

    /**
     * @brief 添加界面按钮
     */
    void addLayout();

private slots:
    void setGeneralPanel();
    void setModelPanel();
};

#endif // HFAST_H
