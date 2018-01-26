#include "cnotify.h"
#include <QMessageBox>
CNotify::CNotify(QObject *parent)
	: QObject(parent)
{

}

CNotify::~CNotify()
{

}
void CNotify::notifyMessage(QString sMessage)
{
	QMessageBox box;
	box.setText(sMessage);	
	box.exec();
}