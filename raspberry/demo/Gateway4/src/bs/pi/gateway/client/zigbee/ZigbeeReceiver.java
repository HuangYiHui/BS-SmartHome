package bs.pi.gateway.client.zigbee;

import java.util.ArrayList;
import java.util.HashMap;

import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.main.IReceivedListener;
import bs.pi.gateway.main.IReceiver;
import bs.pi.gateway.msg.IMsg;
import bs.pi.gateway.msg.PortMsgArrivedMsg;

public class ZigbeeReceiver implements IReceiver {

	private ArrayList<IReceivedListener> receivedListenerList;
	private IReceiver portReceiver;
	private IConverter converter;
	private IReceivedListener receivedListener = new IReceivedListener() {
		@Override
		public void handleEvent(IMsg msg) {
			if(converter != null && receivedListenerList != null && receivedListenerList.size() > 0){
				if(IMsg.MSG_PORT_MSG_ARRIVED.equals(msg.getName())){
					PortMsgArrivedMsg portMsgReceivedMsg = (PortMsgArrivedMsg) msg;
					ZigbeeMsgReceive zigbeeMsgReceive = new ZigbeeMsgReceive();
					zigbeeMsgReceive.setMsg(portMsgReceivedMsg);
					IMsg msg1 = converter.convertMsgReceive(zigbeeMsgReceive);
					//×ª»»³É¹¦
					if(msg1 != null){
						for(IReceivedListener receivedListener : receivedListenerList){
							receivedListener.handleEvent(msg1);
						}
					}
				}
			}
		}
	};
	
	public ZigbeeReceiver(IReceiver portReceiver, IConverter converter){
		this.portReceiver = portReceiver;
		this.converter = converter;
	}
	
	@Override
	public void addReceivedListenr(IReceivedListener listener) {
		if(listener == null)
			return;
		if(receivedListenerList == null)
			receivedListenerList = new ArrayList<IReceivedListener>();
		receivedListenerList.add(listener);
	}

	@Override
	public void start() {
		flush();
		portReceiver.addReceivedListenr(receivedListener);
		portReceiver.start();
	}

	@Override
	public void stop() {
		portReceiver.stop();
	}

	@Override
	public void flush() {
		portReceiver.flush();
	}

	@Override
	public String getName() {
		return IReceiver.NAME_ZIGBEE_RECEIVER;
	}
}
