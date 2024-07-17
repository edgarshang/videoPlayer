#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QMediaPlayer>
//#include <QVideoWidget>
#include <QPushButton>
#include <QSlider>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include "IInterface.h"
#include "QShowWidget.h"

class MainWindow : public QMainWindow, public IVideoMessageNotify
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QAction *openAct;
    QAction *playAct;

private:
    QAbstractButton *m_openButton;
    QPushButton *m_pauseButton;
    QPushButton *m_stopButton;
    QSlider *m_positionSlider;
    QLabel *m_durationLabel;
    QAbstractButton *m_playButton;
    QShowWidget *m_videoWidget;
    QComboBox *urlBox;

private slots:
    void openFile();
    void play();
private:
    void createActions();

private:
     qint64 duration;
     IVideoHandle *m_player;

public:
     virtual void showImage(const QImage &imgs);
     virtual void tellInfoVideo(S_VideoInfo &info);
};

#endif // MAINWINDOW_H
