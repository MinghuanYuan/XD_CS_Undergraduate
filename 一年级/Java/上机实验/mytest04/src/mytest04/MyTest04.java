package mytest04;

import java.io.*;
import java.rmi.RMISecurityException;
import java.util.*;

public class MyTest04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println("欢迎来到统计系统");
		Scanner scanner = new Scanner(System.in);
		System.out.println("请输入待统计文件的绝对路径");
		Count count = new Count();
		try {
			boolean mark = count.theFileToRead(scanner.nextLine());
			if(mark) {
				count.openInStream();
				count.alphabetread();
				count.wordread();
				System.out.println("请选择结果的输出方式"+"输出至控制台请选择1"+"输出到文件请选择2");
				switch(scanner.nextInt()) {
				case 1 :
					count.printAlphabetToConsole();
					count.printWordToConsole();
//					count.openOutStream();//为了避免finally报错
					break;
				case 2 :
					System.out.println("请输入待写入文件的绝对路径");
					scanner.nextLine();
					count.theFileToWrite(scanner.nextLine());
					count.openOutStream();
					count.printAlphabetToFile();
					count.printWordToFile();
					break;
				default:
					
				}
			}
			else {
				System.out.println("文件不存在");
			}
		}
		catch (IOException e) {
			System.err.println("IOException");
			System.err.println(e.getMessage());
			e.printStackTrace();
		}
		catch (Exception e) {
			System.err.println("Exception");
			System.err.println(e.getMessage());
			e.printStackTrace();
		}
		finally {
			try{
				count.closeInStream();
				count.closeOutStream();
			}
			catch (Exception e) {
				System.err.println("Finally Exception");
				System.err.println(e.getMessage());
				e.printStackTrace();
			}
			System.out.println("程序执行完成！！！");
		}
	}
}
