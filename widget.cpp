#include "widget.h"
#include "ui_widget.h"
#include "fullscreenwindow.h"
#include <QClipboard>
#include <QPainter>
#include <QScreen>
#include <QDesktopWidget>
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QTime>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget),screenshotCompleted(true)
{
    ui->setupUi(this);
    //移除最大化按钮并限制更改大小
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint); setFixedSize(this->width(), this->height());
    // 创建场景和图像项
    scene = new QGraphicsScene(this);
    recorder = new VideoRecorder();
    ui->graphicsView->setScene(scene);
//    // 按键
//    shortcut = new QShortcut(QKeySequence(Qt::ALT + Qt::Key_X), this);
//    connect(shortcut, &QShortcut::activated, this, &Widget::takeScreenshot);
    // 创建全局快捷键监听
    hotkey = new QHotkey(QKeySequence(Qt::ALT + Qt::Key_X), true, this);
    connect(hotkey, &QHotkey::activated, this, &Widget::takeScreenshot);
    
}

Widget::~Widget()
{
    // 释放资源
    delete ui;
    
}

void Widget::takeScreenshot()
{
    // 获取主屏幕和副屏的截图
    QScreen *primaryScreen = QGuiApplication::primaryScreen();
    QScreen *secondaryScreen = nullptr;

    QList<QScreen*> screens = QGuiApplication::screens();
    if (screens.size() > 1) {
        secondaryScreen = screens.at(1); // 假设第二个屏幕是副屏
    }

    QPixmap primaryScreenshot = primaryScreen->grabWindow(0);
    QPixmap secondaryScreenshot = secondaryScreen ? secondaryScreen->grabWindow(0) : QPixmap(); // 如果没有副屏，使用空的 QPixmap

    // 合并主屏幕和副屏的截图
    QPixmap combinedScreenshot(primaryScreenshot.width() + secondaryScreenshot.width(), std::max(primaryScreenshot.height(), secondaryScreenshot.height()));
    QPainter painter(&combinedScreenshot);
    painter.drawPixmap(0, 0, primaryScreenshot);
    painter.drawPixmap(primaryScreenshot.width(), 0, secondaryScreenshot);

    // 创建全屏窗口并传递合并后的截图
    FullScreenWindow *fullscreenWindow = new FullScreenWindow(combinedScreenshot);
    connect(fullscreenWindow, &FullScreenWindow::screenshotSelected, this, &Widget::handleScreenshotSelected);
    connect(fullscreenWindow, &FullScreenWindow::screenshotCancelled, this, &Widget::handleScreenshotCancelled);


}


void Widget::on_screenshotButton_clicked()
{
    if (screenshotCompleted) {
        screenshotCompleted = false; // 设置标志位为false，表示截图进行中
        hide(); // 隐藏主界面
        // 添加一个等待操作以确保主界面完全隐藏
        QTime dieTime = QTime::currentTime().addMSecs(100); // 100毫秒的等待时间
        while (QTime::currentTime() < dieTime)
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        takeScreenshot();
    }
}

void Widget::handleScreenshotSelected(const QPixmap& selectedScreenshot)
{
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem();
    // 处理截图完成后的操作
    screenshotCompleted = true; // 设置标志位为true，表示截图已完成
    //将屏幕截图复制到剪贴板
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setPixmap(selectedScreenshot);
    // 缩放截图适应窗体大小
    scaledScreenshot = selectedScreenshot.scaled(ui->graphicsView->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pixmapItem->setPixmap(scaledScreenshot);
    scene->clear();
    scene->addItem(pixmapItem);
    show(); // 显示主界面

}

void Widget::handleScreenshotCancelled()
{
    screenshotCompleted = true; // 设置标志位为true，表示截图已完成
    show(); // 显示主界面
}


void Widget::on_saveButton_clicked()
{
    if (screenshotCompleted) {
           screenshotCompleted = false; // 设置标志位为false，表示保存截图进行中

           if (!scaledScreenshot.isNull()) {
               // 打开文件对话框以获取保存路径和文件名
               QString filePath = QFileDialog::getSaveFileName(this, "保存截图", QDir::homePath(), "Images (*.png *.jpg *.bmp)");

               if (!filePath.isEmpty()) {
                   // 保存截图到指定路径
                   scaledScreenshot.save(filePath);
                   screenshotCompleted = true; // 设置标志位为true，表示保存截图已完成
                   QMessageBox::information(this, "保存成功", "截图已成功保存");
               }
           } else {
               // 如果截图为空，弹出警告
               screenshotCompleted = true; // 设置标志位为true，表示保存截图已完成
               QMessageBox::warning(this, "警告", "当前没有截图可保存");
           }
       }
}


void Widget::on_videoButton_clicked()
{
    if (!isRecording) {
            // 开始录制
            // 这里调用 videoScreen 的开始录制方法
        recorder->startRecording("luzhi.mp4",1920,1080,2000000);

        ui->videoButton->setText("Stop Recording");
        } else {
            // 停止录制
        recorder->stopRecording();
            //screenRecorder->stopRecording();
            ui->videoButton->setText("Record Video");
        }
        isRecording = !isRecording;
}

