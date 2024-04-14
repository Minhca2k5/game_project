#include "general.h"
#include "text.h"
#include "game1.h"
#include "game2.h"
#include "game3.h"
#include "no.h"

Game1 nv, nvd1, nvd2, mb[4];
Game2 bird, top[9], bottom[9];
Game3 plane, dich[4];
No no;
TTF_Font* font;
TTF_Font* ft;
bool clicked = false, game1 = false, game2 = false, game3 = false, check = false;
int vt = 0, current = 0, start = 0, mang = 0, muctieu = 0;
bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }
    window = SDL_CreateWindow("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) return false;
    screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (screen == nullptr) return false;
    SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);
    if (TTF_Init() == -1) {
        return false;
    }
    font = TTF_OpenFont("arial.ttf", 60);
    ft = TTF_OpenFont("arial.ttf", 20);
    if (font == nullptr || ft == nullptr) return false;
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        return false;
    }
    sound[0] = Mix_LoadWAV("no_1.wav");
    sound[1] = Mix_LoadWAV("no_2.wav");
    sound[2] = Mix_LoadWAV("no_3.wav");
    sound[3] = Mix_LoadWAV("sound_1.wav");
    sound[4] = Mix_LoadWAV("sound_4.wav");
    sound[5] = Mix_LoadWAV("sound_5.wav");
    return true;
}
void game1_input() {
    nv.load("actor.png");
    nv.setrect(0, 440, 100, 80);
    nv.set_clip();
    nvd1.load("nv1.png");
    nvd1.setrect(600, 442, 100, 80);
    nvd2.load("nv2.png");
    nvd2.setrect(WIDTH - 100, 447, 100, 80);
    mb[0].load("plane_1_blue.png");
    mb[1].load("plane_1_pink.png");
    mb[2].load("plane_1_red.png");
    mb[3].load("plane_1_yellow.png");
    int vt = 500;
    for (int i = 0; i < 4; i++) {
        SDL_Rect rtc;
        rtc.x = vt;
        rtc.y = 100;
        rtc.w = 100;
        rtc.h = 50;
        vt += 300;
        mb[i].setrect(rtc.x, rtc.y, rtc.w, rtc.h);
    }
}
void game2_input() {
    bird.load("bird1.png");
    bird.setrect(100, 50, 60, 60);
    for (int i = 0; i < 9; i++) {
        top[i].load("top.png");
        bottom[i].load("bottom.png");
        top[i].vt_cot();
        bottom[i].vt_cot();
        top[i].set_vt(i);
        top[i].load_cot_top();
        bottom[i].set_vt(i);
        bottom[i].load_cot_bottom();
    }
}
void game3_input() {
    mang = 5;
    muctieu = 0;
    plane.load("plane_2_red.png");
    plane.setrect(0, 300, 100, 60);
    dich[0].load("plane_3_blue.png");
    dich[1].load("plane_3_red.png");
    dich[2].load("plane_3_green.png");
    dich[3].load("plane_3_yellow.png");
    int x = 10;
    for (int i = 0; i < 4; i++) {
        dich[i].setrect(WIDTH, x, 100, 60);
        x += 150;
        dich[i].khoitao();
    }
}
void call_bg1() {
    while (!clicked) {
        if (e.button.button==SDL_BUTTON_LEFT) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            cout << x << " " << y << endl;
            if (x >= 560 && x <= 930 && y >= 290 && y <= 340) {
                SDL_Delay(1000);
                SDL_RenderClear(screen);
                pdm::show1(bg[1], 0, 0, WIDTH, HEIGHT);
                pdm::show(font);
                clicked = true;
            }
            else if (x >= 560 && x <= 930 && y >= 420 && y <= 470) {
                SDL_Quit();
            }
        }
    }
}
void call_bg2() {
    bool click = false;
    while (!click) {
        if (e.button.button == SDL_BUTTON_LEFT) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (x >= 200 && x <= 300 && y >= 150 && y <= 200) {
                game1 = true;
                SDL_Delay(1000);
                SDL_RenderClear(screen);
                game1_input();
                check = true;
                click = true;
                current = SDL_GetTicks() / 1000;
            }
            else if (x >= 200 && x <= 300 && y >= 300 && y <= 350) {
                game2 = true;
                SDL_Delay(1000);
                SDL_RenderClear(screen);
                game2_input();
                check = true;
                click = true;
                start = SDL_GetTicks() / 1000;
            }
            else if (x >= 200 && x <= 300 && y >= 450 && y <= 500) {
                game3 = true;
                SDL_Delay(1000);
                SDL_RenderClear(screen);
                game3_input();
                check = true;
                click = true;
            }
        }
    }
}
void bg_handle(int t) {
    vt--;
    pdm::show1(bg[t], vt, 0, WIDTH, HEIGHT);
    pdm::show1(bg[t], vt + WIDTH, 0, WIDTH, HEIGHT);
    if (vt <= -WIDTH) {
        vt = 0;
    }
}
void input() {
    pdm::add_bg();
    pdm::show1(bg[0], 0, 0, WIDTH, HEIGHT);
    game1_input();
    game2_input();
    game3_input();
    no.load("no.png");
    no.set_no();
}
void dc(Game1& rct) {
    rct.dich_handle();
    rct.ape3();
}
void g1() {
    for (int i = 0; i < 8; i++) {
        SDL_RenderClear(screen);
        SDL_Delay(60);
        bg_handle(2);
        nv.set_fr(i);
        nv.handle();
        nv.set_show();
        dc(nvd1); dc(nvd2);
        for (int i = 0; i < 4; i++) {
            dc(mb[i]);
        }
        int tm = SDL_GetTicks() / 1000 - current;
        string s = "THOI GIAN:" + to_string(tm);
        Text tx;
        tx.content(s);
        tx.setrect(600, 0, 150, 50);
        tx.set_color(Text::BLACK);
        tx.showex(ft);
        if (pdm::ktvc(nv.Rect(), nvd1.Rect()) || pdm::ktvc(nv.Rect(), nvd2.Rect())) {
            Mix_PlayChannel(-1, sound[3], 0);
            game1 = false;
            nv.set_nhay(false);
            SDL_RenderClear(screen);
            pdm::show1(bg[1], 0, 0, WIDTH, HEIGHT);
            pdm::show(font);
            if (MessageBox(NULL, L"DEFEAT!", L"INFO", MB_OK) == IDOK) {
            }
            break;
        }
        else if (tm >= 20) {
            game1 = false;
            nv.set_nhay(false);
            SDL_RenderClear(screen);
            pdm::show1(bg[1], 0, 0, WIDTH, HEIGHT);
            pdm::show(font);
            if (MessageBox(NULL, L"VICTORY!", L"INFO", MB_OK) == IDOK) {
            }
            break;
        }
        SDL_RenderPresent(screen);
    }
}
void g2() {
    bool df = false;
    SDL_Delay(100);
    bg_handle(3);
    bird.handle_bird();
    for (int i = 0; i < 9; i++) {
        SDL_Delay(20);
        bird.ape1();
        top[i].handle_cot();
        top[i].ape1();
        bottom[i].handle_cot();
        bottom[i].ape1();
        if (pdm::ktvc(bird.Rect(), top[i].Rect()) || pdm::ktvc(bird.Rect(), bottom[i].Rect())) {
            Mix_PlayChannel(-1, sound[3], 0);
            game2 = false;
            nv.set_nhay(false);
            SDL_RenderClear(screen);
            pdm::show1(bg[1], 0, 0, WIDTH, HEIGHT);
            pdm::show(font);
            df = true;
            if (MessageBox(NULL, L"DEFEAT!", L"INFO", MB_OK) == IDOK) {
            }
            break;
        }
    }
    int tm = SDL_GetTicks() / 1000 - start;
    string s = "THOI GIAN:" + to_string(tm);
    Text tx;
    tx.content(s);
    tx.setrect(600, 0, 150, 50);
    tx.set_color(Text::BLACK);
    tx.showex(ft);
    if (df) {
        SDL_RenderClear(screen);
        pdm::show1(bg[1], 0, 0, WIDTH, HEIGHT);
        pdm::show(font);
    }
    if (tm >= 60) {
        game2 = false;
        nv.set_nhay(false);
        SDL_RenderClear(screen);
        pdm::show1(bg[1], 0, 0, WIDTH, HEIGHT);
        pdm::show(font);
        df = true;
        if (MessageBox(NULL, L"VICTORY!", L"INFO", MB_OK) == IDOK) {
        }
    }
    SDL_RenderPresent(screen);
}
void stk() {
    mang--;
    for (int j = 0; j < 4; j++) {
        no.get_frame(j);
        int x = plane.Rect().x + plane.Rect().w / 2;
        int y = plane.Rect().y + plane.Rect().h / 2;
        no.setrect(x, y, 80, 60);
        no.showext();
        SDL_RenderPresent(screen);
    }
    plane.setrect(0, 300, 100, 60);
    int x = 10;
    for (int i = 0; i < 4; i++) {
        dich[i].setrect(WIDTH, x, 100, 60);
        x += 150;
        vector<Game3*> dan_dich = dich[i].dich();
        for (int l = 0; l < dan_dich.size(); l++) {
            Game3* amo = dan_dich.at(l);
            amo->setrect(-100, -100, 0, 0);
        }
    }
    vector<Game3*> dan_ta = plane.ta();
    for (int l = 0; l < dan_ta.size(); l++) {
        Game3* amo = dan_ta.at(l);
        amo->setrect(-100, -100, 0, 0);
    }
}
void g3() {
    bg_handle(4);
    plane.mb_dc();
    plane.ape1();
    plane.show_dan();
    for (int i = 0; i < 4; i++) {
        SDL_Delay(3);
        dich[i].set_frame(i);
        dich[i].dich_handle();
        dich[i].ape3();
        dich[i].show_dd();
        string s = "luot choi:" + to_string(mang);
        Text tx;
        tx.content(s);
        tx.setrect(0, 0, 100, 50);
        tx.set_color(Text::BLACK);
        tx.showex(ft);
        string st = "muc tieu:" + to_string(muctieu);
        Text txt;
        txt.content(st);
        txt.setrect(600, 0, 150, 50);
        txt.set_color(Text::BLACK);
        txt.showex(ft);
        if (pdm::ktvc(plane.Rect(), dich[i].Rect())) { 
            Mix_PlayChannel(-1, sound[4], 0);
            stk();
        }
        vector<Game3*> dan_dich = dich[i].dich();
        for (int l = 0; l < dan_dich.size(); l++) {
            Game3* amo = dan_dich.at(l);
            if (pdm::ktvc(plane.Rect(), amo->Rect())) {
                Mix_PlayChannel(-1, sound[3], 0);
                stk();
            }
        }
        vector<Game3*> dan_ta = plane.ta();
        for (int l = 0; l < dan_ta.size(); l++) {
            Game3* amo = dan_ta.at(l);
            if (pdm::ktvc(amo->Rect(), dich[i].Rect())) {
                Mix_PlayChannel(-1, sound[5], 0);
                muctieu++;
                for (int j = 0; j < 4; j++) {
                    no.get_frame(j);
                    int x = amo->Rect().x + amo->Rect().w / 2;
                    int y = amo->Rect().y + amo->Rect().h / 2;
                    no.setrect(x, y, 80, 60);
                    no.showext();
                    SDL_RenderPresent(screen);
                }
                amo->setrect(-100, -100, 0, 0);
                dich[i].setrect(WIDTH, i * 150 + 10, 100, 60);
            }
            vector<Game3*> dan_dich = dich[i].dich();
            for (int k = 0; k < dan_dich.size(); k++) {
                Game3* p_amo = dan_dich.at(k);
                if (pdm::ktvc(amo->Rect(), p_amo->Rect())) {
                    Mix_PlayChannel(-1, sound[3], 0);
                    for (int j = 0; j < 4; j++) {
                        no.get_frame(j);
                        int x = amo->Rect().x + amo->Rect().w / 2;
                        int y = amo->Rect().y + amo->Rect().h / 2;
                        no.setrect(x, y, 50, 30);
                        no.showext();
                        SDL_RenderPresent(screen);
                    }
                    amo->setrect(2000, 2000, 0, 0);
                    p_amo->setrect(-100, -100, 0, 0);
                }
            }
        }
        if (mang == 0) {
            game3 = false;
            nv.set_nhay(false);
            SDL_RenderClear(screen);
            pdm::show1(bg[1], 0, 0, WIDTH, HEIGHT);
            pdm::show(font);
            if (MessageBox(NULL, L"DEFEAT!", L"INFO", MB_OK) == IDOK) {
            }
            break;
        }
        else if (muctieu >= 2) {
            game3 = false;
            nv.set_nhay(false);
            stk();
            SDL_RenderClear(screen);
            pdm::show1(bg[1], 0, 0, WIDTH, HEIGHT);
            pdm::show(font);
            if (MessageBox(NULL, L"VICTORY!", L"INFO", MB_OK) == IDOK) {
            }
            break;
        }
    }
}
int main(int argc, char* args[]) {
    if (!init()) return 0;
    input();
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) quit = true;
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (!clicked)  call_bg1();
                else if (game3) plane.dan_handle(sound);
                else {
                    call_bg2();
                }
            }
            else if (e.type == SDL_KEYDOWN) {
                nv.nut();
                bird.handle();
                plane.mb_handle();
            }
        }
        if (check) {
            if (game1) g1();
            else if (game2) g2();
            else if (game3) g3();
        }
        SDL_RenderPresent(screen);
    }
    pdm::close();
    return 0;
}