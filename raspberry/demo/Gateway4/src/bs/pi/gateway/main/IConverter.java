package bs.pi.gateway.main;

import bs.pi.gateway.msg.IMsg;

public interface IConverter {
	
	public IMsg convertMsgReceive(Object msg);
	public Object convertMsgSend(IMsg msg);
}
