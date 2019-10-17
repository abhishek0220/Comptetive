#include<bits/stdc++.h>
using namespace std;

//function to merge the given sorted array
void merging(int arr[],int low,int mid,int high){
    int i,j,k;
    int n1 = mid - low+1;
    int n2 = high - mid;
    int L[n1];   // left array
    int R[n2];   // right array
    for(i=0;i<n1;i++){
        L[i] = arr[low+i];      // filling the left array
    }
    for(j=0;j<n2;j++){
        R[j] = arr[mid+j+1];    // filling the right array
    }
    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2){        // comparing the elements of left and right arrays
        if(L[i]<=R[j]){         // and then storing them in arr array back.
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    if(i<n1){                   // filling the remaining elements of left array to arr array.
        arr[k] = L[i];
        i++;
        k++;
    }
    if(j<n2){                   // filling the remaining elements of right array to arr array.
        arr[k] = R[j];
        j++;
        k++;
    }
}
// the main merge sort function which recursively break the array in two half untill we get
// single sized arrays and then merge them according to values in ascending order
void mergesort(int arr[],int low,int high){
    if(low < high){
        // find mid index of element
        int mid = (low+(high-1))/2;
        // recursively merges the array in two halves
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        // finally merging them into single sorted array
        merging(arr,low,mid,high);
    }
}
// function to print the elements of array
void printarr(int arr[],int n){
    for(int k = 0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}
//it is the driver programme to execute the above algorithm.
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        int t;
        cin>>t;
        arr[i] = t;
    }
    mergesort(arr,0,n-1);
    printarr(arr,n);
}
