

import java.util.ArrayList;
import java.util.HashMap;

import bs.pi.gateway.main.IReceivedListener;
import bs.pi.gateway.main.IReceiver;

public class TestReceiver implements IReceiver {

	private ArrayList<IReceivedListener> receivedListenerList;
	private Thread rTread = new Thread(new Runnable() {
		@Override
		public void run() {
			while( ! rTread.isInterrupted()){
				HashMap<String, Object> msg = new HashMap<String, Object>();
				msg.put("test1", 123);
				if(receivedListenerList != null && receivedListenerList.size() > 0){
					for(IReceivedListener listener : receivedListenerList);
					//	listener.handleEvent(msg);
				}
				try {
					Thread.sleep(2000);
				} catch (InterruptedException e) {
					return;
				}
			}
		}
	});
	
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
		// TODO Auto-generated method stub
		rTread.start();
	}

	@Override
	public void stop() {
		// TODO Auto-generated method stub
		rTread.interrupt();
	}

	@Override
	public void flush() {
		// TODO Auto-generated method stub
		
	}

}