package bs.pi.gateway.main;


public interface IReceiver {

	public final static String NAME_HTTP_RECEIVER = "HttpReceiver";
	public final static String NAME_PORT_RECEIVER = "PortReceiver";
	public final static String NAME_ZIGBEE_RECEIVER = "ZigbeeReceiver";
	public final static String NAME_MQTT_SRECEIVER = "MqttReceiver";
	
	public String getName();
	public void addReceivedListenr(IReceivedListener listener);
	public void start();
	public void stop();
	public void flush();
}
