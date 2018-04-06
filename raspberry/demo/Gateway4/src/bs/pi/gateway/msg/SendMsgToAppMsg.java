package bs.pi.gateway.msg;

import java.util.HashMap;

public class SendMsgToAppMsg implements IMsg {
	
	private short appID;
	private String cmd;
	private HashMap<String, Object> params;
	
	@Override
	public String getName() {
		return IMsg.MSG_SEND_MSG_TO_APP;
	}

	public short getAppID() {
		return appID;
	}

	public void setAppID(short appID) {
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
