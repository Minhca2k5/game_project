#include "common.h"

void Common::load(const string& path) {
	image = pdm::loadtexture(path);
}
void Common::setrect(int x, int y, int w, int h) {
	rect.x = x; rect.y = y;
	rect.w = w; rect.h = h;
}
void Common::setrc(int x, int y, int w, int h) {
	rc.x = x; rc.y = y;
	rc.w = w; rc.h = h;
}
void Common::ape1() {
	pdm::show1(image, rect.x, rect.y, rect.w, rect.h);
}
void Common::ape2() {
	pdm::show2(image, rect.x, rect.y, rect.w, rect.h, rc);
}
void Common::ape3() {
	pdm::show3(image, rect.x, rect.y, rect.w, rect.h);
}
