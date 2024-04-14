#ifndef NO_H_
#define NO_H_

#include "common.h"
const int WT = 165;
const int HT = 165;
class No : public Common {
protected:
	SDL_Rect item[4];
	int vt;
public:
	No();
	void set_no();
	void get_frame(int k) {
		vt = k;
	}
	void showext();
};

#endif // !NO_H_
