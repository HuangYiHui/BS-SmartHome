package bs.pi.gateway.main;

import bs.pi.gateway.msg.IMsg;

public interface IReceivedListener {
	public void handleEvent(IMsg msg);
}
