package bs.pi.gateway.client.mqtt;

import net.sf.json.JSONObject;
import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.msg.IMsg;
import bs.pi.gateway.msg.SimpleMsg;

public class MQTTConverter implements IConverter{

	private final static String K_CMD = "cmd";
	private final static String K_PARAM = "param";
	
	private final static String V_CMD_GET_HTTP_COMMAND = "getHttpCmd";
	private final static String V_CMD_UPLAOD_ALL_DEVICE_VALUE = "postDatas";
	private final static String V_CMD_KEEP_ALIVE = "keepAlive";
	
	@Override
	public IMsg convertMsgReceive(Object msg) {
		//System.out.println(msg);
		try{
			JSONObject jo = JSONObject.fromObject(msg);
			String cmd = jo.getString(K_CMD);
			if(cmd.equals(V_CMD_GET_HTTP_COMMAND)){
				return new SimpleMsg(IMsg.MSG_GET_HTTP_COMMAND);
			}else if(cmd.equals(V_CMD_UPLAOD_ALL_DEVICE_VALUE)){
				return new SimpleMsg(IMsg.MSG_UPLAOD_ALL_DEVICE_VALUE);
			}
		}catch(Exception e){
			e.printStackTrace();
			return null;
		}
		return null;
	}

	@Override
	public Object convertMsgSend(IMsg msg) {
		// TODO Auto-generated method stub
		return null;
	}

}
