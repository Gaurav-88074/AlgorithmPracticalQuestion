#include<iostream>
using namespace std;
class Graph{
    private:
        int size;
        int** matrix;
    public:
        Graph(int size){
            this->size = size;
            this->matrix = new int*[size];
            this->createGraph();
        }
        void createGraph(){
            for (int i = 0; i < this->size; i++){
                this->matrix[i] = new int[this->size]{0};
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
            if(this->matrix[i][j]==1){
                return true;
            }
            return false;
        }
        void setEdge(int i,int j){
            this->matrix[i][j] = 1;
            this->matrix[j][i] = 1;
        }
        int getSize(){
            return this->size;
        }
};
void DFS_REC(Graph &graph,int  source,bool visited[]){
    cout<<source<<" ";
    visited[source] = true;
    for (int i = 0; i < graph.getSize(); i++){
        if (graph.isConnected(source,i)&& !visited[i]){
            visited[i] = true;
            DFS_REC(graph,i,visited);
        }
    }
}
void DFS(Graph &graph,int  source){
    cout<<"Source : "<<source<<endl;
    bool visited[graph.getSize()] = {false};
    DFS_REC(graph,source,visited);
    cout<<endl<<endl;
}
int main(){
    
    Graph graph(6);

    graph.setEdge(0,1);
    graph.setEdge(0,4);
    graph.setEdge(0,2);
    graph.setEdge(1,4);
    graph.setEdge(1,5);
    graph.setEdge(2,4);

    graph.displayGraph();

    DFS(graph,0);
    DFS(graph,1);
    DFS(graph,2);
    DFS(graph,3);
    DFS(graph,4);
    

    return 0;
}