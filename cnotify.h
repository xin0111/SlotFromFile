#ifndef CNOTIFY_H
#define CNOTIFY_H

#include <QObject>

class CNotify : public QObject
{
	Q_OBJECT

public:
	CNotify(QObject *parent=0);
	~CNotify();
	public slots:
		void notifyMessage(QString sMessage);
private:
	
};

#endif // CNOTIFY_H
