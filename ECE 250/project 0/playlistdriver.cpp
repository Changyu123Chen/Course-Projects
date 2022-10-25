#include <iostream>
int main();

class Song{
public:
	std::string Playlist_size(int m_size, std::string cmd);
	std::string Add_songs(std::string cmd);
	std::string Position();
	std::string Erase();
	Song();
	~Song();
private:
	int size;
	std::string *playlist;

};

//construction
Song::Song(){
	playlist = new std::string[size];

}

//deconstruction
Song::~Song(){
	delete [] playlist;
}

//set the maximum size of the song list 
std::string Song::Playlist_size(int m_size, std::string cmd){
	if(cmd == "m"){
		size = m_size;
		for(int i{0}; i< size; ++i){ //initiate the values in the arrary to ;
			playlist[i] = ";";
		}
		return "success";
	}
	return "fail";
	
}

std::string Song::Add_songs(std::string cmd){
	//std::string cmd{"好无语"};
	std::string sa{};
	std::cin.get();
	std::string restriction;
	//std::cin >> cmd; //ask customer to choose the command to use
	getline(std::cin, sa); // song to add

	if(cmd == "i"){
		//check for fullness
		for(int i{size-1}; i>=0; --i){
			if(playlist[i] != ";"){
				return "cannot insert" + sa;
			}else{
				break; 
			}
		}

		//check for 重复

		for(int i{0}; i< size; ++i){
			if(sa == playlist[i]){
				return "can not insert " + sa;
			}
		}



		//check for restriction
		for(int i{0}; i<sa.length(); ++i){
			if(sa[i] != ';'){
				restriction += sa[i];
			}else{
				break;
			}
		}

		if(sa == "Muskrat Love; Captain and Tennille" || restriction == "My Heart Will Go On"){
			return "can not insert " + sa;
		}

		for(int i{0}; i < size; ++i){
			if(playlist[i] == ";"){
				playlist[i] = sa;
				return "success";
				break;
			}
		}
	}
	return "fail";
}

std::string Song::Position(){//从1开始算还是0
	int n{0};
	std::cin >> n;
	if(playlist[n] == ";"){
		return "can not play " + std::to_string(n);
	}else{
		return "played" + playlist[n];
	}
	return "fail";
}

std::string Song::Erase(){
	int n{0};
	std::cin >> n;
	if(playlist[n] == ";"){
		return "can not erase " + std::to_string(n);
	}else{
		for(int i{n}; i<size-1; ++i){
			playlist[i] = playlist[i+1];

		}
		playlist[size-1] = ";";
		return "success";
	}
}


int main(){
	Song playlist_1;
	std::string cmd{};
	int m_size{};
	while(true){
		std::cin >> cmd;
		if(cmd == "m"){
			std::cin >> m_size;
			std::cout << playlist_1.Playlist_size(m_size, cmd)<<std::endl;
		}

		if(cmd == "i"){
			std::cout << playlist_1.Add_songs(cmd)<<std::endl;
		}

		if(cmd == "p"){
			std::cout << playlist_1.Position()<<std::endl;
		}
		if(cmd == "e"){
			std::cout << playlist_1.Erase() << std::endl;
		}

		if(cmd == "6"){
			break;
		}
	}


	return 0;
}