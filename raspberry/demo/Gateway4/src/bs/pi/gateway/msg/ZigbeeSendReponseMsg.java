package bs.pi.gateway.msg;

public class ZigbeeSendReponseMsg implements IMsg {

	private boolean sendSuccess;
	
	@Override
	public String getName() {
		return IMsg.MSG_ZIGBEE_SEND_RESPONSE;
	}

	public boolean getSendSuccess() {
		return sendSuccess;
	}

	public void setSendSuccess(boolean sendSuccess) {
		this.sendSuccess = sendSuccess;
	}
}
