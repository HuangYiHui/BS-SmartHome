package bs.pi.gateway.processor;

import java.util.ArrayList;
import java.util.Map;

import bs.pi.gateway.main.IProcessor;
import bs.pi.gateway.main.IReceiver;
import bs.pi.gateway.main.ISender;
import bs.pi.gateway.msg.HttpCommandArrivedMsg;
import bs.pi.gateway.msg.IMsg;
import bs.pi.gateway.msg.OtherZigbeeConnectedMsg;
import bs.pi.gateway.msg.OutSensorValuesComingMsg;
import bs.pi.gateway.msg.QueryZigbeeIsOnlineMsg;
import bs.pi.gateway.msg.ResponseToZigbeeOnlineQueryMsg;
import bs.pi.gateway.msg.SendMsgToAppMsg;
import bs.pi.gateway.msg.SimpleMsg;
import bs.pi.gateway.msg.UploadSensorValueToHttpServerMsg;

//消息接收与处理为两个线程，采用了消费者模式
public class MyProcessor implements IProcessor {

	private ArrayList<ISender> senderList;
	private ArrayList<IReceiver> receiverList;
	private ArrayList<IMsg> msgList;	//消息队列
	private Thread processThread = new Thread(new Runnable() {
		@Override
		public void run() {
			while( ! processThread.isInterrupted()){
				IMsg msg = nextMsg();
				if(msg != null)
					process(msg);
			}
		}
	});
	
	public MyProcessor(){
		msgList = new ArrayList<IMsg>();
	}
	
	@Override
	public void setSenders(ArrayList<ISender> senderList) {
		this.senderList = senderList;
	}

	//消息处理，消息到来的时候放进消息队列，唤醒等待的线程
	@Override
	public void handleEvent(IMsg msg) {
		if(msg != null){
			synchronized (msgList) {
				msgList.add(msg);
				msgList.notifyAll();
			}
		}
	}
	
	@Override
	public void start(){
		processThread.start();
	}
	
	@Override
	public void stop(){
		//让nextMsg能退出
		msgList.notifyAll();
		processThread.interrupt();
	}
	
	//取出下一条消息
	private IMsg nextMsg(){
		IMsg msg = null;
		synchronized (msgList) {
			if(msgList.size() == 0){
				try {
					msgList.wait();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			if(msgList.size() > 0)
				msg = msgList.remove(0);
			msgList.notifyAll();
		}
		return msg;
	}
	
	//消息处理逻辑
	private void process(IMsg msg){
		System.out.println(msg.getName());
		if(IMsg.MSG_QUERY_ZIGBEE_IS_ONLINE.equals(msg.getName())){
			QueryZigbeeIsOnlineMsg queryZigbeeIsOnlineMsg = (QueryZigbeeIsOnlineMsg) msg;
			if(queryZigbeeIsOnlineMsg.getSrcAddr() != null && queryZigbeeIsOnlineMsg.getSrcAddr().length == 2){
				ResponseToZigbeeOnlineQueryMsg responseToZigbeeOnlineQueryMsg = new ResponseToZigbeeOnlineQueryMsg();
				responseToZigbeeOnlineQueryMsg.setSrcAddr(queryZigbeeIsOnlineMsg.getSrcAddr());
				send(ISender.NAME_ZIGBEE_SENDER, responseToZigbeeOnlineQueryMsg);
			}
		}else if(IMsg.MSG_UPLAOD_ALL_DEVICE_VALUE.equals(msg.getName())){
			send(ISender.NAME_ZIGBEE_SENDER, msg);
		}else if(IMsg.MSG_OUT_SENSOR_VALUES_COMING.equals(msg.getName())){
			send(ISender.NAME_ZIGBEE_SENDER, msg);
		}else if(IMsg.MSG_SEND_MSG_TO_APP.equals(msg.getName())){
			send(ISender.NAME_ZIGBEE_SENDER, msg);
		}else if(IMsg.MSG_HTTP_COMMAND_ARRIVED.equals(msg.getName())){
			HttpCommandArrivedMsg httpCommandReceivedMsg = (HttpCommandArrivedMsg) msg;
			if(httpCommandReceivedMsg.isSuccess()){
				//删除平台命令
				send(ISender.NAME_HTTP_SENDER, new SimpleMsg(IMsg.MSG_DELETE_HTTP_COMMAND));
				send(ISender.NAME_ZIGBEE_SENDER, msg);
			}
		}else if(IMsg.MSG_UPLAOD_SENSOR_VALUE_TO_HTTP_SERVER.equals(msg.getName())){
			send(ISender.NAME_HTTP_SENDER, msg);
		}else if(IMsg.MSG_UPLAOD_EXECUTER_VALUE_TO_HTTP_SERVER.equals(msg.getName())){
			send(ISender.NAME_HTTP_SENDER, msg);
		}else if(IMsg.MSG_RESPONSE_TO_HTTP_SERVER_ALIVE.equals(msg.getName())){
			send(ISender.NAME_HTTP_SENDER, msg);
		}else if(IMsg.MSG_OTHER_ZIGBEE_CONNECTED.equals(msg.getName())){
			//send(ISender.NAME_ZIGBEE_SENDER, msg);
		}else if(IMsg.MSG_GET_HTTP_COMMAND.equals(msg.getName())){
			if(receiverList != null && receiverList.size()>0){
				for(IReceiver receiver : receiverList){
					if(IReceiver.NAME_HTTP_RECEIVER.equals(receiver.getName())){
						receiver.start();
					}
				}
			}
		}
	}
	
	//让发送器发送消息
	private void send(String senderName, IMsg msg){
		for(ISender sender : senderList){
			if(senderName.equals(sender.getName())){
				try {
					sender.send(msg);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
	}

	@Override
	public void setReceivers(ArrayList<IReceiver> receiverList) {
		this.receiverList = receiverList;
	}
}
