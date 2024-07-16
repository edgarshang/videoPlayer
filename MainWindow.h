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
#include "QShowWidget.h"

class MainWindow : public QMainWindow
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

private:
     qint64 duration;
};

#endif // MAINWINDOW_H
