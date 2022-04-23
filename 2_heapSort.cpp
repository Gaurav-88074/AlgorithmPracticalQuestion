#include<iostream>
using namespace std;
void displayArray(int * &array,int size){
    cout<<"Displaying Your Array..."<<endl;
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl<<endl;
}
void swap(int * &array,int a,int b){
    int temp = array[a];
    array[a]  = array[b];
    array[b]  = temp;
}
void heapify(int * &array,int size,int index){
    int largest = index;
    int leftChild  = 2*index +1;
    int rightChild = 2*index +2;
    
    if(leftChild<size && array[leftChild]>array[largest]){
        largest = leftChild;
    }
    if(rightChild<size && array[rightChild]>array[largest]){
        largest = rightChild;
    }
    if(largest!=index){
        swap(array,largest,index);
        heapify(array,size,largest);
    }
}
void buildHeap(int * &array,int size){
    for (int i = size/2; i >=0; i--){
        heapify(array,size,i);
    }
}
void heapSort(int * &array,int size){
    buildHeap(array,size);
    size-=1;
    for (int i = 0; i < (size+i); i++){
        swap(array,0,size);
        heapify(array,size,0);
        size-=1;
    }
}
int main(){
    int arr[] = {30,20,10,5,4,3,2,1};
    int * array = arr;
    int size = sizeof(arr)/sizeof(int);

    displayArray(array,size);
    heapSort(array,size);
    displayArray(array,size);

    return 0;
}