#pragma once


class ScreenCapture
{
private:
	HDC hMemDC, hDisplayDC;

public:
	UINT screenSizeX, screenSizeY;

	void init(HDC hMemDC, HDC hDisplayDC);
	void shot();

};

