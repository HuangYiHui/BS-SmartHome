package bs.pi.gateway.client.mqtt;

import java.util.ArrayList;

import org.fusesource.hawtbuf.Buffer;
import org.fusesource.hawtbuf.UTF8Buffer;
import org.fusesource.mqtt.client.Callback;
import org.fusesource.mqtt.client.CallbackConnection;
import org.fusesource.mqtt.client.QoS;
import org.fusesource.mqtt.client.Topic;

import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.main.IReceivedListener;
import bs.pi.gateway.main.IReceiver;
import bs.pi.gateway.msg.IMsg;

public class MQTTReceiver implements IReceiver, org.fusesource.mqtt.client.Listener, Callback{

	private CallbackConnection connection;
	private Topic[] topics;
	private IConverter converter;
	private ArrayList<IReceivedListener> receivedListenerList;
	
	public MQTTReceiver(CallbackConnection connection, Topic[] topics, IConverter converter){
		this.connection = connection;
		this.topics = topics.clone();
		this.converter = converter;
		this.connection.listener(this);
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
		connection.connect(this);
	}

	@Override
	public void stop() {
		connection.disconnect(this);
	}

	@Override
	public void flush() {
	}

	@Override
	public void onConnected() {
	}

	@Override
	public void onDisconnected() {
	}

	@Override
	public void onFailure(Throwable arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onPublish(UTF8Buffer topic, Buffer msgBuffer, Runnable ack) {
		String msgStr = msgBuffer.utf8().toString();
		IMsg msg = converter.convertMsgReceive(msgStr);
		if(msg != null && receivedListenerList != null && receivedListenerList.size()>0){
			for(IReceivedListener listener : receivedListenerList)
				listener.handleEvent(msg);
		}
	}

	@Override
	public void onSuccess(Object arg0) {
        connection.subscribe(topics, new Callback<byte[]>() {
            public void onSuccess(byte[] qoses) {
            }
            public void onFailure(Throwable value) {
                value.printStackTrace();
                System.exit(-2);
            }
        });
	}

	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return IReceiver.NAME_MQTT_SRECEIVER;
	}
}
