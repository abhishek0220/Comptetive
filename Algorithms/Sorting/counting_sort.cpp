#include<bits/stdc++.h>
using namespace std;
// this functions returns the minimum element of the given array
int minimum(int arr[],int sizee){
    int key = arr[0];
    for(int i = 1;i<sizee;i++){
        if(arr[i]<key){
            key = arr[i];
        }
    }
    return key;
}
// this functions gives the maximum element of the provided array
int maximum(int arr[],int sizee){
    int key = arr[0];
    for(int i = 1;i<sizee;i++){
        if(arr[i]>key){
            key = arr[i];
        }
    }
    return key;
}
//this is the main counting sort function
void counting_sort(int arr[],int sizee){
    int mini = minimum(arr,sizee);  //initializing minimum element
    int maxi = maximum(arr,sizee);  // initializing maximum element

    int counting[maxi+1];  //create counting array of size max+1

    for(int i = 0;i<maxi+1;i++){
        counting[i] = 0;    // initializing all the counting array with 0's
    }
    for(int i = 0;i<sizee;i++){
        ++counting[arr[i]];     //now at each position arr[i] in counting find, increase the value at that index by one
    }
    for(int i = 1;i<maxi+1;i++){
        counting[i] = counting[i] + counting[i-1];  // make the elements of counting array cumulative.
    }
    int res[sizee];
    for(int i = 0;i<sizee;i++){
        res[--counting[arr[i]]] = arr[i];  //now put the elements in res array from the corresponding counting array
    }                                      // and simultaneously reducing the value at the respective position of counting array at each iteration.
    for(int i = 0;i<sizee;i++){
        arr[i] = res[i];            //just copy the elements of res into arr array again.
    }
}
// function to print the given array elements.
void printarr(int arr[],int sizee){
    for(int i =0;i<sizee;i++){
        cout<<arr[i]<<" ";
    }
}
// driver programme to implement the above counting_sort algorithm.
int main(){
    //int arr[] = {2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    counting_sort(arr,n);
    printarr(arr,n);

}
