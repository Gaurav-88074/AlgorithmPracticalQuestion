#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class edge{
    public :
        int source;
        int dest;
        int weight;
        edge(int source,int dest,int weight){
            this->source = source;
            this->dest   = dest;
            this->weight = weight;
        }
};
bool comp(edge &a,edge &b){
    return a.weight<b.weight;
}
void fillArray(int* &array,int size,int value){
    for (int i = 0; i < size; i++){
        array[i] = value;
    }
}
void fillParentArray(int* &array,int size){
    for (int i = 0; i < size; i++){
        array[i] = i;
    }
}
int find(int * &array,int x){
    if(array[x]==x){
        return x;
    }
    else{
        return find(array,array[x]);
    }
}
void Union(int * &rank,int* &parent,int x,int y){

    int xp = find(parent,x);
    int yp = find(parent,y);
    if (xp==yp){
        return;
    }
    if (rank[xp]<rank[yp]){
        parent[xp] = yp;
    }
    else if (rank[xp]>rank[yp]){
        parent[yp] = xp;
    }
    else{
        parent[yp] = xp;
        rank[xp]+=1;
    }
}
int MST(vector<edge> &edges){
    int* rank = new int[edges.size()+1];
    fillArray(rank,edges.size()+1,0);

    int* parent = new int[edges.size()+1];
    fillParentArray(parent,edges.size()+1);

    sort(edges.begin(),edges.end(),comp);

    int res = 0;
    for (int i = 0; i < edges.size(); i++){
        int source = edges[i].source;
        int dest = edges[i].dest;
        if (find(parent,source)!=find(parent,dest)){
            res+=edges[i].weight;
            Union(rank,parent,source,dest);
        }
    }
    return res;
}
int main(){
    vector<edge> edges;

    edges.push_back(edge(1,3,3));
    edges.push_back(edge(2,3,4));
    edges.push_back(edge(1,2,5));
    edges.push_back(edge(0,2,8));
    edges.push_back(edge(0,1,10));
    edges.push_back(edge(2,4,12));
    edges.push_back(edge(3,4,15));

    int res = MST(edges);
    cout<<res<<endl;

    return 0;
}
