#include "EngineReloaderWrapper.h"
#include <QQmlContext>
#include <QGuiApplication>
#include <QDir>
#include "Settings.h"

static QObject *settings_qobject_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Settings *example = new Settings();

    return example;
}

EngineReloaderWrapper::EngineReloaderWrapper()
{

}

EngineReloaderWrapper::~EngineReloaderWrapper()
{

}

void EngineReloaderWrapper::setContextProperies(QQmlContext * pQmlContext)
{
    //Engine
    pQmlContext->setContextProperty("engine", this);
    //Engine.path
    pQmlContext->setContextProperty("ApplicationDirPath", QGuiApplication::applicationDirPath());
    pQmlContext->setContextProperty("ApplicationFilePath", QGuiApplication::applicationFilePath());
    pQmlContext->setContextProperty("QDircurrentpath", QDir::currentPath());
    pQmlContext->setContextProperty("QDirRootPath", QDir::rootPath());
    pQmlContext->setContextProperty("QDirHomePath", QDir::homePath());
}

void EngineReloaderWrapper::registerToQml()
{
    qDebug() << "EngineReloaderWrapper::registerToQml()";
    qmlRegisterSingletonType<Settings>("com.bizerba.Settings", 1, 0, "Settings", settings_qobject_singletontype_provider);
}
