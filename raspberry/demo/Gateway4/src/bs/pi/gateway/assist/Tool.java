package bs.pi.gateway.assist;

import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.IOException;

public class Tool {
	
	public static byte[] strToBytes(String str){
		String hexStr = "0123456789ABCDEF";
		//hexString的长度对2取整，作为bytes的长度
		int len = str.length()/2;
		byte[] bytes = new byte[len];   
		byte high = 0;//字节高四位
		byte low = 0;//字节低四位

		for(int i=0;i<len;i++){
			//右移四位得到高位
			char highC = Character.toUpperCase(str.charAt(2*i));
			high = (byte)((hexStr.indexOf(highC))<<4);
			char lowC = Character.toUpperCase(str.charAt(2*i+1));
			low = (byte)hexStr.indexOf(lowC);
			bytes[i] = (byte) (high|low);//高地位做或运算
		}
		return bytes;
	}
	
	public static float bytesToFloat(byte[] valueBytes) throws Exception{
		if(valueBytes.length != 4)
			throw new Exception("bytesToFloat error");
		
		DataInputStream dis=new DataInputStream(new ByteArrayInputStream(valueBytes));
		float value = dis.readFloat();
		dis.close();
		
		return value;
	}
}
