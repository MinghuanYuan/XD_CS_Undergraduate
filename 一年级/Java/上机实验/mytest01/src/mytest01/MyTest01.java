package mytest01;
import java.util.Calendar;
import java.util.Scanner;

public class MyTest01 {
	static public void main(String args[]) {
		Calendar c = Calendar.getInstance();
		Scanner scanner = new Scanner(System.in);
		System.out.println("输入的年份输出该年日历请输入1" + 
				"输入日期，输出该天星期请输入2");
		int choice = scanner.nextInt();
		if(choice==1) {
			System.out.println("请问您需要哪一年的日历？（请直接输入四位年份）");
			int year = scanner.nextInt();
			c.set(year, Calendar.JANUARY, 1);
			while(c.get(Calendar.YEAR)==year) {
				if(c.get(Calendar.DATE)==1) {
					System.out.println();
					System.out.println("第"+(c.get(Calendar.MONTH)+1)+"月");
					System.out.println("日\t一\t二\t三\t四\t五\t六");
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
			System.out.println("请输入想要查询的日期，格式为yyyy mm dd，注意需要加空格！！！");
			int year = scanner.nextInt();
			int month = scanner.nextInt();
			int day = scanner.nextInt();
			c.set(c.YEAR,year);
			c.set(c.MONTH,month-1);
			c.set(c.DATE,day);
			if(c.get(Calendar.DAY_OF_WEEK)==1) {
				System.out.println("这天是星期日");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==2) {
				System.out.println("这天是星期一");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==3) {
				System.out.println("这天是星期二");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==4) {
				System.out.println("这天是星期三");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==5) {
				System.out.println("这天是星期四");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==6) {
				System.out.println("这天是星期五");
			}
			if(c.get(Calendar.DAY_OF_WEEK)==7) {
				System.out.println("这天是星期六");
			}
		}
		
		
	}
}
