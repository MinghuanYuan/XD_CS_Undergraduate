import java.util.Arrays;
import java.util.Scanner;

public class TestSort {

	private static void TestInsertionSort(int cycleindex, int[] a) {
		long[] output = new long[cycleindex+1];
		int[] b = new int[a.length];
		for(int i=0; i<cycleindex; i++) {
			for(int j=0; j<a.length; j++)b[j] = a[j];
			long start = System.currentTimeMillis();
			InsertionSort.sort(b);
			long end = System.currentTimeMillis();
			output[i] = end - start;
			output[cycleindex] += output[i];
			System.out.print(output[i]+"ms\t");
		}
		System.out.println((double)output[cycleindex]/cycleindex + "ms");
	}
	
	private static void TestTopDownMergeSort(int cycleindex, int[] a) {
		long[] output = new long[cycleindex+1];
		int[] b = new int[a.length];
		for(int i=0; i<cycleindex; i++) {
			for(int j=0; j<a.length; j++)b[j] = a[j];
			long start = System.currentTimeMillis();
			MergeSort.topdownsort(b);
			long end = System.currentTimeMillis();
			output[i] = end - start;
			output[cycleindex] += output[i];
			System.out.print(output[i]+"ms\t");
		}
		System.out.println((double)output[cycleindex]/cycleindex + "ms");
	}
	
	private static void TestBottomUpMergeSort(int cycleindex, int[] a) {
		long[] output = new long[cycleindex+1];
		int[] b = new int[a.length];
		for(int i=0; i<cycleindex; i++) {
			for(int j=0; j<a.length; j++)b[j] = a[j];
			long start = System.currentTimeMillis();
			MergeSort.bottomupsort(b);
			long end = System.currentTimeMillis();
			output[i] = end - start;
			output[cycleindex] += output[i];
			System.out.print(output[i]+"ms\t");
		}
		System.out.println((double)output[cycleindex]/cycleindex + "ms");
	}
	
	private static void TestRandomQuickSort(int cycleindex, int[] a) {
		long[] output = new long[cycleindex+1];
		int[] b = new int[a.length];
		for(int i=0; i<cycleindex; i++) {
			for(int j=0; j<a.length; j++)b[j] = a[j];
			long start = System.currentTimeMillis();
			QuickSort.randomquicksort(b);
			long end = System.currentTimeMillis();
			output[i] = end - start;
			output[cycleindex] += output[i];
			System.out.print(output[i]+"ms\t");
		}
		System.out.println((double)output[cycleindex]/cycleindex + "ms");
	}
	
	private static void TestQuick3WaySort(int cycleindex, int[] a) {
		long[] output = new long[cycleindex+1];
		int[] b = new int[a.length];
		for(int i=0; i<cycleindex; i++) {
			for(int j=0; j<a.length; j++)b[j] = a[j];
			long start = System.currentTimeMillis();
			QuickSort.quick3waysort(b, 0, a.length-1);
			long end = System.currentTimeMillis();
			output[i] = end - start;
			output[cycleindex] += output[i];
			System.out.print(output[i]+"ms\t");
		}
		System.out.println((double)output[cycleindex]/cycleindex + "ms");
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		System.out.println("请输入数据规模（数组元素个数）");
		int arraylength = sc.nextInt();
		int[] a = new int[arraylength];
		int cycleindex = 10;
		for(int i=0; i<arraylength; i++) {
			a[i] = (int)(Math.random()*10000000);
		}
//		Arrays.sort(a);
//		for(int i=0; i<arraylength; i++) {
//			System.out.print(a[i]+"  ");
//		}
		System.out.println("\tRun1\tRun2\tRun3\tRun4\tRun5\tRun6\tRun7\tRun8\tRun9\tRun10\tAverage");
		System.out.print("IS\t");
		TestInsertionSort(cycleindex, a);
		System.out.print("TDM\t");
		TestTopDownMergeSort(cycleindex, a);
		System.out.print("BUM\t");
		TestBottomUpMergeSort(cycleindex, a);
		System.out.print("RQ\t");
		TestRandomQuickSort(cycleindex, a);
		System.out.print("QD3P\t");
		TestQuick3WaySort(cycleindex, a);
	}

}
