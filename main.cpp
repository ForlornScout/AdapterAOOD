#include <iostream>

using namespace std;

class TTwarGames { 
	public:
	
		virtual	void fun() = 0; 
		virtual void price() = 0; 
    virtual void gw() = 0;
}; 

class BoltAction : public TTwarGames { 
	
	public:
		void fun() { 
			cout << "Its WWII whats not to like?\n"; 
		} 
		void price() { 
			cout << "Reasonable\n"; 
		} 
    void gw() {
      cout <<"N/a\n";
	
		} 
}; 

class BattleTech : public TTwarGames { 
	 
	public:
		void fun() { 
			cout << "Stompy Neo-Feudal robots, awesome\n"; 
		} 
		void price() { 
			cout << "Reasonable\n"; 
		} 
    void gw() {
      cout <<"N/a\n";
	
		} 
}; 

  class warhammer40k : public TTwarGames { 
	 
  	public:
    void fun() { 
			cout << "Its like a fantasy series but if you made it Sci-fi and gave it Crack\n"; 
		} 
		void price() { 
			cout << "Too much\n"; 
    }
    void gw() {
      cout <<"Its basically crack\n";
	
		} 
}; 
class Warhammer40k { 
	
	public:
		virtual void stop() = 0; 
}; 

class PlasticCrack: public Warhammer40k { 
	public:
		void stop() { 
			cout << "Just don't, its fun but expensive\n"; 
		} 
};


class GameAdapter: public Warhammer40k { 
	
	TTwarGames* games; 
	public:
		GameAdapter(TTwarGames* new_game) { 
			
			games = new_game; 

		} 

		void stop() { 
			
			games->price(); 
		} 
};

int main() { 
	BoltAction* ba = new BoltAction;

  BattleTech* bt = new BattleTech;
  warhammer40k* wk = new warhammer40k;

	Warhammer40k* wh = new PlasticCrack;
	
  Warhammer40k* gameAdapter = new GameAdapter(wk); 

	cout << "Bolt Action?\n"; 
	ba->fun(); 
	ba->price(); 

	cout << "Battletech?\n"; 
	bt->fun(); 
  bt-> price();

  cout<< "Warhammer 40k\n";
  wk->fun();
  wk->price();
  wh->stop();

  cout << "GameAdapter\n"; 
	 gameAdapter->stop(); 
}