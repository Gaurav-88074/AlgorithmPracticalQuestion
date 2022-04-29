#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
class Graph{
    private:
        int size;
        vector<vector<int>> matrix;
    public:
        Graph(int size){
            this->size = size;
            this->matrix = vector<vector<int>>(size);
            this->createGraph();
        }
        void createGraph(){
            for (int i = 0; i < this->size; i++){
                this->matrix[i] = vector<int>(size,-1);
            }
        }
        void displayGraph(){
            cout<<"Displaying Your Graph.."<<endl;
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    cout<<this->matrix[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        bool isConnected(int i,int j){
            if(this->matrix[i][j]>-1){
                return true;
            }
            return false;
        }
        int getWeight(int i,int j){
            return this->matrix[i][j];
        }
        void setEdge(int i,int j,int value){
            this->matrix[i][j] = value;
            this->matrix[j][i] = value;
        }
        int getSize(){
            return this->size;
        }
};
int selectMinVertex(vector<int> &distance,vector<bool> &visited){
    int m = INT_MAX;
    int vertex;
    for (int i = 0; i < distance.size(); i++){
        if (visited[i]==false && distance[i]<m){
            vertex = i;
            m = distance[i];
        }
    }
    return vertex;
    // return 0;
}
void displayArray(vector<int> &array,int size){
    cout<<"Displaying Your Array..."<<endl;
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int MST(Graph &graph,int source){
    vector<int>  distance(graph.getSize(),INT_MAX);
    vector<int>   parent(graph.getSize(),-1);
    vector<bool> visited(graph.getSize(),false);

    distance[source] = 0;
    // parent[source]   = -1;

    for (int i = 0; i < graph.getSize()-1; i++){
        int u = selectMinVertex(distance,visited);
        // cout<<"we got : "<<u<<endl;
        visited[u]  = true;
        // displayArray(parent,graph.getSize());
        // displayArray(distance,graph.getSize());
        // cout<<"---------------"<<endl;
        for (int j = 0; j < graph.getSize(); j++){
            if (graph.isConnected(u,j)&&distance[j]>graph.getWeight(u,j)&&visited[j]==false){
                distance[j] = graph.getWeight(u,j);
                parent[j] = u;
                // cout<<"hit"<<endl;
            }
        }
    }
    int res = 0;
    for(int i=0 ;i<graph.getSize() ; i++){
        if (parent[i]!=-1)
        {
            res+=distance[i];
        }
        
    }
    displayArray(parent,graph.getSize());
    displayArray(distance,graph.getSize());
    return res;
}
int main(){
    
    Graph graph(6);

    graph.setEdge(1,2,3);
    graph.setEdge(1,3,4);
    graph.setEdge(4,2,6);
    graph.setEdge(5,2,2);
    graph.setEdge(2,3,5);
    graph.setEdge(3,5,7);
    
    // graph.displayGraph();
    int res = MST(graph,1);
    cout<<res<<endl;
    return 0;
}