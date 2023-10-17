#ifndef VIDEORECORDER_H
#define VIDEORECORDER_H
#include <QObject>
#include <thread>
#include <mutex>
#include "videoscreen.h"
class VideoRecorder : public QObject
{
    Q_OBJECT
public:
    VideoRecorder(QObject* parent = nullptr);
    ~VideoRecorder();
public:
    void startRecording(const char* outputFilePath, int width, int height, int bitRate);
    void stopRecording();

signals:
    void errorOccurred(const QString& errorMessage);

private:
    std::thread recordingThread;
    std::mutex recordingMutex;
    videoScreen* screenRecorder;
    bool stopRecordingFlag = false;

    void recordingThreadFunc(const char* outputFilePath, int width, int height, int bitRate);
};

#endif // VIDEORECORDER_H
