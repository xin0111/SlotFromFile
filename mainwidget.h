#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QDomDocument>

#include "ui_mainwidget.h"
#include "mybutton.h"
#include "cnotify.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();
	bool openXmlFile(QString filePath,QDomDocument &doc);
public:
	void initUI();
private:
	Ui::MainWidget ui;
	QList<MyButton*> m_buttons; 
	CNotify *m_pObj;
};

#endif // MAINWIDGET_H
