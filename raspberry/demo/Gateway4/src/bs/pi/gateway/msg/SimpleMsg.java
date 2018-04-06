package bs.pi.gateway.msg;

public class SimpleMsg implements IMsg{

	private String msgName;
	
	public SimpleMsg(String msgName){
		this.msgName = msgName;
	}
	
	@Override
	public String getName() {
		return msgName;
	}

}
