#include <QObject>

/*
 * Point : this class with Q_PROPERTY cannot defined in main.cpp
 */
class SingletonTypeExample : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int someProperty READ someProperty WRITE setSomeProperty NOTIFY somePropertyChanged)

public:
	SingletonTypeExample(QObject* parent = 0)
		: QObject(parent), m_someProperty(0)
	{
	}

	~SingletonTypeExample() {}

	Q_INVOKABLE int doSomething() { setSomeProperty(6); return m_someProperty; }

	int someProperty() const { return m_someProperty; }
	void setSomeProperty(int val) { m_someProperty = val; emit somePropertyChanged(val); }

signals:
	void somePropertyChanged(int newValue);

private:
	int m_someProperty;
};