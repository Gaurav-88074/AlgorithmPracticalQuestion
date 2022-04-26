#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class job{
    public :
        int start;
        int finish;
        int profit;

        job(int start,int finish,int profit){
            this->start = start;
            this->finish=finish;
            this->profit=profit;
        }
};
int binarySearch(vector<job> jobs,int index){
    int low = 0;
    int high = index-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(jobs[mid].finish<=jobs[index].start){
            if (jobs[mid+1].finish<=jobs[index].start){
                low = mid+1;
            }
            else{
                return mid;
            } 
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}
int schedule(vector<job> jobs){
    sort(jobs.begin(),jobs.end(),[](job a,job b){
        return a.finish<b.finish;
    });
    int* total = new int[jobs.size()];
    total[0] = jobs[0].profit;
    
    for (int i = 1; i < jobs.size(); i++){
        int l = binarySearch(jobs,i);
        int p=jobs[i].profit;
        if (l!=-1){
            p+= total[l];
        }
        total[i] = max(p,total[i-1]);
    }
    return total[jobs.size()-1];
}

int main(){
    
    vector<job> jobs;

    jobs.push_back(job(1,2,50));
    jobs.push_back(job(3,5,20));
    jobs.push_back(job(6,19,100));
    jobs.push_back(job(2,100,200));
    
    int res = schedule(jobs);
    cout<<res<<endl;

    return 0;
}