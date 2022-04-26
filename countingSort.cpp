#include<iostream>
using namespace std;
//ignore this file
void displayArray(int* &array,int size){
    cout<<"Displaying Your Array..."<<endl;
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl<<endl;
}
void countSort(int * &array,int size){
    int m = array[0];
    for (int i = 0; i < size; i++){
        m = max(m,array[i]);
    }
    int count[m+1] = {0};
    for (int i = 0; i <size; i++){
        int index = array[i];
        count[index]+=1;
    }
    for (int i = 1; i <(m+1); i++){
        count[i]+=count[i-1];
    }

    int output[size];
    for (int i = 0; i < size; i++){
        int index = count[array[i]]-1;
        output[index] = array[i];
        count[array[i]]-=1;
    }
    for (int i = 0; i < size; i++){
        array[i] = output[i];
    }
}

int main(){
    int arr[] = {10,9,86,7,6,5,4,3,1};
    int * array = arr;
    int size = sizeof(arr)/sizeof(int);

    displayArray(array,size);
    countSort(array,size);
    displayArray(array,size);
    
    return 0;
}