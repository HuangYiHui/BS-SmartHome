package bs.pi.gateway.client.http;

import org.apache.http.client.entity.UrlEncodedFormEntity;

public class HttpMsgSend {
	/*
	 * HttpMsg使用json格式
	 * 格式：{success:true/false, msg:{msgJson}}
	 * 
	 * 对设备发送命令的格式：
	 * 		{deviceCmd:testCmd, appID:12, params:{key1:'value1'}}
	 */
	
	public final static String K_VALUE = "value";
	
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
