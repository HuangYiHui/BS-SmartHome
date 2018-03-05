package com.port;


public interface MessageReceiveCallBack {

	//接收到一条消息的回调
	void received(Message message);
}
