package bs.pi.gateway.client.port;

public class PortMsgSend {
	
	public final static String K_CMD0 = "Cmd0";
	public final static String K_CMD1 = "Cmd1";
	public final static String K_DATA = "Data";
	
	private byte[] data;

	public byte[] getData() {
		return data;
	}

	public void setData(byte[] data) {
		this.data = data;
	}
	
	
}
