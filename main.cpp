#include "HASP.h"

struct HASP* game;

using namespace std;
//This vairable is only necessary because we are using a fake "gps"

int main(){
	
	game = new HASP();
	game->start_game();
}
