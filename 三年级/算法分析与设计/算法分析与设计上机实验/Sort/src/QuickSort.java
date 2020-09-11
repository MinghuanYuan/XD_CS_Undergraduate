import edu.princeton.cs.algs4.StdRandom;

public class QuickSort {

	public static void randomquicksort(int[] a) {
		StdRandom.shuffle(a);
		randomquicksort(a, 0, a.length - 1);
	}
	
	private static void randomquicksort(int[] a, int lo, int hi) {
		if(hi <= lo)return;
		int j = partition(a, lo, hi);
		randomquicksort(a, lo, j - 1);
		randomquicksort(a, j + 1, hi);
	}
	
	private static int partition(int[] a, int lo, int hi) {
		int i = lo, j = hi + 1;
		int v = a[lo];
		while(true) {
			while(a[++i] < v)if(i == hi)break;
			while(v < a[--j])if(j == lo)break;
			if(i >= j)break;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		int temp = a[lo];
		a[lo] = a[j];
		a[j] = temp;
		return j;
	}
	
	public static void quick3waysort(int[] a, int lo, int hi) {
		if(hi <= lo)return;
		int lt = lo, i = lo + 1, gt = hi;
		int v = a[lo];
		while(i <= gt) {
			if(a[i] < v) {
				int temp = a[lt];
				a[lt] = a[i];
				a[i] = temp;
				lt++;
				i++;
			}
			else if(a[i] > v) {
				int temp = a[i];
				a[i] = a[gt];
				a[gt] = temp;
				gt--;				
			}
			else i++;
		}
		quick3waysort(a, lo, lt - 1);
		quick3waysort(a, gt + 1, hi);
	}
	
}
