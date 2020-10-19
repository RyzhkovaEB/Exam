/*
 * MyWindow.cc
 *
 *  Created on: 19 ���. 2020 �.
 *      Author: erijkova
 */
#include <conio.h>
#include <stdio.h>
#include <cmath>//��������� ���������� cmath

static constexpr double Pi = acos(-1.);//������������ �� ����� ���������� -1

#include "MyWindow.h"//����������� ExampleWindow.h

MyWindow::MyWindow(int width, int height)//�������� ����, ������� ����
: Window(width, height)
{
	_angle = 0.; // ���� ��������
	_eye_level = 0.;// ������ ������ ����
}

static const float s_material_red[4]     { 1.f, 0.f, 0.f, 1.f };//�������� ����� ��� ���������, �������
static const float s_material_green[4]   { 0.f, 1.f, 0.f, 1.f };//�������
static const float s_material_blue[4]    { 0.f, 0.f, 1.f, 1.f };//�������
static const float s_material_cyan[4]    { 0.f, 1.f, 1.f, 1.f };//�����
static const float s_material_magenta[4] { 1.f, 0.f, 1.f, 1.f };//���������
static const float s_material_yellow[4]  { 1.f, 1.f, 0.f, 1.f };//������

void MyWindow::setup()//��� ���������� ��������� ��������� ����
{
	glEnable(GL_DEPTH_TEST);// ����������� ��������� ������ � ����������� ����� �������
	glEnable(GL_LIGHTING);//���������� ������� ��������� ��������� ��� ���������� ����� ��� ������� �������
	glEnable(GL_LIGHT0);//�������� ���� 0 � ������ ��������� ���������
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);//��� �������� ���������: ������� ������������� �������� ����� � �����
	glMatrixMode(GL_PROJECTION);//������������� ��� ����, ����� �������� ��������� �����: ����� ���������� �������, ��� ������� � ���������� ����� ������������� ��������
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);//������� ��������
	glMatrixMode(GL_MODELVIEW);//��������, �������� ����, ��� ����� ����� ���������
}

void MyWindow::render()//��������� ����
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//������� ������, � ��������� ����� ���������� ��� ������� ������ � ����� �������.

	glLoadIdentity();//�������� ������� ������� ���������� ��������
	gluLookAt(
			10., 0., 0. * _eye_level, //��� ���������� ����� �����
			0., 0., 0.,
			0., 0., 1.); // �������� ������� ��� ���������

	glRotated(_angle, 0., 0., 1.); //������� ������ �����  (0,0,1) �� ����

	if (_isHeight) {
		glScaled(1.,1.,2.);
	}
	if (_isWidth) {
		glScaled(1.,2.,1.);
	}
	if (_isLength) {
		glScaled(2.,1.,1.);
	}

	glBegin(GL_QUADS); //(������� ���������� OpenGL) �� ����������, ��� ����� ��������. �������, ����� �������� �������

	glNormal3d(  1.,  0.,  0.); //�������� ������� � ������������ 1,0,0
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_red); //�������� ��������: ���� ���������, ���� ���������� �����, ���� �� s_material_red
	glVertex3d(  1., -1.,  1.); //������������� ����� �� ��������� (4 �����), ������������ ���������
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1.,  1., -1.);
	glVertex3d(  1., -1., -1.);

	glNormal3d( -1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_cyan);//�������� ��������: ���� ���������, ���� ���������� �����, ���� �� s_material_cyan
	glVertex3d( -1.,  1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d( -1.,  1., -1.);

	glNormal3d(  0.,  1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);//�������� ��������: ���� ���������, ���� ���������� �����, ���� �� s_material_green
	glVertex3d( -1.,  1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);

	glNormal3d(  0., -1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_magenta); //����������
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);//����������
	glVertex3d( -1.,  1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);

	glNormal3d(  0.,  0., -1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_yellow);//����������
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);

	glNormal3d(  0.,  0., 1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_yellow);//�����
	glVertex3d( -1.,  1., 1.);
	glVertex3d(  1.,  1., 1.);
	glVertex3d(  1., -1. / 1000., 2.);
	glVertex3d( -1., -1. / 1000., 2.);

	glNormal3d(  0.,  0., 1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);//�����
	glVertex3d( -1., 1. / 1000., 2.);
	glVertex3d(  1., 1. / 1000., 2.);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);

	glEnd();  //����� ��������� "��������"
}

void MyWindow::handle_logic() //����� ��������� ������, ������� Window
{
//	_angle += 1.10.; //
//	if (_angle >= 360.)
//		_angle -= 360.;
//
//	_eye_level = sin(_angle / 180. * Pi);
}
void MyWindow::handle_keys(const Uint8 * keys) //����� ��������� ������, ������� Window
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
		_isHeight = true;
	}
	if (keys[SDL_SCANCODE_W]) {
		_isWidth = true;
	}
	if (keys[SDL_SCANCODE_L]) {
		_isLength = true;
	}
}
