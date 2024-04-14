#include "no.h"

No::No() {
	vt = 0;
}
void No::set_no() {
	int t = 0;
	for (int i = 0; i < 4; i++) {
		item[i].x = t;
		item[i].y = 0;
		item[i].w = WT;
		item[i].h = HT;
		t += 165;
	}
}
void No::showext() {
	setrc(item[vt].x, item[vt].y, item[vt].w, item[vt].h);
	ape2();
}