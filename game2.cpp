#include "game2.h"

Game2::Game2() {
	check = false;
	dc = 0;
	k = 0;
}
void Game2::handle() {
	if (e.key.keysym.sym == SDLK_SPACE) {
		if (!check) {
			check = true;
			dc = MAX_HT;
		}
	}
}
void Game2::handle_bird() {
	if (check) {
		load("bird2.png");
		rect.y -= 6;
		dc -= 10;
		if (dc <= 0) check = false;
	}
	else {
		load("bird1.png");
		rect.y += 6;
	}
}
void Game2::vt_cot() {
	int vt = 350;
	for (int i = 0; i < 9; i++) {
		top[i].x = vt;
		top[i].w = 50;
		top[i].y = 0;
		bottom[i].x = vt;
		bottom[i].w = 50;
		if (i % 3 == 0) {
			top[i].h = 240;
			bottom[i].h = 240;
			bottom[i].y = HEIGHT - 240;
		}
		else if (i % 3 == 1) {
			top[i].h = 300;
			bottom[i].h = 180;
			bottom[i].y = HEIGHT - 180;
		}
		else if (i % 3 == 2) {
			top[i].h = 180;
			bottom[i].h = 300;
			bottom[i].y = HEIGHT - 300;
		}
		vt += 150;
	}
}
void Game2::load_cot_top() {
	setrect(top[k].x, top[k].y, top[k].w, top[k].h);
}
void Game2::load_cot_bottom() {
	setrect(bottom[k].x, bottom[k].y, bottom[k].w, bottom[k].h);
}
void Game2::handle_cot() {
	rect.x -= 2;
	if (rect.x <= 0) rect.x = WIDTH;
}
