#ifndef IINTERFACE_H
#define IINTERFACE_H

#include <QImage>
#include <QString>

typedef struct{
    int duration;
}S_VideoInfo;

class IVideoMessageNotify
{
public:
    virtual void showImage(const QImage &imgs) = 0;
    virtual void tellInfoVideo(S_VideoInfo &info) = 0;
    virtual ~IVideoMessageNotify() = default;
};

class IVideoHandle
{
public:
    virtual void player(QString &url) = 0;
    virtual ~IVideoHandle() = default;
};

#endif // IINTERFACE_H
