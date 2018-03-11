package bs.pi.gateway.msg;

import java.util.HashMap;

public class SendMsgToAppMsg implements IMsg {
	
	public final static String MSG_NAME = "SendMsgToAppMsg";

	private int appID;
	private String cmd;
	private HashMap<String, Object> params;
	
	@Override
	public String getName() {
		return MSG_NAME;
	}

	public int getAppID() {
		return appID;
	}

	public void setAppID(int appID) {
		this.appID = appID;
	}

	public String getCmd() {
		return cmd;
	}

	public void setCmd(String cmd) {
		this.cmd = cmd;
	}

	public HashMap<String, Object> getParams() {
		return params;
	}

	public void setParams(HashMap<String, Object> params) {
		this.params = params;
	}
}
