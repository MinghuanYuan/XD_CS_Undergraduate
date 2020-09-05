package mytest02;

public class Triangle extends Shape {

	@Override
	public void print() {
		// TODO Auto-generated method stub
		System.out.println("  *  ");
		System.out.println(" * * ");
		System.out.println("* * *");
	}
	
	public String check() {
		return "Triangle";
	}
}
