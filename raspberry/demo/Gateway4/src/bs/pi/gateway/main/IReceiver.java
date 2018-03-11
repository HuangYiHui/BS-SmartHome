package bs.pi.gateway.main;


public interface IReceiver {

	public void addReceivedListenr(IReceivedListener listener);
	public void start();
	public void stop();
	public void flush();
}
