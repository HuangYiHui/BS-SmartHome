package bs.pi.gateway.msg;

import java.util.ArrayList;
import java.util.HashMap;

public class HttpCommandArrivedMsg implements IMsg {
	
	public final static String CMD_ON_SWITCH = "onSwitch";
	public final static String CMD_OFF_SWITCH = "offSwitch";
	
	private boolean success;
	private String cmd;
	private HashMap<String, Object> params;
	
	@Override
	public String getName() {
		return IMsg.MSG_HTTP_COMMAND_ARRIVED;
	}

	public boolean isSuccess() {
		return success;
	}

	public void setSuccess(boolean success) {
		this.success = success;
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
