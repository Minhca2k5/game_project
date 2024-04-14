#ifndef TEXT_H_
#define TEXT_H_

#include "common.h"

class Text :public Common {
protected:
	string text;
	SDL_Color color;
public:
	enum {
		BLACK = 0,
	};
	void content(string path);
	void set_color(int tp);
	void showex(TTF_Font* font);
};
#endif // !TEXT_H_

