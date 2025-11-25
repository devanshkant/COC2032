#ifndef  GRAPH_H
#define  GRAPH_H

#include<iostream>
#include<vector>
#include <list>
#include<queue>
#include<stack>
#include <unordered_map>

//this is dircted graph
using std::unordered_map, std::stack, std::queue, std::cout, std::pair;
template<typename T>
class Graph{
private:
    unordered_map<T, std::list<T>> adj; //we are not uusing std::vector 
                                        //because it will limit us to onlyy integer type nodes,
                                        // in maps the type of nodes can be made generic
public:
    void add_node(const T& node){
        adj[node];
    }
    void add_edge(const T& u, const T& v){
        adj[u].push_back(v);
        //here, u is added to the graph, it's coresponding linked list gets v as it's next node
    }

    Graph() = default;  //default constructor
    Graph(const std::vector<pair<T, T>> &edges){
        for(const auto &[u, v]: edges){
            add_edge(u, v);
        }
    }
    
    void print() const{
        for(const auto &[node, neighbour] : adj){ // in this line, node is key, neighbout is value(which is a linked list)
            std::cout << node << ':';
            for(const auto nbr: neighbour)    //choosing elements from the linked list neighbour
                std::cout << nbr << ' ';
            std::cout << '\n';
        }
    }
    //bfs traversal
    void bfs(const T& start) const{
        unordered_map<T, bool> visited;
        queue<T> q;

        q.push(start);
        visited[start]= true;
        while(! q.empty()){
            T current = q.front();
            q.pop();
            std::cout << current << ' ';
            for(const T& nbr: adj.at(current)){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        std::cout << '\n';
    }
    //dfs traversal
    void dfs(const T& start) const {
        unordered_map<T, bool> visited;
        stack<T> st;
        st.push(start);

        while (!st.empty()) {
            T curr = st.top(); st.pop();
            if (visited[curr]) continue;


            visited[curr] = true;
            std::cout << curr << " ";

            for (const T& nbr : adj.at(curr)) {
                if (!visited[nbr]) st.push(nbr);
            }
        }
        std::cout << "\n";
    }
};

#endif