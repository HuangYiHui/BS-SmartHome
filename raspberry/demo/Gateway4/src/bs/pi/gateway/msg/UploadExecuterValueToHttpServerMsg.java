package bs.pi.gateway.msg;

public class UploadExecuterValueToHttpServerMsg implements IMsg {

	public final static short EXECUTER_ID_SOCKET1 = 30;
	public final static short EXECUTER_ID_SOCKET2 = 34;
	public final static short EXECUTER_ID_SOCKET3 = 35;
	
	public final static String EXECUTER_VALUE_ON = "on";
	public final static String EXECUTER_VALUE_OFF = "off";
	
	private short executerID;
	private String executerValue;
	
	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return IMsg.MSG_UPLAOD_EXECUTER_VALUE_TO_HTTP_SERVER;
	}

	public short getExecuterID() {
		return executerID;
	}

	public void setExecuterID(short executerID) {
		this.executerID = executerID;
	}

	public String getExecuterValue() {
		return executerValue;
	}

	public void setExecuterValue(String executerValue) {
		this.executerValue = executerValue;
	}
}
