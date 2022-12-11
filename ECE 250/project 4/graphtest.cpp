#include <iostream>
#include <fstream>
#include "graph.h"
#include "illegal_exception.h"
int main(){
    illegal_exception c;
    Graph a;
    ifstream input("paperCollabWeighted.txt"); //paperCollabWeighted
    string cmd;
    double num;
    while(cin >> cmd){
        if(cmd == "load"){
            int res_a = 0;
            int res_b = 0;
            double wei = 0.0;
            int count = 0;
            while(input >> num){
                count++;
                if(count == 1){
                    res_a = num;
                }else if(count == 2){
                    res_b = num;
                }else if(count == 3){
                    wei = num;
                    a.insert(res_a, res_b, wei);
                    count = 0;
                }
            }
            cout<<"success"<<endl;
        }
        //insert
        if(cmd == "i"){
            int res_a = 0;
            int res_b = 0;
            double wei = 0.0;
            cin >> res_a;
            cin >> res_b;
            cin >> wei;
            try{
                cout<<a.insert(res_a, res_b, wei)<<endl;
            }catch(illegal_exception &a){
                c.printException();
            }
        }
        //print
        if(cmd == "p"){
            int res_a = 0;
            cin >> res_a;
            try{
                a.print(res_a);
            }catch(illegal_exception &a){
                c.printException();
            }
        }
        //delete
        if(cmd == "d"){
            int res_a = 0;
            cin >> res_a;
            try{
                cout << a.deletion(res_a) << endl;
            }catch(illegal_exception &a){
                c.printException();
            }
            
        }
        //mst
        if(cmd == "mst"){
            int res_a = 0;
            cin >> res_a;
            int check = 0;
            check = a.mst(res_a);
            if(check < 0){
                cout << "failure"<<endl;
            }else{
                cout << check << endl;
            }
        }
        //size
        if(cmd == "size"){
            a.get_size();
        }
        //exit
        if(cmd == "exit"){
            break;
        }
    }

    return 0;
}