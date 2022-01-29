#ifndef _QUICKVIEW_RELOADER_H__
#define _QUICKVIEW_RELOADER_H__

//Common
#include <QObject>
#include <QDebug>
#include <QString>
#include <QUrl>
//View
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
//Style
#include <QQuickStyle>

class QuickViewReloader : public QObject
{
    Q_OBJECT

public:
    QuickViewReloader(QObject *parent = 0);

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
    QQuickView * m_view;
};


#endif//_QUICKVIEW_RELOADER_H__
