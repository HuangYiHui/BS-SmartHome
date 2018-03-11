package bs.pi.gateway.main;

import java.util.HashMap;

import bs.pi.gateway.msg.IMsg;

public interface IConverter {
	
	public final static String K_CONVERT_STATUS = "ConvertStatus";
	
	public final static String V_CONVERT_STATUS_SUCCESS = "Success";
	public final static String V_CONVERT_STATUS_FAIL = "Fail";
	
	public IMsg convertMsgReceive(Object msg);
	public Object convertMsgSend(IMsg msg);
}