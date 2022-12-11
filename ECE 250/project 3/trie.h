#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//illegal arguments
class illegal_exception{
    public:
        void printException();
    

};

//TreeNode
class Node{
    public:
        //constructor
        Node();
        //destructor
        ~Node();
        Node* next[26];
        bool isalphabet;
        std::string s; //if isEnd, store the word
};

//Implement tree
class Trie{
    public:
        //constructor √
        Trie();
        //destructor √
        ~Trie();
        //insert √
        std::string insert(Node* &root, std::string word);
        //search √
        std::string search(Node* root, std::string word);
        //erase √
        std::string erase(Node* root, std::string word);
        //size √
        void count();
        //empty √
        std::string empty();

        //print √
        void print(Node* root);
        //spellcheck √
        void spellcheck(Node* root, std::string word);
        //clear √
        std::string clear(Node* root);
        int get_size();
    private:
        Node* root;
        int num;
        //std::string word;
        std::vector<std::string> words;
        void helper_check(Node* a);
        

        
};
