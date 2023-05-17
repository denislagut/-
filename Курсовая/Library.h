#pragma once
#pragma comment(lib, "SDL2_mixer.lib")
#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>
#include <ctime>
#include <locale>
#include <iostream>
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#include <cmath>
#include <string>
using namespace std;

void Fon_menu(SDL_Renderer* renderer);
void Button(SDL_Renderer* renderer,SDL_Rect button ,int flag_button);

int Main(SDL_Window *window,SDL_Renderer* renderer);