package bs.pi.gateway.msg;

public class SendPortMsgMsg implements IMsg {

	private byte[] data;
	
	@Override
	public String getName() {
		return IMsg.MSG_SEND_PORT_MSG;
	}

	public byte[] getData() {
		return data;
	}

	public void setData(byte[] data) {
		this.data = data;
	}
}
