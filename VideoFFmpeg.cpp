#include "VideoFFmpeg.h"
#include <QDebug>
#include <QMessageBox>

VideoFFmpeg::VideoFFmpeg(QWidget *parent) : QWidget(parent)
{
    avformat_network_init();
    frame = av_frame_alloc();
    packet = av_packet_alloc();
    qDebug() << "VideoFFmpeg";
}

void VideoFFmpeg::player(QString &url)
{
    Q_UNUSED(url);
    QString l_url = url;
    if (l_url.isEmpty())
    {
        qDebug() << "the url is empty";
        return;
    }

    if (m_formatContext)
    {
        avformat_close_input(&m_formatContext);
        m_formatContext = nullptr;
    }

    avformat_open_input(&m_formatContext, l_url.toStdString().c_str(), nullptr, nullptr);
    avformat_find_stream_info(m_formatContext, nullptr);

    m_videoStreamIndex = -1;
    for (unsigned int i = 0; i < m_formatContext->nb_streams; i++)
    {
      if (m_formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
      {
          m_videoStreamIndex = static_cast<int>(i);
          break;
      }
    }

    m_fps = 1000 / static_cast<uint8_t>(av_q2d(m_formatContext->streams[m_videoStreamIndex]->r_frame_rate));
    m_frames = m_formatContext->streams[m_videoStreamIndex]->nb_frames;

    if (m_videoStreamIndex == -1) {
        QMessageBox::warning(this, "Error", "No video stream found.");
        return;
    }

    const AVCodec *codec = avcodec_find_decoder(m_formatContext->streams[m_videoStreamIndex]->codecpar->codec_id);

    if (m_codecContext)
    {
        avcodec_free_context(&m_codecContext);
        m_codecContext = nullptr;
    }

    m_codecContext = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(m_codecContext, m_formatContext->streams[m_videoStreamIndex]->codecpar);
    avcodec_open2(m_codecContext, codec, nullptr);

    if (m_swsContext)
    {
        sws_freeContext(m_swsContext);
        m_swsContext = nullptr;
    }

   m_swsContext = sws_getContext(m_codecContext->width, m_codecContext->height, m_codecContext->pix_fmt,
                               m_codecContext->width, m_codecContext->height, AV_PIX_FMT_RGB24,
                               SWS_BILINEAR, nullptr, nullptr, nullptr);
}

VideoFFmpeg::~VideoFFmpeg()
{
    qDebug() << "~VideoFFmpeg";
    if(frame != nullptr)
    {
        av_frame_free(&frame);
    }

    if(packet != nullptr)
    {
        av_packet_free(&packet);
    }

    if (m_codecContext)
    {
        avcodec_free_context(&m_codecContext);
        m_codecContext = nullptr;
    }

    if (m_swsContext)
    {
        sws_freeContext(m_swsContext);
        m_swsContext = nullptr;
    }
}
