package mytest02;
import java.util.*;

public class MyTest02 {

	public static void main(String[] args) {

		// TODO Auto-generated method stub
		List<Shape> shape = new ArrayList<>();
		while(true) {
			System.out.println("输入1，表示创建一个矩形"
					+ "输入2，表示创建一个圆"
					+ "输入3，表示创建一个三角形"
					+ "输入4，表示结束创建");
			Scanner scanner = new Scanner(System.in);
			int choice = scanner.nextInt();
			if(choice==1) {
				System.out.println("请对该图形命名");
				String name = scanner.next();
				Rectangle rectangle = new Rectangle();
				rectangle.modifyname(name);
				shape.add(rectangle);
			}
			else if(choice==2) {
				System.out.println("请对该图形命名");
				String name = scanner.next();
				Circle circle = new Circle();
				circle.modifyname(name);
				shape.add(circle);
			}
			else if(choice==3) {
				System.out.println("请对该图形命名");
				String name = scanner.next();
				Triangle triangle = new Triangle();
				triangle.modifyname(name);
				shape.add(triangle);
			}
			else if(choice==4) {
				break;
			}
			else{
				System.out.println("输入有误，请重新输入");
				continue;
			}	
		}
			
			while(true){
				System.out.println("输入1表示检索功能"
						+"输入2表示绘制功能"
						+"输入3表示结束");
				Scanner scanner = new Scanner(System.in);
				int choice = scanner.nextInt();
				if(choice==1) {
					System.out.println("请输入要检索的名称");
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
							System.out.println("没有该名称的图形");
						}
					}
				}
				else if(choice==2) {
					System.out.println("已经创建"+shape.size()+"个图形");
					System.out.println("请输入要查询的数量");
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
					System.out.println("输入有误，请重新输入");
				}
			}
	}
}
