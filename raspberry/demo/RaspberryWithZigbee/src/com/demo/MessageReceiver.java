package com.demo;

/*
 * 消息接受者，属于消息客户端内部组件
 */
public interface MessageReceiver {
	
	//设置消息接收回调
	void setReceiveCallBack(MessageReceiveCallBack callBack);
	
	//开始接收消息
	void start();
	
	//停止接收消息
	void stop();
}
