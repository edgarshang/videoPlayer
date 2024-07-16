#ifndef VIDEOFFMPEG_H
#define VIDEOFFMPEG_H

#include <QWidget>

#include <QString>

extern "C" {
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavcodec/avcodec.h>
}

class VideoFFmpeg : public QWidget
{
    Q_OBJECT
public:
    explicit VideoFFmpeg(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // VIDEOFFMPEG_H
