#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QObject>
#include <QSystemTrayIcon>

class QMenu;
class QAction;

class SysTray : public QObject
{
    Q_OBJECT
public:
    explicit SysTray(QObject *parent = nullptr);
    QMenu *mMenu;
    QAction *mActionShow;
    QAction *mActionHide;
    QSystemTrayIcon *mSystemTray;

signals:

public slots:
    void activeTray(QSystemTrayIcon::ActivationReason reason);
    void showMenu();
    void showWindow();
    void showMessage();
};

#endif // SYSTRAY_H
