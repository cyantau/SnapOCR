#include "pch.h"
#include "ScreenCapture.h"
#include "SaveBitmapToFile.h"
//#include "SaveBitmapToFile.h"

void ScreenCapture::init(HDC hMemDC, HDC hDisplayDC){
	this->hMemDC = hMemDC;
	this->hDisplayDC = hDisplayDC;
	//获取设备属性
	screenSizeX = GetDeviceCaps(hMemDC, DESKTOPHORZRES); //retrieves device-specific information for the specified device.
	screenSizeY = GetDeviceCaps(hMemDC, DESKTOPVERTRES);
}

void ScreenCapture::shot()
{

	HBITMAP hBitmap = CreateCompatibleBitmap(hDisplayDC, screenSizeX, screenSizeY);// creates a bitmap compatible with the device that is associated with the specified device context.
	//SaveBitmapToFile(hBitmap, L"screen.png");
	SelectObject(hMemDC, hBitmap);//selects an object into the specified device context (DC). The new object replaces the previous object of the same type.
	//SaveBitmapToFile(hBitmap, L"screen2.png");
	BitBlt(hMemDC,0,0, screenSizeX, screenSizeY, hDisplayDC,0,0, SRCCOPY);//performs a bit-block transfer of the color data corresponding to 
	SaveBitmapToFile(hBitmap, L"screen1.png");

}
