
/////find the unique element formed by taking bitwise OR between the elements of different subarrays formed through the array
  
#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;

/*

  APPROACH1: we are enumarating all the possible subarrays and taking the bitwise OR seperately
  time complexity: O(n^2), space: O(n)

   ---check out second approach using DP below---
  



int main()
{

    int n;
    vector<int> arr;

    set<int> st; // to store the unique elements obtained by bitwise OR of diff subarrays

    while (cin >> n)
    {
        arr.push_back(n);
    }

    for (int i = 0; i < arr.size(); i++)
    {

        int val = arr[i];
        st.insert(val);

        for (int j = i + 1; j < arr.size(); j++)
        {

            val |= arr[j];
            st.insert(val);
        }
    }

    // printing the unique elements

    for (int ele : st)
    {
        cout << ele << " ";
    }
    // cout<<st.size();

    return 0;
}
    
*/


// -----approach 2 using dynamic programming-------


int main(){


    int n;
    vector<int> arr;


    while (cin >> n)
    {
        arr.push_back(n);
    }

     // Set to store unique OR results
    unordered_set<int>uniqueOR; 
    // Temporary set to store OR results of all the previous sub arrays that can be formed from the next element;  
    unordered_set<int>currOR;

     // Iterate through the array
    for(int i=0; i<arr.size(); i++){
        // Temporary set for the current element
          unordered_set<int>tempOR;
          tempOR.insert(arr[i]);  // Add the current element itself

 // Compute OR of the current element with all previous results
          for(int val : currOR){
                uniqueOR.insert(val | arr[i]);
          }

           // Update the unique OR results
          for(int val : tempOR){
                uniqueOR.insert(val);
          }
  // Update currentOrSet for the next iteration
          currOR = tempOR;
    }

    for (int ele : uniqueOR)
    {
        cout << ele << " ";
    }

    return 0;
}
 
