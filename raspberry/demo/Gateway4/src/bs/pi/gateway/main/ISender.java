package bs.pi.gateway.main;

import bs.pi.gateway.msg.IMsg;

public interface ISender {

	public final static String NAME_HTTP_SENDER = "HttpSender";
	public final static String NAME_PORT_SENDER = "PortSender";
	public final static String NAME_ZIGBEE_SENDER = "ZigbeeSender";
	public final static String NAME_MQTT_SENDER = "MqttSender";
	
	public String getName();
	public IMsg send(IMsg msg);
}
