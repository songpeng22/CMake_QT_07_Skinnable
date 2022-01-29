#include "EngineReloader.h"
#include <QQuickStyle>
#include <QQmlContext>

EngineReloader::EngineReloader(QObject *parent) : QObject(parent), m_instance(0)
{

}

void EngineReloader::load(QUrl &source)
{
    m_source = source;
    reload();
}

void EngineReloader::reloadStyle(const QString &style)
{
    m_style = style;
    // This method is called from QML, so we cannot just immediately delete the QML engine in here,
    // because the execution would return to an engine that was destroyed. Just like in C++ you cannot
    // delete the sender of a signal.
    m_instance->deleteLater();
    connect(m_instance, SIGNAL(destroyed()), this, SLOT(reload()));
}

void EngineReloader::reload()
{
    qmlClearTypeRegistrations();

    QQuickStyle::setStyle(m_style);
    m_instance = new QQmlApplicationEngine(this);
    setContextProperies(m_instance->rootContext());
    registerToQml();
    m_instance->load(m_source);
}

void EngineReloader::setContextProperies(QQmlContext * pQmlContext)
{
    pQmlContext->setContextProperty("engine", this);
}

void EngineReloader::registerToQml()
{
    qDebug() << "EngineReloader::registerToQml()";
}
