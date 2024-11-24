#include<iostream>
using namespace std;
////////////////////////////////////1. Implementing n queues in a single array///////////////////////////////////////////////////////////////
////////////////////////////////////2. Implement queue using stack///////////////////////////////////////////////////////////////////////////
////////////////////////////////////3. Implement stack using queue//////////////////////////////////////////////////////////////////////////
///////////////////////////////////4. input q: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} => output q: {1, 6, 2, 7, 3, 8, 4, 9, 5, 10} using stack and queue////

class KQueue{
       
       public: 
           int* arr;
           int* next;  
           int* front; //each cell will store the front of each queue
           int* rear;  //each cell will store the rear of each queue
           int n;
           int k;
           int freeSlot;

        //constructor
           KQueue(int n, int k){

              this->n = n;
              this->k = k;
              this->arr = new int[n];
              this->next = new int[n];
              this->front = new int[k];
              this->rear = new int[k];
              this->freeSlot = 0;

              //initializing next array: initially next[i] will contain the next freeslot
              for(int i=0; i<n-1; i++) next[i] = i+1;
               next[n-1] = -1;

            //initializing front and rear with -1 initially all k queues will be empty
                for(int i=0; i<k; i++) {
                    front[i] = -1;
                    rear[i] = -1;
                }

           }

/////////isFull/////////////
       bool isFull(int qn){
            return freeSlot == -1;
       }

/////////isEmpty/////////
       bool isEmpty(int qn){
            return { front[qn-1] == -1 };
       }       

 ///////////////////////////////////push function of queue///////////////////////////////////
       void push(int data, int qn){

                //check condition of overflow
                 if(isFull(qn)) {
                    cout<<"Queue is full"<<endl;
                    return;
                 }
                
             //finding free slot to push
                int index = freeSlot;
             
             //updating the freeSlot   
                freeSlot = next[freeSlot];
             
             //pushing the first element
              if(front[qn-1] == -1) {
                front[qn-1] = index;
              }else{
                 next[rear[qn-1]] = index;   //connecting the index with the previous element of the same queue
              }

             //pushing the element
              arr[index] = data;

              //updating the next[index] since this place is occupied now
              next[index] = -1;

              //updating the rear of qn
              rear[qn-1] = index;       
       }    
               
/////////////////////pop function of queue/////////////////////////
    int pop(int qn){

        //cheching the underflow
        if(isEmpty(qn)){
            cout<<"Queue underflow"<<endl;
            return -1;
        }

        //getting index 
        int index = front[qn-1];
        front[qn-1] = next[front[qn-1]];

        //Making sure that freeSlot always points to the first possible freeSlot in the arr
        next[index] = freeSlot;     //connecting the new freeSlot with the previos freeSlot
        freeSlot = index;           //updating the freeSlot to make it point to the first freeSlot possible
  
        return arr[index];

    }
};


int main(){

  KQueue q1(5, 3);  //implementing 3 queues in a single array q1 of size = 5;
  
  q1.push(10, 1);
  q1.push(20, 2);
  q1.push(30, 2);
  q1.push(40, 1);
  q1.push(50, 1);


//   cout<<q1.pop(1)<<endl;
//   cout<<q1.pop(1)<<endl;
//   cout<<q1.pop(1)<<endl;
//   cout<<q1.pop(2)<<endl;
//   cout<<q1.pop(2)<<endl;
  
//printing first queue
while(!q1.isEmpty(1)){
    cout<<q1.pop(1)<<endl;
}

while(!q1.isEmpty(2)){
    cout<<q1.pop(2)<<endl;
}



    return 0;
}