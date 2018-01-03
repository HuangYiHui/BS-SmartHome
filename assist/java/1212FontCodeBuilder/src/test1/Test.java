package test1;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class Test {

	private static final char[] HEX_CHAR = {'0', '1', '2', '3', '4', '5', 
        '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    private byte[][] arr;//返回的二维数组
    private String path;
    
    public static void main(String[] args) throws IOException {
		Test test = new Test();
	}
    
    public Test() throws IOException{
    	
    	path = (new File("")).getCanonicalPath();
    	drawString("基");
    	printHexs();//打印nokia5110显示码
    }
    
    public String bytesToHex(byte[] bytes) {
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
    
    public void printHexs(){
    	byte mydata[] = new byte[24];
    	for(int i=0;i<12;i++){
    		byte b = (byte) ((arr[0][i]*0x10)+
    					(arr[1][i]*0x02)+
    					(arr[2][i]*0x04)+
    					(arr[3][i]*0x08)+
    					(arr[4][i]*0x10)+
    					(arr[5][i]*0x20)+
    					(arr[6][i]*0x40)+
    					(arr[7][i]*0x80));
    		mydata[i] = b;
    	}
    	
    	for(int i=0;i<12;i++){
    		byte b = (byte) ((arr[0+8][i]*0x01)+
    					(arr[1+8][i]*0x02)+
    					(arr[2+8][i]*0x04)+
    					(arr[3+8][i]*0x08)+
    					(arr[4+8][i]*0x10)+
    					(arr[5+8][i]*0x20)+
    					(arr[6+8][i]*0x40)+
    					(arr[7+8][i]*0x80));
    		mydata[12+i] = b;
    	}
    	System.out.println(bytesToHex(mydata));
    }
    public void drawString(String str) {
        byte[] data = null;
        int byteCount;
        byteCount = 0;
        arr = new byte[16][12];
        if (str.charAt(0) < 0xff) {
        	data = read(str.charAt(0));
        	
            for (int line = 0; line < 12; line++) {
                
                for (int j = 0; j < 8; j++) {
                    if (((data[byteCount] >> (7 - j)) & 0x1) == 1) {
                        System.out.print("●");
                        arr[line][j] = 1;
                    } else {
                        System.out.print("○");
                        arr[line][j] = 0;
                    }
                }
                byteCount++;
                System.out.println();
            }
        }else{
        	int[] code = getByteCode(str);
        	data = read(code[0], code[1]);
			for (int line = 0; line < 12; line++) {
                for (int j = 0; j < 8; j++) {
                    if (((data[byteCount] >> (7 - j)) & 0x1) == 1) {
                        System.out.print("●");
                        arr[line][j] = 1;
                    } else {
                        System.out.print("○");
                        arr[line][j] = 0;
                    }
                }
                byteCount++;
                for (int j = 0; j < 4; j++) {
                    if (((data[byteCount] >> (7 - j)) & 0x1) == 1) {
                        System.out.print("●");
                        arr[line][8+j] = 1;
                    } else {
                        System.out.print("○");
                        arr[line][8+j] = 0;
                    }
                }
                byteCount++;
                System.out.println();
            }
        }
    }
    
    protected byte[] read(char char_) {
        byte[] data = null;
        int ascii = (int) char_;
        try {
            data = new byte[12];//定义缓存区大小
            //InputStream in = getResources().openRawResource(R.raw.asc16);//打开字库
            File file = new File(path+"res/ASC12");
            InputStream in = new FileInputStream(file);
            long offset = (ascii) * 12;//asii码在字库里的偏移量
            in.skip(offset);
            in.read(data, 0, 12);
            in.close();

        } catch (Exception e) {
            System.err.println("SORRY,THE FILE CAN'T BE READ");
        }
        return data;
    }
    
    protected byte[] read(int areaCode, int posCode) {
        byte[] data = null;
        try {
            int area = areaCode - 0xa0;//区码
            int pos = posCode - 0xa0;//位码
            //InputStream in = getResources().openRawResource(R.raw.hzk16);//读取中文库
            // InputStream in1=getResources().getAssets().open("hzk16");
            File file = new File(path+"/res/Hzk12.bin");
            
            InputStream in = new FileInputStream(file);
            long offset = 24 * ((area - 1) * 94 + pos - 1);//偏移量
            in.skip(offset);
            data = new byte[24];
            in.read(data, 0, 24);
            in.close();
        } catch (Exception ex) {
            System.err.println("SORRY,THE FILE CAN'T BE READ");
        }
        return data;

    }
    
    /**
     * 获取汉字的区，位（ascii码不需要区码，位码）
     *
     * @param str
     * @return
     */
    protected int[] getByteCode(String str) {
        int[] byteCode = new int[2];
        try {
            byte[] data = str.getBytes("GBK");
            byteCode[0] = data[0] < 0 ? 256 + data[0] : data[0];
            byteCode[1] = data[1] < 0 ? 256 + data[1] : data[1];
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return byteCode;
    }
}

