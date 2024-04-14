#ifndef GENERAL_H_
#define GENERAL_H_
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<windows.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int WIDTH = 1500;
const int HEIGHT = 600;

extern SDL_Window* window;
extern SDL_Renderer* screen;
extern vector<SDL_Texture*>bg;
extern SDL_Event e;

static Mix_Chunk* sound[6];

namespace pdm {
	void add_bg();
	SDL_Texture* loadtexture(const string& path);
	void close();
	bool ktvc(const SDL_Rect& rect1, const SDL_Rect& rect2);
	void show1(SDL_Texture* image, int x, int y, int w, int h);
	void show2(SDL_Texture* image, int x, int y, int w, int h, SDL_Rect set);
	void show3(SDL_Texture* image, int x, int y, int w, int h);
	void show(TTF_Font* font);
}
#endif // !1
