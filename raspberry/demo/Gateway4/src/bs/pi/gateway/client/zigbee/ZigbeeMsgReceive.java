package bs.pi.gateway.client.zigbee;

import bs.pi.gateway.msg.PortMsgArrivedMsg;

public class ZigbeeMsgReceive {
	
	private PortMsgArrivedMsg msg;

	public PortMsgArrivedMsg getMsg() {
		return msg;
	}

	public void setMsg(PortMsgArrivedMsg msg) {
		this.msg = msg;
	}
}
