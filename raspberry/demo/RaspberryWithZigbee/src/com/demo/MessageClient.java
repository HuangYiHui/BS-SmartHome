package com.demo;


/*
 * ��Ϣ�ͻ���
 * ��Ϣ�ͻ��˿����Ǵ�����Ϣ�ͻ��ˡ�mqtt�ͻ��ˡ�http�ͻ��ˡ�websocket�ͻ��˵ȵȣ����԰�����չ
 */
public interface MessageClient {
	
	//����
	void connect() throws Exception;
	
	//��Ϣ���ջص�������Ϣ���ͻ�ص�
	void setReceiveCallBack(MessageReceiveCallBack callBack);
	
	//��ʼ��Ϣ����
	void startReceive();
	
	//ֹͣ��Ϣ����
	void stopReceive();
	
	//����һ����Ϣ
	boolean send(Message message);
}
