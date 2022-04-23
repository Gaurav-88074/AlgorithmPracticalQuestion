#include<iostream>
using namespace std;
void displayArray(int* &array,int size){
    cout<<"Displaying Your Array..."<<endl;
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl<<endl;
}
int insertionSort(int* &array,int &size){
    int j;
    int key;
    int comparison=0;
    for (int i = 0; i < size; i++){
        key = array[i];
        j = i-1;
        while (j>=0 && key<array[j]){
            comparison+=1;
            array[j+1] = array[j];
            j-=1;
        }
        j+=1;
        array[j] = key;
    }
    return comparison;
}

int main(){
    int arr[] = {10,9,8,7,6,5,4,3,1};
    int * array = arr;
    int size = sizeof(arr)/sizeof(int);

    displayArray(array,size);

    int comparison = insertionSort(array,size);
    displayArray(array,size);
    cout<<"Total Comparisons : "<<comparison<<endl;
   
    return 0;
}