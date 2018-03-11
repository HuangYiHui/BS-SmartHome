package bs.pi.gateway.client.http;

import org.apache.http.client.entity.UrlEncodedFormEntity;

public class HttpMsg {
	/*
	 * HttpMsgʹ��json��ʽ
	 * ��ʽ��{success:true/false, msg:{msgJson}}
	 * 
	 * ���豸��������ĸ�ʽ��
	 * 		{deviceCmd:testCmd, appID:12, params:{key1:'value1'}}
	 */
	
	public final static String K_URL = "url";
	public final static String K_METHOD = "method";
	public final static String K_APIKEY = "apiKey";
	public final static String K_PARAMS = "params";
	public final static String K_VALUE = "value";
	public final static String K_CMD_NAME = "cmdName";
	public final static String K_SUCCESS = "success";
	public final static String K_MSG = "msg";
	public final static String K_APP_ID = "appID";
	public final static String K_DEVICE_CMD = "deviceCmd";
	public final static String K_CMD_PARAMS = "params";
	public final static String K_SEND_STATUS = "sendStatus";
	
	public final static String V_CMD_NAME_GET_DEVICE_CMD = "getDeviceCmd";
	public final static String V_CMD_NAME_SEND_CMD_TO_APP = "sendCmdToApp";
	public final static boolean V_SUCCESS_TRUE = true;
	public final static boolean V_SUCCESS_FALSE = false;
	public final static String V_SEND_STATUS_SUCCESS = "success";
	public final static String V_SEND_STATUS_FAIL = "fail";
	
	//������
	public final static String V_DEVICE_CMD_TEST_CMD = "testCmd";
	
	
	public final static int METHOD_GET = 1;
	public final static int METHOD_POST = 2;
	public final static int METHOD_PUT = 3;
	public final static int METHOD_DELETE = 4;
	
	private int requestType;
	private String url;
	private int method;
	private String apiKey;
	private UrlEncodedFormEntity params;
	public String getUrl() {
		return url;
	}
	public void setUrl(String url) {
		this.url = url;
	}
	public int getMethod() {
		return method;
	}
	public void setMethod(int method) {
		this.method = method;
	}
	public String getApiKey() {
		return apiKey;
	}
	public void setApiKey(String apiKey) {
		this.apiKey = apiKey;
	}
	public UrlEncodedFormEntity getParams() {
		return params;
	}
	public void setParams(UrlEncodedFormEntity params) {
		this.params = params;
	}
	public int getRequestType() {
		return requestType;
	}
	public void setRequestType(int requestType) {
		this.requestType = requestType;
	}
}