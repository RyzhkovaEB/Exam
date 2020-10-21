/*
 * MyWindow.cc
 *
 *  Created on: 19 окт. 2020 г.
 *      Author: erijkova
 */
#include <conio.h>
#include <stdio.h>
#include <cmath>//включение библиотеки cmath

static constexpr double Pi = acos(-1.);//опеределение Пи через арккосинус -1

#include "MyWindow.h"//подключение ExampleWindow.h

MyWindow::MyWindow(int width, int height)//создание окна, размеры окна
: Window(width, height)
{
	_angle = 0.; // угол поворота
	_eye_level = 0.;// высота уровня глаз
	_houseWidth = 1.;
	_houseLength = 1.;
	_houseHeight = 1.;
}

static const float s_material_red[4]     { 1.f, 0.f, 0.f, 1.f };//задаются цвета для плоскости, красный
static const float s_material_green[4]   { 0.f, 1.f, 0.f, 1.f };//зеленый
static const float s_material_blue[4]    { 0.f, 0.f, 1.f, 1.f };//голубой
static const float s_material_cyan[4]    { 0.f, 1.f, 1.f, 1.f };//синий
static const float s_material_magenta[4] { 1.f, 0.f, 1.f, 1.f };//пурпурный
static const float s_material_yellow[4]  { 1.f, 1.f, 0.f, 1.f };//желтый

void MyWindow::setup()//тут происходит начальная настройка окна
{
	glEnable(GL_DEPTH_TEST);// выполняется сравнение глубин и обновляется буфер глубины
	glEnable(GL_LIGHTING);//использует текущие параметры освещения для вычисления цвета или индекса вершины
	glEnable(GL_LIGHT0);//включает свет 0 в оценку уравнения освещения
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);//это параметр состояния: который устанавливает значение цвета в буфер
	glMatrixMode(GL_PROJECTION);//предназначена для того, чтобы задавать матричный режим: будет определена матрица, над которой в дальнейшем будут производиться операции
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);//создает проекцию
	glMatrixMode(GL_MODELVIEW);//возможно, просмотр того, что будет внизу строиться
}

void MyWindow::render()//отрисовка окна
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//очищает Буферы, в настоящее время включенные для цветной записи и Буфер глубины.

	glLoadIdentity();//заменяет текущую матрицу идентичной матрицей
	gluLookAt(
			10., 0., 0. * _eye_level, //тут отдаляться будет кубик
			0., 0., 0.,
			0., 0., 1.); // задается матрица для просмотра

	glRotated(_angle, 0., 0., 1.); //поворот вокруг точки  (0,0,1) на угол

	glScaled(_houseWidth, _houseLength, _houseHeight);

	glBegin(GL_QUADS); //(Функция библиотеки OpenGL) мы определяем, что будем рисовать. Кажется, здесь четверня названо

	glNormal3d(  1.,  0.,  0.); //задается нормаль с координатами 1,0,0
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_red); //задается материал: всей плоскости, цвет диффузного света, цвет из s_material_red
	glVertex3d(  1., -1.,  1.); //устанавливает точки на плоскости (4 штуки), расположение плоскости
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1.,  1., -1.);
	glVertex3d(  1., -1., -1.);

	glNormal3d( -1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_cyan);//задается материал: всей плоскости, цвет диффузного света, цвет из s_material_cyan
	glVertex3d( -1.,  1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d( -1.,  1., -1.);

	glNormal3d(  0.,  1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);//задается материал: всей плоскости, цвет диффузного света, цвет из s_material_green
	glVertex3d( -1.,  1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);

	glNormal3d(  0., -1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_magenta); //аналогично
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);//аналогично
	glVertex3d( -1.,  1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);

	glNormal3d(  0.,  0., -1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_yellow);//аналогично
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);

	glNormal3d(  0.,  0., 1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_yellow);//крыша
	glVertex3d( -1.,  1., 1.);
	glVertex3d(  1.,  1., 1.);
	glVertex3d(  1., -1. / 1000., 2.);
	glVertex3d( -1., -1. / 1000., 2.);

	glNormal3d(  0.,  0., 1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);//крыша
	glVertex3d( -1., 1. / 1000., 2.);
	glVertex3d(  1., 1. / 1000., 2.);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);

	glEnd();  //конец рисования "четверни"
}

void MyWindow::handle_logic() //метод обработки логики, потомок Window
{

}
void MyWindow::handle_keys(const Uint8 * keys) //метод обработки логики, потомок Window
{
	if (keys[SDL_SCANCODE_LEFT]) {
		_angle -= 1/10.;
			if (_angle >= 360.)
				_angle -= 360.;

			_eye_level = sin(_angle / 180. * Pi);
	}

	if (keys[SDL_SCANCODE_RIGHT]) {
		_angle += 1/10.;
			if (_angle >= 360.)
				_angle -= 360.;

			_eye_level = sin(_angle / 180. * Pi);

	}

	if (keys[SDL_SCANCODE_H]) {
		_houseHeight = _houseHeight + 1. / 1000.;
	} else {
		if (_houseHeight > 1.) {
			_houseHeight = _houseHeight - 1. / 1000.;
		}
	}

	if (keys[SDL_SCANCODE_W]) {
		_houseWidth = _houseWidth + 1. / 1000.;
	} else {
		if (_houseWidth > 1.) {
			_houseWidth = _houseWidth - 1. / 1000.;
		}
	}

	if (keys[SDL_SCANCODE_L]) {
		_houseLength = _houseLength + 1. / 1000.;
	} else {
		if (_houseLength > 1.) {
			_houseLength = _houseLength - 1. / 1000.;
		}
	}
}
