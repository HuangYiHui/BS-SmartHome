package bs.pi.gateway.assist;

import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.IOException;

public class Tool {
	
	private final static String HEX_STR = "0123456789ABCDEF";
	
	private static byte charsToByte(char highC, char lowC) throws Exception{
		highC = Character.toUpperCase(highC);
		lowC = Character.toUpperCase(lowC);
		if(HEX_STR.indexOf(highC) == -1 || HEX_STR.indexOf(lowC) == -1){
			throw new Exception("strToByte error");
		}
		byte high = (byte)((HEX_STR.indexOf(highC))<<4);
		byte low = (byte)HEX_STR.indexOf(lowC);
		byte result = (byte) (high|low);
		return result;
	}
	
	public static byte strToByte(String str) throws Exception{
		if(str.length() < 3 || str.length() > 4 || ! str.startsWith("0x"))
			throw new Exception("strToByte error");
		char c1 = Character.toUpperCase(str.charAt(2));
		if(HEX_STR.indexOf(c1) == -1){
			throw new Exception("strToByte error");
		}
		
		if(str.length() == 3){
			return charsToByte('0', c1);
		}else{
			char c2 = Character.toUpperCase(str.charAt(3));
			if(HEX_STR.indexOf(c2) == -1){
				throw new Exception("strToByte error");
			}
			return charsToByte(c1, c2);
		}
		
	}
	
	public static byte[] strToBytes(String str) throws Exception{
		if(str == null || str.length() < 3 || ! str.startsWith("0x")){
			throw new Exception("strToByte error");
		}
		char c1 = Character.toUpperCase(str.charAt(2));
		if(HEX_STR.indexOf(c1) == -1){
			throw new Exception("strToByte error");
		}
		
		String str1 = str.substring(2, str.length());
		int len = str1.length()/2;
		byte[] bytes = null;
		if(str1.length() % 2 == 0){
			bytes = new byte[len];
			for(int i=0; i<len; i++){
				char hc = str1.charAt(2*len-2*i-2);
				char lc = str1.charAt(2*len-2*i-1);
				bytes[i] = charsToByte(hc, lc);
			}
		}else{
			bytes = new byte[len+1];
			for(int i=0; i<len+1; i++){
				char hc = '0';
				if(2*len-2*i-1 > 0){
					hc = str1.charAt(2*len-2*i-1);
				}
				char lc = str1.charAt(2*len-2*i);
				System.out.println(hc+","+lc);
				bytes[i] = charsToByte(hc, lc);
			}
		}
		return bytes;
	}
	
	public static float bytesToFloat(byte[] valueBytes) throws Exception{
		if(valueBytes.length != 4)
			throw new Exception("bytesToFloat error");
		byte[] bs = new byte[4];
		bs[0] = valueBytes[3];
		bs[1] = valueBytes[2];
		bs[2] = valueBytes[1];
		bs[3] = valueBytes[0];
		
		DataInputStream dis=new DataInputStream(new ByteArrayInputStream(bs));
		float value = dis.readFloat();
		dis.close();
		
		return value;
	}
	
	public static byte[] intTo2Byte(int n){
		byte[] bs = new byte[2];
		bs[0] = (byte) (n % 256);
		bs[1] = (byte) (n / 256);
		return bs;
	}
	
	public static short bytesToShort(byte lowByte, byte HighByte){
		return (short)(((HighByte << 8) | lowByte & 0xff));
	}
	
	public static byte[] shortTo2Byte(short n){
		 byte[] shortBuf = new byte[2];
		  for(int i=0;i<2;i++) {
		     int offset = (shortBuf.length - 1 -i)*8;
		     shortBuf[1-i] = (byte)((n>>>offset)&0xff);
		  }
		  return shortBuf;
	}
	
	public static byte[] floatToBytes(float f){
		// 把float转换为byte[]  
	    int fbit = Float.floatToIntBits(f);  
	      
	    byte[] b = new byte[4];    
	    for (int i = 0; i < 4; i++) {    
	        b[i] = (byte) (fbit >> (24 - i * 8));    
	    }   
	      
	    // 翻转数组  
	    int len = b.length;  
	    // 建立一个与源数组元素类型相同的数组  
	    byte[] dest = new byte[len];  
	    // 为了防止修改源数组，将源数组拷贝一份副本  
	    System.arraycopy(b, 0, dest, 0, len);  
	    byte temp;  
	    // 将顺位第i个与倒数第i个交换  
	    for (int i = 0; i < len / 2; ++i) {  
	        temp = dest[i];  
	        dest[i] = dest[len - i - 1];  
	        dest[len - i - 1] = temp;  
	    }  
	      
	    return dest;  
	}
}
