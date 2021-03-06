package bs.pi.gateway.client.port;

import java.io.IOException;
import java.io.OutputStream;

import com.test.Debugger;

import bs.pi.gateway.main.IConverter;
import bs.pi.gateway.main.ISender;
import bs.pi.gateway.msg.IMsg;
import bs.pi.gateway.msg.PortSendResponseMsg;

public class PortSender implements ISender {

	private OutputStream oStream;
	private IConverter converter;
	
	public PortSender(OutputStream oStream, IConverter converter){
		this.oStream = oStream;
		this.converter = converter;
	}
	
	@Override
	public String getName() {
		return ISender.NAME_PORT_SENDER;
	}

	@Override
	public IMsg send(IMsg msg) {
		PortSendResponseMsg response = new PortSendResponseMsg();
		Object obj = converter.convertMsgSend(msg);
		if(obj != null){
			PortMsgSend portMsg = (PortMsgSend)obj;
			try {
				oStream.write(portMsg.getData());
				response.setSendSuccess(true);
			} catch (IOException e) {
				e.printStackTrace();
				response.setSendSuccess(false);
			}
		}else{
			response.setSendSuccess(false);
		}
		return response;
	}

}
