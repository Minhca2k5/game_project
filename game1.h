#ifndef GAME1_H_
#define GAME1_H_

#include "common.h"
const int W = 60;
const int H = 64;
const int MAX_H = 160;
class Game1 :public Common {
protected:
	SDL_Rect nv[8];
	int fr,dc;
	bool check, nhay;
public:
	Game1();
	void set_clip();
	void set_fr(int k) {
		fr = k;
	}
	void set_show();
	void dich_handle();
	void nut();
	void handle();
	void set_nhay(bool kt) {
		nhay = kt;
	}
};
#endif // !GAME1_H_

