package mytest05;

public class Ticket extends Thread {

	private int count;
	
	private int current = 0;
	
	public void setCount(int count) {
		this.count = count;
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true){
			synchronized(this){
				current++;
				if(current <= count)
				System.out.println(Thread.currentThread().getName()+"��ǰ�۳���"+current+"�ŵ�ӰƱ");
			}
			try {
				Thread.sleep((long) (1+Math.random()*1000));
			}
			catch (Exception e) {
				// TODO: handle exception
				e.printStackTrace();
			}
		}
	}
}
