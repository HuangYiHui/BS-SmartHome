package com.demo;
import gnu.io.CommPort;
import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

import main.Message;
import main.MessageClient;
import main.MessageReceiveCallBack;
import main.MessageReceiver;
import main.MessageSender;

/*
 * port�ͻ��ˣ��û����պͷ��ʹ�����Ϣ
 */
public class MyPortClient implements MessageClient{
	
	//�����ļ����·��
	private static final String OPTION_FILE_PATH = System.getProperty("file.separator")+"portOption.properties";
	private PortOption option;
	private SerialPort serialPort;
	private MessageReceiver receiver;
	private MessageSender sender;
	
	public MyPortClient(){
		this.option = loadOption();
	}
	
	//�������ļ���������
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
			System.err.println(">>>MyPortClient.loadOption Error: ��������"+path+"���س���");
			e.printStackTrace();
		}
		
		return option;
	}
	
	public void connect () throws Exception{
		
		CommPortIdentifier portIdentifier = CommPortIdentifier.getPortIdentifier(option.getPortName());
        if ( portIdentifier.isCurrentlyOwned() ){
            String errorStr = ">>>MyPortClient.loadOption Error: ����" + option.getPortName() +"��ռ��";
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
                String errorStr = ">>>MyPortClient.loadOption Error: "+  option.getPortName() +"���Ǵ���";
	            throw new Exception(errorStr);
            }
        }
    }
	
	@Override
	public void setReceiveCallBack(MessageReceiveCallBack callBack) {
		// TODO Auto-generated method stub
		receiver.setReceiveCallBack(callBack);
	}

	@Override
	public void startReceive() {
		// TODO Auto-generated method stub
		receiver.start();
	}

	@Override
	public void stopReceive() {
		// TODO Auto-generated method stub
		receiver.stop();
	}

	@Override
	public boolean send(Message message) {
		// TODO Auto-generated method stub
		return sender.send(message);
	}
    
}
