/*
 * ExampleWindow.cc
 *
 *  Created on: 19 РѕРєС‚. 2020 Рі.
 *      Author: unyuu
 */

#include <cmath>//включение библиотеки cmath

static constexpr double Pi = acos(-1.);//опеределение Пи через арккосинус -1

#include "ExampleWindow.h"//подключение ExampleWindow.h

ExampleWindow::ExampleWindow(int width, int height)//создание окна, размеры окна
: Window(width, height)
{
	_angle = 0.; // угол поворота
	_eye_level = 0.;// высота уровня глаз
}

static const float s_material_red[4]     { 1.f, 0.f, 0.f, 1.f };//задаются цвета для плоскости, красный
static const float s_material_green[4]   { 0.f, 1.f, 0.f, 1.f };//зеленый
static const float s_material_blue[4]    { 0.f, 0.f, 1.f, 1.f };//голубой
static const float s_material_cyan[4]    { 0.f, 1.f, 1.f, 1.f };//синий
static const float s_material_magenta[4] { 1.f, 0.f, 1.f, 1.f };//пурпурный
static const float s_material_yellow[4]  { 1.f, 1.f, 0.f, 1.f };//желтый

void ExampleWindow::setup()//тут происходит начальная настройка окна
{
	glEnable(GL_DEPTH_TEST);// выполняется сравнение глубин и обновляется буфер глубины
	glEnable(GL_LIGHTING);//использует текущие параметры освещения для вычисления цвета или индекса вершины
	glEnable(GL_LIGHT0);//включает свет 0 в оценку уравнения освещения
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);//это параметр состояния: который устанавливает значение цвета в буфер
	glMatrixMode(GL_PROJECTION);//предназначена для того, чтобы задавать матричный режим: будет определена матрица, над которой в дальнейшем будут производиться операции
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);//создает проекцию
	glMatrixMode(GL_MODELVIEW);//возможно, просмотр того, что будет внизу строиться
}

void ExampleWindow::render()//отрисовка окна
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//очищает Буферы, в настоящее время включенные для цветной записи и Буфер глубины.

	glLoadIdentity();//заменяет текущую матрицу идентичной матрицей
	gluLookAt(
			5., 5., 5. * _eye_level, //тут отдаляться будет кубик
			0., 0., 0.,
			0., 0., 1.);// задается матрица для просмотра

	glRotated(_angle, 0., 0., 1.); //поворот вокруг точки  (0,0,1) на угол

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

	glEnd();  //конец рисования "четверни"
}

void ExampleWindow::handle_logic() //метод обработки логики, потомок Window
{
	_angle += 1/10.; // скорость. я замедлила, потому что он у меня слишком быстро вертелся
	if (_angle >= 360.) //если угол > = 360,
		_angle -= 360.;//то вычесть 360

	_eye_level = sin(_angle / 180. * Pi); //взять синус от _angle / 180. * Pi, может чтобы по кругу вращалось..
}
