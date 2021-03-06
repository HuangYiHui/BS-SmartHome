package com.demo;
import gnu.io.CommPort;
import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

/*
 * port客户端，用户接收和发送串口消息
 */
public class MyPortClient{
	
	//配置文件相对路径
	private static final String OPTION_FILE_PATH = System.getProperty("file.separator")+"portOption.properties";
	private PortOption option;
	private SerialPort serialPort;
	private PortReceiver receiver;
	private PortSender sender;
	
	public MyPortClient(){
		this.option = loadOption();
	}
	
	//从配置文件加载配置
	private PortOption loadOption(){
		String path = System.getProperty("user.dir") + OPTION_FILE_PATH;
    	Properties properties = new Properties();
		try {
			properties.load(new FileInputStream(path));
			option = new PortOption();
			option.setPortName(properties.getProperty("portName"));
			int baudRate = Integer.parseInt(properties.getProperty("baudRate"));
			option.setBaudRate(baudRate);
			int dataBits = Integer.parseInt(properties.getProperty("dataBits"));
			option.setDataBits(dataBits);
			int stopBits = Integer.parseInt(properties.getProperty("stopBits"));
			option.setStopBits(stopBits);
			int parity = Integer.parseInt(properties.getProperty("parity"));
			option.setParity(parity);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.err.println(">>>MyPortClient.loadOption Error: 串口配置"+path+"加载出错！");
			e.printStackTrace();
		}
		
		return option;
	}
	
	public void connect () throws Exception{
		
		CommPortIdentifier portIdentifier = CommPortIdentifier.getPortIdentifier(option.getPortName());
        if ( portIdentifier.isCurrentlyOwned() ){
            String errorStr = ">>>MyPortClient.loadOption Error: 串口" + option.getPortName() +"被占用";
            throw new Exception(errorStr);
        }
        else{
            CommPort commPort = portIdentifier.open(option.getPortName(), 2000);
            
            if ( commPort instanceof SerialPort ){
                serialPort = (SerialPort) commPort;
                serialPort.setSerialPortParams(
                		option.getBaudRate(),
                		option.getDataBits(),
                		option.getStopBits(),
                		option.getParity());
                
                receiver = new PortReceiver(serialPort.getInputStream());
                sender = new PortSender(serialPort.getOutputStream());
            }
            else{
                String errorStr = ">>>MyPortClient.loadOption Error: "+  option.getPortName() +"不是串口";
	            throw new Exception(errorStr);
            }
        }
    }
	
	public void setReceiveCallBack(MessageReceiveCallBack callBack) {
		// TODO Auto-generated method stub
		receiver.setReceiveCallBack(callBack);
	}
	
	public void startReceive() {
		// TODO Auto-generated method stub
		receiver.start();
	}

	public void stopReceive() {
		// TODO Auto-generated method stub
		receiver.stop();
	}

	public boolean send(byte[] bs) {
		return sender.send(bs);
	}
    
}
