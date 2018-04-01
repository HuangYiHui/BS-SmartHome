package bs.pi.gateway.client.zigbee;

import java.util.Arrays;

import com.test.Debugger;

//zigbee命令byte序列生成器
public class CodeGenerator {

	public final static byte SOF = (byte) 0xfe;
	public final static byte[] CMD_DEVICE_RESET = {SOF, 0x01, 0x41, 0x00, 0x00, 0x40};
	public final static byte[] CMD_BOOTLOADDER_RESET = {SOF, 0x01, 0x41, 0x00, 0x01, 0x41};
	public final static byte[] CMD_STARTUP_WITH_LAST_STATE = {SOF, 0x03, 0x26, 0x05, 0x03, 0x01, 0x00, 0x22};
	public final static byte[] CMD_STARTUP_WITHOUT_LAST_STATE = {SOF, 0x03, 0x26, 0x05, 0x03, 0x01, 0x03, 0x21};
	//当其他zigbee发出ZDO_IEEE_ADDR_RSP或ZDO_NWK_ADDR_RSP查询命令时，这条命令能是本zigbee发出回复，否则不回复
	public final static byte[] CMD_ZDO_DIRECT_CB = {SOF, 0x03, 0x26, 0x05, (byte) 0x8f, 0x01, 0x01, (byte) 0xaf};
	public final static byte[] CMD_STARTUP_FROM_APP = {SOF, 0x02, 0x25, 0x40, 0x00, 0x00, 0x67};
	
	private static byte calCrc(byte[] bs){
		byte result = 0;
		for(byte b : bs)
			result ^= b;
		return result;
	}
	
	public static byte[] chanlistCfg(byte[] channel){
		byte[] bs = new byte[11];
		bs[0] = SOF;
		bs[1] = 0x06;
		bs[2] = 0x26;
		bs[3] = 0x05;
		bs[4] = (byte) 0x84;
		bs[5] = 0x04;
		bs[6] = channel[0]; 
		bs[7] = channel[1];
		bs[8] = channel[2];
		bs[9] = channel[3];
		bs[10] = calCrc(Arrays.copyOfRange(bs, 1, bs.length-1));
		return bs;
	}
	
	public static byte[] PANIDCfg(byte[] panid){
		byte[] bs = new byte[9];
		bs[0] = SOF;
		bs[1] = 0x04;
		bs[2] = 0x26;
		bs[3] = 0x05;
		bs[4] = (byte) 0x83;
		bs[5] = 0x02;
		bs[6] = panid[0];
		bs[7] = panid[1];
		bs[8] = calCrc(Arrays.copyOfRange(bs, 1, bs.length-1));
		return bs;
	}
	
	public static byte[] deviceTypeCfg(byte type)
	{
		byte[] bs = new byte[8];
		bs[0] = SOF;
		bs[1] = 0x03;
		bs[2] = 0x26;
		bs[3] = 0x05;
		bs[4] = (byte) 0x87;
		bs[5] = 0x01;
		bs[6] = type;
		bs[7] = calCrc(Arrays.copyOfRange(bs, 1, bs.length-1));
		return bs;
	}
	
	public static byte[] appRegister(ZigbeeAppReg reg)
	{
		int bsLength = 14 + reg.getAppNumInClusters()*2 + reg.getAppNumOutClusters()*2;
		byte[] bs = new byte[bsLength];
		bs[0] = SOF;
		bs[1] = (byte) (0x09 + reg.getAppNumInClusters()*2 + reg.getAppNumOutClusters()*2);
		bs[2] = 0x24;
		bs[3] = 0x00;
		bs[4] = reg.getEndpoint();
		bs[5] = reg.getAppProfID()[0];
		bs[6] = reg.getAppProfID()[1];
		bs[7] = reg.getAppDeviceID()[0];
		bs[8] = reg.getAppDeviceID()[1];
		bs[9] = reg.getEndDevVer();
		bs[10] = reg.getLatencyReq();
		bs[11] = reg.getAppNumInClusters();
		byte[] bs1 = reg.getAppInClusterListBytes();
		if(bs1 != null && bs1.length > 0)
			System.arraycopy(bs1, 0, bs, 12, bs1.length);
		int index = 12 + bs1.length;
		bs[index] = reg.getAppNumOutClusters();
		index++;
		byte[] bs2 = reg.getAppOutClusterListBytes();
		if(bs2 != null && bs2.length > 0)
			System.arraycopy(bs2, 0, bs, index, bs2.length);
		bs[bs.length-1] = calCrc(Arrays.copyOfRange(bs, 1, bs.length-1));
		return bs;
	}
	
	public static byte[] packetSend(ZigbeeMsgSend packet)
	{
		byte[] bs = new byte[15 + packet.getData().length];
		bs[0] = SOF;
		bs[1] = (byte) (10 + packet.getData().length);
		bs[2] = 0x24;
		bs[3] = 0x01;
		bs[4] = packet.getDstAddr()[0];
		bs[5] = packet.getDstAddr()[1];
		bs[6] = packet.getDstEndpoint();
		bs[7] = packet.getSrcEndpoint();
		bs[8] = packet.getClusterID()[0];
		bs[9] = packet.getClusterID()[1];
		bs[10] = packet.getTransID();
		bs[11] = packet.getOptions();
		bs[12] = packet.getRadius();
		bs[13] = (byte) packet.getData().length;
		System.arraycopy(packet.getData(), 0, bs, 14, packet.getData().length);
		bs[bs.length-1] = calCrc(Arrays.copyOfRange(bs, 1, bs.length-1));
		
		Debugger.printBytes(bs);
		
		return bs;
	}
	
	public static byte[] networkAddrReuqest(byte[] IEEEAddr){
		byte[] bs = new byte[15];
		bs[0] = SOF;
		bs[1] = 0x0a;
		bs[2] = 0x25;
		bs[3] = 0x00;
		System.arraycopy(IEEEAddr, 0, bs, 4, 8);
		bs[12] = 0x00;
		bs[13] = 0x00;
		bs[14] = calCrc(Arrays.copyOfRange(bs, 1, bs.length-1));
		return bs;
	}
}
