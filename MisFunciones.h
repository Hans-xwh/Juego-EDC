#pragma once

#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED


#include <iostream>
#include <Windows.h>
#include <stdlib.h>


using namespace std;
using namespace System;

void crash() {
	cout << "Test";
	throw(0);
}

void colores(int codigo) {
	switch (codigo)
	{
	case 0:
		Console::ForegroundColor = ConsoleColor::Black;
		break;
	case 1:
		Console::ForegroundColor = ConsoleColor::Red;
		break;
	default:
		break;
	}
}
#endif