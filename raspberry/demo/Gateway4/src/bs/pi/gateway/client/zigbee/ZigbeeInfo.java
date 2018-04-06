package bs.pi.gateway.client.zigbee;

import java.util.ArrayList;

public class ZigbeeInfo {
	
	private byte[] IEEEAddr;
	private byte[] NWKAddr;
	private ArrayList<Byte> appIDList;
	
	public ZigbeeInfo(){
		
	}
	
	public ZigbeeInfo(byte[] IEEEAddr, byte[] NWKAddr, ArrayList<Byte> appIDList){
		if(IEEEAddr != null)
			this.IEEEAddr = IEEEAddr.clone();
		if(NWKAddr != null)
			this.NWKAddr = NWKAddr.clone();
		if(appIDList != null)
			this.appIDList = (ArrayList<Byte>) appIDList.clone();
	}
	
	public byte[] getIEEEAddr() {
		if(IEEEAddr == null)
			return null;
		else
			return IEEEAddr.clone();
	}
	public void setIEEEAddr(byte[] IEEEAddr) {
		if(IEEEAddr != null)
			this.IEEEAddr = IEEEAddr.clone();
	}
	public byte[] getNWKAddr() {
		if(NWKAddr == null)
			return null;
		else
			return NWKAddr.clone();
	}
	public void setNWKAddr(byte[] NWKAddr) {
		if(NWKAddr != null)
			this.NWKAddr = NWKAddr.clone();
	}
	public ArrayList<Byte> getAppIDList() {
		return appIDList;
	}
	public void setAppIDList(ArrayList<Byte> appIDList) {
		if(appIDList != null)
			this.appIDList = (ArrayList<Byte>) appIDList.clone();
	}
}
