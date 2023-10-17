#include "videorecorder.h"

VideoRecorder::VideoRecorder(QObject* parent)
    : QObject(parent)
{
    screenRecorder = new videoScreen();
}

VideoRecorder::~VideoRecorder()
{
    stopRecording();
    delete screenRecorder;
}

void VideoRecorder::startRecording(const char *outputFilePath, int width, int height, int bitRate)
{
    stopRecording(); // 停止之前的录制（如果有）
    recordingThread = std::thread(&VideoRecorder::recordingThreadFunc, this, outputFilePath, width, height, bitRate);
}

void VideoRecorder::stopRecording()
{
    stopRecordingFlag = true;
    screenRecorder->stopRecording();
    if (recordingThread.joinable()) {
        recordingThread.join();
    }
}

void VideoRecorder::recordingThreadFunc(const char *outputFilePath, int width, int height, int bitRate)
{
    screenRecorder->startRecording(outputFilePath, width, height, bitRate);
}


