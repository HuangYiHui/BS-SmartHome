package bs.pi.gateway.main;

import java.util.ArrayList;

public interface IProcessor extends IReceivedListener {

	public void setSenders(ArrayList<ISender> senderList);
	public void start();
	public void stop();
}
