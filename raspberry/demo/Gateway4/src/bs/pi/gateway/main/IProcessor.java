package bs.pi.gateway.main;

import java.util.ArrayList;

import bs.pi.gateway.msg.IMsg;

public interface IProcessor extends IReceivedListener {

	public void setSenders(ArrayList<ISender> senderList);
	public void setReceivers(ArrayList<IReceiver> receiverList);
	public void start();
	public void stop();
}
