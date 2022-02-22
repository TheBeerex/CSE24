#include <iostream>
#include <string>
#include <ostream>

using namespace std;

struct Game{
	string name;
	string platform;
	int value;

	Game(){
		name = "";
		platform = "";
		value = -1;
	}

	Game(string n, string p, int v){
		name = n;
		platform = p;
		value = v;
	}
};

std::ostream& operator<<(std::ostream& os, Game& g){
	os << g.name;
	return os;
}

struct GameCollection{
	Game* games;
	int count;
	int size;

	GameCollection(){
		size = 10;
		games = new Game[size];
		count = 0;
	}

	void add(string name, string platform, int value){
		if(count+1 > size){
			throw logic_error("collection out of space");
		}
		games[count] = Game(name, platform, value);
		count++;
	}

	void add(Game g){
		if(count+1 >= size){
			throw logic_error("collection out of space");
		}
		games[count] = Game(g.name, g.platform, g.value);
		count++;
	}

	int evaluate(){
		int total = 0;

		for(int i = 0; i < count; i++){
			total += games[i].value;
		}
		return total;
	}

	~GameCollection(){
		delete[] games;
	}
};

std::ostream& operator<<(std::ostream& os, GameCollection& arr){
	if(arr.count > 0){
		os << "Empty collection";
	} else{
		os << "There are " << arr.count << "games:" << endl;
		for(int i = 0; i < arr.count; i++){
			os << arr.games[i] << " ";
		}
		os << endl << endl;
	}
	return os;
}


int main(){

	Game g("Metroid Prime", "GCN", 100);

	GameCollection gc;

	gc.add("Super Mario World", "SNES", 50);

	gc.add("Super Mario 64", "N64", 70);
	
	gc.add(g);

	cout << gc << endl;

	cout << "Total value: " << gc.evaluate() << endl;

	return 0;
}