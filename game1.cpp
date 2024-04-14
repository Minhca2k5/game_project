#include "game1.h"
Game1::Game1() {
	dc = 0;
	check = false;
	nhay = true;
}
void Game1::set_clip() {
	int x = 0;
	for(int i=0;i<8;i++){
		nv[i].x = x;
		nv[i].y = 0;
		nv[i].w = W;
		nv[i].h = H;
		x += W;
	}
}
void Game1::set_show() {
	setrc(nv[fr].x, nv[fr].y, nv[fr].w, nv[fr].h);
	ape2();
}
void Game1::dich_handle() {
	rect.x -= 5;
	if (rect.x < 0) rect.x = WIDTH;
}
void Game1::nut() {
	if(e.key.keysym.sym==SDLK_SPACE){
		if (!check) {
			check = true;
			dc = MAX_H;
		}
	}
	else if (e.key.keysym.sym == SDLK_a) {
		nhay = true;
	}
}
void Game1::handle() {
	if (check) {
		if (nhay) {
			rect.y -= 10;
			dc -= 8;
			if (dc <= 0) check = false;
		}
	}
	else {
		if (rect.y < 440) rect.y += 10;
	}
}