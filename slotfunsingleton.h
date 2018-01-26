#ifndef SLOTFUNSINGLETON_H
#define SLOTFUNSINGLETON_H

#include <QObject>
#include <QMap>
#include "csingleton.h"

class SlotFunSingleton : public QObject
{
	Q_OBJECT

public:
	SlotFunSingleton();
	~SlotFunSingleton();

public:
	void addMapValue(QString strName, QObject* pObj);
	QObject* getObj(QString strName);
private:
	QMap<QString,QObject*> m_slotfunsMap;
};

typedef Singleton<SlotFunSingleton> SlotsSingleton;

#endif // SLOTFUNSINGLETON_H
