#### 通过字符串调用槽函数的一种方式
QMetaObject::invokeMethod 
```` C++
void MyButton::findFunc(){
	QStringList finder = m_strSlotFunc.split("::");
	QString strObj = finder.at(0);		
	qDebug()<<strObj;
	QString strSlot = finder.at(1);
	int nPos =  strSlot.indexOf("(");
	strSlot = strSlot.mid(0,nPos);
	QObject *pObj = SlotsSingleton::getInstance().getObj(strObj);	
	if(pObj){
		QMetaObject::invokeMethod(pObj,strSlot.toLatin1(), Qt::QueuedConnection,Q_ARG(QString,m_strValue));
	}
}
````
