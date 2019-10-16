#include <iostream>
using namespace std;

void display(int arr[], int n){
	for(int i =0; i<n; i++)
		cout << arr[i] <<" ";
	cout<<endl;
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void selectionsort(int arr[], int n){
	int min_ele;
	for(int i = 0; i < n-1; i++){
		min_ele = i+1;
		for(int j = i+1; j < n; j++)
			if(arr[j] < arr[min_ele])
				min_ele = j;
		swap(arr[i], arr[min_ele]);
	}
}

int main(){
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	display(arr, n);
	selectionsort(arr, n); 
	display(arr, n);
	return 0;
}