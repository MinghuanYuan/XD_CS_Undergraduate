package mytest04;

import java.io.*;
import java.rmi.RMISecurityException;
import java.util.*;

public class MyTest04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println("��ӭ����ͳ��ϵͳ");
		Scanner scanner = new Scanner(System.in);
		System.out.println("�������ͳ���ļ��ľ���·��");
		Count count = new Count();
		try {
			boolean mark = count.theFileToRead(scanner.nextLine());
			if(mark) {
				count.openInStream();
				count.alphabetread();
				count.wordread();
				System.out.println("��ѡ�����������ʽ"+"���������̨��ѡ��1"+"������ļ���ѡ��2");
				switch(scanner.nextInt()) {
				case 1 :
					count.printAlphabetToConsole();
					count.printWordToConsole();
//					count.openOutStream();//Ϊ�˱���finally����
					break;
				case 2 :
					System.out.println("�������д���ļ��ľ���·��");
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
				System.out.println("�ļ�������");
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
			System.out.println("����ִ����ɣ�����");
		}
	}
}
