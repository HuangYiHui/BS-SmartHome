package bs.pi.gateway.msg;

public class OtherZigbeeConnectedMsg implements IMsg {
	
	private byte[] IEEEAddr;
	private byte[] NWKAddr;
		
	public OtherZigbeeConnectedMsg(byte[] IEEEAddr, byte[] NWKAddr){
		this.IEEEAddr = IEEEAddr.clone();
		this.NWKAddr = NWKAddr.clone();
	}
	
	@Override
	public String getName() {
		return IMsg.MSG_OTHER_ZIGBEE_CONNECTED;
	}

	public byte[] getIEEEAddr() {
		return IEEEAddr;
	}

	public void setIEEEAddr(byte[] iEEEAddr) {
		IEEEAddr = iEEEAddr.clone();
	}

	public byte[] getNWKAddr() {
		return NWKAddr;
	}

	public void setNWKAddr(byte[] nWKAddr) {
		NWKAddr = nWKAddr.clone();
	}
	
}
