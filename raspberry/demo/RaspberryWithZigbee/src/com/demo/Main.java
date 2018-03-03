package com.demo;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MessageClient portClient;
		try {
			portClient = new MyPortClient();
			portClient.connect();
			portClient.setReceiveCallBack(new MessageReceiveCallBack() {
				
				@Override
				public void received(Message message) {
					// TODO Auto-generated method stub
					System.out.println(message.getMsg());
				}
			});
			portClient.startReceive();
			while(true){
				Message message  =new Message();
				message.setMsg("1234567890");
				portClient.send(message);
				Thread.currentThread().sleep(500);
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
