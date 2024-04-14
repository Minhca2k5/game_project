#include "general.h"
#include "text.h"
SDL_Window* window;
SDL_Renderer* screen;
vector<SDL_Texture*>bg;
SDL_Event e;
SDL_Texture* pdm::loadtexture(const string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface != nullptr) {
        if(path=="actor.png") SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 167, 175, 180));
        else SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 255, 255));
        SDL_Texture* image = SDL_CreateTextureFromSurface(screen, surface);
        SDL_FreeSurface(surface);
        return image;
    }
    return NULL;
}
void pdm::add_bg() {
    bg.push_back(loadtexture("menu.jpg"));
    bg.push_back(loadtexture("nature.png"));
    bg.push_back(loadtexture("hinhnen3.png"));
    bg.push_back(loadtexture("bautroi.png"));
    bg.push_back(loadtexture("sky.png"));
}
void pdm::close() {
    SDL_DestroyRenderer(screen);
    screen = nullptr;
    bg.clear();
    SDL_DestroyWindow(window);
    window = nullptr;
}
void pdm::show1(SDL_Texture* image, int x, int y, int w, int h) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_RenderCopy(screen, image, NULL, &rect);
}
void pdm::show2(SDL_Texture* image, int x, int y, int w, int h, SDL_Rect set) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_RenderCopy(screen, image, &set, &rect);
}
void pdm::show3(SDL_Texture* image, int x, int y, int w, int h) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyEx(screen, image, NULL, &rect, 0, NULL, flip);
}
bool pdm::ktvc(const SDL_Rect& rect1, const SDL_Rect& rect2) {
    return (rect1.x <= rect2.x + rect2.w && rect1.x + rect1.w >= rect2.x && rect1.y <= rect2.y + rect2.h && rect1.y + rect1.h >= rect2.y);
}
void pdm::show(TTF_Font* font) {
    SDL_Rect icon[4];
    int t = 0;
    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            icon[i].x = 100;
            icon[i].w = 300;
        }
        else {
            icon[i].x = 200;
            icon[i].w = 100;
        }
        icon[i].y = t;
        icon[i].h = 50;
        t += 150;
    }
    Text ct[4];
    for (int i = 0; i < 4; i++) {
        if (i == 0) ct[i].content("DO YOU WANT TO PLAY: ");
        if (i == 1) ct[i].content("GAME 1");
        if (i == 2) ct[i].content("GAME 2");
        if (i == 3) ct[i].content("GAME 3");
        ct[i].setrect(icon[i].x, icon[i].y, icon[i].w, icon[i].h);
        ct[i].set_color(Text::BLACK);
        ct[i].showex(font);
    }
    show1(loadtexture("plane_1_blue.png"), 600, 200, 150, 50);
    show1(loadtexture("plane_1_pink.png"), 600, 400, 150, 50);
    show3(loadtexture("plane_1_yellow.png"), 1000, 200, 150, 50);
}
