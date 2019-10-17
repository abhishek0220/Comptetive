#include<bits/stdc++.h>
using namespace std;

void insertionsort(int arr[],int size){
  int key;
  for(int i=1;i<size;i++){
    key = arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>key){
      arr[j+1] = arr[j];
      j=j-1;
    }
    arr[j+1] = key;
  }
  for(int k = 0;k<size;k++){
    cout<<arr[k]<<" ";
  }
}
int main(){
  int arr[10] = {39,1,11,23,23,87,5,6,7,0};
  insertionsort(arr,10);
}
