package bs.pi.gateway.client.mqtt;

import org.fusesource.mqtt.client.FutureConnection;

import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.main.ISender;
import bs.pi.gateway.msg.IMsg;

public class MQTTSender implements ISender {

	private FutureConnection connection;
	private IConverter converter;
	
	public MQTTSender(FutureConnection connection, IConverter converter){
		this.connection = connection;
		this.converter = converter;
	}
	
	@Override
	public String getName() {
		return NAME_MQTT_SENDER;
	}

	@Override
	public IMsg send(IMsg msg) {
		Object obj = converter.convertMsgSend(msg);
		if(obj != null){
			MQTTMsgSend mqttMsgSend = (MQTTMsgSend)obj;
			try{
				connection.connect().await();
		        connection.publish(mqttMsgSend.getTopic(), mqttMsgSend.getMsg(), mqttMsgSend.getQos(), mqttMsgSend.isRetain());
		        connection.disconnect().await();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
		return null;
	}
}
