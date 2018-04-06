package bs.pi.gateway.client.http;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import org.apache.http.Consts;
import org.apache.http.NameValuePair;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.message.BasicNameValuePair;

import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.msg.HttpCommandArrivedMsg;
import bs.pi.gateway.msg.IMsg;
import bs.pi.gateway.msg.UploadExecuterValueToHttpServerMsg;
import bs.pi.gateway.msg.UploadSensorValueToHttpServerMsg;

public class HttpConverter implements IConverter {	
	
	private final static String K_SUCCESS = "success";
	private final static String K_DATA = "data";
	private final static String K_CMD = "cmd";
	private final static String K_PARAMS = "params";
	private final static String K_NAME = "name";
	private final static String K_VALUE = "value";
	
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
			JSONObject jo = httpMsgReceive.getData();
			HttpCommandArrivedMsg httpCommandReceivedMsg = new HttpCommandArrivedMsg();
			if(HttpMsgReceive.V_SUCCESS_TRUE == jo.getBoolean(K_SUCCESS)){
				httpCommandReceivedMsg.setSuccess(true);
				JSONObject data = jo.getJSONObject(K_DATA);
				httpCommandReceivedMsg.setCmd(data.getString(K_CMD));
//				System.out.println(jo);
				JSONArray paramsArray = data.getJSONArray(K_PARAMS);
				if(paramsArray != null){
					HashMap<String, Object> cmdParams = new HashMap<String, Object>();
					for(int i = 0;i<paramsArray.size(); i++){
					  JSONObject paramJson = JSONObject.fromObject(paramsArray.getString(i));
					  cmdParams.put(paramJson.getString(K_NAME), paramJson.get(K_VALUE));
					}
					httpCommandReceivedMsg.setParams(cmdParams);
				}	
				
			}
			else {
				httpCommandReceivedMsg.setSuccess(false);
			}
			
			return httpCommandReceivedMsg;
		}
		return null;
	}

	@Override
	public Object convertMsgSend(IMsg msg) {
		if(msg == null)
			return null;
		
		HttpMsgSend httpMsg = new HttpMsgSend();
		
		if(IMsg.MSG_UPLAOD_SENSOR_VALUE_TO_HTTP_SERVER.equals(msg.getName())){
			UploadSensorValueToHttpServerMsg msg1 = null;
			try{
				msg1 = (UploadSensorValueToHttpServerMsg) msg;
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
		}else if(IMsg.MSG_UPLAOD_EXECUTER_VALUE_TO_HTTP_SERVER.equals(msg.getName())){
			UploadExecuterValueToHttpServerMsg msg1 = null;
			try{
				msg1 = (UploadExecuterValueToHttpServerMsg) msg;
			}catch(Exception e){
				return null;
			}
			String url = cfg.getServiceUrl()+"/device/"+cfg.getDeviceID()+"/sensor/"+msg1.getExecuterID()+"/datapoint";
			List<NameValuePair> paramList = new ArrayList<NameValuePair>();
			paramList.add(new BasicNameValuePair(HttpMsgSend.K_VALUE, ""+msg1.getExecuterValue()));
			UrlEncodedFormEntity params = new UrlEncodedFormEntity(paramList, Consts.UTF_8);
			
			httpMsg.setUrl(url);
			httpMsg.setMethod(HttpMsgSend.METHOD_POST);
			httpMsg.setApiKey(cfg.getApiKey());
			httpMsg.setParams(params);
			
			return httpMsg;	
		}else if(IMsg.MSG_DELETE_HTTP_COMMAND.equals(msg.getName())){
			String url = cfg.getServiceUrl()+"/device/"+cfg.getDeviceID()+"/command";
			httpMsg.setUrl(url);
			httpMsg.setMethod(HttpMsgSend.METHOD_DELETE);
			httpMsg.setApiKey(cfg.getApiKey());
			return httpMsg;
		}else if(IMsg.MSG_RESPONSE_TO_HTTP_SERVER_ALIVE.equals(msg.getName())){
			String url = cfg.getServiceUrl()+"/device/"+cfg.getDeviceID()+"/keep_alive";
			httpMsg.setUrl(url);
			httpMsg.setMethod(HttpMsgSend.METHOD_PUT);
			httpMsg.setApiKey(cfg.getApiKey());
			return httpMsg;
		}
		return null;
	}
}
