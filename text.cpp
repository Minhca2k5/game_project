#include "text.h"

void Text::content(string path) {
	text = path;
}
void Text:: set_color(int tp) {
	if (tp == BLACK) color = { 0,0,0 };
}
void Text::showex(TTF_Font* font) {
	SDL_Surface* t = TTF_RenderText_Solid(font, text.c_str(), color);
	image = SDL_CreateTextureFromSurface(screen, t);
	SDL_FreeSurface(t);
	ape1();
}