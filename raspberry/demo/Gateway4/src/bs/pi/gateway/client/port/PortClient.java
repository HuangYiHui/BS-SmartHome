package bs.pi.gateway.client.port;

import gnu.io.CommPort;
import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import bs.pi.gateway.main.IClient;
import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.main.IReceiver;
import bs.pi.gateway.main.ISender;

public class PortClient implements IClient{

	public static final String DEFAULT_CFG_PATH = System.getProperty("user.dir")+System.getProperty("file.separator")+"portClientCfg.properties";
	private String cfgPath;
	private PortClientCfg cfg;
	private SerialPort serialPort;
	private PortSender sender;
	private PortReceiver receiver;
	private IConverter converter;
	
	public PortClient(String cfgPath){
		this.cfgPath = cfgPath;
	}
	
	@Override
	public void init() throws Exception {
		if(cfgPath == null)
			cfgPath = DEFAULT_CFG_PATH;
		cfg = new PortClientCfg(cfgPath);
	}

	@Override
	public void start() throws Exception {
		CommPortIdentifier portIdentifier = CommPortIdentifier.getPortIdentifier(cfg.getPortName());
        if ( portIdentifier.isCurrentlyOwned() ){
            String errorStr = "port:" + cfg.getPortName() +" was occupied";
            throw new Exception(errorStr);
        }
        else{
            CommPort commPort = portIdentifier.open(cfg.getPortName(), 2000);
            if ( commPort instanceof SerialPort ){
            	serialPort = (SerialPort) commPort;
                serialPort.setSerialPortParams(cfg.getBaudRate(), cfg.getDataBits(), cfg.getStopBits(), cfg.getParity());
                sender = new PortSender(serialPort.getOutputStream(), converter);
                receiver = new PortReceiver(serialPort.getInputStream(), converter);
            }
            else{
                String errorStr = cfg.getPortName() +"not a serial port";
	            throw new Exception(errorStr);
            }
        }
	}

	@Override
	public void destroy() {
		receiver.stop();
		serialPort.close();
		sender = null;
		receiver = null;
	}

	@Override
	public ISender getSender() {
		return sender;
	}

	@Override
	public IReceiver getReceiver() {
		return receiver;
	}

	@Override
	public void setConverter(IConverter converter) {
		this.converter = converter;
	}

}
