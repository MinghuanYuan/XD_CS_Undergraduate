package mytest01;
import java.util.Calendar;
import java.util.Scanner;

public class MyTest01 {
	static public void main(String args[]) {
		Calendar c = Calendar.getInstance();
		Scanner scanner = new Scanner(System.in);
		System.out.println("�������������������������1" + 
				"�������ڣ������������������2");
		int choice = scanner.nextInt();
		if(choice==1) {
			System.out.println("��������Ҫ��һ�������������ֱ��������λ��ݣ�");
			int year = scanner.nextInt();
			c.set(year, Calendar.JANUARY, 1);
			while(c.get(Calendar.YEAR)==year) {
				if(c.get(Calendar.DATE)==1) {
					System.out.println();
					System.out.println("��"+(c.get(Calendar.MONTH)+1)+"��");
					System.out.println("��\tһ\t��\t��\t��\t��\t��");
					for(int j=0;j<c.get(Calendar.DAY_OF_WEEK)-1;j++) {
						System.out.print("\t");
					}
				}
				System.out.print(c.get(Calendar.DATE)+"\t");
				if(c.get(Calendar.DAY_OF_WEEK)==7) {
					System.out.println();
				}
				c.add(Calendar.DATE, 1);
			}
			
		}
		if(choice==2) {
			System.out.println("��������Ҫ��ѯ�����ڣ���ʽΪyyyy mm dd��ע����Ҫ�ӿո񣡣���");
			int year = scanner.nextInt();
			int month = scanner.nextInt();
			int day = scanner.nextInt();
			c.set(c.YEAR,year);
			c.set(c.MONTH,month-1);
			c.set(c.DATE,day);
			if(c.get(Calendar.DAY_OF_WEEK)==1) {
				System.out.println("������������");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==2) {
				System.out.println("����������һ");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==3) {
				System.out.println("���������ڶ�");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==4) {
				System.out.println("������������");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==5) {
				System.out.println("������������");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==6) {
				System.out.println("������������");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==7) {
				System.out.println("������������");
			}
		}
		
		
	}
}
