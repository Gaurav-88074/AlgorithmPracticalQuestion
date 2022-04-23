#include<iostream>
#include<vector>
using namespace std;
void displayArray(vector<int> array,int size){
    cout<<"Displaying Your Array..."<<endl;
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl<<endl;
}

vector<int> merge(vector<int> &array1,vector<int> &array2,int* &comparisons){
    vector<int> res(array1.size()+array2.size());
    int p1 = 0;
    int p2 = 0;
    int index = 0;
    while (p1<array1.size() && p2<array2.size()){
        if(array1[p1]<array2[p2]){
            res[index++] = array1[p1++];
        }
        else{
            res[index++] = array2[p2++];
        }
        (*comparisons)+=1;
    }
    while (p1<array1.size()){
        res[index++] = array1[p1++];
        (*comparisons)+=1;
    }
    while (p2<array2.size()){
        res[index++] = array2[p2++];
        (*comparisons)+=1;
    }
    return res;
}
vector<int> mergeSort(vector<int> &array,int start,int end,int* &comparisons){
    if (start==end){
        vector<int> res;
        res.push_back(array[end]);
        return res;
    }

    int mid = (start+end)/2;
    vector<int> left  = mergeSort(array,start,mid,comparisons);
    vector<int> right = mergeSort(array,mid+1,end,comparisons);
    return merge(left,right,comparisons);
}
vector<int> toVector(int * array,int &size){
    vector<int> res;
    for (int i = 0; i < size; i++){
        res.push_back(array[i]);
    }
    return res;
}
int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int size = sizeof(arr)/sizeof(int);
    int * comparisons = new int(0);
    
    vector<int> array = toVector(arr,size);
    displayArray(array,size);

    vector<int> sortedArray = mergeSort(array,0,size-1,comparisons);
    displayArray(sortedArray,size);

    cout<<"Total Comparisons : "<<*comparisons<<endl;

    return 0;
}