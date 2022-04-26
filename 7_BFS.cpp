#include<iostream>
#include<queue>
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
void BFS(Graph &graph,int  source){
    cout<<"Source : "<<source<<endl;;
    bool visited[graph.getSize()] = {false};
    visited[source] = true;
    queue<int> Queue;
    Queue.push(source);
    while (!Queue.empty()){
        int node = Queue.front();
        cout<<node<<" ";
        Queue.pop();
        for (int i = 0; i < graph.getSize(); i++){
            if (graph.isConnected(node,i) && !visited[i]){
                visited[i] = true;
                Queue.push(i);
            }
        }
    }
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

    BFS(graph,0);
    BFS(graph,1);
    BFS(graph,2);
    BFS(graph,3);
    BFS(graph,4);
    BFS(graph,5);

    return 0;
}