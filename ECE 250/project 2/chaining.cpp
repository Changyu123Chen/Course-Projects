#include "hash.h"
//constructor
using namespace std;
chaining::chaining(){
	size = 0;
	position = 0;
	vector<vector<std::string> > SNN(size);

}
//destructor
chaining::~chaining(){};

//set the row of the vector
std::string chaining::set_size(int n){
	this->size = n;
	SNN.resize(n);
	for(int i = 0; i<size; ++i){
		SNN[i].resize(1, "0");
	}
	//std::cout << SNN.size() << std::endl;
	return "success";
}

//insert keys by chaining (column of the vector)
std::string chaining::insert_key(std::string SN_name){
	//get SN from SN_name
	int count = 0;
	unsigned int num_string = 0;
	unsigned int num_vector = 0;
	int h_1;
	int sz;
	while(SN_name[count] != ' '){
		count++;
	}
	num_string = stoul(SN_name.substr(0, count));

	//get the position, size of the vector
	h_1 = function(num_string);
	sz = SNN[h_1].size();
	//check for duplication
	for(int i = 0; i < sz; ++i){
		unsigned int num = get_SN(h_1, i);

		if(num == num_string){
			return "failure";
		}
	}
	//case 1: SNN[h_1][0] = "0";
	if(SNN[h_1][0] == "0"){
		SNN[h_1][0] = SN_name;
		//std::cout << SNN[h_1][0] << std::endl;
		return "success";
	}else if(SNN[h_1][sz-1] != "0"){ //num_string is the smallest + resize
		SNN[h_1].resize(sz+1, "0");
		num_vector = get_SN(h_1, sz-1);
		if(num_string < num_vector){
			SNN[h_1][sz] = SN_name;
			return "success";

		}else{ //普通情况　
			//SNN[h_1].resize(sz+1);
			for(int i = 0; i < sz; ++ i){
				num_vector = get_SN(h_1, i);
				if(num_string > num_vector){
					for(int j = sz; j >= i; --j){
						SNN[h_1][j] = SNN[h_1][j-1];
					}
					SNN[h_1][i] = SN_name;
					return "success";
				}

			}
		}
	}
	

	return "failure";
}

//h_1 function return the row to insert
int chaining::function(unsigned int SN){
	position = SN%size;
	return position;
}

//help function, used to get the student number in each vector
unsigned int chaining::get_SN(int i, int j){
	int count = 0;
	unsigned int num = 0;
	while(SNN[i][j][count] != ' '){
		count++;
	}

	num = stoul(SNN[i][j].substr(0, count));
	return num;
}

std::string chaining::get_name(int i, int j){
	std::string name;
	int count = 1;
	int sz = SNN[i][j].size();
	while(SNN[i][j][count] != ' '){
		count++;
	}
	name = SNN[i][j].substr(count, sz-count);
	return name;
}
//delete
std::string chaining::delete_key(unsigned int SN){
	int h_1 = 0;
	int sz = 0;
	unsigned int num_vector;
	h_1 = function(SN);//get the row  sn may at
	sz = SNN[h_1].size();
	//case 1: row is empty
	if(SNN[h_1][0] == "0"){
		return "failure";
	}else if(sz == 1){ //only one element in this row check equality
		num_vector = get_SN(h_1, 0);
		if(SN == num_vector){
			SNN[h_1][0] = "0";
			return "success";
		}
	}
	//check if SN is the smallest
	num_vector = get_SN(h_1, sz-1);
	if(num_vector == SN){
		SNN[h_1][sz-1] == "0";
		SNN[h_1].resize(sz-1);//删除等于0的vector元素
		return "success";
	}

	//normal condition, SN is neither max or min
	for(int i = 0; i< sz; ++i){
		num_vector = get_SN(h_1, i);
		if(SN == num_vector){
			SNN[h_1].erase(SNN[h_1].begin() + i);
			return "success";
			break;
		}
	}

	return "failure";




}

//search:
void chaining::search_key(unsigned int SN){
	int h_1;
	int sz = 0;
	std::string name;
	unsigned int num_vector;
	bool found = 0;
	h_1 = function(SN);
	sz = SNN[h_1].size();
	for(int i = 0; i<sz; ++i){
		if(SNN[h_1][i] != "0"){
			num_vector = get_SN(h_1, i);
			name = get_name(h_1, i);
			if(SN == num_vector){
				std::cout<<"found " << get_name(h_1, i) << " in " << h_1 << std::endl;
				found = 1;
			}
		}
		
	}
	if(found == 0){
		std::cout << "not found" << std::endl;
	}
	
}
//print
void chaining::print_key(int n){
	int col = SNN[n].size();
	unsigned int num_vector;
	if(SNN[n][0] != "0"){
		for(int i = 0; i < col; ++i){
			if(SNN[n][i] != "0"){
				num_vector = get_SN(n, i);
				std::cout << num_vector << " ";
			}
		}	
		std::cout << std::endl;
	}else{
		std::cout << "chain is empty" << std::endl;
	}
}














