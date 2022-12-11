#include "graph.h"
#include "illegal_exception.h"

Edge e;
Node::Node(){
    res = 0;
    weight = 0;
    next = NULL;
}

Node::~Node(){
    delete next;
}

Graph::Graph(){
    num_ver = 0;
    v.resize(num_ver, NULL);

}

Graph::~Graph(){
    for(int i = 0; i< v.size(); ++i){
        delete v[i];
    }
    v.clear();
}

string Graph::insert(int res_a, int res_b, double wei){
    // invalid input
    if(res_a > 23133 || res_b <= 0 || res_a <= 0 || res_b > 23133 || wei < 0 || wei > 1){
        throw illegal_exception();
    }
    // exist
    if(num_ver == 0){
        Node* t_a = new Node();
        Node* t_b = new Node();
        t_a ->res = res_a;
        t_b ->res = res_b;
        v.push_back(t_a);
        v.push_back(t_b);
        Node* adj = new Node();
        adj ->res = res_b;
        adj ->weight = wei;
        adj ->next = NULL;
        Node* p = v[0];
        p->next = adj;
        num_ver = 2;

        e.add_vector(res_a, res_b, wei);
        return "success";
    }

    bool ex_b = 0;
    int index_a = -1;
    for(int i = 0; i<num_ver; ++i){
        if(v[i]->res == res_a){
            index_a = i;
        }
        if(v[i]->res == res_b){
            ex_b = 1;
        }
    }

    if(index_a != -1 && ex_b != 0){
        Node* temp = v[index_a];
        while(temp != NULL){
            if(temp->res == res_b){
                return "failure";
            }
            // cout << "sha" << endl;
            temp = temp->next;
        }
    }

    if(index_a == -1){
        Node* t_a = new Node();
        t_a ->res = res_a;
        v.push_back(t_a);
        index_a = v.size()-1;
    }
    if(!ex_b){
        Node* t_b = new Node();
        t_b ->res = res_b;
        v.push_back(t_b);
    }
    num_ver = v.size();

    Node* temp = v[index_a];
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* adj = new Node();
    adj ->res = res_b;
    adj ->weight = wei;
    adj->next = NULL;
    temp->next = adj;
    e.add_vector(res_a, res_b, wei);
    return "success";
    
}

void Graph::print(int res_a){
    if(res_a <= 0 || res_a > 23133){
        throw illegal_exception();
    }
    for(int i = 0; i<v.size(); ++i){
        if(v[i] -> res == res_a){
            Node* a = v[i]->next;
            while(a != NULL){
                cout << a->res << " ";
                a = a->next;
            }
            break;
        }
    }
    cout << endl;
}

string Graph::deletion(int res_a){
    if(res_a <= 0 || res_a > 23133){
        throw illegal_exception();
    }
    int index_a = -1;
    for(int i = 0; i< v.size(); ++i){
        if(v[i] -> res == res_a){
            index_a = i;
        }
    }
    if(index_a == -1){
        return "failure";
    }

    delete v[index_a];
    v.erase(v.begin() + index_a);
    // cout << "success" <<endl;
    for(int i = 0; i< v.size(); ++i){
        if(v[i]->next != NULL){
            Node* prev = v[i];
            Node* curr = v[i]->next;
            while(curr != NULL && curr->res != res_a){
                prev = curr;
                curr = curr->next;
            }
            if(curr != NULL){
                prev->next = curr->next;
                free(curr);
            }
        }
    }

    e.del_vector(res_a);
    return "success";

}

void Graph::get_size(){
    num_ver = v.size();
    cout << "number of vertices is " << num_ver << endl;
}

int Graph::mst(int res_a){
    if(v.size() == 0){
        cout << "?"<<endl;
        return -9;
    }
    bool ex_v = 0;
    for(int i = 0; i<v.size(); ++i){
        if(v[i]->res == res_a){
            ex_v = 1;
            break;
        }
    }
    if(!ex_v){
        return -10;
    }
    vector<int> vertex;
    vector<int>temp;
    vector<Edge_Node*> E;
    E = e.get_vec();
    vertex.push_back(res_a);
    for(int i = 0; i<E.size(); ++i){
        if(E[i]->a == res_a){
            vertex.push_back(E[i]->b);
            E[i]->w = -100;
        }
    }
    int count = 1;
    // while(count != 0){
    //     count = 0;
    //     temp.clear();
    //     for(int i = 1; i<vertex.size(); ++i){
    //         for(int j = 0; j<E.size(); ++j){
    //             if(vertex[i] == E[j]->a){
    //                 //判断b在不在vertex里面
    //                 bool ex_b = 0;
    //                 for(int k = 0; k<vertex.size(); ++k){
    //                     if(vertex[k] == E[j]->b){
    //                         ex_b == 1;
    //                     }
    //                 }
    //                 //
    //                 if(ex_b == 0){
    //                     temp.push_back(E[j]->b);
    //                 }
    //             }
    //         }
    //     }
    //     for(int i = 0; i<vertex.size(); ++i){
    //         cout << vertex[i] << " ";
    //     }
    //     cout << endl;
    //     count = temp.size();
    //     if(count != 0){
    //         for(int i = 0; i<temp.size(); ++i){
    //             vertex.push_back(temp[i]);
    //         }
    //     }
    // }
    
    return vertex.size();


}

Edge_Node::Edge_Node(){
    a = 0;
    b = 0;
    w = 0.0;
}

Edge_Node::~Edge_Node(){
    
}

Edge::Edge(){
    E.resize(0, NULL);
}
Edge::~Edge(){
    for(int i = 0; i< E.size(); ++i){
        delete E[i];
    }
    E.clear();
}

void Edge::add_vector(int a, int b, double w){
    Edge_Node* vertex = new Edge_Node();
    vertex->a = a;
    vertex->b = b;
    vertex->w = w;
    E.push_back(vertex);
}

void Edge::del_vector(int a){
    for(int i = 0; i< E.size(); ++i){
        if(E[i]->a == a || E[i]->b == a){
            delete(E[i]);
            
        }
    }
}

vector<Edge_Node*> Edge::get_vec(){
    return E;
}