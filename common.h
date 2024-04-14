#ifndef COMMON_H_
#define COMMON_H_
#include "general.h"

class Common {
protected:
	SDL_Rect rect;
	SDL_Rect rc;
	SDL_Texture* image;
public:
	void load(const string& path);
	SDL_Rect Rect() {
		return rect;
	}
	SDL_Rect Rc() {
		return rc;
	}
	void setrect(int x, int y, int w, int h);
	void setrc(int x, int y, int w, int h);
	void ape1();
	void ape2();
	void ape3();
};
#endif // !COMMON_H_

