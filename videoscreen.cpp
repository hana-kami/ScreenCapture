#include "videoscreen.h"
#include "ui_videoscreen.h"
#include <QDebug>
#include <QTimer>
videoScreen::videoScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::videoScreen),
    formatContext(nullptr),
    codecContext(nullptr),
    videoStream(nullptr),
    outputFilePath(""),
    isRecording(false),
    frameCount(0)
{
    ui->setupUi(this);

    // 初始化 FFmpeg
    av_register_all();
    avformat_network_init();
    avdevice_register_all();  // 注册设备
    //outputFilePath = ""; // 初始化输出文件路径为空

}

videoScreen::~videoScreen()
{
    // 停止录制
    if (isRecording) {
        stopRecording();
    }

    delete ui;

}

//AVCodecContext *videoScreen::configureVideoCodec(AVFormatContext* formatContext,int width, int height, int bitRate)
//{
//    AVCodecContext* codecContext = nullptr;
//    // 选择视频编码器
//    const AVCodec* codec = avcodec_find_encoder(AV_CODEC_ID_H264);
//    if (!codec) {
//            qDebug() << "找不到H.264编码器";
//            return nullptr;
//    }
//    codecContext = avcodec_alloc_context3(codec);
//    if (!codecContext) {
//            qDebug() << "无法分配编码器上下文";
//            return nullptr;
//    }
//    // 配置视频参数
//    codecContext->width = width;
//    codecContext->height = height;
//    codecContext->codec_type =  AVMEDIA_TYPE_VIDEO;
//    codecContext->pix_fmt = AV_PIX_FMT_YUV420P;  // 像素格式，通常使用YUV420P
//    codecContext->time_base = (AVRational){1, 30}; // 30 FPS、
//    codecContext->framerate = (AVRational){30, 1};  // 帧率
//    codecContext->bit_rate = bitRate;//码率
//    codecContext->gop_size = 12;  // I帧间隔
//    codecContext->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;

//    // 打开编码器
//    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
//        qDebug() << "无法打开编码器";
//        avcodec_free_context(&codecContext);
//        return nullptr;
//    }
//    return codecContext;
//}
void videoScreen::startRecording(const char* outputFilePath, int width, int height, int bitRate)
{
    frameCount = 0;
    if (isRecording) {
        qDebug() << "已经在录制中";
        return;
    }

    // 设置输出文件路径
    this->outputFilePath = outputFilePath;
    // 打开输出文件和设置格式
    avformat_alloc_output_context2(&formatContext, nullptr, nullptr, outputFilePath);
    if (!formatContext) {
        qDebug() << "输出文件为空";
        return;
    }

    // 打开输出文件
    if (avio_open(&formatContext->pb, outputFilePath, AVIO_FLAG_WRITE) < 0) {
        qDebug() << "打开输出文件失败";
        return;
    }

    // 设置输出文件的格式
    formatContext->oformat = av_guess_format(nullptr, outputFilePath, nullptr);
    qDebug() << formatContext->oformat->name;
    if (!formatContext->oformat) {
        qDebug() << "设置格式失败";
        return;
    }

    // 添加视频流到输出文件
    videoStream = avformat_new_stream(formatContext, nullptr);
    if (!videoStream) {
        qDebug() << "添加视频流到输出文件失败";
        return;
    }
    // 设置视频编码参数
    //codecContext = configureVideoCodec(formatContext,width, height, bitRate);
    const AVCodec* codec = avcodec_find_encoder(AV_CODEC_ID_H264);
    if (!codec) {
        qDebug() << "找不到H.264编码器";

    }
    codecContext = avcodec_alloc_context3(codec);
    if (!codecContext) {
        qDebug() << "无法分配编码器上下文";

    }
    // 配置视频参数
    codecContext->width = width;
    codecContext->height = height;
    codecContext->codec_type =  AVMEDIA_TYPE_VIDEO;
    codecContext->pix_fmt = AV_PIX_FMT_YUV420P;  // 像素格式，通常使用YUV420P
    codecContext->time_base = (AVRational){1, 30}; // 30 FPS、
    codecContext->framerate = (AVRational){30, 1};  // 帧率
    codecContext->bit_rate = bitRate;//码率
    codecContext->gop_size = 12;  // I帧间隔
    codecContext->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;

    // 打开编码器
    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
        qDebug() << "无法打开编码器";
    }
    videoStream->time_base = codecContext->time_base;

    //拷贝一些参数，给codecpar赋值
    if(avcodec_parameters_from_context(videoStream->codecpar,codecContext) < 0)
    {
        qDebug() << "拷贝参数失败";
        return;
    }
    // 写文件头
    int ret = avformat_write_header(formatContext, nullptr);
    if (ret < 0) {
        char errbuf[AV_ERROR_MAX_STRING_SIZE];
        av_strerror(ret, errbuf, sizeof(errbuf));
        qDebug() << "写文件头失败: " << ret <<errbuf;
        return;
    }

    // 更新录制状态
    isRecording = true;
    // 开始录制屏幕
    if (!open("desktop")) {
        qDebug() << "无法开始屏幕录制";
        stopRecording();  // 停止录制
    }
    // 处理录制和编码的逻辑
    // 查询编码器
    capturedFrame = av_frame_alloc();
    if(!capturedFrame)
    {
        close();
        showError(AVERROR(ENOMEM));
    }
    capturedFrame->format = codec->pix_fmts[0];
    while (isRecording) {
        // 从屏幕捕获获取帧
        capturedFrame = read();
        if(!swsFormat(capturedFrame))              // 由于解码的图像格式和编码需要的图像格式不一定相同，所以需要转换一下格式
        {
            qDebug() << "失败";
            return;
        }
        if (capturedFrame) {
            // 发送捕获到的帧给编码器
            capturedFrame->pts = frameCount;
            //qDebug() << "capturedFrame->pts"<< capturedFrame->pts;
            frameCount++;
            //qDebug() << "frameCount"<< frameCount;
            int ret = avcodec_send_frame(codecContext, capturedFrame);
            if (ret < 0) {
                qDebug() << "发送帧给编码器失败" << ret;
                break;
            }
            // 从编码器接收编码后的帧
            encodedPacket = av_packet_alloc();
            av_init_packet(encodedPacket);

            ret = avcodec_receive_packet(codecContext, encodedPacket);
            if (ret == 0) {
                // 将编码后的帧写入输出文件
                // 将数据包中的有效时间字段（时间戳/持续时间）从一个时基转换为 输出流的时间
                av_packet_rescale_ts(encodedPacket, codecContext->time_base, videoStream->time_base);
                av_write_frame(formatContext, encodedPacket);
                av_packet_unref(encodedPacket);
            }
        }else {
            // 未成功读取到帧

            sleepMsec(1);

            qDebug() << "未成功读取到帧";

        }
    }
}
bool videoScreen::open(const QString &url)
{
    // 打开GDI设备m_packet
    const AVInputFormat* inputFormat = av_find_input_format("gdigrab");
    if (!inputFormat) {
        showError(-1);  // 找不到输入格式
        return false;
    }

    m_inputFormat = inputFormat;
    AVDictionary* options = nullptr;
    av_dict_set(&options, "framerate", "20", 0);  // 设置帧率
    av_dict_set(&options, "pixel_format", "yuv420p", 0);  // 设置像素格式
    av_dict_set(&options, "draw_mouse", "1", 0);          // 指定是否绘制鼠标指针。0：不包含鼠标，1：包含鼠标
    av_dict_set(&options, "video_size", "1920x1080", 0);  // 设置捕获分辨率

    int ret = avformat_open_input(&m_formatContext, url.toStdString().data(), const_cast<AVInputFormat*>(m_inputFormat), &options);
    av_dict_free(&options);

    if (ret < 0) {
        showError(ret);
        return false;
    }

    // 找到视频流信息
    ret = avformat_find_stream_info(m_formatContext, nullptr);
    if (ret < 0) {
        showError(ret);
        return false;
    }

    // 找到视频流索引
    m_videoIndex = -1;
    for (unsigned int i = 0; i < m_formatContext->nb_streams; i++) {
        if (m_formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            m_videoIndex = i;
            break;
        }
    }

    if (m_videoIndex == -1) {
        showError(-2);  // 找不到视频流
        return false;
    }

    // 获取视频信息
    m_size.setWidth(m_formatContext->streams[m_videoIndex]->codecpar->width);
    m_size.setHeight(m_formatContext->streams[m_videoIndex]->codecpar->height);
    m_frameRate = rationalToDouble(&m_formatContext->streams[m_videoIndex]->r_frame_rate);

    // 创建解码上下文
    m_codecContext = avcodec_alloc_context3(nullptr);
    avcodec_parameters_to_context(m_codecContext, m_formatContext->streams[m_videoIndex]->codecpar);

    // 打开解码器
    ret = avcodec_open2(m_codecContext, avcodec_find_decoder(m_codecContext->codec_id), nullptr);
    if (ret < 0) {
        showError(ret);
        return false;
    }

    // 初始化帧和数据包
    m_packet = av_packet_alloc();
    m_frame = av_frame_alloc();

    return true;

}

AVFrame *videoScreen::read()
{
    if (!m_formatContext || !m_codecContext || !m_packet || !m_frame) {
        return nullptr;
    }

    int readRet = av_read_frame(m_formatContext, m_packet);
    if (readRet < 0)
    {
        avcodec_send_packet(m_codecContext, m_packet); // 向解码器发送空数据包，确保读取出最后几帧
    }
    else
    {
        if (m_packet->stream_index == m_videoIndex) // 如果数据包属于视频流
        {
            int ret = avcodec_send_packet(m_codecContext, m_packet); // 将数据包传入解码器
            if (ret < 0)
            {
                showError(ret); // 处理解码错误
            }
        }
    }

    av_packet_unref(m_packet); // 释放数据包的引用，引用计数-1，为0时释放内存

    av_frame_unref(m_frame); // 释放帧的引用
    int ret = avcodec_receive_frame(m_codecContext, m_frame);
    if (ret < 0)
    {
        av_frame_unref(m_frame); // 释放帧的引用
        if (readRet < 0)
        {
            isRecording = false;//当无法读取到数据包并且解码器中也没有数据时表示读取完成
        }
        return nullptr; // 返回空指针
    }

    return m_frame; // 返回解码后的帧
}

void videoScreen::showError(int err)
{
    // 处理错误信息
    char errbuf[AV_ERROR_MAX_STRING_SIZE];
    av_strerror(err, errbuf, sizeof(errbuf));
    m_error = strdup(errbuf);
    qDebug() << m_error;
}

bool videoScreen::swsFormat(AVFrame *frame)
{
    //qDebug() << "1";
    if (!frame || frame->width <= 0 || frame->height <= 0) {

        qDebug() << "2" ;
        return false;

    }

    AVFrame *outputFrame = av_frame_alloc();
    if (!outputFrame) {
        qDebug() << "3";
        return false;
    }

    // 初始化输出帧的像素格式（在这里，你可以指定目标像素格式）
    outputFrame->format = AV_PIX_FMT_YUV420P;
    outputFrame->width = frame->width;
    outputFrame->height = frame->height;

    if (av_frame_get_buffer(outputFrame, 3*8) < 0) {
        av_frame_free(&outputFrame);
        qDebug() << "4";
        return false;
    }

    SwsContext *swsContext = sws_getContext(frame->width, frame->height, (AVPixelFormat)frame->format,
                                            frame->width, frame->height, AV_PIX_FMT_YUV420P,
                                            SWS_BILINEAR, nullptr, nullptr, nullptr);
    if (!swsContext) {
        av_frame_free(&outputFrame);
        qDebug() << "5";
        return false;
    }

    if (sws_scale(swsContext, frame->data, frame->linesize, 0, frame->height,
                  outputFrame->data, outputFrame->linesize) <= 0) {
        av_frame_free(&outputFrame);
        sws_freeContext(swsContext);
        qDebug() << "6";
        return false;
    }

    sws_freeContext(swsContext);

    // 释放输入帧，将输出帧数据拷贝回原始帧
    av_frame_unref(frame);
    av_frame_move_ref(frame, outputFrame);
    av_frame_free(&outputFrame);

    return true;
}

void videoScreen::close()
{
    if (m_formatContext) {
        avformat_close_input(&m_formatContext);
    }

    if (m_codecContext) {
        avcodec_free_context(&m_codecContext);
    }

    if (m_packet) {
        av_packet_free(&m_packet);
    }

    if (m_frame) {
        av_frame_free(&m_frame);
    }

    m_formatContext = nullptr;
    m_codecContext = nullptr;
    m_packet = nullptr;
    m_frame = nullptr;
}

void videoScreen::sleepMsec(int msec)
{
    if(msec <= 0) return;
    QEventLoop loop;		//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();			//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}

qreal videoScreen::rationalToDouble(AVRational *rational)
{
    return static_cast<qreal>(rational->num) / static_cast<qreal>(rational->den);
}
void videoScreen::stopRecording() //停止录制
{
    if (!isRecording) {
        qDebug() << "未在录制中，无需停止";
        return;
    }

    // 停止录制并释放资源
    av_write_trailer(formatContext);
    avio_close(formatContext->pb);

    // 释放视频流
    avformat_free_context(formatContext);

    // 释放编码器上下文
    avcodec_free_context(&codecContext);

    // 更新录制状态
    isRecording = false;

    // 重置输出文件路径
    outputFilePath = "";

}


