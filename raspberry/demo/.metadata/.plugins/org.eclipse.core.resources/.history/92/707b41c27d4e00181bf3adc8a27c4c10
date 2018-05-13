package com.test;

import org.fusesource.hawtbuf.AsciiBuffer;
import org.fusesource.hawtbuf.Buffer;
import org.fusesource.hawtbuf.UTF8Buffer;
import org.fusesource.mqtt.client.QoS;

public class MQTTMsgSend {
	
	private UTF8Buffer topic;
	private Buffer msg;
	private QoS qos;
	private boolean retain;
	public UTF8Buffer getTopic() {
		return topic;
	}
	public void setTopic(UTF8Buffer topic) {
		this.topic = topic;
	}
	public QoS getQos() {
		return qos;
	}
	public void setQos(QoS qos) {
		this.qos = qos;
	}
	public boolean isRetain() {
		return retain;
	}
	public void setRetain(boolean retain) {
		this.retain = retain;
	}
	public Buffer getMsg() {
		return msg;
	}
	public void setMsg(String msg) {
		this.msg = new AsciiBuffer(msg);
	}
}
