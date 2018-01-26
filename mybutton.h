#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QWidget>

class MyButton : public QPushButton
{
	Q_OBJECT

public:
	MyButton(QWidget *parent=0);
	~MyButton();
private slots:
	void findFunc();
public:
	QString m_strSlotFunc;
	QString m_strValue;	
};

#endif // MYBUTTON_H
