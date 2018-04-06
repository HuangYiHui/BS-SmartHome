package bs.pi.gateway.client.http;

import java.util.ArrayList;

import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.main.IReceivedListener;
import bs.pi.gateway.main.IReceiver;
import bs.pi.gateway.msg.IMsg;

public class HttpReceiver implements IReceiver {
	
	private ArrayList<IReceivedListener> receivedListenerList;
	private HttpClientCfg cfg;
	private IConverter converter;
	private HttpSender sender;
	
	public HttpReceiver(HttpClientCfg cfg, IConverter converter){
		this.cfg = cfg;
		this.converter = converter;
	}
	@Override
	public void addReceivedListenr(IReceivedListener listener) {
		// TODO Auto-generated method stub
		if(listener == null)
			return;
		if(receivedListenerList == null)
			receivedListenerList = new ArrayList<IReceivedListener>();
		receivedListenerList.add(listener);
	}

	@Override
	public void start() {
		flush();
		new Thread(new Runnable() {
			@Override
			public void run() {
				receive();
			}
		}).start();
	}

	@Override
	public void stop() {
	}

	@Override
	public void flush() {

	}
	@Override
	public String getName() {
		return IReceiver.NAME_HTTP_RECEIVER;
	}
	
	private void receive(){
		if(converter != null && receivedListenerList != null && receivedListenerList.size()>0){
			String url = cfg.getServiceUrl()+"/device/"+cfg.getDeviceID()+"/command";
			HttpExecuter executer = new HttpExecuter(url, HttpMsgSend.METHOD_GET, cfg.getApiKey(), null);
			HttpMsgReceive httpMsgReceive = executer.execute();
			httpMsgReceive.setType(HttpMsgReceive.TYPE_DEVICE_CMD);
			IMsg msg = converter.convertMsgReceive(httpMsgReceive);
			if(msg != null){
				for(IReceivedListener listener : receivedListenerList){
					listener.handleEvent(msg);
				}
			}
		}
	}

}
