package mytest05;

import java.util.Scanner;

public class MyTest05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		System.out.println("�������Ʊ����");
		Ticket ticket = new Ticket();
		ticket.setCount(scanner.nextInt());
		new Thread(ticket, "����һ").start();
		new Thread(ticket, "���ڶ�").start();
		new Thread(ticket, "������").start();
	}
}
