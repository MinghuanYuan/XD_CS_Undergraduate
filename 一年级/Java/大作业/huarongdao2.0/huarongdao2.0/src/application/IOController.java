package application;

import java.io.*;

public class IOController {

	private DataInputStream in;
	
	private DataOutputStream out;
	
	private File filemain;
	
	private File filegame;
	
	private static RandomAccessFile outend;
	
	private static File fileend;
	
	public double[] get(int n) throws Exception{
		filemain = new File("state.hrd");
		in = new DataInputStream(new FileInputStream(filemain));
		double array[]=new double[53];
		double a;
		for(int j=0;j < (n-1)*53;j++)a = in.readDouble();
		int i = 0;
		while(i<53) {
			array[i] = in.readDouble();
			i++;
		}
		in.close();
		this.newfile(array);
		return array;
	}
	
	public double[] getgame() throws Exception{
		filegame = new File("filegame.hrd");
		RandomAccessFile inend = new RandomAccessFile(filegame,"r");
		long l = inend.length();
		int n = (int)l/8/53;
		inend.seek((n-1)*8*53);
		double array[]=new double[53];
		int i = 0;
		while(i<53) {
			array[i] = inend.readDouble();
			i++;
		}
		inend.close();
		return array;
	}
	
	private void newfile(double[] a) throws Exception{
		
		filegame = new File("filegame.hrd");
		if(!filegame.exists())
			filegame.createNewFile();
		out = new DataOutputStream(new FileOutputStream(filegame));
		for(double e: a) {
			out.writeDouble(e);
			out.flush();
		}
		out.close();
	}
	
	public static void printfile(double n,double[] a){
		try {
			fileend = new File("filegame.hrd");
			outend = new RandomAccessFile(fileend,"rw");
			outend.seek(outend.length());
			for(double e: a) {
				outend.writeDouble(e);
			}
			outend.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
}
