#include "MainWindow.h"

//#include <QMenu>
//#include <QMenuBar>
#include <QApplication>
//#include <QStatusBar>
//#include <QDateTime>
//#include <QToolBar>
//#include <QScreen>
//#include <QRect>
//#include <QGraphicsVideoItem>

#include <QtWidgets>

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
    m_playButton->setEnabled(false);
    m_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    m_positionSlider = new QSlider(Qt::Horizontal);
    m_positionSlider->setRange(0,0);

    m_durationLabel = new QLabel(this);
    QHBoxLayout *durationLayout = new QHBoxLayout;

    durationLayout->addWidget(m_openButton);
    durationLayout->addWidget(m_playButton);
    durationLayout->addWidget(m_positionSlider,1);
    durationLayout->addWidget(m_durationLabel);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_videoWidget,1);
    mainLayout->addLayout(durationLayout);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);

//    centralWidget->setStyleSheet("background-color:rgb(128,128,128);");

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{

}
