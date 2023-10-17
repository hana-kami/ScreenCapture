#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QShortcut>
#include <QHotkey>
#include "videoscreen.h"
#include "videorecorder.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    //void paintEvent(QPaintEvent *event) override;
//    void mousePressEvent(QMouseEvent *event) override;
//    void mouseMoveEvent(QMouseEvent *event) override;
//    void mouseReleaseEvent(QMouseEvent *event) override;
private slots:
    void on_screenshotButton_clicked();

    void on_saveButton_clicked();

    void on_videoButton_clicked();

private:
    Ui::Widget *ui;
    QPoint startPos;
    QPoint endPos;
    QGraphicsScene *scene;
    QShortcut *shortcut;
    QHotkey* hotkey;
    VideoRecorder* recorder;
    QPixmap scaledScreenshot;
    bool screenshotCompleted; // 标志位，表示截图是否已完成
    bool isRecording;// 标志位，录制开始结束标志位
    void handleScreenshotSelected(const QPixmap& selectedScreenshot);
    void handleScreenshotCancelled();
    void takeScreenshot();
};
#endif // WIDGET_H
