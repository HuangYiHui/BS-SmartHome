package bs.pi.gateway.client.port;

import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.msg.IMsg;
import bs.pi.gateway.msg.PortMsgReceivedMsg;
import bs.pi.gateway.msg.SendPortMsgMsg;

public class PortConverter implements IConverter {

	/*
	 * 格式：
	 * 由项组成：MsgType, Cmd0, Cmd1, Data
	 * MsgType固定为字符串"PortMsg"
	 * Cmd0和Cmd1都为一个字节的Byte,
	 * Data为Byte数组
	 */
	
	@Override
	public IMsg convertMsgReceive(Object msg) {
		if(msg == null)
			return null;
		
		PortMsgReceive PortMsgReceive = null;
		try{
			PortMsgReceive = (PortMsgReceive) msg;
		}catch(Exception e){
			return null;
		}
		PortMsgReceivedMsg portMsgReceivedMsg = new PortMsgReceivedMsg();
		portMsgReceivedMsg.setCmd0(PortMsgReceive.getCmd0());
		portMsgReceivedMsg.setCmd1(PortMsgReceive.getCmd1());
		portMsgReceivedMsg.setData(PortMsgReceive.getData());
		return portMsgReceivedMsg;
	}

	@Override
	public Object convertMsgSend(IMsg msg) {
		if( msg != null && SendPortMsgMsg.MSG_NAME.equals(msg.getName())){
			SendPortMsgMsg sendPortMsgMsg = (SendPortMsgMsg) msg;
			PortMsgSend portMsg = new PortMsgSend();
			portMsg.setData(sendPortMsgMsg.getData());
			return portMsg;
		}
		
		return null;
	}

}
