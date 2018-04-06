package bs.pi.gateway.main;

import java.util.ArrayList;

import bs.pi.gateway.msg.IMsg;
import bs.pi.gateway.msg.SimpleMsg;

public class Gateway {
	
	private ArrayList<ISender> senderList;
	private ArrayList<IReceiver> receiverList;
	private IProcessor processor;
	private Thread responseAliveToHttpServerThread = new Thread(new Runnable() {
		@Override
		public void run() {
			while(true){
				processor.handleEvent(new SimpleMsg(IMsg.MSG_RESPONSE_TO_HTTP_SERVER_ALIVE));
				try {
					Thread.sleep(3500);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	});
	
	public Gateway(){
		receiverList = new ArrayList<IReceiver>();
		senderList = new ArrayList<ISender>();
	}
	
	public void installSender(ISender sender){
		senderList.add(sender);
	}
	
	public void installReceiver(IReceiver receiver){
		if(receiver != null)
			receiverList.add(receiver);
	}
	
	public void setProcessor(IProcessor processor){
		this.processor = processor;
	}
	
	public void start(){
		
		//给processor发送器提供发送器
		processor.setSenders(senderList);
		processor.setReceivers(receiverList);
		processor.start();
				
		//processor监听各个接收器消息接收事件
		if(receiverList.size()>0){
			for(IReceiver receiver : receiverList){
				receiver.addReceivedListenr(processor);
				receiver.start();
			}
		}
		
		responseAliveToHttpServerThread.start();
	}
	
	public void destroy(){
		
	}
}
