#include "game3.h"
Game3::Game3() {
	x = 0;
	y = 0;
	fr = 0;
	check = false;
	move = false;
}
void Game3::mb_handle() {
	switch (e.key.keysym.sym) {
	case SDLK_RIGHT:
		x += 10;
		break;
	case SDLK_LEFT:
		x -= 10;
		break;
	case SDLK_UP:
		y -= 5;
		break;
	case SDLK_DOWN:
		y += 5;
		break;
	}
}
void Game3::mb_dc() {
	rect.x += x;
	rect.y += y;
	if (rect.x <= 0 || rect.x + 100 > WIDTH) rect.x -= x;
	if (rect.y <= 0 || rect.y + 60 > HEIGHT) rect.y -= y;
	x = 0;
	y = 0;
}
void Game3::dan_handle(Mix_Chunk* sound_bullet[]) {
	Game3* amo = new Game3();
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		if (e.button.button == SDL_BUTTON_LEFT) {
			amo->load("dan1.png");
			Mix_PlayChannel(-1, sound_bullet[0], 0);
		}
		else {
			amo->load("dan2.png");
			Mix_PlayChannel(-1, sound_bullet[1], 0);
		}
		amo->setrect(rect.x + rect.w, rect.y + rect.h / 2, 20, 10);
		spin.push_back(amo);
	}
}
void Game3::dan_dc() {
	rect.x += 5;
	if (rect.x >= WIDTH) {
		check = true;
	}
}
void Game3::show_dan() {
	for (int i = 0; i < spin.size(); i++) {
		Game3* amo = spin.at(i);
		if (!check) {
			amo->dan_dc();
			amo->ape1();
		}
	}
}
void Game3::khoitao() {
	Game3* p_amo = new Game3();
	p_amo->load("sphere.png");
	p_amo->setrect(rect.x, rect.y + rect.h / 2, 20, 10);
	spin_dich.push_back(p_amo);
}
void Game3::dandich_handle() {
	rect.x -= 5;
	if (rect.x < 0) move = true;
}
void Game3::show_dd() {
	for (int i = 0; i < spin_dich.size(); i++) {
		Game3* amo = spin_dich.at(i);
		if (!move) {
			amo->dandich_handle();
			amo->ape3();
		}
	}
}
void Game3::dich_handle() {
	rect.x -= 2;
	if (rect.x < 0) {
		rect.x = WIDTH;
		if (fr == 0) rect.y = rand() % 80;
		else if (fr == 1) rect.y = rand() % 80 + 150;
		else if (fr == 2) rect.y = rand() % 80 + 300;
		else if (fr == 3) rect.y = rand() % 80 + 450;
		khoitao();
	}
	int vt = 400;
	for (int i = vt; i < WIDTH; i += 200) {
		if (rect.x == i) khoitao();
	}
}
