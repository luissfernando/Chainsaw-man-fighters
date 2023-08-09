#ifndef GAME_FONT_H
#define GAME_FONT_H
#include <SFML/Graphics.hpp>

class GameFont{
	
	public:
		GameFont(){
			if(!font.loadFromFile("Fonts/Ancient Medium.ttf")){
				//handle error

			}
		}
		
		Font *getFont(){
			return &font;
		}
		
	private:
		Font font;
};

#endif