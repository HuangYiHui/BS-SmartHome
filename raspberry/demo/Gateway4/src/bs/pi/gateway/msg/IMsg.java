package bs.pi.gateway.msg;

public interface IMsg {

	public final static String MSG_DELETE_HTTP_COMMAND = "DeleteHttpCommandMsg";
	public final static String MSG_GET_HTTP_COMMAND = "GetHttpCommandMsg";
	public final static String MSG_UPLAOD_ALL_DEVICE_VALUE = "UplaodAllDeviceValue";
	public final static String MSG_UPLAOD_SENSOR_VALUE_TO_HTTP_SERVER = "UploadSensorValueToHttpServerMsg";
	public final static String MSG_UPLAOD_EXECUTER_VALUE_TO_HTTP_SERVER = "UploadExecuterValueToHttpServerMsg";
	public final static String MSG_HTTP_SEND_RESPONSE = "HttpSendResponseMsg";
	public final static String MSG_OTHER_ZIGBEE_CONNECTED = "OtherZigbeeConnectedMsg";
	public final static String MSG_OUT_SENSOR_VALUES_COMING = "OutSensorValuesComingMsg";
	public final static String MSG_PORT_MSG_ARRIVED = "PortMsgArrivedMsg";
	public final static String MSG_PORT_SEND_RESPONSE = "PortSendResponseMsg";
	public final static String MSG_QUERY_ZIGBEE_IS_ONLINE = "QueryZigbeeIsOnlineMsg";
	public final static String MSG_RESPONSE_TO_ZIGBEE_ONLINE_QUERY = "ResponseToZigbeeOnlineQueryMsg";
	public final static String MSG_SEND_MSG_TO_APP = "SendMsgToAppMsg";
	public final static String MSG_SEND_PORT_MSG = "PortSendMsgMsg";
	public final static String MSG_ZIGBEE_SEND_RESPONSE = "ZigbeeSendResponseMsg";
	public final static String MSG_HTTP_COMMAND_ARRIVED = "HttpCommandArrivedMsg";
	public final static String MSG_RESPONSE_TO_HTTP_SERVER_ALIVE = "ResponseToHttpServerAliveMsg";
	public String getName();
	
}
