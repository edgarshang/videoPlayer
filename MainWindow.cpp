#include "MainWindow.h"

#include <QApplication>

//#include <QDateTime>

//#include <QScreen>
//#include <QRect>
//#include <QGraphicsVideoItem>

#include <QtWidgets>
#include <QStringList>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QDebug>
#include "VideoFFmpeg.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_videoWidget = new QShowWidget(this);
    m_videoWidget->setStyleSheet("background-color:rgb(50,50,50);");

    QScreen *screen = QGuiApplication::primaryScreen();

    QRect srceenGeomery = screen->geometry();

    m_videoWidget->setMinimumSize(srceenGeomery.width()/3 ,srceenGeomery.height()/3);

    m_openButton = new QPushButton(tr("Open..."));
    m_playButton = new QPushButton();
//    m_playButton->setEnabled(true);
    m_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    m_positionSlider = new QSlider(Qt::Horizontal);
    m_positionSlider->setRange(0,0);

    m_durationLabel = new QLabel(this);
    QHBoxLayout *durationLayout = new QHBoxLayout;

    durationLayout->addWidget(m_openButton);
    durationLayout->addWidget(m_playButton);
    durationLayout->addWidget(m_positionSlider,1);
    durationLayout->addWidget(m_durationLabel);

    urlBox = new QComboBox(this);


    QStringList urls;
    urls << "http://vfx.mtime.cn/Video/2021/11/16/mp4/211116131456748178.mp4";
    urls << "http://vd3.bdstatic.com/mda-jennyc5ci1ugrxzi/mda-jennyc5ci1ugrxzi.mp4";
    urls << "rtsp://admin:Admin123456@192.168.0.15:554/media/video1";
    urlBox->addItems(urls);
    urlBox->setCurrentIndex(0);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_videoWidget,1);
    mainLayout->addLayout(durationLayout);
    mainLayout->addWidget(urlBox);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);

//    centralWidget->setStyleSheet("background-color:rgb(128,128,128);");

    setCentralWidget(centralWidget);

    createActions();
    connect(m_openButton, &QAbstractButton::clicked,
            this, &MainWindow::openFile);
    connect(m_playButton, &QAbstractButton::clicked,
            this, &MainWindow::play);

    m_player = new VideoFFmpeg(this);
}

void MainWindow::openFile()
{
    qDebug() << "test openFile";
}

void MainWindow::play()
{
    qDebug() << "test play";
}

void MainWindow::showImage(const QImage &imgs)
{
    Q_UNUSED(imgs)
}
void MainWindow::tellInfoVideo(S_VideoInfo &info)
{
    Q_UNUSED(info)
}

void MainWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/images/open.png"));
    QToolBar *fileToolBar = addToolBar(tr("File"));
    openAct = fileMenu->addAction(tr("&Open..."), this, &MainWindow::openFile);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setIcon(openIcon);
    fileToolBar->addAction(openAct);

    fileMenu->addSeparator();

//    QAction *closeAct = fileMenu->addAction(tr("&Close"), this, &QWidget::close);
//    const QIcon closeIcon = QIcon::fromTheme("document-close", QIcon(":/images/exit.png"));
//    closeAct->setShortcut(tr("Ctrl+Q"));
//    closeAct->setIcon(closeIcon);


//    QMenu *playMenu = menuBar()->addMenu(tr("&Play"));

//     QAction *stopAct = playMenu->addAction(tr("&Stop"), this, &VideoPlayUI::stop);
//     const QIcon stopIcon = QIcon::fromTheme("document-play", QIcon(":/images/stop.png"));
//     stopAct->setIcon(stopIcon);
//     fileToolBar->addAction(stopAct);

//     playMenu->addSeparator();

//     QAction *captureAct = playMenu->addAction(tr("&Capture"), this, &VideoPlayUI::caputure);
//     const QIcon captureIcon = QIcon::fromTheme("document-play", QIcon(":/images/camera.png"));
//     captureAct->setIcon(captureIcon);
//     fileToolBar->addAction(captureAct);

//     fileToolBar->addAction(closeAct);
}

MainWindow::~MainWindow()
{

}
