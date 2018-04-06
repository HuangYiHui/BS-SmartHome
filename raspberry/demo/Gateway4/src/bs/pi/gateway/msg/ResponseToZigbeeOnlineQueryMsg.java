package bs.pi.gateway.msg;

public class ResponseToZigbeeOnlineQueryMsg implements IMsg {
	
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
		return IMsg.MSG_RESPONSE_TO_ZIGBEE_ONLINE_QUERY;
	}

}
