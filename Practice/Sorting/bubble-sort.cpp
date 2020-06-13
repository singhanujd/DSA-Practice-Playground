#include<bits/stdc++.h>
using namespace std;

int* bubbleSort(int arr[],int n){
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      if(arr[i] > arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  return arr;
}

int main(){
  int arr[] = {10,9,8,7,6,5,4,3,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  int *result = bubbleSort(arr,n);
  const int *end = &result[n];
  for (int * curr = result; curr != end; ++curr) cout<<(*curr)<<" ";
  cout<<endl;
}