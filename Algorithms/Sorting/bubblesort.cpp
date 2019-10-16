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

void bubblesort(int arr[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-1-i; j++)
			if(arr[j] > arr[j+1])
			swap(arr[j], arr[j+1]);
	}
}

int main(){
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	display(arr, n);
	bubblesort(arr, n); 
	display(arr, n);
	return 0;
}