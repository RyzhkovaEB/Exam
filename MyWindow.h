/*
 * MyWindow.h
 *
 *  Created on: 19 окт. 2020 г.
 *      Author: erijkova
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Window.h"

// Объявление класса MyWindow как потомка Window
class MyWindow: public Window
{
	double _houseWidth;
	double _houseLength;
	double _houseHeight;

public:
	static constexpr int DEFAULT_WIDTH = 800;
	static constexpr int DEFAULT_HEIGHT = 600;

protected:
	double _angle; // угол поворота
	double _eye_level; // высота уровня глаз
	bool _isHeight = false; // увеличивать высоту
	bool _isWidth = false; // увеличивать ширину
	bool _isLength = false; // увеличивать длину

public:

	// Конструктор класса ExampleWindow
	MyWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);

	// Деструктор класса ExampleWindow
	virtual ~MyWindow() = default;

	// Метод начальной настройки окна
	virtual void setup() override;

	// Метод отрисовки окна
	virtual void render() override;

	// Метод обработки логики
	virtual void handle_logic() override;

	// Метод обработки логики
	virtual void handle_keys(const Uint8 * keys) override;
};




#endif /* MYWINDOW_H_ */
