/*
 * main.cc - отсюда всё начинается.
 *
 *  Created on: 14 окт. 2020 г.
 *      Author: unyuu
 */


#include <iostream>
#include <stdexcept>
#include <locale>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "ExampleWindow.h"
#include "MyWindow.h"

// ����� ������� �������!
int main(int, char**)
{
	// ������������� SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	try {

		MyWindow w;

		w.main_loop();


	} catch (const std::exception &e) {
		// Обработка стандартных исключений
		std::cerr <<
				"При выполнении программы возникла "
				"ошибка:" << std::endl <<
				e.what() << std::endl;
		return 1;
	} catch (...) {
		// Обработка неизвестных исключений
		std::cerr <<
				"При выполнении программы возникла "
				"неизвестная ошибка." << std::endl;
		return 1;
	}


	return 0;
}

