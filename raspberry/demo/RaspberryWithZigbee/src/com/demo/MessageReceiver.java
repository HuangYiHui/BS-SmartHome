package com.demo;

/*
 * ��Ϣ�����ߣ�������Ϣ�ͻ����ڲ����
 */
public interface MessageReceiver {
	
	//������Ϣ���ջص�
	void setReceiveCallBack(MessageReceiveCallBack callBack);
	
	//��ʼ������Ϣ
	void start();
	
	//ֹͣ������Ϣ
	void stop();
}
