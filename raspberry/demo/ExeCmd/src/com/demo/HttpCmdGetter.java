package com.demo;

import java.io.IOException;

import net.sf.json.JSONObject;

import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;

public class HttpCmdGetter {
	
	private String url;
	private String apiKey;
	
	public String getUrl() {
		return url;
	}

	public void setUrl(String url) {
		this.url = url;
	}
	public String getApiKey() {
		return apiKey;
	}

	public void setApiKey(String apiKey) {
		this.apiKey = apiKey;
	}


	public String[] getHttpCmd() throws ClientProtocolException, IOException{
		
		HttpGet httpPost = new HttpGet(url);
		httpPost.addHeader("APIKEY", apiKey);
		HttpClient client = HttpClients.createDefault();
		HttpResponse response =  client.execute(httpPost);
		//打印结果
		String rStr = EntityUtils.toString(response.getEntity());
		//System.out.println(rStr);
		JSONObject jo = JSONObject.fromObject(rStr);
		//System.out.println("success:"+jo.getString("success"));
		//命令格式 ：appMsgCmd-appID-appMsg
		if(jo.getString("success").equals("true")){
			String msg = jo.getString("msg");
			String[] strs = msg.split("-");
			if(strs.length > 1 && strs[0].equals("CMD_APP_MSG")){
				String[] result = new String[strs.length-1];
				//截取appID-appMsg作为命令appMsgCmd内容
				System.arraycopy(strs, 1, result, 0, strs.length-1);
				return result;
			}else{
				return new String[0];
			}
		}else{
			return new String[0];
		}
		
	}
}
