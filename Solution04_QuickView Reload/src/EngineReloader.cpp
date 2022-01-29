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
    m_view->deleteLater();
    connect(m_view, SIGNAL(destroyed()), this, SLOT(reload()));
}

void EngineReloader::reload()
{
    qmlClearTypeRegistrations();

    QQuickStyle::setStyle(m_style);
#if 1
    m_view = new QQuickView;
    m_instance = m_view->engine();
    setContextProperies( m_view->rootContext() );
#else
    m_instance = new QQmlApplicationEngine(this);
    setContextProperies(m_instance->rootContext());
#endif

    registerToQml();
#if 1
    m_view->setSource(m_source);
    m_view->show();
#else
    m_instance->load(m_source);
#endif
}

void EngineReloader::setContextProperies(QQmlContext * pQmlContext)
{
    pQmlContext->setContextProperty("engine", this);
}

void EngineReloader::registerToQml()
{
    qDebug() << "EngineReloader::registerToQml()";
}
