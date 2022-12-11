#include "trie.h"
//illegal exception
void illegal_exception::printException(){
    std::cout << "illegal argument" << std::endl;
}

//TrieNode
Node::Node(){
    for (int i = 0; i<26; ++i){
        next[i] = NULL;
    }
    isalphabet = false;
    s = "";
}

Node::~Node(){
    for(int i=0; i< 26; ++i){
        if(next[i]){
            delete next[i];
        }
    }
}

// Trieの天下
//constructor
Trie::Trie(){
    root = new Node();
    num = 0;
    words.clear();
    
}
//destructor
Trie::~Trie(){
    delete root;
}

//insert
std::string Trie::insert(Node* &root, std::string word){
    Node* a = root;
    std::string x;
    //check if the word is already in the tree;
    x = search(root, word);
    if(x[0] == 'f'){
        return "failure";
    }
    //check for illegal input;
    for(int i =0; i<(int)word.size();++i){
        if((int)word[i] < 97 || (int)word[i] > 122){
            throw illegal_exception();
        }
    }
    //insert the word
    for(int i=0; i<(int)word.size(); ++i){
        if(a->next[word[i]-'a'] == NULL){
            a->next[word[i]-'a'] = new Node();
        }
        a = a->next[word[i] - 'a'];
        // a -> isalphabet = false;
    }
    a-> isalphabet = true;
    a-> s = word;
    num += 1;
    
    return "success";
}

//search
std::string Trie::search(Node* root, std::string word){
    Node *a = root;
    //check for illegal input
    for(int i =0; i<(int)word.size();++i){
        if((int)word[i] < 97 || (int)word[i] > 122){
            throw illegal_exception();
        }
    }

    //check if the word is in the tree
    for(int i=0; i<(int)word.size(); ++i){
        char b = word[i];
        if(a->next[b-'a'] == NULL){
            return "not found";
        }
        a = a->next[b - 'a'];

    }
    if(a->isalphabet == true){
        return "found " + a->s;

    }else{
        return "not found";
    }
}

//empty
std::string Trie::empty(){
    if(num == 0){
        return "empty 1";
    }else{
        return "empty 0";
    }
}

//erase
std::string Trie::erase(Node *root, std::string word){
    std::string Empty;
    std::string Search;
    Node *a = root;
    //check for illegal input
    for(int i =0; i<(int)word.size();++i){
        if((int)word[i] < 97 || (int)word[i] > 122){
            throw illegal_exception();
        }
    }

    //check if the trie is empty / word is in the list
    Empty = empty();
    Search = search(root, word);
    if(Empty == "empty 1" || Search == "not found"){
        return "failure";
    }

    //word is in the trie and needs to be erased
    for(int i=0; i<(int)word.size(); ++i){
        a = a->next[word[i] - 'a'];
    }
    a -> isalphabet = false;
    a -> s = "";
    num -= 1;
    return "success";
}

//size
void Trie::count(){
    std::cout << "number of words is: " << num << std::endl;
}

//clear 
std::string Trie::clear(Node* root){
    if(!root){
        return "success";
    }
    if(root->isalphabet){
        root->isalphabet = false;
    }
    for(int i=0; i<26; ++i){
        clear(root->next[i]);
    }
    num = 0;
    return "success";
}

//print
void Trie::print(Node* root){
	if(!root){
		return;
	}
	if(root->isalphabet){
		std::cout<<root->s << " ";
	}
	for(int i=0; i<26; ++i){
		print(root->next[i]);
	}
}

//spellcheck
void Trie::spellcheck(Node* root, std::string word){
    Node* a = root;
    std::string check;
    words.clear();
    bool first_letter = 0;
    //check if the word is in the trie
    check = search(root, word);
    if(check[0] == 'f'){
        std::cout << "correct" << std::endl;
    }else if(a->next[word[0] - 'a'] == NULL ){
        std::cout << std::endl;
    }else{
        helper_check(root);
        
        while(word.size()!= 0){
            bool finished = 0;
            for(int i = 0; i<words.size(); ++i){
                if(word == words[i].substr(0, word.size())){
                    std::cout << words[i] << " ";
                    finished = 1;
                }
            }
            if(finished == 1){
                break;
            }else{
                word = word.substr(0, word.size()-1);
            }
        }
        std::cout << std::endl;

    }
    
}

//helper function: used in spellcheck DFT
void Trie::helper_check(Node* a){
    if(!a){ //if NULL return
        return;
    }
    if(a->isalphabet == true){
        words.push_back(a->s);
    }
    for(int i = 0; i<26; ++i){
        helper_check(a->next[i]);
    }
}

int Trie::get_size(){
    return num;
}

// void Trie::get_words(){
//     for(int i = 0; i<words.size(); ++i){
//         std::cout << words[i] << " ";
//     }
// }