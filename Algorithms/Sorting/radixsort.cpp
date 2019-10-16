#include <iostream>
#include <algorithm>
using namespace std;

void display(int arr[], int n){
	for(int i =0; i<n; i++)
		cout << arr[i] <<" ";
	cout<<endl;
}

void countsort(int arr[], int n, int exp){
	int brr[n], count[10], index;
	for(int i = 0; i < 10; i++)
		count[i] = 0;
	for(int i = 0; i < n; i++){
		index = (arr[i]/exp)%10;
		count[index]++;
	}
	for(int i = 1; i < 10; i++)
		count[i] = count[i] + count[i-1];
	for(int i = n-1; i >= 0; i--){
		index = (arr[i]/exp)%10;
		brr[count[index] - 1] = arr[i];
		count[index]--;
	}
	for(int i = 0; i < n; i++)
		arr[i] = brr[i];
}

void radixsort(int arr[], int n){
	int max_ele, exp;
	max_ele = *max_element(arr, arr + n);
	exp = 1;
	while(max_ele/exp > 0){
		countsort(arr, n, exp);
		exp = exp * 10;
	}
}

int main(){
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	display(arr, n);
	radixsort(arr, n); 
	display(arr, n);
	return 0;
}