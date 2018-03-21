package bs.pi.gateway.client.http;

import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.main.ISender;
import bs.pi.gateway.msg.HttpSendResponseMsg;
import bs.pi.gateway.msg.IMsg;

public class HttpSender implements ISender {
	
	private IConverter converter;
	private HttpClientCfg cfg;
	
	public HttpSender(HttpClientCfg cfg, IConverter converter){
		this.cfg = cfg;
		this.converter = converter;
	}
	
	@Override
	public String getName() {
		return ISender.V_SEND_NAME_HTTP_SNEDER;
	}

	@Override
	public IMsg send(IMsg msg){
		Object obj = converter.convertMsgSend(msg);
		HttpSendResponseMsg responseMsg = new HttpSendResponseMsg();
		if(obj != null){
			HttpMsgSend msg1 = (HttpMsgSend)obj;
			responseMsg.setRequestType(msg1.getRequestType());
			HttpExecuter executer = new HttpExecuter(msg1.getUrl(), msg1.getMethod(), msg1.getApiKey(), msg1.getParams());
			HttpMsgReceive httpMsgReceive = executer.execute();
			if(httpMsgReceive != null){
				responseMsg.setSendSuccess(true);
				System.out.println("http send ok");
			}else{
				responseMsg.setSendSuccess(false);
			}
		}else{
			responseMsg.setSendSuccess(false);
		}
		
		return responseMsg;
	}
}
