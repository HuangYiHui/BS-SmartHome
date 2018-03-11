package bs.pi.gateway.msg;

public class ResponseMsg implements IMsg {

	public final static String MSG_NAME = "ResponseMsg";
	
	@Override
	public String getName() {
		return MSG_NAME;
	}

}
