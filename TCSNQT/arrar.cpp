//findig smallest number
//finding largest number
// finding second smallest number
//finding second largest number


#include<iostream>
using namespace std;
#include<vector>
//finding the smallest element  
int smallestElement(int arr[], int n){
      
       int min = INT8_MAX;
      
       for(int i=0; i<n; i++){
              if(min > arr[i]) min = arr[i];
       }

       return min;
}

//finding the largest number
int largestNum(int arr[], int n){

    int max = INT8_MIN;
    for(int i=0; i<n; i++){
        if(max < arr[i]) max = arr[i];
    }
    return max;
}

//finding the second smallest and second largest

//approach1: traversing the array two times
int secondSmallest(int arr[], int n){
    
     if(n < 2) return -1;

        int smallest = smallestElement(arr, n);
        int secondSmallest = INT8_MAX;
        bool distinct = false;
        for(int i=0; i<n; i++){
            if(arr[i] < secondSmallest && arr[i] != smallest){
                      secondSmallest = arr[i];
                      distinct = true;  
            }
        }

        if(distinct) {
            return secondSmallest;
        }
        else{
            return -1;
        }
}

//optimal approach: finding the second largest using only one traversal

int secondLargest(int arr[], int n){

    //edge case:
    if(n<2) return -1;
      
        int largest = INT8_MIN, secondLargest = INT8_MIN;
        bool distinct = false;
        for(int i=0; i<n; i++){
               
                if(arr[i]>largest){
                     
                      secondLargest = largest;
                      largest = arr[i];
                }
                else if(arr[i] > secondLargest && arr[i] != largest){
                        secondLargest = arr[i];
                } 
                if(i < n-1 && arr[i] != arr[i+1])  distinct = true;
        } 
        if(distinct) return secondLargest;
        else return -1;
}


int main(){

  int n;
  cin>>n;
  vector<int>v(n);
  int arr[n];
  
   for(int i=0; i<n; i++){ 
         cin>>arr[i]; 
   }

  for(auto ele: arr){
    cout<<ele<<" ";
  }
   cout<<endl;


   int min = smallestElement(arr, n);
   int max = largestNum(arr, n);
   int secondSmallestNum = secondSmallest(arr, n);
   int secondLargestNum = secondLargest(arr, n);
   cout<<"Smallest Number is " <<min<<endl;
   cout<<"Largest Number is " <<max<<endl;
   cout<<"Second smallest Number is " <<secondSmallestNum<<endl;
   cout<<"Second largest Number is " <<secondLargestNum<<endl;
   

    return 0;
}