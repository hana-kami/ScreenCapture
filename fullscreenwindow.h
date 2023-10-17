#ifndef FULLSCREENWINDOW_H
#define FULLSCREENWINDOW_H

#include <QWidget>
#include <QPixmap>
#include <QRect>
#include <QPushButton>

class FullScreenWindow : public QWidget
{
    Q_OBJECT
public:
    FullScreenWindow(QPixmap screenshot);

protected:
    // 函数声明
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;


private:
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QPixmap screenshot;
    QRect selectionRect;
    QPoint startPos;
    QPoint endPos;
    QRect selectedRegion;
    QPixmap fullScreenScreenshot;
    void closeWindow();
    void confirmSelection();
    void cancelSelection();


signals:
    void screenshotSelected(const QPixmap& screenshot);
    void screenshotCancelled();
};

#endif // FULLSCREENWINDOW_H
