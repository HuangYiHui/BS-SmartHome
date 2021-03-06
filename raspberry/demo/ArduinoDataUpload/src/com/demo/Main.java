package com.demo;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.util.EntityUtils;

import com.port.Message;
import com.port.MessageReceiveCallBack;
import com.port.MyPortClient;
import com.zigbeee.Zigbee;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		MyPortClient client = new MyPortClient();
		client.connect();
		client.setReceiveCallBack(new MessageReceiveCallBack() {
			@Override
			public void received(Message msg) {
	
				//0x81一定要转成byte
				if(msg != null && msg.getCmd0() == 0x44 && msg.getCmd1() == (byte)0x81){
					int value = msg.getData()[17];
					Uploader.uplaod(""+value);
				}
			}
		});
	
		Zigbee zigbee = new Zigbee();
		zigbee.setPortClient(client);
		zigbee.init();
		zigbee.start();
	
		client.startReceive();
	}
}
