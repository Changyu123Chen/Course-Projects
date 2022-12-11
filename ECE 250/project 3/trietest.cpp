#include "trie.h"

int main(){
    Trie a;
    Node* root = new Node();
    illegal_exception c;
    //load corpus 文件
    std::ifstream input("corpus.txt");
    std::string cmd;
    std::string word;
    while(std::cin >> cmd){
        if(cmd == "load"){
            while(input >> word){
                a.insert(root, word);
                // std::cout << word << " ";
            }
            std::cout << "success" << std::endl;
        }
        if(cmd == "p"){
            a.print(root);
            if(a.get_size() != 0){
                std::cout << std::endl;
            }
        }
        if(cmd == "empty"){
            std::cout << a.empty() << std::endl;
        }

        if(cmd == "size"){
            a.count();
        }

        if(cmd == "exit"){
            break;
        }
        if(cmd == "clear"){
            std::cout << a.clear(root)<<std::endl;
        }

        if(cmd == "i"){
            std::string w;
            std::cin >> w;
            try{
                std::cout << a.insert(root, w)<<std::endl;
            }catch(illegal_exception &a){
                c.printException();
            }
        }

        if(cmd == "s"){
            std::string w;
            std::cin >> w;
            try{
                std::cout << a.search(root, w)<<std::endl;
            }catch(illegal_exception &a){
                c.printException();
            }
            
        }

        if(cmd == "e"){
            std::string w;
            std::cin >> w;
            try{
                std::cout << a.erase(root, w)<<std::endl;
            }catch(illegal_exception &a){
                c.printException();
            }
            
        }

        if(cmd == "spellcheck"){
            std::string w;
            std::cin >> w;
            a.spellcheck(root, w);
            // std::cout << std::endl;
            // a.get_words();
        }
        
    }



    delete root;
    return 0;
}