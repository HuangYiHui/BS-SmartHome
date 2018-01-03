import com.builder.font16.Font16Builder;


public class Test {

	public static void main(String[] args) {
		//÷–Œƒ≤‚ ‘
		byte[] bs0 = Font16Builder.readChineseRawCode('¿Ë');
		Font16Builder.printChineseRawCode(bs0);
		
		byte[][] res0 = Font16Builder.getCode('¿Ë');
		System.out.println(Font16Builder.bytesToHex(res0[0]));
		System.out.println(Font16Builder.bytesToHex(res0[1]));
		
		//”¢Œƒ≤‚ ‘
		byte[] bs1 = Font16Builder.readAscRawCode('B');
		Font16Builder.printAscRawCode(bs1);
		
		byte[][] res1 = Font16Builder.getCode('B');
		System.out.println(Font16Builder.bytesToHex(res1[0]));
		System.out.println(Font16Builder.bytesToHex(res1[1]));
	}
}
