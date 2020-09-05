package mytest05;

import java.util.Scanner;

public class MyTest05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		System.out.println("请输入出票数量");
		Ticket ticket = new Ticket();
		ticket.setCount(scanner.nextInt());
		new Thread(ticket, "窗口一").start();
		new Thread(ticket, "窗口二").start();
		new Thread(ticket, "窗口三").start();
	}
}
