#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <QCoreApplication>
#include <QSettings>
#include <QFile>
#include <QDebug>

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0)
    {
        settings = new QSettings( parent );
    }
    explicit Settings(QString filename, QObject *parent = 0)
    {
        settings = new QSettings( filename,
                                  QSettings::IniFormat,
                                  parent);
    }
    ~Settings()
    {
        if( nullptr != settings ){
            delete settings;
            settings = nullptr;
        }
    }
public:
    Q_INVOKABLE inline void setValue(const QString &key, const QVariant &value) {
        if( settings )
            settings->setValue(key, value);
    }
    Q_INVOKABLE inline QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const {
        if( settings )
            return settings->value(key, defaultValue);
        else
            return QVariant(QStringLiteral("null"));
    }
    Q_INVOKABLE inline void setFileName(const QString &fileName)
    {
        QFile file( fileName );
        if( !file.exists() ){
            qDebug() << "Settings::file do not exist";
            return;
        }
        if(nullptr != settings){
            delete settings;
            settings = new QSettings( fileName,QSettings::IniFormat,Q_NULLPTR );
        }

    }
    Q_INVOKABLE inline QString fileName() const {
        if( settings )
            return settings->fileName();
        else
            return QString(QStringLiteral("null"));
    }
public:
    QSettings * settings;
    static int typeId;
};

Q_DECLARE_METATYPE(Settings*)

#endif//_SETTINGS_H_
