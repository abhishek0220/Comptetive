#include <iostream>
#include <random>
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

void quicksort(int arr[], int start, int end){
	if(start > end)
		return;
	int done, pivot;
	done = start - 1;
	pivot = arr[end];
	for(int i = start; i < end; i++){
		if(arr[i] < pivot){
			done++;
			swap(arr[i], arr[done]);
		}
	}
	done++;
	swap(arr[done], arr[end]);
	quicksort(arr, start, done-1);
	quicksort(arr, done+1, end);
}

int main(){
	int n = 5;
	int arr[n];
	for(int i = 0; i < n; i++)
		arr[i] = rand();
	display(arr, n);
	quicksort(arr, 0, n-1);
	display(arr, n);
	return 0;
}