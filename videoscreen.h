#ifndef VIDEOSCREEN_H
#define VIDEOSCREEN_H

#include <QWidget>

extern "C" {
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
    #include "libswscale/swscale.h"
    #include "libavdevice/avdevice.h"

}

namespace Ui {
class videoScreen;
}

class videoScreen : public QWidget
{
    Q_OBJECT

public:
    explicit videoScreen(QWidget *parent = nullptr);
    ~videoScreen();
    AVCodecContext* configureVideoCodec(AVFormatContext* formatContext,int width, int height, int bitRate);
    void stopRecording();
    void startRecording(const char* outputFilePath, int width, int height, int bitRate);
    bool open(const QString& url);
    AVFrame* read();
    void showError(int err);
    bool swsFormat(AVFrame *frame);//将解码后的图像帧的像素格式转换为未编码图像帧的像素格式
    void close();
    void  sleepMsec(int msec);
    qreal rationalToDouble(AVRational* rational); // 将AVRational转换为double
private:
    Ui::videoScreen *ui;
    const AVInputFormat* m_inputFormat = nullptr;
    AVFormatContext* m_formatContext = nullptr;   // 解封装上下文
    AVFormatContext *formatContext; // 解封装上下文
    AVCodecContext *codecContext;   // 视频编码上下文
    AVCodecContext*  m_codecContext  = nullptr;   // 解码器上下文
    SwsContext *swsContext = nullptr;
    AVFrame *m_frame  = nullptr;                 // 解码后的视频帧
    AVFrame *capturedFrame = nullptr;
    AVPacket* m_packet = nullptr;                 // 数据包
    AVPacket  * encodedPacket  = nullptr;
    AVStream *videoStream;          // 视频流
    qreal  m_frameRate    = 0;                    // 视频帧率
    QSize  m_size;                                // 视频分辨率大小
    int    m_videoIndex   = 0;                    // 视频流索引
    char*  m_error = nullptr;                     // 保存异常信息
    const char* outputFilePath;//视频保存路径
    bool isRecording;// 标志位，录制开始结束标志位
    int frameCount;  // 在类的成员变量中初始化 frameCount
    qint64 m_totalTime    = 0;                    // 视频总时长

};

#endif // VIDEOSCREEN_H
