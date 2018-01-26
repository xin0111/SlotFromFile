#include "mainwidget.h"

#include <QFile>

#include <QtCore/QStringList>
#include "slotfunsingleton.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
	m_pObj = new CNotify();
	SlotsSingleton::getInstance().addMapValue("CNotify",m_pObj);
}

MainWidget::~MainWidget()
{

}
bool MainWidget::openXmlFile(QString filePath,QDomDocument &doc)
{
	QFile file( filePath );
	if ( !file.open( QFile::ReadOnly | QFile::Text ))
	{
		return false;
	}
	if (!doc.setContent( &file ))
	{
		file.close();
		return false;
	}
	file.close();
	return true;
}
void MainWidget::initUI()
{
	QDomDocument  doc;
	openXmlFile("config.xml",doc);
	QDomElement root = doc.documentElement();  
	QDomNodeList list = root.childNodes();
	for (int i=0;i<list.count();i++)
	{
		QDomNode domNode = list.item(i);
		QDomElement element = domNode.toElement();
		MyButton *pButton = new MyButton(this);
		QString strName = element.attribute("name"); 
		QString strslotfun = element.attribute("slot"); 
		QString strvalue = element.attribute("value"); 
		QStringList pos = element.attribute("pos").split(',');
		int nrow = pos.at(0).toInt();
		int ncol =  pos.at(1).toInt();
		pButton->setText(strName);		
		pButton->m_strSlotFunc = strslotfun;
		pButton->m_strValue = strvalue;	
		ui.gridLayout->addWidget(pButton, nrow ,ncol,1,1);
	}
}
