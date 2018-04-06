package bs.pi.gateway.client.mqtt;

import org.fusesource.mqtt.client.MQTT;

import bs.pi.gateway.main.IClient;
import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.main.IReceiver;
import bs.pi.gateway.main.ISender;

public class MQTTClient implements IClient{

	public static final String DEFAULT_CFG_PATH = System.getProperty("user.dir")+System.getProperty("file.separator")+"mqttClientCfg.properties";
	private String cfgPath;
	private MQTTClientCfg cfg;
	MQTT mqtt;
	private MQTTSender sender;
	private MQTTReceiver receiver;
	private IConverter converter;
	
	public MQTTClient(String path){
		this.cfgPath = path;
	}
	private void loadCfg() throws Exception{
		if(cfgPath == null){
			throw new Exception("cfgPath is null");
		}else{
			cfg = new MQTTClientCfg(cfgPath);
		}
	}
	
	@Override
	public void init() throws Exception {
		loadCfg();
		mqtt = new MQTT();
        mqtt.setHost(cfg.getHost(), cfg.getPort());
        mqtt.setUserName(cfg.getUsername());
        mqtt.setPassword(cfg.getPassword());
	}

	@Override
	public void start() throws Exception {
		try {
			sender = new MQTTSender(mqtt.futureConnection(), converter);
			receiver = new MQTTReceiver(mqtt.callbackConnection(), cfg.getTopics(), converter);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@Override
	public void destroy() throws Exception {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setConverter(IConverter converter) {
		// TODO Auto-generated method stub
		this.converter = converter;
	}

	@Override
	public ISender getSender() {
		// TODO Auto-generated method stub
		return sender;
	}

	@Override
	public IReceiver getReceiver() {
		// TODO Auto-generated method stub
		return receiver;
	}

}
