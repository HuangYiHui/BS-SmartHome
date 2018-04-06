package bs.pi.gateway.msg;

public class PortMsgArrivedMsg implements IMsg {
	
	private byte cmd0;
	private byte cmd1;
	private byte[] data;
	
	@Override
	public String getName() {
		return IMsg.MSG_PORT_MSG_ARRIVED;
	}

	public byte getCmd0() {
		return cmd0;
	}

	public void setCmd0(byte cmd0) {
		this.cmd0 = cmd0;
	}

	public byte getCmd1() {
		return cmd1;
	}

	public void setCmd1(byte cmd1) {
		this.cmd1 = cmd1;
	}

	public byte[] getData() {
		return data;
	}

	public void setData(byte[] data) {
		this.data = data;
	}
}
