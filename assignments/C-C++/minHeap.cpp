/*
Nane: James Schvaneveldt
Name: Min Heap Implementation
Section: 003
*/
 
#include "minHeap.h"
#include <tgmath.h> 

//called from insert function
void minHeap::siftUp(int pos){
    if(pos != 0){//base case, stops at root of tree
        int parentIndex = (pos-1)/2; //finds index to swap and compare with
        int temp = heap[parentIndex]; //stores value of parent 
        if(heap[pos] < temp){ //swap case
            heap[parentIndex] = heap[pos];
            heap[pos] = temp;
            siftUp(parentIndex);
        }
    }
}

//called return min function
void minHeap::siftDown(int pos){
    //establishes index positions of value, left and right nodes    
    int compare = pos;
    int left = 2*pos+1;
    int right = 2*pos+2;
    //establishes size for readability purposes
    int size = heap.size();
        if(heap[left] < heap[compare] && left < size){
            compare = left;
        }
        if(heap[right] < heap[compare] && right < size){
            compare = right;
        }
        if(compare != pos){
            int temp = heap[pos];
            heap[pos] = heap[compare];
            heap[compare] = temp;
            siftDown(compare);
        }
}

//constructor for input of vector
minHeap::minHeap(vector<int> data) : heap(data){
    for (int i = heap.size()/2-1; i >= 0; --i){
		siftDown(i);
    }
}

//insert function
void minHeap::insert(int value){
    heap.push_back(value);
    siftUp(heap.size()-1); //begins recurisve call of siftUp
}

//remove minimum function
int minHeap::removeMin(){
    int result = heap[0]; //sets return value of root (min)
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0); //begins recurisve call of sift down
    return result; //returns original root after rearrangement
}