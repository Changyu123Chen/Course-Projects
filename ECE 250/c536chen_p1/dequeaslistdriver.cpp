//
//  main.cpp
//  dequeueaslist
//
//  Created by 陈昶宇 on 2022/10/16.
//

#include <iostream>
#include "deque.h"
int main();

int main(){
    Deque history;
    std::string line;
    std::string cmd;
    std::string url;
    int index = 0;
    getline(std::cin, line);

    while(line[index]!= ' '){
        cmd += line[index];
        index++;
    }
    index += 1;

    while(index < line.length()){
        url += line[index];
        index++;
    }

    if(cmd == "m"){
        history.max_size(stoi(url));
        std::cout << "success" << std::endl;
    }

    while(line != "exit"){
        line.clear();
        getline(std::cin, line);

        //1
        if(line.length() > 10 && line.substr(0, 10) == "push_front"){
            // 把url提取出来
            int count = 0;
            while(line[count] != ' ' && count < line.length()){
                count++;
            }
            count += 1;
            std::string name_url;
            name_url = line.substr(count, line.length());
            history.push_front(name_url);
            //history.b_print();
        }
        
        //2
        else if(line.length() > 9 && line.substr(0,9) == "push_back"){
            // 把url提取出来
            int count = 0;
            while(line[count] != ' ' && count < line.length()){
                count++;
            }
            count += 1;
            std::string name_url;
            name_url = line.substr(count, line.length());

            history.push_back(name_url);
            //history.b_print();
        }

        //3
        else if(line.length() >= 8 && line.substr(0,8) == "pop_back"){
            std::cout << history.pop_back() << std::endl;
            //history.b_print();
        }

        //4
        else if(line.length() >= 9 && line.substr(0, 9) =="pop_front"){
            std::cout << history.pop_front() << std::endl;
            //history.b_print();
        }

        //5
        else if(line.length() > 4 && line.substr(0, 4) == "find"){
            // 把url提取出来
            int count = 0;
            while(line[count] != ' ' && count < line.length()){
                count++;
            }
            count += 1;
            std::string name_url;
            name_url = line.substr(count, line.length());

            std::cout << history.find(name_url) << std::endl;
        }


        //6
        else if(line.length() > 5 && line.substr(0, 5) == "print"){
            history.b_print();
        }


        //7
        else if(line.length() >= 5 && line.substr(0, 5) == "clear"){
            history.clear();
        }

        //8
        else if(line.length() >= 5 && line.substr(0, 5) == "empty"){
            std::cout << history.empty() << std::endl;
        }


        //9
        else if(line.length() >= 5 && line.substr(0, 5) == "front"){
            history.ele_front();
        }

        //10
        else if(line.length() >= 4 && line.substr(0, 4) == "back"){
            history.ele_back();
        }

        //11
        else if(line.length() >= 8 && line.substr(0, 8) == "size"){
            std::cout <<"size is " << history.get_size() <<std::endl;
        }


    }

    return 0;
}