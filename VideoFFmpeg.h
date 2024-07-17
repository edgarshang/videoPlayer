#ifndef VIDEOFFMPEG_H
#define VIDEOFFMPEG_H

#include <QWidget>

#include <QString>
#include "IInterface.h"

extern "C" {
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavcodec/avcodec.h>
}

class VideoFFmpeg : public QWidget, public IVideoHandle
{
    Q_OBJECT
public:
    explicit VideoFFmpeg(QWidget *parent = nullptr);
    void player(QString &url);
    ~VideoFFmpeg();
signals:

public slots:

private:

    AVFormatContext *m_formatContext = nullptr;
    AVCodecContext *m_codecContext = nullptr;
    SwsContext *m_swsContext = nullptr;
    AVFrame *frame = nullptr;
    AVPacket *packet = nullptr;
    int m_videoStreamIndex = -1;
    int m_fps = 0;
    int64_t m_frames = 0;
};

#endif // VIDEOFFMPEG_H
