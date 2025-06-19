#pragma once

/*======================================*/
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <chrono>  // Necesario para std::chrono
/*======================================*/

/*======================================*/
using namespace std;
using namespace System;
/*======================================*/

//Constantes y variales globales
const int FILAS_MAPA = 25;
const int COLUMNAS_MAPA = 55;

//definen la posición actual del personaje
int personaje_fila = 1;
int personaje_columna = 1;

string personaje[4] = {
	" o ",
	"-0-",
	" # ",
	"/ \\"
};

int mapa_1[FILAS_MAPA][COLUMNAS_MAPA] = {
{3,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,1,1,1,1,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,3,3,3,0,0,0,0,0,0,3,3,3,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,1,1,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,3,3,3,0,0,0,0,0,0,3,3,3,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,3,3,3,0,0,0,0,0,3,3,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0},
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}
};

void establecer_color_mapa(int color_codigo) {
	switch (color_codigo) {
	case 0: Console::ForegroundColor = ConsoleColor::Black; break;
	case 1: Console::ForegroundColor = ConsoleColor::Yellow; break;
	case 2: Console::ForegroundColor = ConsoleColor::Red; break;
	case 3: Console::ForegroundColor = ConsoleColor::Green; break;
	case 4: Console::ForegroundColor = ConsoleColor::White; break;
	case 5: Console::ForegroundColor = ConsoleColor::Cyan; break;
	case 6: Console::ForegroundColor = ConsoleColor::Magenta; break;
	case 7: Console::ForegroundColor = ConsoleColor::Gray; break;
	case 8: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
	default: Console::ForegroundColor = ConsoleColor::Gray; break;
	}
}

void configurar_ventana_mapa() {
	Console::SetWindowSize(150, 40);
	Console::CursorVisible = false;
}

void dibujar_mapa(int mapa[FILAS_MAPA][COLUMNAS_MAPA]) {
	for (int fila = 0; fila < FILAS; fila++)
	{
		for (int columna = 0; columna < COLUMNAS; columna++)
		{
			mover_cursor(columna, fila);
			establecer_color_mapa(mapa[fila][columna]);
			cout << (char)219;
		}
	}
}


void borrar_personaje(int fila, int columna) {
	for (int i = 0; i < 4; i++) {
		mover_cursor(columna, fila + i);
		cout << "    ";
	}
}


bool puede_moverse_a(int fila, int columna) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int f = fila + i;
			int c = columna + j;
			if (f < 0 || f >= FILAS_MAPA || c < 0 || c >= COLUMNAS_MAPA || mapa_1[f][c] != 0)
				return false;
		}
	}
	return true;
}

void dibujar_personaje(int fila, int columna) {
	for (int i = 0; i < 4; i++) {
		//SE MUEVE EL CURSOR PARA IMPRIMIR EL PERSONAJE DE ARRIBA HACIA ABAJO
		mover_cursor(columna, fila + i);
		Console::ForegroundColor = ConsoleColor::DarkYellow;
		cout << " " << personaje[i];
	}
}

void ejecutar_segundo_nivel() {
	configurar_ventana_mapa();
	dibujar_mapa(mapa_1);

	dibujar_personaje(personaje_fila, personaje_columna);

	char tecla;
	do {
		if (_kbhit()) {
			tecla = _getch();
			borrar_personaje(personaje_fila, personaje_columna);

			int nueva_fila = personaje_fila;
			int nueva_columna = personaje_columna;

			switch (tecla) {
			case 'w': nueva_fila--; break;
			case 's': nueva_fila++; break;
			case 'a': nueva_columna--; break;
			case 'd': nueva_columna++; break;
			}

			if (puede_moverse_a(nueva_fila, nueva_columna)) {
				personaje_fila = nueva_fila;
				personaje_columna = nueva_columna;
			}

			dibujar_personaje(personaje_fila, personaje_columna);
		}
	} while (tecla != 27);//escape


	Console::Clear();

	cin.get();
}