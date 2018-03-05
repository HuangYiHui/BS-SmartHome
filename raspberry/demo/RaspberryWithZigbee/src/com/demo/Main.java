package com.demo;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyPortClient portClient;
		try {
			portClient = new MyPortClient();
			portClient.connect();
			portClient.setReceiveCallBack(new MessageReceiveCallBack() {
				
				@Override
				public void received(Message msg) {
					// TODO Auto-generated method stub
					System.out.println("----msg----");
					System.out.print("cmd0 : ");
					System.out.printf("%x\n", msg.getCmd0());
					System.out.print("cmd1 : ");
					System.out.printf("%x\n", msg.getCmd1());
					System.out.print("data : ");
					for(byte b : msg.getData()){
						System.out.printf("%x,", b);
					}
					System.out.println();
					System.out.println("----msg----");
				}
			});
			portClient.startReceive();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
