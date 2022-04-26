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
    int temp  = array[a];
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

int kthSmallestElement(int* &array,int start,int end,int k){
    if(start==end){
        return array[start];
    }
    int pos = partition(array,start,end);
    int index = pos-start+1;
    if (index==k){
        return array[pos];
    }
    else if (k<index){
        return kthSmallestElement(array,start,pos-1,k);
    }
    else{
        return kthSmallestElement(array,pos+1,end,k -index);
    }
}
int main(){
    int arr[] = {90,80,70,50,40,30,20,10};
    int * array = arr;
    int size = sizeof(arr)/sizeof(int);
    
    displayArray(array,size);
    int res = kthSmallestElement(array,0,size,5);
    cout<<res<<endl;

    return 0;
}