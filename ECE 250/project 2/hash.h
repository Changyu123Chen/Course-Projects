#include <iostream>
#include <string>
#include <vector>

class double_hash{
public:
	//constructor
	double_hash();
	~double_hash();
	//desctructor
	std::string set_size(int n);
	//insertion
	std::string insert_key(std::string SN_name);
	//search
	void search_key(unsigned int SN);
	//delete
	std::string delete_key(unsigned int SN);
	//function
	// void double_function(unsigned int SN);

private:
	int size;
	int position;
	std::vector<std::string> SNN;

};







class chaining{
public:
	//constructor:
	chaining();
	//destructor:
	~chaining();
	//size
	std::string set_size(int n);
	//this->size = n;

	//insert
	std::string insert_key(std::string SN_name);
	//delete
	std::string delete_key(unsigned int SN);
	//search:
	void search_key(unsigned int SN);
	//print
	void print_key(int n);
	//function
	int function(unsigned int SN);

private:
	int size;
	int position;
	std::vector<std::vector<std::string> > SNN;
	unsigned int get_SN(int i, int j);
	std::string get_name(int i, int j);

};



