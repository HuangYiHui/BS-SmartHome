package bs.pi.gateway.msg;

public class ResponseToZigbeeOnlineQueryMsg implements IMsg {

	public final static String MSG_NAME = "ResponseToZigbeeOnlineQueryMsg";
	
	private byte[] srcAddr;
	
	public byte[] getSrcAddr() {
		return srcAddr;
	}

	public void setSrcAddr(byte[] srcAddr) {
		this.srcAddr = srcAddr;
	}
	
	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return MSG_NAME;
	}

}
