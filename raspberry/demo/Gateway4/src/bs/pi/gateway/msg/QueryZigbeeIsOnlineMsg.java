package bs.pi.gateway.msg;

public class QueryZigbeeIsOnlineMsg implements IMsg {

	public final static String MSG_NAME = "QueryZigbeeIsOnlineMsg";
	
	private byte[] srcAddr;
	
	@Override
	public String getName() {
		return MSG_NAME;
	}

	public byte[] getSrcAddr() {
		return srcAddr;
	}

	public void setSrcAddr(byte[] srcAddr) {
		this.srcAddr = srcAddr;
	}
}
