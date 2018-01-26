#include "mybutton.h"
#include "slotfunsingleton.h"
#include <QMetaObject>

MyButton::MyButton(QWidget *parent)
{
	connect(this,SIGNAL(clicked()),this,SLOT(findFunc()));
}

MyButton::~MyButton()
{

}
#include <QDebug>
void MyButton::findFunc(){
	qDebug()<<m_strSlotFunc;
	QStringList finder = m_strSlotFunc.split("::");
	QString strObj = finder.at(0);		
	qDebug()<<strObj;
	QString strSlot = finder.at(1);
	int nPos =  strSlot.indexOf("(");
	strSlot = strSlot.mid(0,nPos);
	qDebug()<<strSlot;
	QObject *pObj = SlotsSingleton::getInstance().getObj(strObj);	
	if(pObj){
		QMetaObject::invokeMethod(pObj,strSlot.toLatin1(), Qt::QueuedConnection,Q_ARG(QString,m_strValue));
	}
}