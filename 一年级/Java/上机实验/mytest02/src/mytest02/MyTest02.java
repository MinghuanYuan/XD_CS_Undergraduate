package mytest02;
import java.util.*;

public class MyTest02 {

	public static void main(String[] args) {

		// TODO Auto-generated method stub
		List<Shape> shape = new ArrayList<>();
		while(true) {
			System.out.println("����1����ʾ����һ������"
					+ "����2����ʾ����һ��Բ"
					+ "����3����ʾ����һ��������"
					+ "����4����ʾ��������");
			Scanner scanner = new Scanner(System.in);
			int choice = scanner.nextInt();
			if(choice==1) {
				System.out.println("��Ը�ͼ������");
				String name = scanner.next();
				Rectangle rectangle = new Rectangle();
				rectangle.modifyname(name);
				shape.add(rectangle);
			}
			else if(choice==2) {
				System.out.println("��Ը�ͼ������");
				String name = scanner.next();
				Circle circle = new Circle();
				circle.modifyname(name);
				shape.add(circle);
			}
			else if(choice==3) {
				System.out.println("��Ը�ͼ������");
				String name = scanner.next();
				Triangle triangle = new Triangle();
				triangle.modifyname(name);
				shape.add(triangle);
			}
			else if(choice==4) {
				break;
			}
			else{
				System.out.println("������������������");
				continue;
			}	
		}
			
			while(true){
				System.out.println("����1��ʾ��������"
						+"����2��ʾ���ƹ���"
						+"����3��ʾ����");
				Scanner scanner = new Scanner(System.in);
				int choice = scanner.nextInt();
				if(choice==1) {
					System.out.println("������Ҫ����������");
					String name = scanner.next();
					for(int i=0;i<shape.size();i++) {
						Shape needcheck = shape.get(i);
						if((needcheck.getName()).equals(name)) {
							System.out.println(StaticCheck.checktype(needcheck));
							System.out.println(shape.indexOf(needcheck)+1);
							break;
						}
						else if(i<shape.size()-1) {
							continue;
						}
						else {
							System.out.println("û�и����Ƶ�ͼ��");
						}
					}
				}
				else if(choice==2) {
					System.out.println("�Ѿ�����"+shape.size()+"��ͼ��");
					System.out.println("������Ҫ��ѯ������");
					int number = scanner.nextInt();
					for(int i=0;i<number;i++) {
						Shape needprint = shape.get(i);
						needprint.print();
						System.out.println(shape.indexOf(needprint)+1);
						System.out.println(needprint.getName());
					}
				}
				else if(choice==3) {
					break;
				}
				else {
					System.out.println("������������������");
				}
			}
	}
}
