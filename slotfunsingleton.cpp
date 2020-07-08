#include "slotfunsingleton.h"
#include <QMapIterator>
SlotFunSingleton::SlotFunSingleton()
{
	m_slotfunsMap.clear();
}

SlotFunSingleton::~SlotFunSingleton()
{

}

void SlotFunSingleton::addMapValue(QString strName, QObject* pObj)
{
	m_slotfunsMap.insert(strName,pObj);
}

QObject* SlotFunSingleton::getObj( QString strName)
{
	QObject *pReturn = NULL;
	QMap<QString,QObject*>::iterator itor = m_slotfunsMap.find(strName);
	if(itor != m_slotfunsMap.end()){
		pReturn = itor.value();
	}
	return pReturn;
}

