///////////rotate array elements by k distance/////////////////

//approach1
#include<bits/stdc++.h>
using namespace std;

void rotateArr(int* arr, int n, int k){

    k = k%n;     //when k > n
     int temp[k];

     for(int i=0; i<k; i++){
           temp[i] = arr[n-k+i];
     }

     for(int i=n-k-1; i>=0; i--){
           arr[i+k] = arr[i];
     }

     for(int i=0; i<k; i++){
           arr[i] = temp[i];
     }
}

//print function
 void printMe(int* arr, int n){
     for(int i= 0; i<n; i++){
         cout<<arr[i]<<" ";
     }
 }

int main(){


  int n, k;
  cin>>n>>k;
  int arr[n];
  
   for(int i=0; i<n; i++){ 
         cin>>arr[i]; 
   }

  for(auto ele: arr){
    cout<<ele<<" ";
  }
   cout<<endl;

 rotateArr(arr, n, k);

printMe(arr, n);

return 0;
}