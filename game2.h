#ifndef GAME2_H_
#define GAME2_H_

#include "common.h"
const int MAX_HT = 60;
class Game2 :public Common {
protected:
	bool check;
	SDL_Rect top[9]; 
	SDL_Rect bottom[9];
	int dc, k;
public:
	Game2();
	void handle();
	void load_cot();
	void handle_cot();
	void handle_bird();
	void vt_cot();
	void load_cot_top();
	void load_cot_bottom();
	void set_vt(int m) {
		k = m;
	}
};

#endif // !GAME2_H_
