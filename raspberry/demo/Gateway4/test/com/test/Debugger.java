package com.test;
import java.util.HashMap;
import java.util.Map;


public class Debugger {

	public static void printHashMap(HashMap<String, Object> msg){
		if(msg == null){
			System.out.println("printHashMap params null");
			return;
		}
		System.out.println("HashMap:");
		for(Map.Entry<String, Object> entry : msg.entrySet()){
			System.out.println(entry.getKey()+" : "+entry.getValue());
		}
	}
	
	public static void println(String str){
		System.out.println(str);
	}
	
	public static void print(String str){
		System.out.print(str);
	}
	
	public static void printBytes(byte[] bs){
		for(byte b : bs)
			System.out.printf("%x,", b);
		System.out.println();
	}
}
