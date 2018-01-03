package com.builder.font16;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class Font16Builder {
	
	private static final char[] HEX_CHAR = {'0', '1', '2', '3', '4', '5', 
        '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	private static final String ascFontCodeFilePath = "/res/asc16";
	private static final String chineseFontCodeFilePath = "/res/hzk16";
	
	
	/*
	 * 对于16*16的显示格式，英文点阵是16*8，中文点阵是16*16
	 * 对于返回结果，英文是2*8的数组，中文是2*16的数组
	 */
	public static byte[][] getCode(char c){
		if(c < 0xff)
			return getAscCode(c);
		else
			return getChineseCode(c);
	}
	
	public static byte[][] getAscCode(char c){
		byte[] codes = readAscRawCode(c);
		byte[][] res = new byte[2][8];
		
		byte[] codes0 = new byte[8];
		for(int i=0;i<8;i++){
			codes0[i] = codes[i];
		}
		
		byte[] codes1 = new byte[8];
		for(int i=8;i<16;i++){
			codes1[i-8] = codes[i];
		}
		res[0] = getRowsCode(codes0);
		res[1] = getRowsCode(codes1);
		
		return res;
	}
	
	public static byte[][] getChineseCode(char c){
		byte[] codes = readChineseRawCode(c);
		byte[][] tempRes = new byte[4][8];
		byte[][] res = new byte[2][16];
		
		
		byte[] codes0 = new byte[8];
		for(int i=0;i<8;i++){
			codes0[i] = codes[i*2];
		}
		
		byte[] codes1 = new byte[8];
		for(int i=0;i<8;i++){
			codes1[i] = codes[i*2+1];
		}
		
		byte[] codes2 = new byte[8];
		for(int i=0;i<8;i++){
			codes2[i] = codes[i*2+16];
		}
		
		byte[] codes3 = new byte[8];
		for(int i=0;i<8;i++){
			codes3[i] = codes[i*2+17];
		}
		
		tempRes[0] = getRowsCode(codes0);
		tempRes[1] = getRowsCode(codes1);
		tempRes[2] = getRowsCode(codes2);
		tempRes[3] = getRowsCode(codes3);
		
		for(int i=0;i<8;i++){
			res[0][i] = tempRes[0][i];
			res[0][i+8] = tempRes[1][i];
			res[1][i] = tempRes[2][i];
			res[1][i+8] = tempRes[3][i];
		}
		
		return res;
	}
	//获取8*8字体点阵第所有列的编码
	private static byte[] getRowsCode(byte[] codes){
		byte[] res = new byte[8];
		
		for(int i=0;i<8;i++){
			res[i] = getColCode(codes, i);
		}
		
		return res;
	}
	
	//获取8*8字体点阵第j列的编码
	public static byte getColCode(byte[] codes, int j){
		byte res = 0;
		for(int i=0; i<8; i++){
			byte bit = (byte) ((codes[i] >> (7 - j)) & 0x1);
			res += Math.pow(2, i) * bit;
		}
		return res;
	}
	
	//从英文字库中读取英文显示码
	public static byte[] readAscRawCode(char c) {
        byte[] code = null;
        int ascii = (int) c;
        try {
        	code = new byte[16];//定义缓存区大小
        	String path = (new File("")).getCanonicalPath()+ascFontCodeFilePath;
            InputStream in = new FileInputStream(new File(path));
            long offset = (ascii) * 16;
            in.skip(offset);
            in.read(code, 0, 16);	//英文字体用8*16，中文用16*16
            in.close();
        } catch (Exception e) {
            System.err.println("SORRY,THE FILE CAN'T BE READ");
        }
        return code;
    }
	
	//从中文字库中读取中文显示码
	public static byte[] readChineseRawCode(char c) {
		int[] pacode = getByteCode(c);
		int areaCode = pacode[0];
		int posCode = pacode[1];
        byte[] data = null;
        try {
            int area = areaCode - 0xa0;//区码
            int pos = posCode - 0xa0;//位码
            String path = (new File("")).getCanonicalPath()+chineseFontCodeFilePath;
            InputStream in = new FileInputStream(new File(path));
            long offset = 32 * ((area - 1) * 94 + pos - 1);//偏移量
            in.skip(offset);
            data = new byte[32];
            in.read(data, 0, 32);
            in.close();
        } catch (Exception ex) {
            System.err.println("SORRY,THE FILE CAN'T BE READ");
        }
        return data;

    }
	
	private static int[] getByteCode(char c) {
        int[] byteCode = new int[2];
        String str = ""+c;
        try {
            byte[] data = str.getBytes("GBK");
            byteCode[0] = data[0] < 0 ? 256 + data[0] : data[0];
            byteCode[1] = data[1] < 0 ? 256 + data[1] : data[1];
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return byteCode;
    }
	
	public static String bytesToHex(byte[] bytes) {
        // 一个byte为8位，可用两个十六进制位标识
        char[] buf = new char[bytes.length * 5];
        int a = 0;
        int index = 0;
        for(byte b : bytes) { // 使用除与取余进行转换
            if(b < 0) {
                a = 256 + b;
            } else {
                a = b;
            }

            buf[index++] = '0';
            buf[index++] = 'x';
            buf[index++] = HEX_CHAR[a / 16];
            buf[index++] = HEX_CHAR[a % 16];
            buf[index++] = ',';
        }

        return new String(buf);
    }
	
	//打印英文显示编码点阵
	public static void printAscRawCode(byte data[]){
		int byteCount = 0;
        for (int line = 0; line < 16; line++) {
            for (int j = 0; j < 8; j++) {
                if (((data[byteCount] >> (7 - j)) & 0x1) == 1) {
                    System.out.print("●");
                } else {
                    System.out.print("○");
                }
            }
            byteCount++;
            System.out.println();
        }
	}
	
	//打印中文显示编码点阵
	public static void printChineseRawCode(byte data[]){
		int byteCount = 0;
		for (int line = 0; line < 16; line++) {
            for (int k = 0; k < 2; k++) {
                for (int j = 0; j < 8; j++) {
                    if (((data[byteCount] >> (7 - j)) & 0x1) == 1) {
                        System.out.print("●");
                    } else {
                        System.out.print("○");
                    }
                }
                byteCount++;
            }
            System.out.println();
        }
	}
}
