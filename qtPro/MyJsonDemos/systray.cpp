#include "systray.h"
#include <QMenu>
#include <QAction>
#include <QDebug>

SysTray::SysTray(QObject *parent) : QObject(parent)
{
    mSystemTray = new QSystemTrayIcon;
    mMenu = new QMenu;
    mActionHide = new QAction;
    mActionShow = new QAction;

    mActionHide->setText("ShowWindow");
    mActionShow->setText("ShowMessage");

    mMenu->addAction(mActionHide);
    mMenu->addAction(mActionShow);

    connect(mActionHide, &QAction::triggered, this, &SysTray::showWindow);
    connect(mActionShow, &QAction::triggered, this, &SysTray::showMessage);

    mSystemTray->setContextMenu(mMenu);
    mSystemTray->setIcon(QIcon(":/app/config/setting.ico"));
    mSystemTray->setToolTip("SystemTray Program");
    mSystemTray->show();
    connect(mSystemTray, &QSystemTrayIcon::activated, this, &SysTray::activeTray);
    connect(mSystemTray, &QSystemTrayIcon::messageClicked, this, &SysTray::showWindow);

}

void SysTray::activeTray(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Context:
        showMenu();
        break;
    case QSystemTrayIcon::DoubleClick:
        showWindow();
        break;
    case QSystemTrayIcon::Trigger:
        showMessage();
        break;
    }
}

void SysTray::showMenu()
{
    mMenu->show();
}

void SysTray::showWindow()
{
    mMenu->show();
}

void SysTray::showMessage()
{
    qDebug()<<"ttttttttttttt";
    mSystemTray->showMessage("Information",//消息窗口标题
        "There is a new message!",//消息内容
        QSystemTrayIcon::MessageIcon::Information,//消息窗口图标
        2000);//消息窗口显示时长
}
