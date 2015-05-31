#ifndef stan_h
#define stan_h

#include "window.hpp"

class Stan
{
	public:
    	Stan(Window m, std::string s, int health, int light, int x, int y);
		SDL_Texture* loadTexture(std::string path, Window main);
    	void Place();
		void movement(SDL_Event& e);
		int getHealth();
		int getLight();
		int getX();
		int getY();
		int getSpeed();
		void setDirection(int x);
		int getDirection();

	protected:
    	int xPosition, yPosition; //Coordinates of entity on window
		int height, width; //Dimensions of image on window
		int degrees = 0;
		SDL_Texture* texture;
		SDL_Renderer* renderer;

	private:
		int health = 100;
		int light = 100;
		int speed = 20;
		int direction = 1; //1 - forward; 2 - backward; 3 - left; 4 - right;
};

#endif
