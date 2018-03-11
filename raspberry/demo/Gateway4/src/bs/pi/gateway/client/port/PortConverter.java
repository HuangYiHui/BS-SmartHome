package bs.pi.gateway.client.port;

import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.msg.IMsg;
import bs.pi.gateway.msg.PortMsgReceivedMsg;
import bs.pi.gateway.msg.SendPortMsgMsg;

public class PortConverter implements IConverter {

	/*
	 * ��ʽ��
	 * ������ɣ�MsgType, Cmd0, Cmd1, Data
	 * MsgType�̶�Ϊ�ַ���"PortMsg"
	 * Cmd0��Cmd1��Ϊһ���ֽڵ�Byte,
	 * DataΪByte����
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
