package mytest03;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

import org.omg.CORBA.PUBLIC_MEMBER;

public class MyTest03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scanner = new Scanner(System.in);
		List<Notepad> notepad = new ArrayList<>();
		while(true) {
			System.out.println("��ѡ������Ҫ�Ĺ��ܣ�"
					+"1���һ������¼"
					+"2�鿴����¼����"
					+"3�鿴ĳһ������¼"
					+"4�鿴���б���¼"
					+"5ɾ��ĳһ������¼"
					+"6ɾ�����б���¼"
					+"7�˳�����");
			int choice = scanner.nextInt();
			scanner.nextLine();
			if(choice==1) {
				Notepad tempnotepad = new Notepad();
				System.out.println("�����뱸��¼����");
				String content = scanner.nextLine();
				tempnotepad.setContent(content);
				System.out.println("�������������");
				String describe = scanner.nextLine();
				tempnotepad.setDescribe(describe);
				notepad.add(tempnotepad);
			}
			else if(choice==2) {
				System.out.println("�ñ���¼����"+notepad.size()+"��");
			}
			else if(choice==3) {
				System.out.println("��������鿴����¼�ı��");
				int number = scanner.nextInt();
				Notepad tempnotepad = notepad.get(number-1);
				System.out.println("�ñ���¼������Ϊ��"+tempnotepad.getContent());
				System.out.println("�ñ���¼������Ϊ��"+tempnotepad.getDescribe());
				System.out.print("�ñ���¼�Ĵ���ʱ��Ϊ��");
				tempnotepad.getMoment();
			}
			else if(choice==4) {
				Iterator<Notepad> iterator = notepad.iterator();
				int i = 0;
				while(iterator.hasNext()) {
					i++;
					Notepad tempnotepad = iterator.next();
					System.out.println("��"+i+"������¼��");
					System.out.println("����¼������Ϊ��"+tempnotepad.getContent());
					System.out.println("����¼������Ϊ��"+tempnotepad.getDescribe());
					System.out.print("����¼�Ĵ���ʱ��Ϊ��");
					tempnotepad.getMoment();
				}
			}
			else if(choice==5) {
				System.out.println("�������ɾ������¼�ı��");
				int number = scanner.nextInt();
				notepad.remove(number-1);
				System.out.println("�ñ���¼��ɾ����");
			}
			else if(choice==6) {
				notepad.clear();
				System.out.println("���б���¼��ɾ����");
			}
			else if(choice==7)break;
			else {
				System.out.println("�����������������룡");
			}
		}
		
	}

}
