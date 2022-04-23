#include<iostream>
#include<time.h>
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

int partition(int * &array,int start,int end){
    int index = start-1;
    int pivot = end;
    while (start<end){
        if (array[start]<=array[pivot]){
            index+=1;
            swap(array,index,start);
        }
        start+=1;
    }
    index+=1;
    swap(array,index,pivot);
    return index;
}
int partitionrandom(int* &array,int start,int end){
    srand(time(NULL));
    int randompivot = start+ rand() % (start - end);
    swap(array,randompivot,end);
    return partition(array, start, end);
}
void quickSort(int * &array,int start,int end){
    if (start<end){
        int partion = partitionrandom(array,start,end);
        quickSort(array,start,partion-1);
        quickSort(array,partion+1,end);
    }
}

int main(){
    int arr[] = {90,80,70,50,40,30,20,10};
    int * array = arr;
    int size = sizeof(arr)/sizeof(int);

    displayArray(array,size);
    quickSort(array,0,size-1);
    displayArray(array,size);

    return 0;
}