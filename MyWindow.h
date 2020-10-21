/*
 * MyWindow.h
 *
 *  Created on: 19 ���. 2020 �.
 *      Author: erijkova
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Window.h"

// ���������� ������ MyWindow ��� ������� Window
class MyWindow: public Window
{
public:
	static constexpr int DEFAULT_WIDTH = 800;
	static constexpr int DEFAULT_HEIGHT = 600;

protected:
	double _angle; // ���� ��������
	double _eye_level; // ������ ������ ����
	double _houseHeight;
	double _houseWidth;
	double _houseLength;

public:


	// ����������� ������ ExampleWindow
	MyWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);

	// ���������� ������ ExampleWindow
	virtual ~MyWindow() = default;

	// ����� ��������� ��������� ����
	virtual void setup() override;

	// ����� ��������� ����
	virtual void render() override;

	// ����� ��������� ������
	virtual void handle_logic() override;

	// ����� ��������� ������
	virtual void handle_keys(const Uint8 * keys) override;
};




#endif /* MYWINDOW_H_ */
