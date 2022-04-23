#include<iostream>
using namespace std;

void displayArray(int* &array,int size){
    cout<<"Displaying Your Array..."<<endl;
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl<<endl;
}
void countSort(int * &array,int size,int exp){
    int m = array[0];
    for (int i = 0; i < size; i++){
        m = max(m,array[i]);
    }
    int count[m+1] = {0};
    for (int i = 0; i <size; i++){
        int index = (array[i]/exp);
        count[index%10]+=1;
    }
    for (int i = 1; i <(m+1); i++){
        count[i]+=count[i-1];
    }

    int output[size];
    for (int i = size-1; i >=0; i--){
        int index = array[i]/exp;
        output[count[index%10]-1] = array[i];
        count[index%10]-=1;
    }
    for (int i = 0; i < size; i++){
        array[i] = output[i];
    }
}
void radixSort(int * &array,int size){
    int m = array[0];
    for (int i = 0; i < size; i++){
        m = max(m,array[i]);
    }
    int exp = 1;
    while ((m/exp)>0){
        countSort(array,size,exp);
        exp*=10;
    }
}
int main(){
    int arr[] = {10,9,86,7,6,5,4,3,1};
    int * array = arr;
    int size = sizeof(arr)/sizeof(int);

    displayArray(array,size);
    radixSort(array,size);
    displayArray(array,size);
    
    return 0;
}