//
//  deque.h
//  dequeueaslist
//
//  Created by 陈昶宇 on 2022/10/16.
//

#ifndef deque_h
#define deque_h

#include <iostream>
#include <string>

class Node{
public:
    Node();
    ~Node();
    std::string data;
    Node* prev;
    Node* next;

    
};

class Deque{
public:
    Deque();
    ~Deque();
    //max size of deque
    void max_size(int n);//n is the max size of the deque
    //insert element at the front
    void push_front(std::string data);
    //末尾加
    void push_back(std::string data);
    //删除第一个，减小大小
    std::string pop_front();
    //删最后一个，减小大小
    std::string pop_back();
    //删除所有element
    void clear();
    //链表大小
    int get_size();
    //输出第一个node的值
    void ele_front();
    //输出最后一个的值
    void ele_back();
    //判断deque是否为空
    std::string empty();
    //查找
    std::string find(std::string url_name);
    //从后向前输出值
    void b_print();
//    //exit
//    void exit();
private:
    Node* head;
    Node* tail;
    int size;
    int max;
    
    
};
#endif /* deque_h */
