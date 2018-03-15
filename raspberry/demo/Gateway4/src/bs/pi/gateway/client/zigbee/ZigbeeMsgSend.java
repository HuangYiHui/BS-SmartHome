package bs.pi.gateway.client.zigbee;

public class ZigbeeMsgSend {

	public final static byte[] CMD_TEST_CMD = {0x12, 0x34};
	
	private byte[] dstAddr = new byte[2];
	private byte dstEndpoint;
	private byte srcEndpoint;
	private byte[] clusterID = new byte[2];
	private byte transID;
	private byte options;
	private byte radius;
	private byte[] data = new byte[0];

	public byte[] getDstAddr() {
		
		return dstAddr;
	}

	public void setDstAddr(byte[] dstAddr) {
		if(dstAddr != null)
			this.dstAddr = dstAddr.clone();
	}

	public byte getDstEndpoint() {
		return dstEndpoint;
	}

	public void setDstEndpoint(byte dstEndpoint) {
		this.dstEndpoint = dstEndpoint;
	}

	public byte getSrcEndpoint() {
		return srcEndpoint;
	}

	public void setSrcEndpoint(byte srcEndpoint) {
		this.srcEndpoint = srcEndpoint;
	}

	public byte[] getClusterID() {
		if(clusterID == null)
			return null;
		else
			return clusterID.clone();
	}

	public void setClusterID(byte[] clusterID) {
		if(clusterID != null)
			this.clusterID = clusterID.clone();
	}

	public byte getTransID() {
		return transID;
	}

	public void setTransID(byte transID) {
		this.transID = transID;
	}

	public byte getOptions() {
		return options;
	}

	public void setOptions(byte options) {
		this.options = options;
	}

	public byte getRadius() {
		return radius;
	}

	public void setRadius(byte radius) {
		this.radius = radius;
	}

	public byte[] getData() {
		if(data == null)
			return null;
		else
			return data.clone();
	}

	public void setData(byte[] data) {
		if(data != null)
			this.data = data.clone();
	}
}
