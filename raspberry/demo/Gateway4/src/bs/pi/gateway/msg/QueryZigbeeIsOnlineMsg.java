package bs.pi.gateway.msg;

public class QueryZigbeeIsOnlineMsg implements IMsg {

	private byte[] srcAddr;
	
	@Override
	public String getName() {
		return IMsg.MSG_QUERY_ZIGBEE_IS_ONLINE;
	}

	public byte[] getSrcAddr() {
		return srcAddr;
	}

	public void setSrcAddr(byte[] srcAddr) {
		this.srcAddr = srcAddr;
	}
}
