#ifndef _ENGINE_RELOADER_H__
#define _ENGINE_RELOADER_H__

//Common
#include <QObject>
#include <QDebug>
#include <QString>
#include <QUrl>
//Engine
#include <QQmlApplicationEngine>
#include <QQmlContext>
//Style
#include <QQuickStyle>

class EngineReloader : public QObject
{
    Q_OBJECT

public:
    EngineReloader(QObject *parent = 0);

    void load(QUrl &source);
private:
    virtual void setContextProperies( QQmlContext * pQmlContext );
    virtual void registerToQml();
public slots:
    void reloadStyle(const QString &style);

private slots:
    void reload();

private:
    QUrl m_source;
    QString m_style;
    QQmlApplicationEngine *m_instance;
};


#endif//_ENGINE_RELOADER_H__
