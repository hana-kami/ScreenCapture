#include "fullscreenwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QScreen>


FullScreenWindow::FullScreenWindow(QPixmap screenshot) : screenshot(screenshot)
{
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    setCursor(QCursor(Qt::CrossCursor));
    // 设置窗口位置和大小以适应图像大小
    setGeometry(0, 0, screenshot.width(), screenshot.height());

    // 在构造函数中创建按钮并设置属性
    confirmButton = new QPushButton("确定", this);
    confirmButton->setMinimumSize(80, 30);
    confirmButton->setMaximumSize(80, 30);
    confirmButton->hide();
    cancelButton = new QPushButton("取消", this);
    cancelButton->setMinimumSize(80, 30);
    cancelButton->setMaximumSize(80, 30);
    cancelButton->hide();
    connect(confirmButton, &QPushButton::clicked, this, &FullScreenWindow::confirmSelection);
    connect(cancelButton, &QPushButton::clicked, this, &FullScreenWindow::cancelSelection);
    show();
}

void FullScreenWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, screenshot);
    painter.setPen(QPen(Qt::red, 1, Qt::DashLine));

    QRect selectionRect(startPos, endPos);
    painter.drawRect(selectionRect);
}



void FullScreenWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        startPos = event->pos();
        //selectingScreenshot = true;
    }
}

void FullScreenWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        endPos = event->pos();
        update();
    }
}

void FullScreenWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        selectedRegion = QRect(startPos, endPos);
        // 处理用户选择的区域
        // 在用户选择区域的正下方放置按钮
        int buttonX = selectedRegion.center().x() - confirmButton->width() / 2;
        int buttonY = selectedRegion.bottom() + 10; // 10 是按钮与选择区域的间距

        // 设置按钮的位置
        confirmButton->move(buttonX, buttonY);
        cancelButton->move(buttonX + confirmButton->width() + 10, buttonY);
        // 显示按钮
        confirmButton->show();
        cancelButton->show();
//        // 创建布局管理器，并将按钮放置在适当的位置
//        QVBoxLayout *layout = new QVBoxLayout(this);
//        layout->addWidget(confirmButton);
//        layout->addWidget(cancelButton);
//        // 设置布局的边框和背景颜色

//        // 设置布局的位置
//        int layoutTop = selectionRect.bottom() + 10;  // 10 是布局距离矩形框底部的垂直偏移量
//        //layout->setGeometry(QRect(10, layoutTop, layout->sizeHint().width(), layout->sizeHint().height()));
        //setLayout(layout);
    }
}

void FullScreenWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
            // 如果用户按下 ESC 键，关闭窗口
            close();
            emit screenshotCancelled();
        }
}
void FullScreenWindow::confirmSelection()
{
    if (!selectedRegion.isEmpty())
    {
        // 裁剪整个屏幕截图为所选区域
        QPixmap croppedScreenshot = screenshot.copy(selectedRegion);
        // 发送裁剪后的截图给主页面
        emit screenshotSelected(croppedScreenshot);

        // 关闭窗口
        close();
    }
}

void FullScreenWindow::cancelSelection()
{
    emit screenshotCancelled();
    // 关闭窗口
    close();
}
