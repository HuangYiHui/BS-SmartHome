import com.builder.font16.Font16Builder;


public class Test {

	public static void main(String[] args) {
		//���Ĳ���
		byte[] bs0 = Font16Builder.readChineseRawCode('��');
		Font16Builder.printChineseRawCode(bs0);
		
		byte[][] res0 = Font16Builder.getCode('��');
		System.out.println(Font16Builder.bytesToHex(res0[0]));
		System.out.println(Font16Builder.bytesToHex(res0[1]));
		
		//Ӣ�Ĳ���
		byte[] bs1 = Font16Builder.readAscRawCode('B');
		Font16Builder.printAscRawCode(bs1);
		
		byte[][] res1 = Font16Builder.getCode('B');
		System.out.println(Font16Builder.bytesToHex(res1[0]));
		System.out.println(Font16Builder.bytesToHex(res1[1]));
	}
}
