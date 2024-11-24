////////////////////////////////////////////sum-minimum-maximum-elements-subarrays-size-k///////////////////////////////////////////


#include<bits/stdc++.h>
using namespace std;

int sumMinMax(int arr[], int n, int k ){
               
//finding sum in first window

  int ans = 0;
  deque<int>maxi(k);      //stores the elements in the descending order i.e : front element will contain the largest in the window
  deque<int>mini(k);  //stores the elements in the increasing order i.e : front element will contain the smallest in the window

//finding sum of first window
  for(int i=0; i<k; i++){
         
      //addition of elements of a window in queue 

 // Remove all previous smaller elements that are useless
    while(!maxi.empty() && arr[maxi.back()] <= arr[i]) { 
                   maxi.pop_back();
    }
 
   // Remove all previous greater elements that are useless.
    while(!mini.empty() && arr[mini.back()] >= arr[i]) {
                   mini.pop_back();
        }

    maxi.push_back(i);
    mini.push_back(i); 
  }

   ans = arr[maxi.front()] + arr[mini.front()];       

//searching in the remaining window
for(int i=k; i<n; i++){
  
//removal of elements that are out of window
    while(!maxi.empty() && (i - maxi.front() + 1) > k){
        maxi.pop_front();
    }

    while(!mini.empty() && (i - mini.front() + 1) > k){
        mini.pop_front();
    }


 //addition of elements
// Remove all previous smaller elements that are useless
    while(!maxi.empty() && arr[maxi.back()] <= arr[i]) { 
                   maxi.pop_back();
    }
 
// Remove all previous greater elements that are useless.
    while(!mini.empty() && arr[mini.back()] >= arr[i]) {
                   mini.pop_back();
        }

    maxi.push_back(i);
    mini.push_back(i); 
     
  ans += arr[maxi.front()] + arr[mini.front()];  
}
 return ans;

}



int main(){
     
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout << sumMinMax(arr, n, k) ;
    return 0;



}