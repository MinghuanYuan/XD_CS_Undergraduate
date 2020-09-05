package mytest02;

public abstract class Shape {
	private String name;
	
	
	public  void modifyname(String name)
	{
		this.name = name;
	}
	
	
	public String getName()
	{
		return this.name;
	}
	
	
	public abstract void print();
	
	public abstract String check();
}
