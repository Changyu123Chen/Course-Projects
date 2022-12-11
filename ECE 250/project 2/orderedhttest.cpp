#include "hash.h"
#include <iostream>
int main(){
	chaining table;
	int n = 0;
	std::string command;
	getline(std::cin, command);
	if(command[0] == 'm'){
		n = stoi(command.substr(2,command.size() - 2));
		command = command.substr(0, 1);
	}
	if(command == "m"){
		std::cout << table.set_size(n) << std::endl;
	}

	while(true){
		std::string command;
		std::string cmd;
		std::string snn;
		std::string last_name;
		unsigned int sn;
		int cases = 0;
		int n = 0;
		getline(std::cin, command);
		if(command == ""){
			break;
		}
		cmd = command.substr(0, 1);
		if(cmd == "p"){
			cases = 4;
			n = stoi(command.substr(2, command.size()-2));
		}else if(cmd == "i"){
			cases = 1;
			snn = command.substr(2, command.size()-2);
			int i = 0;
			while(snn[i] != ' '){
				i++;
			}
			sn = stoul(snn.substr(0, i));
		}else if(cmd == "s"){
			cases = 2;
			sn = stol(command.substr(2, command.size()-2));
		}else if(cmd == "d"){
			cases = 3;
			sn = stol(command.substr(2, command.size()-2));
		}

		switch(cases){
			case 1:
				std::cout << table.insert_key(snn) << std::endl;
				break;
			case 2:
				table.search_key(sn);
				break;

			case 3:
				std::cout << table.delete_key(sn) << std::endl;
				break;

			case 4:
				table.print_key(n);
				break;

		}	
	}

	return 0;
}