#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using std::stack;
using std::vector;
using std::queue;
class Graph{
    private:
        vector<int> *adj;
        int size;
    public:
        Graph(int size)
        {
            this->size=size;
            this->adj = new vector<int>[this->size];
        }

        void Insert(int u,int v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
            std::cout<<"Inserted"<<std::endl;
        }
        void BFS(int start)
        {
            
            vector<bool> visited(this->size,false);
            
            queue<int> qt;

            qt.push(start);
            visited[start]=true;
            std::cout<<"BFS Entered"<<std::endl;
            

            while(!qt.empty())
            {
                int temp = qt.front();
                qt.pop();

                std::cout<<"BFS-> "<<temp<<std::endl;
                for(int n : this->adj[temp])
                {
                
                    if(!visited[n])
                    {
                        visited[n]=true;
                        qt.push(n);
                    }
                }
            }

        }
        void DFS(int start)
        {
            vector<bool> visited(this->size,false);
            stack<int> st;


            st.push(start);
            visited[start]=true;

            while(!st.empty())
            {
                int temp = st.top();
                st.pop();

                std::cout<<"DFS-> "<<temp<<std::endl;

                for(int n:this->adj[temp])
                {
                    if(!visited[n])
                    {
                        visited[n]=true;
                        st.push(n);
                    }
                }
            }
            
        }

};