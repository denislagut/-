#include "Library.h"

//Фон
void Fon_menu(SDL_Renderer* renderer) {
	SDL_Surface* fonImage = IMG_Load("Fon.bmp");
	SDL_SetColorKey(fonImage, SDL_TRUE,
		SDL_MapRGB(fonImage->format, 255, 255, 255));
	SDL_Texture* fonTexture = SDL_CreateTextureFromSurface(renderer, fonImage);
	SDL_FreeSurface(fonImage);
	SDL_Rect Fon = { 0,0,1200, 700 };
	SDL_RenderCopy(renderer, fonTexture, NULL, &Fon);
	SDL_DestroyTexture(fonTexture);
}

//Фоновая музыка
void loadmusic(Mix_Music *fon)
{
	fon = Mix_LoadMUS("fon.wav");
	Mix_PlayMusic(fon, -1);
}
//Звук нажатия по кнопке
void Sound(Mix_Chunk* sound)
{
	sound = Mix_LoadWAV("but.wav");
	Mix_PlayChannel(-1, sound, 0);
}

//Текст
SDL_Texture* get_textTexture(SDL_Renderer*& renderer, string text, TTF_Font* font, SDL_Rect &textPoison) {
	SDL_Surface* textSurface = NULL;
	SDL_Color fore_color = { 4,58,128 };
	textSurface = TTF_RenderText_Solid(font, text.c_str(), fore_color);
	textPoison.w = textSurface->w;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return texture;
}
//Значения на графике
SDL_Texture* get_argTexture(SDL_Renderer*& renderer, char* text, TTF_Font* font, SDL_Rect& textPoison) {
	SDL_Surface* textSurface = NULL;
	SDL_Color fore_color = { 255,255,255 };
	textSurface = TTF_RenderText_Solid(font, text, fore_color);
	textPoison.w = textSurface->w;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return texture;
}

//Отрисовка текста
void draw_text(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect textPoison) {
	SDL_RenderCopy(renderer, texture, NULL, &textPoison);
}

//Кнопка построения графика
void Button(SDL_Renderer* renderer,SDL_Rect button ,int flag_button) {
	SDL_Surface* buttonImage = IMG_Load("button.bmp");
	SDL_SetColorKey(buttonImage, SDL_TRUE,
		SDL_MapRGB(buttonImage->format, 255, 255, 255));
	SDL_Texture* buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonImage);
	SDL_FreeSurface(buttonImage);
	SDL_Surface* button2Image = IMG_Load("button2.bmp");
	SDL_SetColorKey(button2Image, SDL_TRUE,
		SDL_MapRGB(button2Image->format, 255, 255, 255));
	SDL_Texture* button2Texture = SDL_CreateTextureFromSurface(renderer, button2Image);
	SDL_FreeSurface(button2Image);
	switch (flag_button)
	{
	case 1: {SDL_RenderCopy(renderer, buttonTexture, NULL, &button); break; }
	case 2: {SDL_RenderCopy(renderer, button2Texture, NULL, &button); break; }
	}
	SDL_DestroyTexture(buttonTexture);
	SDL_DestroyTexture(button2Texture);
}

//Блок коэффициентов
void Odds(SDL_Renderer* renderer,  int flag_button) {
	SDL_Surface* oddImage;

	switch (flag_button)
	{
	case 2: { 
		oddImage = IMG_Load("func2.bmp"); 
		SDL_Rect odds = {100, 350, 800, 200};
		SDL_SetColorKey(oddImage, SDL_TRUE,
			SDL_MapRGB(oddImage->format, 255, 255, 255));
		SDL_Texture* oddTexture = SDL_CreateTextureFromSurface(renderer, oddImage);
		SDL_FreeSurface(oddImage);
		SDL_RenderCopy(renderer, oddTexture, NULL, &odds);
		SDL_DestroyTexture(oddTexture); break; }
	case 3: { 
		oddImage = IMG_Load("func3.bmp"); 
		SDL_Rect odds = { 100, 350, 800, 200 };
		SDL_SetColorKey(oddImage, SDL_TRUE,
			SDL_MapRGB(oddImage->format, 255, 255, 255));
		SDL_Texture* oddTexture = SDL_CreateTextureFromSurface(renderer, oddImage);
		SDL_FreeSurface(oddImage);
		SDL_RenderCopy(renderer, oddTexture, NULL, &odds);
		SDL_DestroyTexture(oddTexture); break; }
	case 4: { 
		oddImage = IMG_Load("func4.bmp"); 
		SDL_Rect odds = { 100, 350, 800, 200 };
		SDL_SetColorKey(oddImage, SDL_TRUE,
			SDL_MapRGB(oddImage->format, 255, 255, 255));
		SDL_Texture* oddTexture = SDL_CreateTextureFromSurface(renderer, oddImage);
		SDL_FreeSurface(oddImage);
		SDL_RenderCopy(renderer, oddTexture, NULL, &odds);
		SDL_DestroyTexture(oddTexture); break; }
	}
	
}

//Кнопка экранной клавиатуры
void But_keyboard(SDL_Renderer *renderer, SDL_Rect but) {
	SDL_Surface* button3Image = IMG_Load("button3.bmp");
	SDL_SetColorKey(button3Image, SDL_TRUE,
		SDL_MapRGB(button3Image->format, 255, 255, 255));
	SDL_Texture* button3Texture = SDL_CreateTextureFromSurface(renderer, button3Image);
	SDL_FreeSurface(button3Image);
	SDL_RenderCopy(renderer, button3Texture, NULL, &but);
	SDL_DestroyTexture(button3Texture);
}

//Попадание по кнопке экранной клавиатуры
bool Button_hit(SDL_Rect but, int x, int y)
{
	int centerX = but.x + but.w / 2;
	int centerY = but.y + but.h / 2;
	int radius = but.w / 2;
	return sqrt((centerX - x) * (centerX - x) + (centerY - y) * (centerY - y)) < radius;
}

//Отрисовка интерфейса
void Interface(SDL_Renderer* renderer, SDL_Rect str, SDL_Rect str2, SDL_Rect str3, SDL_Rect func) {
	SDL_Surface* strImage = IMG_Load("stroka.bmp");
	SDL_SetColorKey(strImage, SDL_TRUE,
		SDL_MapRGB(strImage->format, 255, 255, 255));
	SDL_Texture* strTexture = SDL_CreateTextureFromSurface(renderer, strImage);
	SDL_FreeSurface(strImage);
	SDL_Surface* funcImage = IMG_Load("func.bmp");
	SDL_SetColorKey(funcImage, SDL_TRUE,
		SDL_MapRGB(funcImage->format, 255, 255, 255));
	SDL_Texture* funcTexture = SDL_CreateTextureFromSurface(renderer, funcImage);
	SDL_FreeSurface(funcImage);
	SDL_Rect x = {810, 110, 40, 40}; 
	SDL_Rect y = {510, 110, 40, 40};
	SDL_Surface* XImage = IMG_Load("X.bmp");
	SDL_SetColorKey(XImage, SDL_TRUE,
		SDL_MapRGB(XImage->format, 255, 255, 255));
	SDL_Texture* XTexture = SDL_CreateTextureFromSurface(renderer, XImage);
	SDL_FreeSurface(XImage);
	SDL_Surface* YImage = IMG_Load("Y.bmp");
	SDL_SetColorKey(YImage, SDL_TRUE,
		SDL_MapRGB(YImage->format, 255, 255, 255));
	SDL_Texture* YTexture = SDL_CreateTextureFromSurface(renderer, YImage);
	SDL_FreeSurface(YImage);

	Fon_menu(renderer);
	SDL_RenderCopy(renderer, funcTexture, NULL, &func);
	SDL_RenderCopy(renderer, strTexture, NULL, &str);
	SDL_RenderCopy(renderer, strTexture, NULL, &str2);
	SDL_RenderCopy(renderer, strTexture, NULL, &str3);
	SDL_RenderCopy(renderer, XTexture, NULL, &x);
	SDL_RenderCopy(renderer, YTexture, NULL, &y);

	SDL_DestroyTexture(funcTexture);
	SDL_DestroyTexture(strTexture);
	SDL_DestroyTexture(XTexture);
	SDL_DestroyTexture(YTexture);
}

//Сообщение об ошибке
void Error(SDL_Renderer* renderer) {
	SDL_Rect err = { 400, 225, 400, 250 };
	SDL_Surface* errImage = IMG_Load("error.bmp");
	SDL_SetColorKey(errImage, SDL_TRUE,
		SDL_MapRGB(errImage->format, 255, 255, 255));
	SDL_Texture* errTexture = SDL_CreateTextureFromSurface(renderer, errImage);
	SDL_FreeSurface(errImage);

	SDL_RenderCopy(renderer, errTexture, NULL, &err);

	SDL_DestroyTexture(errTexture);
}

//Парсинг границ
int Parsing_borders(string bord, double* num, int index) {
	int flagBord = 0, flagBord2 = 0, t=0, flag=0, error=0;
	string help, help2;
	for (int i = 0; i < bord.length(); i++) {
		if (isspace(bord[i])) { continue; }
		if (bord[i] == '[' || bord[i] == '(') {
			if (bord[i] == '[')flagBord = 1;
			if (bord[t] == '(')flagBord = 2;
			i += 1;
			t = i;
			while ((isdigit(bord[t]) || bord[t] == '.' || bord[t] == ',' || bord[t] == '-' || bord[t] == ';') && t < bord.length()) {
				if (bord[t] == ';' || flagBord2 == 1) {
					t++;
					help2 += bord[t];
					flagBord2 = 1;
				}
				else {
					help += bord[t];
					t++;
				}
			}
			if (bord[t] == ')')flagBord += 3;
			if (bord[t] == ']')flagBord += 1;
			num[index] = stod(help);
			num[index+1] = stod(help2);
			if (num[index+1] <= num[index])error = 1;
			if (flagBord2==0)error = 1;
			break;
		}
		else { error = 1; break; }
	}
	if (error == 1)return 0;
	else return flagBord;
}

//Элементарная проверка строки коэффициента
int Err(string odds)
{
	int flag = 0, flag2=0;
	for (int i = 0; i < odds.length(); i++) {
		if (!isdigit(odds[i]) && odds[i] != 's' && odds[i] != 'i' && odds[i] != 'n' && odds[i] != 'q'
			&& odds[i] != 'r' && odds[i] != 't' && odds[i] != 'g' && odds[i] != 'c' && odds[i] != 'o'
			&& odds[i] != 'l' && odds[i] != '-' && odds[i] != '+' && odds[i] != ' ' && odds[i] != '('
			&& odds[i] != ')' && odds[i] != '^' && odds[i] != '.' && odds[i] != ',') {
			flag = 1;
			break;
		}
	}
	for (int i = 0; i < odds.length(); i++) {
		if (isdigit(odds[i])) {
			flag2 = 1;
			break;
		}
	}
	if (flag == 1 || flag2==0)return 1;
	else return 0;
}
//Парсинг коэффициентов
int Parsing(string odds, double* num, int index) {
	string save, step; 
	int error=0, j=0, k=0, flag=0, flagstep=0;
	for (int i = 0; i < odds.length(); i++){
		if (isspace(odds[i])) { continue; }
		if (odds[i] == '-') {
			flag = 1;
			i += 1;
		}

		if (odds[i]=='s') {
			i += 1;
			if (odds[i] == 'i') {
				k = i + 3;
				if (isspace(odds[k])) { k += 1; }
				while ((isdigit(odds[k]) || odds[k] == '.' || odds[k] == ',' || odds[k] == '-')&& k<odds.length()) {
					save += odds[k];
					k++;
				}
				if (flag == 1) {
					num[index] = -sin(stod(save)); break;
				}
				else {
					num[index] = sin(stod(save)); break;
				}
			}
			else {
				if (odds[i] == 'q') {
					k = i + 4;
					if (isspace(odds[k])) { k += 1; }
					while ((isdigit(odds[k]) || odds[k] == '.' || odds[k] == ',') && k < odds.length()) {
						save += odds[k];
						k+=1;
					}
					if (odds[k] == '-') { error = 1; break; }
					if (flag == 1) {
						num[index] = -sqrt(stod(save)); break;
					}
					else {
						num[index] = sqrt(stod(save)); break;
					}
				}
			}
		}
		if (odds[i] == 'l') {
			k = i + 4;
			if (isspace(odds[k])) { k += 1; }
			while ((isdigit(odds[k]) || odds[k] == '.' || odds[k] == ',') && k < odds.length()) {
				save += odds[k];
				k++;
			}
			if (odds[k] == '-') { error = 1; break; }
			if (flag == 1) {
				num[index] = -log(stod(save)); break;
			}
			else {
				num[index] = log(stod(save)); break;
			}
		}
		if (odds[i] == 'c') {
			i += 1;
			if (odds[i] == 'o') {
				k = i + 3;
				if (isspace(odds[k])) { k += 1; }
				while ((isdigit(odds[k]) || odds[k] == '.' || odds[k] == ',' || odds[k] == '-') && k < odds.length()) {
					save += odds[k];
					k++;
				}
				if (flag == 1) {
					num[index] = -cos(stod(save)); break;
				}
				else {
					num[index] = cos(stod(save)); break;
				}
			}
			else {
				if (odds[i] == 't') {
					k = i + 3;
					if (isspace(odds[k])) { k += 1; }
					while ((isdigit(odds[k]) || odds[k] == '.' || odds[k] == ',' || odds[k] == '-') && k < odds.length()) {
						save += odds[k];
						k++;
					}
					if (flag == 1) {
						num[index] = -1/(tan(stod(save))); break;
					}
					else {
						num[index] = 1/tan(stod(save)); break;
					}
				}
			}
		}
		if (odds[i] == 't') {
			k = i + 3;
			if (isspace(odds[k])) { k += 1; }
			while ((isdigit(odds[k]) || odds[k] == '.' || odds[k] == ',' || odds[k] == '-') && k < odds.length()) {
				save += odds[k];
				k++;
			}
			if (flag == 1) {
				num[index] = -tan(stod(save)); break;
			}
			else {
				num[index] = tan(stod(save)); break;
			}
		}
			if (isdigit(odds[i])) {

				k = i;

				while ((isdigit(odds[k]) || odds[k] == '.' || odds[k] == ','||odds[k]=='^' || odds[k] == '-') && k < odds.length()) {
					if (odds[k] == '^') {
						k += 1;
						
						if (odds[k] == '-') {
							flag = 2;
							k += 1;
						}
						j = 0;
						flagstep = 1;
					}

					if (flagstep == 1) {
						step+= odds[k];
					}
					else {
						save += odds[k];

					}

					k+=1;

				}

				if (flag == 1) {
					num[index] = -(stod(save));
				}
				if(flag==0){
					num[index] = stod(save);
				}
				if (flagstep == 1 && flag != 2) {
					num[index] = pow(num[index], stod(step));
				}
				else {
					if (flag == 2) {
						num[index] = pow(num[index], -(stod(step)));
					}
				}
				break;
			}
	}
	
	error += Err(odds);
	if (error > 0)return 0;
	else return 1;
}

//Отрисовка аргументов функции
void Arguments(SDL_Renderer* renderer2, TTF_Font*font ,double *num, int scale, int func) {
	SDL_Texture* argTexture;
	char argum[10];
	SDL_Rect arg = { 0,0,10,10 };

	//Отрисовка границ
	_itoa_s(num[4], argum, 10);
	arg.x = 400 - (400/(num[5]-num[4])/2 * (num[5]-num[4]));
	arg.y = 307;
	argTexture = get_argTexture(renderer2, argum, font, arg);
	draw_text(renderer2, argTexture, arg);
	SDL_DestroyTexture(argTexture);
	_itoa_s(num[5], argum, 10);
	arg.x = 400 + (400 / (num[5] - num[4]) / 2 * (num[5] - num[4]));
	arg.y = 307;
	argTexture = get_argTexture(renderer2, argum, font, arg);
	draw_text(renderer2, argTexture, arg);
	SDL_DestroyTexture(argTexture);

	_itoa_s(num[6], argum, 10);
	arg.x = 407;
	arg.y = 300 + ((300 / (num[7] - num[6])) * fabs(num[6]));
	argTexture = get_argTexture(renderer2, argum, font, arg);
	draw_text(renderer2, argTexture, arg);
	SDL_DestroyTexture(argTexture);
	_itoa_s(num[7], argum, 10);
	arg.x = 407;
	arg.y = 300 - ((300 / (num[7] - num[6])) * fabs(num[7]));
	argTexture = get_argTexture(renderer2, argum, font, arg);
	draw_text(renderer2, argTexture, arg);
	SDL_DestroyTexture(argTexture);

	//Отрисовка аргументов
	switch (func)
	{
	case 2:;
	case 5:;
	case 6:;
	case 1 : {
		
		_itoa_s(num[1], argum, 10);
		arg.x = 405;
		arg.y = 300 - num[1] * scale;
		argTexture = get_argTexture(renderer2, argum, font, arg);
		draw_text(renderer2, argTexture, arg);
		SDL_DestroyTexture(argTexture);
		break;
	}
	case 3: {
		
		_itoa_s(num[0]+num[1], argum, 10);
		arg.x = 405;
		arg.y = 300 - ((num[0]+num[1]) * scale);
		argTexture = get_argTexture(renderer2, argum, font, arg);
		draw_text(renderer2, argTexture, arg);
		SDL_DestroyTexture(argTexture);
		break;
	}
	case 4: {
		
		_itoa_s(num[2], argum, 10);
		arg.x = 405;
		arg.y = 300 - (num[2] * scale);
		argTexture = get_argTexture(renderer2, argum, font, arg);
		draw_text(renderer2, argTexture, arg);
		SDL_DestroyTexture(argTexture);
		break;
	}
	
	}
	
}

//Построение графиков
void Graphics(SDL_Window*window2,SDL_Renderer*renderer2, TTF_Font*font, SDL_Surface* screen,double *num, int func, int borders, int trigonom) {
	
		const int Height2 = 600, Width2 = 800, Graph_width = 600, Graph_height = 400;
		double y;
		int X = Width2 / 2, Y = Height2 / 2;
		double x_range = num[5] - num[4];
		double y_range = num[7] - num[6];
		int x_scale = Width2 / x_range / 2;
		int y_scale = Height2 / y_range / 2;

		SDL_Surface* saveImage = IMG_Load("save.bmp");
		SDL_SetColorKey(saveImage, SDL_TRUE,
			SDL_MapRGB(saveImage->format, 255, 255, 255));
		SDL_Texture* saveTexture = SDL_CreateTextureFromSurface(renderer2, saveImage);
		SDL_FreeSurface(saveImage);
		SDL_Rect save = { 600, 530,200,70 };

		SDL_SetRenderDrawColor(renderer2, 40, 40, 40, 0);
		SDL_RenderClear(renderer2);
		SDL_SetRenderDrawColor(renderer2, 150, 150, 150, 0);
		SDL_RenderDrawLine(renderer2, 0, Y, Width2, Y);
		SDL_RenderDrawLine(renderer2, X, 0, X, Height2);
		SDL_SetRenderDrawColor(renderer2, 150, 150, 150, 0);

		for (int i = X; i <= Width2; i += x_scale) {
			SDL_RenderDrawLine(renderer2, i, Y - 2, i, Y + 2);
		}
		for (int i = X; i >= 0; i -= x_scale) {
			SDL_RenderDrawLine(renderer2, i, Y - 2, i, Y + 2);
		}
		for (int j = Y; j <= Height2; j += y_scale) {
			SDL_RenderDrawLine(renderer2, X - 2, j, X + 2, j);
		}
		for (int j = Y; j >= 0; j -= y_scale) {
			SDL_RenderDrawLine(renderer2, X - 2, j, X + 2, j);
		}
		Arguments(renderer2, font, num, y_scale, func);

		for (int i = 0; i <= Height2; i += 10) {
			SDL_RenderDrawLine(renderer2, X + x_scale * x_range / 2, i, X + x_scale * x_range / 2, i + 5);
			SDL_RenderDrawLine(renderer2, X - x_scale * x_range / 2, i, X - x_scale * x_range / 2, i + 5);
		}
		for (int i = 0; i <= Width2; i += 10) {
			SDL_RenderDrawLine(renderer2, i, (Y - (fabs(num[7]) * y_scale)), i + 5, (Y - (fabs(num[7]) * y_scale)));
			SDL_RenderDrawLine(renderer2, i, (Y + (fabs(num[6]) * y_scale)), i + 5, (Y + (fabs(num[6]) * y_scale)));
		}

		SDL_SetRenderDrawColor(renderer2, 0, 255, 127, 0);

		switch (func)
		{
		case 1: {
			for (double x = num[4]; x <= num[5]; x += 0.00001) {
				y = num[0] * x + num[1];
				int screenx = X - ((x_range / 2) * x_scale) + x_scale * (x - (num[4]));
				int screeny = Y - y_scale * y;
				if (screeny == Y - num[1] * y_scale) {
					if (screenx < X) {
						for (int j = screenx; j <= X; j += 10) {
							SDL_RenderDrawLine(renderer2, j, screeny, j + 5, screeny);
						}
					}
					else {
						for (int j = screenx; j >= X; j -= 10) {
							SDL_RenderDrawLine(renderer2, j, screeny, j - 5, screeny);
						}
					}
				}
				SDL_RenderDrawPoint(renderer2, screenx, screeny);
			}
			break;

		}
		case 2: {
			for (double x = num[4]; x <= num[5]; x += 0.00001) {
				y = num[0] * pow(x, num[2]) + num[1];
				int screenx = X - ((x_range / 2) * x_scale) + x_scale * (x - (num[4]));
				int screeny = Y - y_scale * y;
				if (screeny == Y - num[1] * y_scale) {
					if (screenx < X) {
						for (int j = screenx; j <= X; j += 10) {
							SDL_RenderDrawLine(renderer2, j, screeny, j + 5, screeny);
						}
					}
					else {
						for (int j = screenx; j >= X; j -= 10) {
							SDL_RenderDrawLine(renderer2, j, screeny, j - 5, screeny);
						}
					}
				}
				SDL_RenderDrawPoint(renderer2, screenx, screeny);
			}
			break;
		}
		case 3: {
			int fl = 0;
			switch (trigonom)
			{
			case 0: {
				for (double x = num[4]; x <= num[5]; x += 0.0001) {
					y = num[0] * sin(num[3] * x + num[2]) + num[1];

					int screenx = X - ((x_range / 2) * x_scale) + x_scale * (x - (num[4]));
					int screeny = Y - y_scale * y;

					if (screeny == Y - (num[1] + num[0]) * y_scale && fl == 0) {
						if (screenx < X) {
							for (int j = screenx; j <= X; j += 10) {
								SDL_RenderDrawLine(renderer2, j, screeny, j + 5, screeny);
							}
						}
						else {
							for (int j = screenx; j >= X; j -= 10) {
								SDL_RenderDrawLine(renderer2, j, screeny, j - 5, screeny);
							}
						}
						fl = 1;

					}
					SDL_RenderDrawPoint(renderer2, screenx, screeny);

					break;
				}
			case 1: {
				for (double x = num[4]; x <= num[5]; x += 0.0001) {
					y = num[0] * cos(num[3] * x + num[2]) + num[1];

					int screenx = X - ((x_range / 2) * x_scale) + x_scale * (x - (num[4]));
					int screeny = Y - y_scale * y;
					if (screeny == Y - (num[1] + num[0]) * y_scale && fl == 0) {
						if (screenx < X) {
							for (int j = screenx; j <= X; j += 10) {
								SDL_RenderDrawLine(renderer2, j, screeny, j + 5, screeny);
							}
						}
						else {
							for (int j = screenx; j >= X; j -= 10) {
								SDL_RenderDrawLine(renderer2, j, screeny, j - 5, screeny);
							}
						}
						fl = 1;

					}
					SDL_RenderDrawPoint(renderer2, screenx, screeny);
				}
				break;
			}
			case 2: {
				for (double x = num[4]; x <= num[5]; x += 0.0001) {
					y = num[0] * tan(num[3] * x + num[2]) + num[1];

					int screenx = X - ((x_range / 2) * x_scale) + x_scale * (x - (num[4]));
					int screeny = Y - y_scale * y;

					SDL_RenderDrawPoint(renderer2, screenx, screeny);
				}
				break;
			}
			case 3: {
				for (double x = num[4]; x <= num[5]; x += 0.0001) {
					y = num[0] * (1 / tan(num[3] * x + num[2])) + num[1];

					int screenx = X - ((x_range / 2) * x_scale) + x_scale * (x - (num[4]));
					int screeny = Y - y_scale * y;

					SDL_RenderDrawPoint(renderer2, screenx, screeny);
				}
				break;
			}
			}
			}

			break;
		}
		case 4: {
			for (double x = num[4]; x <= num[5]; x += 0.0001) {
				y = num[0] * (x * x) + num[1] * x + num[2];

				int screenx = X - ((x_range / 2) * x_scale) + x_scale * (x - (num[4]));
				int screeny = Y - y_scale * y;
				if (screeny == Y - num[2] * y_scale) {
					if (screenx < X) {
						for (int j = screenx; j <= X; j += 10) {
							SDL_RenderDrawLine(renderer2, j, screeny, j + 5, screeny);
						}
					}
					else {
						for (int j = screenx; j >= X; j -= 10) {
							SDL_RenderDrawLine(renderer2, j, screeny, j - 5, screeny);
						}
					}
				}
				SDL_RenderDrawPoint(renderer2, screenx, screeny);
			}
			break;

		}
		case 5: {
			for (double x = num[4]; x <= num[5]; x += 0.0001) {
				y = num[0] * (x * x * x) + num[1];

				int screenx = X - ((x_range / 2) * x_scale) + x_scale * (x - (num[4]));
				int screeny = Y - y_scale * y;
				if (screeny == Y - num[1] * y_scale) {
					if (screenx < X) {
						for (int j = screenx; j <= X; j += 10) {
							SDL_RenderDrawLine(renderer2, j, screeny, j + 5, screeny);
						}
					}
					else {
						for (int j = screenx; j >= X; j -= 10) {
							SDL_RenderDrawLine(renderer2, j, screeny, j - 5, screeny);
						}
					}
				}
				SDL_RenderDrawPoint(renderer2, screenx, screeny);
			}
			break;
		}
		case 6: {
			for (double x = num[4]; x <= num[5]; x += 0.0001) {
				y = (num[0] / x) + num[1];

				int screenx = X - ((x_range / 2) * x_scale) + x_scale * (x - (num[4]));
				int screeny = Y - y_scale * y;

				SDL_RenderDrawPoint(renderer2, screenx, screeny);
			}
			break;
		}
		}
		SDL_RenderCopy(renderer2, saveTexture, NULL, &save);
		SDL_RenderPresent(renderer2);
	
}

//Отрисовка клавиатуры
void Keyboard(SDL_Renderer* renderer) {
	SDL_Rect key = { 740,340, 670,450 };
	SDL_Surface* keyImage = IMG_Load("keyboard.bmp");
	SDL_SetColorKey(keyImage, SDL_TRUE,
		SDL_MapRGB(keyImage->format, 255, 255, 255));
	SDL_Texture* keyTexture = SDL_CreateTextureFromSurface(renderer, keyImage);
	SDL_FreeSurface(keyImage);
	SDL_RenderCopy(renderer, keyTexture, NULL, &key);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(keyTexture);

}
//Сохранение графика функции
void Save(SDL_Surface* screen, SDL_Renderer*renderer2, SDL_Window *window2, int form) {
	screen = SDL_GetWindowSurface(window2);
	SDL_LockSurface(screen);
	screen = SDL_CreateRGBSurface(0, 750, 750, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(renderer2, NULL, SDL_PIXELFORMAT_ARGB8888, screen->pixels, screen->pitch);
	if (form == 1) {
		SDL_SaveBMP(screen, "screenshot.bmp");
	}
	else {
		IMG_SaveJPG(screen, "screenshot.jpg", 100);
	}
	SDL_UnlockSurface(screen);
	SDL_FreeSurface(screen);
}

//Кнопки экранной клавиатуры клавиатуры
void Keyboard_Button(SDL_Event event, string& input, SDL_Rect TextPoison, int inter) {
	if (TextPoison.x + TextPoison.w < inter)
	{
		if ((event.button.x >= 755 && event.button.x <= 840) && (event.button.y <= 420 && event.button.y >= 355)) { input += "sin("; }
		if ((event.button.x >= 845 && event.button.x <= 930) && (event.button.y <= 420 && event.button.y >= 355)) { input += "cos("; }
		if ((event.button.x >= 935 && event.button.x <= 1020) && (event.button.y <= 420 && event.button.y >= 355)) { input += "tg("; }
		if ((event.button.x >= 1025 && event.button.x <= 1110) && (event.button.y <= 420 && event.button.y >= 355)) { input += "ctg("; }
		if ((event.button.x >= 1115 && event.button.x <= 1200) && (event.button.y <= 420 && event.button.y >= 355)) { input += "("; }
		if ((event.button.x >= 755 && event.button.x <= 840) && (event.button.y <= 490 && event.button.y >= 425)) { input += "7"; }
		if ((event.button.x >= 845 && event.button.x <= 930) && (event.button.y <= 490 && event.button.y >= 425)) { input += "8"; }
		if ((event.button.x >= 935 && event.button.x <= 1020) && (event.button.y <= 490 && event.button.y >= 425)) { input += "9"; }
		if ((event.button.x >= 1025 && event.button.x <= 1110) && (event.button.y <= 490 && event.button.y >= 425)) { input += "log("; }
		if ((event.button.x >= 1115 && event.button.x <= 1200) && (event.button.y <= 490 && event.button.y >= 425)) { input += ")"; }
		if ((event.button.x >= 755 && event.button.x <= 840) && (event.button.y <= 560 && event.button.y >= 495)) { input += "4"; }
		if ((event.button.x >= 845 && event.button.x <= 930) && (event.button.y <= 560 && event.button.y >= 495)) { input += "5"; }
		if ((event.button.x >= 935 && event.button.x <= 1020) && (event.button.y <= 560 && event.button.y >= 495)) { input += "6"; }
		if ((event.button.x >= 1025 && event.button.x <= 1110) && (event.button.y <= 560 && event.button.y >= 495)) { input += "^"; }
		if ((event.button.x >= 1115 && event.button.x <= 1200) && (event.button.y <= 560 && event.button.y >= 495)) { input += "["; }
		if ((event.button.x >= 755 && event.button.x <= 840) && (event.button.y <= 630 && event.button.y >= 565)) { input += "1"; }
		if ((event.button.x >= 845 && event.button.x <= 930) && (event.button.y <= 630 && event.button.y >= 565)) { input += "2"; }
		if ((event.button.x >= 935 && event.button.x <= 1020) && (event.button.y <= 630 && event.button.y >= 565)) { input += "3"; }
		if ((event.button.x >= 1025 && event.button.x <= 1110) && (event.button.y <= 630 && event.button.y >= 565)) { input += "-"; }
		if ((event.button.x >= 1115 && event.button.x <= 1200) && (event.button.y <= 630 && event.button.y >= 565)) { input += "]"; }
		if ((event.button.x >= 755 && event.button.x <= 840) && (event.button.y <= 700 && event.button.y >= 635)) { input += ","; }
		if ((event.button.x >= 845 && event.button.x <= 930) && (event.button.y <= 700 && event.button.y >= 635)) { input += "0"; }
		if ((event.button.x >= 935 && event.button.x <= 1020) && (event.button.y <= 700 && event.button.y >= 635)) { input += "."; }
		if ((event.button.x >= 1025 && event.button.x <= 1110) && (event.button.y <= 700 && event.button.y >= 635)) { input += "sqrt("; }
	}
}

int Main(SDL_Window *window,SDL_Renderer* renderer) {
	
	SDL_Rect button = { 400,560,200, 70 };
	SDL_Rect button2 = { 0,0, 40, 40 };

	SDL_Rect str = { 100, 0 , 380,300 };
	SDL_Rect str2 = { 800,0, 280,300 };
	SDL_Rect str3 = { 500, 0 , 280,300 };
	SDL_Rect funcions = { -35,170, 1140, 500 };

	SDL_Rect textPoison = { 120, 120, 100, 30 };
	SDL_Rect textPoison2 = { 850, 120, 20, 30 };
	SDL_Rect textPoison3 = { 550, 120, 20, 30 };

	SDL_Rect textPoisonA = { 225, 390, 20, 30 };
	SDL_Rect textPoisonB = { 225, 453, 20, 30 };
	SDL_Rect textPoisonC = { 515, 390, 20, 30 };
	SDL_Rect textPoisonK = { 515, 453, 20, 30 };

	string inputText, inputInterX, inputInterY,inputa, inputb, inputk, inputc;
	SDL_Texture* Text=NULL, *Interval=NULL;
	int flagButton = 0, flagStr = 0, flagStr2 = 0, flagOdds = 0, flag=1, keyboard=0;
	double *num = new double[8];
	int trigonom = 0, open=0;
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("text2.ttf", 30);
	TTF_Font* font2 = TTF_OpenFont("text.ttf", 10);
	bool quit = false;
	SDL_Event event;
	Mix_Chunk* sound = NULL;
	Mix_Music* fon = NULL;

	Mix_Init(0);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
	Interface(renderer, str, str2, str3, funcions);
	SDL_RenderPresent(renderer);
	SDL_Window* window2=NULL; 
	SDL_Renderer* renderer2=NULL; 
	SDL_Surface* screen = NULL;

	loadmusic(fon);
	while (!quit) {
		SDL_Rect text = { 600, 530, 90, 70 };
		SDL_SetRenderDrawColor(renderer2, 255, 0, 0, 0);
		SDL_RenderDrawRect(renderer2, &text);
		SDL_RenderPresent(renderer2);
		SDL_StartTextInput();
		Button(renderer, button, 1);
		But_keyboard(renderer, button2);
		SDL_RenderPresent(renderer);
		
		while (SDL_PollEvent(&event)) {
			
			if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				if (event.window.windowID == SDL_GetWindowID(window2)) {
					open = 0;
					SDL_DestroyRenderer(renderer2);
					SDL_DestroyWindow(window2);
				}
				if (event.window.windowID == SDL_GetWindowID(window)) {
					quit = true;
				
					SDL_DestroyRenderer(renderer2);
					SDL_DestroyWindow(window2);
				}
			}
			if (event.window.windowID == SDL_GetWindowID(window2)) {
				if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
					if ((event.button.x >= 600 && event.button.x <= 690) && (event.button.y <= 600 && event.button.y >= 530)) {
						Save(screen, renderer2, window2, 1);
						Sound(sound);
					}
					if ((event.button.x >= 710 && event.button.x <= 800) && (event.button.y <= 600 && event.button.y >= 530)) {
						Save(screen, renderer2, window2, 0);
						Sound(sound);
					}
				}
			}
			if ((event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN))
			{
				if (open!=1 && (((event.button.x >= button.x && event.button.x <= button.x + button.w)
					&& (event.button.y <= button.y + button.h && event.button.y >= button.y)) || event.key.keysym.sym == SDLK_RETURN))
				{
					Sound(sound);
					Button(renderer, button, 2); SDL_RenderPresent(renderer); SDL_Delay(100);
					switch (flagButton)
					{
					case 1:
					case 5:
					case 6: {
						flag *= Parsing(inputa, num, 0);
						flag *= Parsing(inputb, num, 1);
						break;
					}
					case 2:
					case 4: {
						flag *= Parsing(inputa, num, 0);
						flag *= Parsing(inputb, num, 1);
						flag *= Parsing(inputc, num, 2);
						break;
					}
					case 3: {
						flag *= Parsing(inputa, num, 0);
						flag *= Parsing(inputb, num, 1);
						flag *= Parsing(inputc, num, 2);
						flag *= Parsing(inputk, num, 3);
						break;
					}
					}
					if (flag == 0) {
						Error(renderer); SDL_RenderPresent(renderer); SDL_Delay(2000);
						SDL_RenderClear(renderer);
						Interface(renderer, str, str2, str3, funcions);
						flag = 1;
					}
					else {
						if (Parsing_borders(inputInterX, num, 4) == 0 || Parsing_borders(inputInterY, num, 6) == 0) {
							Error(renderer); SDL_RenderPresent(renderer); SDL_Delay(2000);
							SDL_RenderClear(renderer);
							Interface(renderer, str, str2, str3, funcions);
						}
						else {
							
							const int Height2 = 600, Width2 = 800;
							window2 = SDL_CreateWindow(u8"График",
								SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
								Width2, Height2, SDL_WINDOW_SHOWN);
							if (window2 == NULL)
							{
								cout << "Окно не может быть создано! SDL_Error: %s\n" << SDL_GetError();
							}
							renderer2 = SDL_CreateRenderer(window2, -1, 0);
							SDL_RenderClear(renderer2);
							open = 1;
							Graphics(window2, renderer2, font2, screen,num, flagButton, Parsing_borders(inputInterX, num, 4), trigonom);
						}
					}
				}
				if (Button_hit(button2, event.button.x, event.button.y)) {
					Keyboard(renderer);
					keyboard=1;
				}
				
				if ((event.button.x >= 105 && event.button.x <= 425) && (event.button.y <= 252 && event.button.y >= 187) ) {
					SDL_RenderClear(renderer);
					Interface(renderer, str, str2, str3, funcions);
					flagStr = 0; flagStr2 = 0; keyboard = 0;
					inputa = ""; inputb = ""; inputc = ""; inputk = ""; inputInterX = ""; inputInterY = "";
					textPoisonA = { 225, 390, 20, 30 };
					textPoisonB = { 225, 455, 20, 30 };
					textPoisonC = { 520, 390, 20, 30 };
					textPoisonK = { 520, 455, 20, 30 };
					inputText = "y=a*x+b";
					Text = get_textTexture(renderer, inputText, font, textPoison);
					draw_text(renderer, Text, textPoison);
					Odds(renderer, 2);
					SDL_RenderPresent(renderer);
					SDL_DestroyTexture(Text);
					flagButton = 1;
				}
				if ((event.button.x >= 435 && event.button.x <= 755) && (event.button.y <= 252 && event.button.y >= 187) ) {
					SDL_RenderClear(renderer);
					Interface(renderer, str, str2, str3, funcions);
					flagStr = 0; flagStr2 = 0; keyboard = 0;
					inputa = ""; inputb = ""; inputc = ""; inputk = ""; inputInterX = ""; inputInterY = "";
					textPoisonA = { 225, 390, 20, 30 };
					textPoisonB = { 225, 455, 20, 30 };
					textPoisonC = { 520, 390, 20, 30 };
					textPoisonK = { 520, 455, 20, 30 };
					inputText = "y=a*x^c+b";
					Text = get_textTexture(renderer, inputText, font, textPoison);
					draw_text(renderer, Text, textPoison);
					Odds(renderer, 3);
					SDL_RenderPresent(renderer);
					SDL_DestroyTexture(Text);
					flagButton = 2;
				}
				if ((event.button.x >= 765 && event.button.x <= 1085) && (event.button.y <= 252 && event.button.y >= 187) ) {
					SDL_RenderClear(renderer);
					Interface(renderer, str, str2, str3, funcions);
					flagStr = 0; flagStr2 = 0; keyboard = 0;
					inputa = ""; inputb = ""; inputc = ""; inputk = ""; inputInterX = ""; inputInterY = "";
					textPoisonA = { 225, 390, 20, 30 };
					textPoisonB = { 225, 455, 20, 30 };
					textPoisonC = { 520, 390, 20, 30 };
					textPoisonK = { 520, 455, 20, 30 };
					inputText = "y=a*sin(k*x+c)+b";
					Text = get_textTexture(renderer, inputText, font, textPoison);
					draw_text(renderer, Text, textPoison);
					Odds(renderer, 4);
					SDL_RenderPresent(renderer);
					SDL_DestroyTexture(Text);
					flagButton = 3;
				}
				if ((event.button.x >= 105 && event.button.x <= 425) && (event.button.y <= 337 && event.button.y >= 267) ) {
					SDL_RenderClear(renderer);
					Interface(renderer, str, str2, str3, funcions);
					flagStr = 0; flagStr2 = 0; keyboard = 0;
					inputa = ""; inputb = ""; inputc = ""; inputk = ""; inputInterX = ""; inputInterY = "";
					textPoisonA = { 225, 390, 20, 30 };
					textPoisonB = { 225, 455, 20, 30 };
					textPoisonC = { 520, 390, 20, 30 };
					textPoisonK = { 520, 455, 20, 30 };
					inputText = "y=a*x^2+b*x+c";
					Text = get_textTexture(renderer, inputText, font, textPoison);
					draw_text(renderer, Text, textPoison);
					Odds(renderer, 3);
					SDL_RenderPresent(renderer);
					SDL_DestroyTexture(Text);
					flagButton = 4;
				}
				if ((event.button.x >= 435 && event.button.x <= 755) && (event.button.y <= 337 && event.button.y >= 267) ) {
					SDL_RenderClear(renderer);
					Interface(renderer, str, str2, str3, funcions);
					flagStr = 0; flagStr2 = 0; keyboard = 0;
					inputa = ""; inputb = ""; inputc = ""; inputk = ""; inputInterX = ""; inputInterY = "";
					textPoisonA = { 225, 390, 20, 30 };
					textPoisonB = { 225, 455, 20, 30 };
					textPoisonC = { 520, 390, 20, 30 };
					textPoisonK = { 520, 455, 20, 30 };
					inputText = "y=a*x^3+b";
					Text = get_textTexture(renderer, inputText, font, textPoison);
					draw_text(renderer, Text, textPoison);
					Odds(renderer, 2);
					SDL_RenderPresent(renderer);
					SDL_DestroyTexture(Text);
					flagButton = 5;
				}
				if ((event.button.x >= 765 && event.button.x <= 1085) && (event.button.y <= 337 && event.button.y >= 267) ) {
					SDL_RenderClear(renderer);
					Interface(renderer, str, str2, str3, funcions);
					flagStr = 0; flagStr2 = 0; keyboard = 0;
					inputa = ""; inputb = ""; inputc = ""; inputk = ""; inputInterX = ""; inputInterY = "";
					textPoisonA = { 225, 390, 20, 30 };
					textPoisonB = { 225, 455, 20, 30 };
					textPoisonC = { 520, 390, 20, 30 };
					textPoisonK = { 520, 455, 20, 30 };
					inputText = "y=a/x+b";
					Text = get_textTexture(renderer, inputText, font, textPoison);
					draw_text(renderer, Text, textPoison);
					Odds(renderer, 2);
					SDL_RenderPresent(renderer);
					SDL_DestroyTexture(Text);
					flagButton = 6;
				}
				
			}

			if (flagButton == 3) {
				if ((event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT &&
					(event.button.x >= 100 && event.button.x <= 475) && (event.button.y <= 165 && event.button.y >= 100))) {
					trigonom += 1;
					if (trigonom == 4)trigonom = 0;
					switch (trigonom)
					{
					case 0: {inputText = "y=a*sin(k*x+c)+b"; break; }
					case 1:{inputText = "y=a*cos(k*x+c)+b"; break;}
					case 2:{inputText = "y=a*tg(k*x+c)+b"; break; }
					case 3: {inputText = "y=a*ctg(k*x+c)+b"; break; }
					}
					flagStr = 0; flagStr2 = 0;
					inputa = ""; inputb = ""; inputc = ""; inputk = ""; inputInterX = ""; inputInterY = "";
					textPoisonA = { 225, 390, 20, 30 };
					textPoisonB = { 225, 455, 20, 30 };
					textPoisonC = { 520, 390, 20, 30 };
					textPoisonK = { 520, 455, 20, 30 };
					SDL_RenderClear(renderer);
					Interface(renderer, str, str2, str3, funcions);
					Text = get_textTexture(renderer, inputText, font, textPoison);
					draw_text(renderer, Text, textPoison);
					Odds(renderer, 4);
					SDL_RenderPresent(renderer);
					SDL_DestroyTexture(Text);
				}
			}
			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && keyboard == 1 && flagOdds != 0) {
				if ((event.button.x >= 755 && event.button.x <= 1180) && (event.button.y <= 700 && event.button.y >= 355) && flagOdds ==1) {
					if (flagStr == 0 && flagStr2 == 0) {
						Keyboard_Button(event, inputa, textPoisonA, 375);
						Text = get_textTexture(renderer, inputa, font, textPoisonA);
						draw_text(renderer, Text, textPoisonA);
						SDL_DestroyTexture(Text);
					}
					if (flagStr == 0 && flagStr2 == 1) {
						Keyboard_Button(event, inputb, textPoisonB, 375);
						Text = get_textTexture(renderer, inputb, font, textPoisonB);
						draw_text(renderer, Text, textPoisonB);
						SDL_DestroyTexture(Text);
					}
					if (flagStr == 1 && flagStr2 == 0 && (flagButton == 2 || flagButton == 3 || flagButton == 4)) {
						Keyboard_Button(event, inputc, textPoisonC, 670);
						Text = get_textTexture(renderer, inputc, font, textPoisonC);
						draw_text(renderer, Text, textPoisonC);
						SDL_DestroyTexture(Text);
					}
					if (flagStr == 1 && flagStr2 == 1 && flagButton == 3) {
						Keyboard_Button(event, inputk, textPoisonK, 670);
						Text = get_textTexture(renderer, inputk, font, textPoisonK);
						draw_text(renderer, Text, textPoisonK);
						SDL_DestroyTexture(Text);
					}
				}
				if ((event.button.x >= 755 && event.button.x <= 1180) && (event.button.y <= 700 && event.button.y >= 355) && flagOdds == 2) {
					Keyboard_Button(event, inputInterX, textPoison2, 1050);
					Interval = get_textTexture(renderer, inputInterX, font, textPoison2);
					draw_text(renderer, Interval, textPoison2);
					SDL_DestroyTexture(Interval);
				}
				if ((event.button.x >= 755 && event.button.x <= 1180) && (event.button.y <= 700 && event.button.y >= 355) && flagOdds == 3) {
					Keyboard_Button(event, inputInterY, textPoison3, 750);
					Interval = get_textTexture(renderer, inputInterY, font, textPoison3);
					draw_text(renderer, Interval, textPoison3);
					SDL_DestroyTexture(Interval);
				}
			}

			if ((event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT &&
				(event.button.x >= 100 && event.button.x <= 750) && (event.button.y <= 550 && event.button.y >= 350))) {
				flagOdds = 1;
			}
			if ((event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT &&
				(event.button.x >= 800 && event.button.x <= 1080) && (event.button.y <= 165 && event.button.y >= 100))) {
				flagOdds = 2;
			}
			if ((event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT &&
				(event.button.x >= 500 && event.button.x <= 780) && (event.button.y <= 165 && event.button.y >= 100))) {
				flagOdds = 3;
			}
				if (flagButton != 0 && flagOdds==1) {
					if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT) {
						if (flagStr == 0) {
							flagStr += 1;
							
						}
					}
					if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT) {
						if (flagStr == 1) {
							flagStr -= 1;
							
						}
					}
					if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN) {
						if (flagStr2 == 0) {
							flagStr2 += 1;
						}
					}
					if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP) {
						if (flagStr2 == 1) {
							flagStr2 -= 1;
						}
					}
				}
				if (event.type == SDL_TEXTINPUT && flagButton != 0 && flagOdds!=0) {
					if (flagOdds == 2) {
						if (textPoison2.x + textPoison2.w < 1050)
						{
							inputInterX += event.text.text;
							Interval = get_textTexture(renderer, inputInterX, font, textPoison2);
							draw_text(renderer, Interval, textPoison2);
							SDL_DestroyTexture(Interval);
						}
					}
					if (flagOdds == 3) {
						if (textPoison3.x + textPoison3.w < 750)
						{
							inputInterY += event.text.text;
							Interval = get_textTexture(renderer, inputInterY, font, textPoison3);
							draw_text(renderer, Interval, textPoison3);
							SDL_DestroyTexture(Interval);
						}
					}
					if(flagOdds ==1) {
						if (flagStr == 0 && flagStr2 == 0 && flagButton != 0) {
							if (textPoisonA.x + textPoisonA.w < 375)
							{
								inputa += event.text.text;
								Text = get_textTexture(renderer, inputa, font, textPoisonA);
								draw_text(renderer, Text, textPoisonA);
								SDL_DestroyTexture(Text);
							}
						}
						if (flagStr == 0 && flagStr2 == 1 && flagButton != 0) {
							if (textPoisonB.x + textPoisonB.w < 375)
							{
								inputb += event.text.text;
								Text = get_textTexture(renderer, inputb, font, textPoisonB);
								draw_text(renderer, Text, textPoisonB);
								SDL_DestroyTexture(Text);
							}
						}
						if (flagStr == 1 && flagStr2 == 0 && (flagButton == 2 || flagButton == 3 || flagButton == 4)) {
							if (textPoisonC.x + textPoisonC.w < 670)
							{
								inputc += event.text.text;
								Text = get_textTexture(renderer, inputc, font, textPoisonC);
								draw_text(renderer, Text, textPoisonC);
								SDL_DestroyTexture(Text);
							}
						}
						if (flagStr == 1 && flagStr2 == 1 && flagButton == 3) {
							if (textPoisonK.x + textPoisonK.w < 670)
							{
								inputk += event.text.text;
								Text = get_textTexture(renderer, inputk, font, textPoisonK);
								draw_text(renderer, Text, textPoisonK);
								SDL_DestroyTexture(Text);
							}
						}
					}
					SDL_RenderPresent(renderer);
				}

				if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE)) {
					if (flagOdds == 2) {
						if (inputInterX.size() > 1) {
							inputInterX.pop_back();
						}
						else {
							inputInterX = " "; 
							SDL_Rect del = { textPoison2.x - 3, 120, 30, 30 };
							SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
							SDL_RenderFillRect(renderer, &del);
						}
						Interval = get_textTexture(renderer, inputInterX, font, textPoison2);
						SDL_Rect del = { textPoison2.x + textPoison2.w - 3, 120, 30, 30 };
						SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
						SDL_RenderFillRect(renderer, &del);
						draw_text(renderer, Interval, textPoison2);
						SDL_RenderPresent(renderer);
						SDL_DestroyTexture(Interval);
					}
					if (flagOdds == 3) {
						if (inputInterY.size() > 1) {
							inputInterY.pop_back();
						}
						else {
							inputInterY = " ";
							SDL_Rect del = { textPoison3.x - 3, 120, 30, 30 };
							SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
							SDL_RenderFillRect(renderer, &del);
						}
						Interval = get_textTexture(renderer, inputInterY, font, textPoison3);
						SDL_Rect del = { textPoison3.x + textPoison3.w - 3, 120, 30, 30 };
						SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
						SDL_RenderFillRect(renderer, &del);
						draw_text(renderer, Interval, textPoison3);
						SDL_RenderPresent(renderer);
						SDL_DestroyTexture(Interval);
					}
					if(flagOdds==1) {
						if (flagStr == 0 && flagStr2 == 0 && inputa.size() > 0) {
							if (inputa.size() > 1) {
								inputa.pop_back();
							}
							else {
								inputa = " ";
								SDL_Rect del = { textPoisonA.x - 3, 390, 30, 30 };
								SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
								SDL_RenderFillRect(renderer, &del);
							}
							Text = get_textTexture(renderer, inputa, font, textPoisonA);
							SDL_Rect del = { textPoisonA.x + textPoisonA.w - 3, 390, 30, 30 };
							SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
							SDL_RenderFillRect(renderer, &del);
							draw_text(renderer, Text, textPoisonA);
							SDL_RenderPresent(renderer);
							SDL_DestroyTexture(Text);
						}
						if (flagStr == 0 && flagStr2 == 1 && inputb.size() > 0) {
							if (inputb.size() > 1) {
								inputb.pop_back();
							}
							else {
								inputb = " ";
								SDL_Rect del = { textPoisonB.x - 3, 453, 30, 30 };
								SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
								SDL_RenderFillRect(renderer, &del);
							}
							Text = get_textTexture(renderer, inputb, font, textPoisonB);
							SDL_Rect del = { textPoisonB.x + textPoisonB.w - 3, 453, 30, 30 };
							SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
							SDL_RenderFillRect(renderer, &del);
							draw_text(renderer, Text, textPoisonB);
							SDL_RenderPresent(renderer);
							SDL_DestroyTexture(Text);
						}
						if (flagStr == 1 && flagStr2 == 0 && inputc.size() > 0) {
							if (inputc.size() > 1) {
								inputc.pop_back();
							}
							else {
								inputc = " ";
								SDL_Rect del = { textPoisonC.x - 3, 390, 30, 30 };
								SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
								SDL_RenderFillRect(renderer, &del);
							}
							Text = get_textTexture(renderer, inputc, font, textPoisonC);
							SDL_Rect del = { textPoisonC.x + textPoisonC.w - 3, 390, 30, 30 };
							SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
							SDL_RenderFillRect(renderer, &del);
							draw_text(renderer, Text, textPoisonC);
							SDL_RenderPresent(renderer);
							SDL_DestroyTexture(Text);
						}
						if (flagStr == 1 && flagStr2 == 1 && inputk.size() > 0) {
							if (inputk.size() > 1) {
								inputk.pop_back();
							}
							else {
								inputk = " ";
								SDL_Rect del = { textPoisonK.x - 3, 453, 30, 30 };
								SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
								SDL_RenderFillRect(renderer, &del);
							}
							Text = get_textTexture(renderer, inputk, font, textPoisonK);
							SDL_Rect del = { textPoisonK.x + textPoisonK.w - 3, 453, 30, 30 };
							SDL_SetRenderDrawColor(renderer, 230, 230, 230, 0);
							SDL_RenderFillRect(renderer, &del);
							draw_text(renderer, Text, textPoisonK);
							SDL_RenderPresent(renderer);
							SDL_DestroyTexture(Text);
						}
					}

				}
			
		}
	}
	delete[]num;
	Mix_FreeMusic(fon);
	Mix_FreeChunk(sound);
	Mix_CloseAudio();
	SDL_StopTextInput();
	TTF_CloseFont(font);
	TTF_Quit();
	return 1;
}