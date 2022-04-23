#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void displayArray(double* &array,int size){
    cout<<"Displaying Your Array..."<<endl;
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl<<endl;
}
void bucketSort(double* &array,int size){
    vector<vector<double>> buckets(10);
    for (int i = 0; i < size; i++){
        int index = (int)array[i]%10;
        buckets[index].push_back(array[i]);
    }
    for (int i = 0; i < 10; i++){
        sort(buckets[i].begin(),buckets[i].end());
    }
    int index = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < buckets[i].size(); j++){
            array[index++] = buckets[i][j];
        }
    }
}

int main(){
    double arr[] = {
        0.897, 0.565,
        0.656, 0.1234,
        0.665,0.3434 
    };
    double * array = arr;
    int size = sizeof(arr)/sizeof(double);

    displayArray(array,size);
    bucketSort(array,size);
    displayArray(array,size);
    
    return 0;
}