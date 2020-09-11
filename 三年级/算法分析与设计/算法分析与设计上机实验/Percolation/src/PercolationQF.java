import java.util.Random;

import edu.princeton.cs.algs4.QuickFindUF;

public class PercolationQF {

	private int N;
	
	private int count;
	
	private int[][] grid;
	
	private QuickFindUF qf;
	
	public PercolationQF(int N) {
		if(N<0) throw new IllegalArgumentException("N<0");
		this.N = N;
		count = 0;
		grid = new int[N][N];
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++)
				grid[i][j]=0;
		}
		qf = new QuickFindUF(N*N+2);
	}
	
	public void open(int i, int j) {
		if(i<1 || i>N || j<1 || j>N) throw new IndexOutOfBoundsException("i,j not between 1~N");
		grid[i-1][j-1] = 1;
		count++;
		int location = (i-1)*N+j;
		if(i==1) {
			qf.union(0, location);
			if(isOpen(2, j))qf.union(location+N, location);
		}
		if(i==N) {
			qf.union(N*N+1, location);
			if(isOpen(N-1, j))qf.union(location-N, location);
		}
		if(i!=1 && i!=N) {
			if(isOpen(i-1, j))qf.union(location-N, location);
			if(isOpen(i+1, j))qf.union(location+N, location);
			if(j!=1 && isOpen(i, j-1))qf.union(location-1, location);
			if(j!=N && isOpen(i, j+1))qf.union(location+1, location);
		}
	}
	
	public boolean isOpen(int i,int j) {
		if(i<1 || i>N || j<1 || j>N) throw new IndexOutOfBoundsException("i,j not between 1~N");
		return grid[i-1][j-1]==1;
	}
	
	public boolean isFull(int i, int j) {
		if(i<1 || i>N || j<1 || j>N) throw new IndexOutOfBoundsException("i,j not between 1~N");
		return qf.connected(0, (i-1)*N+j);
	}
	
	public boolean percolates() {
		return qf.connected(0, N*N+1);
	}
	
	public int getCount() {
		return count;
	}
	
	public static void main(String[] args) {
		int N = 2,i,j;
		Random r= new Random();
		PercolationQF p = new PercolationQF(N);
		
		while(!p.percolates()){
			i = r.nextInt(N)+1;
			j = r.nextInt(N)+1;
			
			if(!p.isOpen(i, j)) {
				p.open(i, j);
			}
		}
		
		System.out.println(p.getCount());
	}
}
