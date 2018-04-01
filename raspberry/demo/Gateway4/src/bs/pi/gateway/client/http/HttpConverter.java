package bs.pi.gateway.client.http;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

import net.sf.json.JSONObject;

import org.apache.http.Consts;
import org.apache.http.NameValuePair;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.message.BasicNameValuePair;

import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.msg.IMsg;
import bs.pi.gateway.msg.SendMsgToAppMsg;
import bs.pi.gateway.msg.UploadDataToHttpServerMsg;

public class HttpConverter implements IConverter {	
	
	private HttpClientCfg cfg;
	
	public void setHttpClientCfg(HttpClientCfg cfg){
		this.cfg = cfg;
	}
	
	@Override
	public IMsg convertMsgReceive(Object msg) {
		if(msg ==null)
			return null;
		
		HttpMsgReceive httpMsgReceive = null;
		try{
			httpMsgReceive = (HttpMsgReceive)msg;
		}catch(Exception e){
			return null;
		}
		
		//…Ë±∏√¸¡Ó
		if(HttpMsgReceive.TYPE_DEVICE_CMD == httpMsgReceive.getType()){
			JSONObject data = httpMsgReceive.getData();
			if(HttpMsgReceive.V_SUCCESS_TRUE == data.getBoolean(HttpMsgReceive.K_SUCCESS)){
			
				//	String appMsgStr = data.getString(HttpMsgReceive.K_MSG);
				/*
				JSONObject appMsg = JSONObject.fromObject(appMsgStr.substring(1, appMsgStr.length()-1));
				SendMsgToAppMsg sendMsgToAppMsg = new SendMsgToAppMsg();
				int appID = Integer.parseInt(appMsg.getString(HttpMsgReceive.K_APP_ID));
				sendMsgToAppMsg.setAppID(appID);
				sendMsgToAppMsg.setCmd(appMsg.getString(HttpMsgReceive.K_CMD));
				HashMap<String, Object> params = new HashMap<String, Object>();
				if(data.containsKey(HttpMsgReceive.K_PARAMS)){
					JSONObject paramJson = JSONObject.fromObject(data.getString(HttpMsgReceive.K_PARAMS));
					Set<Map.Entry<String, Object>> entrys = paramJson.entrySet();
					for(Map.Entry<String, Object> entry : entrys)
						params.put(entry.getKey(), entry.getValue());
					sendMsgToAppMsg.setParams(params);
				}*/
			//	return sendMsgToAppMsg;
			}
		}
		return null;
	}

	@Override
	public Object convertMsgSend(IMsg msg) {
		if(msg == null)
			return null;
		
		HttpMsgSend httpMsg = new HttpMsgSend();
		
		if(UploadDataToHttpServerMsg.MSG_NAME.equals(msg.getName())){
			UploadDataToHttpServerMsg msg1 = null;
			try{
				msg1 = (UploadDataToHttpServerMsg) msg;
			}catch(Exception e){
				return null;
			}
			String url = cfg.getServiceUrl()+"/device/"+cfg.getDeviceID()+"/sensor/"+msg1.getSensorID()+"/datapoint";
			List<NameValuePair> paramList = new ArrayList<NameValuePair>();
			paramList.add(new BasicNameValuePair(HttpMsgSend.K_VALUE, ""+msg1.getSensorValue()));
			UrlEncodedFormEntity params = new UrlEncodedFormEntity(paramList, Consts.UTF_8);
			
			httpMsg.setUrl(url);
			httpMsg.setMethod(HttpMsgSend.METHOD_POST);
			httpMsg.setApiKey(cfg.getApiKey());
			httpMsg.setParams(params);
			
			return httpMsg;	
		}
		return null;
	}
}
