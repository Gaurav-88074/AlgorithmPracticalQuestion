#include<iostream>
#include<vector>
using namespace std;

int knapsack(int * &value,int * &weight,int n,int capacity,int** &dp){      
    
    if(n<0){
        return 0;
    }
    if(dp[n][capacity]!=-1){
        return dp[n][capacity];
    }
    if(weight[n]<=capacity){
        dp[n][capacity] =   max(
            knapsack(value,weight,n-1,capacity,dp),
            value[n]+knapsack(value,weight,n-1,capacity-weight[n],dp)
        );
    }
    else{
        dp[n][capacity] = knapsack(value,weight,n-1,capacity,dp);
    }   
    return dp[n][capacity];
}
int**  createDp(int m,int n){
    int ** res  = new int*[m];
    for (int i = 0; i < m; i++){
        res[i] = new int[n];
        for (int j = 0; j < n; j++){
            res[i][j]=-1;
        }
    }
    return res;
}
int main(){
    
    int weight[5]  = {1,2,3,2,2};
    int value[5]   = {8,4,0,5,3};

    int * weightPtr = weight;
    int * valuePtr  = value;
    
    int size = 5;
    int capacity = 4;
    
    int** dp = createDp(100,100);
    int result = knapsack(valuePtr,weightPtr,size-1,capacity,dp);
    cout<<result<<endl;

    return 0;
}
