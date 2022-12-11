#include<iostream>
#include<vector>
// #include "illegal_exception.cpp"
using namespace std;

class Node{
    public:
        Node();
        ~Node();
        int res;
        double weight;
        Node* next;
    private:

};

class Graph{
    public:
        Graph();
        ~Graph();
        string insert(int res_a, int res_b, double wei);
        void print(int res_a);
        string deletion(int res_a);
        void get_size();
        int mst(int res_a);
    private:
        vector<Node*> v;
        int num_ver;
        // void v();
    
};

class Edge_Node{
    public:
        int a;
        int b;
        double w;
        Edge_Node();
        ~Edge_Node();
};

class Edge{
    public:
        Edge();
        ~Edge();
        void add_vector(int a, int b, double w);
        void del_vector(int a);
        vector<Edge_Node*> get_vec();
    private:
        vector<Edge_Node*> E;
};

