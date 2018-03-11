package bs.pi.gateway.main;

import java.util.ArrayList;

public class Gateway {
	
	private ArrayList<ISender> senderList;
	private ArrayList<IReceiver> receiverList;
	private IProcessor processor;
	
	public Gateway(){
		receiverList = new ArrayList<IReceiver>();
		senderList = new ArrayList<ISender>();
	}
	
	public void installSender(ISender sender){
		senderList.add(sender);
	}
	
	public void installReceiver(IReceiver receiver){
		receiverList.add(receiver);
	}
	
	public void setProcessor(IProcessor processor){
		this.processor = processor;
	}
	
	public void start(){
		
		//processor����������������Ϣ�����¼�
		if(receiverList.size()>0){
			for(IReceiver receiver : receiverList)
				receiver.addReceivedListenr(processor);
		}
		//��processor�������ṩ������
		processor.setSenders(senderList);
		
		processor.start();
	}
	
	public void destroy(){
		
	}
}