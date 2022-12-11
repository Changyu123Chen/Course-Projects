#include "hash.h"
double_hash::double_hash(){
	size = 0;
	position = 0;
	SNN.resize(size);
}
double_hash::~double_hash(){}

std::string double_hash::set_size(int n){
	this-> size = n;
	SNN.resize(size);
	for(int i = 0; i<size; ++i){
		SNN[i] = "0";
	}
	return "success";
}

std::string double_hash::insert_key(std::string SN_name){
	int count = 0;
	int temp = 0;
	std::string SN_str;
	std::string SN_vector;
	while(SN_name[temp] != ' '){
		temp++;
	}
	SN_str = SN_name.substr(0, temp);

	for(int i = 0; i<size; ++i){
		if(SNN[i] != "0"){
			count += 1;
			int a = 0;
			while(SNN[i][a] != ' '){
				a++;
			}
			SN_vector = SNN[i].substr(0, a);
		}//check fullness

		if(SN_str == SN_vector){
			return "failure";//already occupied
		}
	}
	if(count == size){
		return "failure"; //table full
	}

	//check the length of student number
	int c = 0;
	for(int i = 0; i<SN_name.length(); ++i){
		if(SN_name[i] != ' '){
			c += 1;
		}else{
			break;
		}
		
	}
	unsigned int SN = stoul(SN_name.substr(0, c));
	//std::cout << SN;
	int h_1 = SN%size;
	int h_2 = (SN/size)%size;
	if(h_2%2 == 0){ //make h_2 odd
		h_2 +=1;
	}
	int h_temp = h_1;
	int i = 1;
	while(SNN[h_temp] != "0"){
		h_temp = (h_1 + i*h_2)%size;
		i++;
	}
	SNN[h_temp] = SN_name;
	return "success";
}


void double_hash::search_key(unsigned int SN){
	unsigned int student_number;
	bool found = 0;
	std::string last_name;
	for(int i = 0; i<size; ++i){
		if(SNN[i] != "0"){
			int c = 0;
			for(int j = 0; j<SNN[i].size(); ++j){
				if(SNN[i][j] != ' '){
					c++;
				}else{
					break;
				}
			}
			student_number = stoul(SNN[i].substr(0, c));
			last_name = SNN[i].substr(c+1, SNN[i].size() - c - 1);
			if(SN == student_number){
				std::cout << "found " << last_name << " in " << i << std::endl;
				found = 1;
				break;
			}
		}
	}
	if(found == 0){
		std::cout << "not found" << std::endl;
	}

}

std::string double_hash::delete_key(unsigned int SN){
	unsigned int number;

	for(int i = 0; i<size; ++i){
		if(SNN[i] != "0"){
			int c = 0;
			for(int j = 0; j<SNN[i].size(); ++j){
				if(SNN[i][j] != ' '){
					c++;
				}else{
					break;
				}
			}
			number = stoul(SNN[i].substr(0, c));
			if(number == SN){
				SNN[i] = "0";
				return "success";
			}
		}
	}
	return "failure";
}