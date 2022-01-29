#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <QCoreApplication>
#include <QSettings>

class Settings : public QSettings
{
    Q_OBJECT
public:
#if 1
	explicit Settings(QString filename = "settings.ini", QObject *parent = 0) : QSettings( filename,
		QSettings::IniFormat,
		parent)
	{

	}
#else
    explicit Settings(QObject *parent = 0) : QSettings(QSettings::IniFormat,
    QSettings::UserScope,
    QCoreApplication::instance()->organizationName(),
    QCoreApplication::instance()->applicationName(),
    parent) 
    {

    }
#endif
public:
    Q_INVOKABLE inline void setValue(const QString &key, const QVariant &value) { 
        QSettings::setValue(key, value); 
    }
    Q_INVOKABLE inline QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const { 
        return QSettings::value(key, defaultValue); 
    }
};

Q_DECLARE_METATYPE(Settings*)

#endif//_SETTINGS_H_