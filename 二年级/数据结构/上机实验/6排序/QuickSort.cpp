#include<stdio.h>

int Partition(int array[], int low, int high);
void QuickSort(int array[], int low, int high){
	int pivotloc; 
	if(low <= high){
		pivotloc = Partition(array, low, high);
		QuickSort(array, low, pivotloc-1);
		QuickSort(array, pivotloc+1, high);
		printf("%d ", array[pivotloc]);
	}
}

int Partition(int array[], int low, int high){
	int pivotkey = array[low];
	while(low < high){
		while(low < high && array[high] >= pivotkey)high--;
		array[low] = array[high];
		while(low < high && array[low] <= pivotkey)low++;
		array[high] = array[low];
	}
	array[low] = pivotkey;
	return low;
}

int main(){
	int n;
	scanf("%d",&n);
	int array[n+1];
	for(int i=1; i<=n; i++){
		scanf("%d", &array[i]);
	}
	
	QuickSort(array, 1, n);
//	for(int i=1; i<=n; i++){
//		printf("%d  ", array[i]);
//	}
	
	return 0;
} 
