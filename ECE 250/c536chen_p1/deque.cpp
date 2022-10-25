//
//  deque.cpp
//  dequeueaslist
//
//  Created by 陈昶宇 on 2022/10/16.
//

#include "deque.h"
//Node constructor
Node::Node(){
    data = 'a';
    prev = nullptr;
    next = nullptr;
}

// //Node deconstructor
Node::~Node(){
    next = NULL;
    prev = NULL;
}


//Deque constructor
Deque::Deque(){
    head = nullptr;
    tail = nullptr;
    size = 0;
    max = 0;
}
Deque::~Deque(){
    head = nullptr;
    tail = nullptr;
}

//return the max size of the deque O(1)
void Deque::max_size(int n){
    max = n;
}

//insert element at the front O(1)
void Deque::push_front(std::string data){
    Node* p_head = new Node;
    p_head -> data = data;
    p_head -> prev = nullptr;
    p_head -> next = nullptr;
    int i;
    if(head == nullptr){
        i = 0;
    }else{
        i = 1;
    }
    switch(i){
        case 0:
            tail = p_head;
            head = tail;

            break;
        case 1:
            p_head -> next = head;
            head -> prev = p_head;
            break;

    }
    head = p_head;

    size++;
    //判断加入值之后，deque的大小有没有超过最大值，超过了的话就删
    if(size > max){
        pop_back();
    }
    
    std::cout << "success"<<std::endl;
    //delete[] p_head;
}

//末尾加 O(1)
void Deque::push_back(std::string data){
    Node* p_head = new Node;
    p_head -> data = data;
    p_head -> prev = nullptr;
    p_head -> next = nullptr;

    int j = 0;
    if(head == nullptr){
        j = 0;
    	// head = p_head;
    	// tail = p_head;
    }else{
        j = 1;
    	//p_head -> next = nullptr;
    	// p_head -> prev = tail;
    	// tail -> next = p_head;
    }

    switch(j){
        case 0:
            head = p_head;
            tail = p_head;
            break;


        case 1:
            p_head -> prev = tail;
            tail -> next = p_head;
            break;

    }
    tail = p_head;

    size++;
    //判断加入值之后，deque的大小有没有超过最大值，超过了的话就删
    if(size > max){
        pop_front();
    }
    
    std::cout << "success"<<std::endl;
    //delete[] p_head;
}

//删除第一个，减小大小 O(1)
std::string Deque::pop_front(){
    Node* p_temp = head;
    if(head == nullptr){
        return "failure";
    }else{
        head = head-> next;
        if(head != nullptr){
            head->prev = nullptr;
            return "success";
            size--;
        }else{
            tail = nullptr;
            return "success";
            size--;
        }
        // delete[] p_temp;
        
        
    }
    
    //delete[] p_temp;
    return "failure";
}
//删最后一个，减小大小 O(1)
std::string Deque::pop_back(){
    Node* p_temp = tail;
    if(head == nullptr){
        return "failure";
    }else{
        tail = tail->prev;
        if(tail != nullptr){
            tail-> next = nullptr;
            size--;
            return "success";
        }else{
            head = nullptr;
            size--;
            return "success";
        }
        // delete[] p_temp;
        

    }
    //delete[] p_temp;
    return "failure";
}

//删除所有element O(n)
void Deque::clear(){
    Node* p_temp = new Node;
    while(head != nullptr){
        p_temp = head;
        head = head->next;
        free(p_temp);
        //head -> prev = nullptr;
    }
    tail = nullptr;
    size = 0;
    std::cout << "success" << std::endl;
}
//链表大小 O(1)
int Deque::get_size(){
    return size;
}
//输出第一个node的值 O(1)
void Deque::ele_front(){
    if(head == nullptr){
        std::cout << "failure"<<std::endl;
    }else{
        std::cout << "front is " << head->data << std::endl;
    }
}
//输出最后一个的值 O(1)
void Deque::ele_back(){
    if(head == nullptr){
        std::cout << "failure" << std::endl;
    }else{
        std::cout << "back is " << tail->data << std::endl;
    }
    
}
//判断deque是否为空 O(1)
std::string Deque::empty(){
    if(size == 0){
        return "empty 1";
    }else{
        return "empty 0";
    }
}
//查找
std::string Deque::find(std::string url_name){
    if(head != nullptr){
        Node* p_temp;
        for(p_temp = head; p_temp!= nullptr; p_temp = p_temp -> next){
            if(p_temp -> data == url_name){
                return "found " + url_name;
            }
        }
        //delete [] p_temp;
    }
    return "not found " + url_name;
}
//从后向前输出值
void Deque::b_print(){
    Node* p_temp = head;
    if(head == nullptr){
        std::cout << "deque is empty" << std::endl;
    }else{
        
        for(p_temp = tail; p_temp != nullptr; p_temp = p_temp->prev){
            std::cout << p_temp -> data << std::endl;
        }
    // std::cout << std::endl;
    }
}

//exit


