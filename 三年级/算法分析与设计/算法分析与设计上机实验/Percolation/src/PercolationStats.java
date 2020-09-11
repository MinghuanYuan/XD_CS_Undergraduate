import java.util.Random;
import java.util.Scanner;

import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {

	private double[] proportion;
	
	private double mean;
	
	private double stddev;
	
	private double lo;
	
	private double hi;
	
	public PercolationStats(int N, int T) {
		if(N<1 || T<1) throw new IllegalArgumentException();
		proportion = new double[T];
		for(int t=0; t<T; t++) {
//			PercolationWQU p = new PercolationWQU(N);
			PercolationQF p = new PercolationQF(N);
			Random r = new Random();
			while(!p.percolates()) {
				int i = r.nextInt(N)+1;
				int j = r.nextInt(N)+1;
				if(!p.isOpen(i, j)) {
					p.open(i, j);
				}
			}
			proportion[t] = p.getCount()/(double)(N*N);
		}
	}
	
	public double mean() {
		mean = StdStats.mean(proportion);
		return mean;
	}
	
	public double stddev() {
		stddev = StdStats.stddev(proportion);
		return stddev;
	}
	
	public double confidenceLo() {
		lo = mean-1.96*stddev/Math.sqrt(proportion.length);
		return lo;
	}
	
	public double confidenceHi() {
		hi = mean+1.96*stddev/Math.sqrt(proportion.length);
		return hi;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入网格边长");
		int N = sc.nextInt();
		System.out.println("请输入循环次数");
		int T = sc.nextInt();
		
		long startTime=System.currentTimeMillis();
		PercolationStats ps = new PercolationStats(N, T);
		long endTime =System.currentTimeMillis();
		
		System.out.println("mean:"+ps.mean());
		System.out.println("stddev:"+ps.stddev());
		System.out.println("confidenceLow:"+ps.confidenceLo());
		System.out.println("confidenceHigh:"+ps.confidenceHi());
		System.out.println("total time:" + (endTime-startTime));
		
	} 
}
