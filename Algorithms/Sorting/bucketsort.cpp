#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(float arr[], int n){
	for(int i =0; i<n; i++)
		cout << arr[i] <<" ";
	cout<<endl;
}

void bucketsort(float arr[], int n){
	vector<float> buk[n];
	int index;
	for(int i = 0; i < n; i++){
		index = n * arr[i];
		buk[index].push_back(arr[i]);
	}
	for(int i = 0; i <n; i++)
		sort(buk[i].begin(), buk[i].end());
	index = 0;
	for(int i = 0; i <n; i++){
		for(int j = 0; j<buk[i].size(); j++){
			arr[index] = buk[i][j];
			index++;
		}
	}

}
int main(){
	float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
	int n = sizeof(arr)/sizeof(arr[0]);
	display(arr, n);
	bucketsort(arr, n);
	display(arr, n);
	return 0;
}