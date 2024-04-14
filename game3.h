#ifndef GAME3_H_
#define GAME3_H_

#include "common.h"

class Game3 : public Common {
protected:
	vector<Game3*>spin;
	vector<Game3*>spin_dich;
	int x, y, fr;
	bool check, move;
public:
	Game3();
	void mb_handle();
	void dan_handle(Mix_Chunk* sound_bullet[]);
	void dan_dc();
	void mb_dc();
	void show_dan();
	void khoitao();
	void dich_handle();
	void dandich_handle();
	void set_frame(int vt) {
		fr = vt;
	}
	void show_dd();
	vector<Game3*> ta() {
		return spin;
	}
	vector<Game3*> dich() {
		return spin_dich;
	}
};

#endif // !GAME3_H_
