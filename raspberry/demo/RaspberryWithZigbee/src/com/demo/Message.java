package com.demo;

/*
 * 消息类，后续会定义具体格式
 */
public class Message {

	private byte cmd0;
	private byte cmd1;
	private byte[] data;
	public byte getCmd0() {
		return cmd0;
	}
	public void setCmd0(byte cmd0) {
		this.cmd0 = cmd0;
	}
	public byte getCmd1() {
		return cmd1;
	}
	public void setCmd1(byte cmd1) {
		this.cmd1 = cmd1;
	}
	public byte[] getData() {
		return data;
	}
	public void setData(byte[] data) {
		this.data = data;
	}
	
	public boolean validate(byte cFcs){
		byte fcs = (byte) data.length;
		fcs ^= cmd0;
		fcs ^= cmd1;
		for(byte b : data)
			fcs ^= b;
		if(cFcs == fcs)
			return true;
		else
			return false;
	}
}
