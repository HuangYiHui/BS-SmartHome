package bs.pi.gateway.main;


public interface IClient {

	public void init() throws Exception;
	public void start() throws Exception;
	public void destroy() throws Exception;
	public void setConverter(IConverter converter);
	public ISender getSender();
	public IReceiver getReceiver();
}
