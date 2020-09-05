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
			System.out.println("请选择您需要的功能："
					+"1添加一条备忘录"
					+"2查看备忘录数量"
					+"3查看某一条备忘录"
					+"4查看所有备忘录"
					+"5删除某一条备忘录"
					+"6删除所有备忘录"
					+"7退出程序");
			int choice = scanner.nextInt();
			scanner.nextLine();
			if(choice==1) {
				Notepad tempnotepad = new Notepad();
				System.out.println("请输入备忘录内容");
				String content = scanner.nextLine();
				tempnotepad.setContent(content);
				System.out.println("请输入相关描述");
				String describe = scanner.nextLine();
				tempnotepad.setDescribe(describe);
				notepad.add(tempnotepad);
			}
			else if(choice==2) {
				System.out.println("该备忘录共有"+notepad.size()+"条");
			}
			else if(choice==3) {
				System.out.println("请输入待查看备忘录的编号");
				int number = scanner.nextInt();
				Notepad tempnotepad = notepad.get(number-1);
				System.out.println("该备忘录的内容为："+tempnotepad.getContent());
				System.out.println("该备忘录的描述为："+tempnotepad.getDescribe());
				System.out.print("该备忘录的创建时间为：");
				tempnotepad.getMoment();
			}
			else if(choice==4) {
				Iterator<Notepad> iterator = notepad.iterator();
				int i = 0;
				while(iterator.hasNext()) {
					i++;
					Notepad tempnotepad = iterator.next();
					System.out.println("第"+i+"条备忘录：");
					System.out.println("备忘录的内容为："+tempnotepad.getContent());
					System.out.println("备忘录的描述为："+tempnotepad.getDescribe());
					System.out.print("备忘录的创建时间为：");
					tempnotepad.getMoment();
				}
			}
			else if(choice==5) {
				System.out.println("请输入待删除备忘录的编号");
				int number = scanner.nextInt();
				notepad.remove(number-1);
				System.out.println("该备忘录已删除！");
			}
			else if(choice==6) {
				notepad.clear();
				System.out.println("所有备忘录已删除！");
			}
			else if(choice==7)break;
			else {
				System.out.println("输入有误，请重新输入！");
			}
		}
		
	}

}
