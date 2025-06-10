#pragma once

#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

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


/* VARIABLES GLOBALES*/
// ===== VARIABLES DE BALA ===== //
bool balaActiva = false;
int balaX, balaY;
int balaDireccion;
bool puedeDisparar = true;       // control de cooldown
clock_t ultimoDisparo = 0;      // tiempo del último disparo
const int cooldownDisparo = 500; // 500ms = 0.5s entre disparos
const int velocidadBala = 1;

const auto intervaloMovimientoBalaVertical = chrono::milliseconds(15); // PARA DISPAROS VERTICALES

const auto intervaloMovimientoBala = chrono::milliseconds(10); // PARA DISPAROS HORIZONTALES

/*======================================*/

/// === Variables personaje ===///
int inmortal = 0; //0=(No inmortal) 


//RELOJ ESTABLE (AHORA)
auto ultimoMovimientoBala = std::chrono::steady_clock::now();

/*======================================*/
/*PARA EL MENU*/
const int FILAS = 40;
const int COLUMNAS = 150;

/*======================================*/
/*MATRIZ MENU*/
int menu_matriz[FILAS][COLUMNAS] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},


//EL 2. DINAMICA
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,0,1,1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
/*======================================*/

void crash() {
	cout << "Test";
	throw(0);
}
/*======================================*/
//Establecer colores
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
/*======================================*/
//FUNCION MOVER CURSOR, PARA INDICAR DONDE IMPRIMIR
void mover_cursor(int columna, int fila) {
	//SET CURSOR POSITION (X - Y)
	Console::SetCursorPosition(columna, fila);
}
/*======================================*/
//ARREGLOS (Y - X)
//DIBUJA EL MAPA
void dibujar_mapa(int menu[FILAS][COLUMNAS]) {
	for (int fila = 0; fila < FILAS; fila++)
	{
		for (int columna = 0; columna < COLUMNAS; columna++)
		{
			//Se llama a la funcion mover cursor para indicar donde va a imprimir el siguiente cout
			mover_cursor(columna, fila);
			//CON EL CURSOR EN LA POSICION, SE ESTABLECE EL COLOR EN LA FILA X COLUMNA DE LA MATRIZ
			colores(menu[fila][columna]);
			//SE COLOCA EL BLOQUE CON EL COLOR SEGUN EL ASCCI
			cout << (char)219;
		}
	}
}
/*======================================*/
void seleccionar_opcion() {
	int tecla;
	//PARA QUE INGRESE EL NUMERO PARA SELECCIONAR UNA PARTE DEL MUNDO
	tecla = _getch();

	PlaySound(NULL, 0, 0); // Detener música del menú
}

/*======================================*/
//Funcion pintar + cursor + cout
void Pintar(int x, int y, string caracter, ConsoleColor fondo, ConsoleColor ColorCaracteres) {
	try {

		Console::BackgroundColor = fondo;
		Console::ForegroundColor = ColorCaracteres;


		Console::SetCursorPosition(x, y);

		cout << caracter;
	}
	catch (...) {
		//Sexoooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
	}
}

/*======================================*/
//Funcion borrar animacion
void BorrarAnimacion(int x, int y, int columna, int fila) {
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {
			Pintar(x + j, y + i, " ", ConsoleColor::Blue, ConsoleColor::Blue);
		}
	}
}

/*======================================*/
/* FUNCION DISPARAR */
void Disparar(int personajeX, int personajeY, int direccionHorizontal, int direccionVertical) {
	clock_t ahora = clock();

	if (puedeDisparar && (ahora - ultimoDisparo) * 1000 / CLOCKS_PER_SEC >= cooldownDisparo) {
		balaActiva = true;


		// Posición inicial basada en la dirección del personaje
		if (direccionVertical == 1) { // Izquierda
			balaX = personajeX + 4;  // Centrar el disparo respecto al personaje
			balaY = personajeY - 1;  // Posición inicial (encima del personaje)
			balaDireccion = 3;       // 3 = dirección hacia arriba (nuevo código)
		}
		else { // Derecha
			balaDireccion = direccionHorizontal; // 1 = izquierda, 2 = derecha
			if (direccionHorizontal == 1) { // Izquierda
				balaX = personajeX - 3;
			}
			else { // Derecha
				balaX = personajeX + 9;
			}
			balaY = personajeY + 4; // Altura del arma (para disparo horizontal)
		}

		ultimoDisparo = ahora;
		puedeDisparar = false;
	}
}

void Cursor(int x, int y) {
	Console::SetCursorPosition(x, y);

}
/*======================================*/

/*ACTUALIAZR BALA*/
void ActualizarBala() {
	auto ahora = std::chrono::steady_clock::now();

	if (!balaActiva) return;


	// Usar intervalo diferente para disparos verticales
	auto intervalo = (balaDireccion == 3) ? intervaloMovimientoBalaVertical : intervaloMovimientoBala;

	// Solo mover la bala si ha pasado el tiempo suficiente
	if (ahora - ultimoMovimientoBala >= intervalo) {
		// 1. Borrar la bala
		Pintar(balaX, balaY, "  ", ConsoleColor::Blue, ConsoleColor::Blue);

		// 2. Mover la bala
		if (balaDireccion == 1) {
			balaX -= velocidadBala;
		}// Izquierda
		else if (balaDireccion == 2) { // Derecha
			balaX += velocidadBala;
		}
		else if (balaDireccion == 3) { // Arriba (nuevo caso)
			balaY -= velocidadBala;
		}

		// 3. Verificar límites
		if (balaX < 2 || balaX > 148 || balaY < 6) {
			balaActiva = false;
			return;
		}

		// 4. Dibujar la bala
		string simboloBala;
		if (balaDireccion == 1) simboloBala = "<=";      // Izquierda
		else if (balaDireccion == 2) simboloBala = "=>"; // Derecha
		else if (balaDireccion == 3) simboloBala = "^^"; // Arriba (nuevo)

		Pintar(balaX, balaY, simboloBala, ConsoleColor::Black, ConsoleColor::Yellow);

		ultimoMovimientoBala = ahora; // Reiniciar el temporizador

		return;
	}
}

/*======================================*/

void Corazones(int CoorX, int CoorY) {
	if (inmortal <= 1) {
		Console::BackgroundColor = ConsoleColor::DarkRed;
	}
	else {
		Console::BackgroundColor = ConsoleColor::Yellow;
	}

	Cursor(CoorX, CoorY); cout << "  ";
	Cursor(CoorX + 3, CoorY); cout << "  ";

	Cursor(CoorX, CoorY + 1); cout << "     ";

	Cursor(CoorX + 1, CoorY + 2); cout << "   ";
	Cursor(CoorX + 2, CoorY + 3); cout << " ";

}

/*======================================*/
//Funcion para el piso del mapa
void Piso(int columnas) {
	Console::BackgroundColor = ConsoleColor::Green;
	for (int i = 0; i < columnas; i++) {
		Console::SetCursorPosition(i, 35);
		cout << " ";
	}
	for (int i = 0; i < columnas; i++) {
		Console::SetCursorPosition(i, 36);
		cout << " ";
	}
	for (int i = 0; i < columnas; i++) {
		Console::SetCursorPosition(i, 37);
		cout << " ";
	}
	for (int i = 0; i < columnas; i++) {
		Console::SetCursorPosition(i, 38);
		cout << " ";
	}
	for (int i = 0; i < columnas; i++) {
		Console::SetCursorPosition(i, 39);
		cout << " ";
	}

}

//Funcion que define los arbustos
void Vegetacion(int animacion, int x, int y) {
	//Definiendo colores de la planta
	Console::ForegroundColor = ConsoleColor::DarkRed;
	Console::BackgroundColor = ConsoleColor::DarkGreen;


	//Animacion 1 (Neutro)
	if (animacion == 1) {
		Cursor(x, y); cout << "  ";
		Cursor(x + 3, y); cout << "* ";
		Cursor(x + 6, y); cout << "* ";
		Cursor(x + 6, y); cout << "* ";
		Cursor(x + 12, y); cout << "  ";

		Cursor(x, y + 1); cout << "* ";
		Cursor(x + 3, y + 1); cout << " *";
		Cursor(x + 6, y + 1); cout << " *";
		Cursor(x + 9, y + 1); cout << " *";
		Cursor(x + 12, y + 1); cout << " *";

		Cursor(x, y + 2); cout << "    *  *  *   ";
		Cursor(x, y + 3); cout << " *  *  *  *  *";
	}
	//Animacion 2 (derecha)
	if (animacion == 2) {
		Cursor(x + 1, y); cout << "  ";
		Cursor(x + 4, y); cout << "* ";
		Cursor(x + 7, y); cout << "* ";
		Cursor(x + 10, y); cout << "* ";
		Cursor(x + 13, y); cout << "  ";

		Cursor(x, y + 1); cout << "* ";
		Cursor(x + 3, y + 1); cout << " *";
		Cursor(x + 6, y + 1); cout << " *";
		Cursor(x + 9, y + 1); cout << " *";
		Cursor(x + 12, y + 1); cout << " *";

		Cursor(x, y + 2); cout << "    *  *  *   ";
		Cursor(x, y + 3); cout << " *  *  *  *  *";

	}
	//Animacion 3(derecha)
	if (animacion == 3) {
		Cursor(x + 4, y); cout << "  ";
		Cursor(x + 7, y); cout << "* ";
		Cursor(x + 6, y); cout << "* ";
		Cursor(x + 13, y); cout << "* ";
		Cursor(x + 16, y); cout << "  ";

		Cursor(x + 2, y + 1); cout << "* ";
		Cursor(x + 5, y + 1); cout << " *";
		Cursor(x + 8, y + 1); cout << " *";
		Cursor(x + 11, y + 1); cout << " *";
		Cursor(x + 14, y + 1); cout << " *";

		Cursor(x, y + 2); cout << "    *  *  *   ";
		Cursor(x, y + 3); cout << " *  *  *  *  *";


	}
	//Animacion 4 (Derecha)
	if (animacion == 4) {
		Cursor(x + 1, y); cout << "  ";
		Cursor(x + 4, y); cout << "* ";
		Cursor(x + 7, y); cout << "* ";
		Cursor(x + 10, y); cout << "* ";
		Cursor(x + 13, y); cout << "  ";

		Cursor(x, y + 1); cout << "* ";
		Cursor(x + 3, y + 1); cout << " *";
		Cursor(x + 6, y + 1); cout << " *";
		Cursor(x + 9, y + 1); cout << " *";
		Cursor(x + 12, y + 1); cout << " *";

		Cursor(x, y + 2); cout << "    *  *  *   ";
		Cursor(x, y + 3); cout << " *  *  *  *  *";

	}
	//Animacion 5 (neutro)
	if (animacion == 5) {
		Cursor(x, y); cout << "  ";
		Cursor(x + 3, y); cout << "* ";
		Cursor(x + 6, y); cout << "* ";
		Cursor(x + 6, y); cout << "* ";
		Cursor(x + 12, y); cout << "  ";

		Cursor(x, y + 1); cout << "* ";
		Cursor(x + 3, y + 1); cout << " *";
		Cursor(x + 6, y + 1); cout << " *";
		Cursor(x + 9, y + 1); cout << " *";
		Cursor(x + 12, y + 1); cout << " *";

		Cursor(x, y + 2); cout << "    *  *  *   ";
		Cursor(x, y + 3); cout << " *  *  *  *  *";
	}
	//Animacion 6 (izquierda)
	if (animacion == 6) {
		Cursor((x + 1) - 2, y); cout << "  ";
		Cursor((x + 4) - 2, y); cout << "* ";
		Cursor((x + 7) - 2, y); cout << "* ";
		Cursor((x + 10) - 2, y); cout << "* ";
		Cursor((x + 13) - 2, y); cout << "  ";

		Cursor(x, y + 1); cout << "* ";
		Cursor(x + 3, y + 1); cout << " *";
		Cursor(x + 6, y + 1); cout << " *";
		Cursor(x + 9, y + 1); cout << " *";
		Cursor(x + 12, y + 1); cout << " *";

		Cursor(x, y + 2); cout << "    *  *  *   ";
		Cursor(x, y + 3); cout << " *  *  *  *  *";

	}
	//Animacion 7 (izquierda)

	if (animacion == 7) {
		Cursor((x + 1) - 3, y); cout << "  ";
		Cursor((x + 4) - 3, y); cout << "* ";
		Cursor((x + 7) - 3, y); cout << "* ";
		Cursor((x + 10) - 3, y); cout << "* ";
		Cursor((x + 13) - 3, y); cout << "  ";

		Cursor(x - 1, y + 1); cout << "* ";
		Cursor((x + 3) - 1, y + 1); cout << " *";
		Cursor((x + 6) - 1, y + 1); cout << " *";
		Cursor((x + 9) - 1, y + 1); cout << " *";
		Cursor((x + 12) - 1, y + 1); cout << " *";

		Cursor(x, y + 2); cout << "    *  *  *   ";
		Cursor(x, y + 3); cout << " *  *  *  *  *";


	}
	//Animacion 8 (izquierda)

	if (animacion == 8) {
		Cursor((x + 1) - 2, y); cout << "  ";
		Cursor((x + 4) - 2, y); cout << "* ";
		Cursor((x + 7) - 2, y); cout << "* ";
		Cursor((x + 10) - 2, y); cout << "* ";
		Cursor((x + 13) - 2, y); cout << "  ";

		Cursor(x, y + 1); cout << "* ";
		Cursor(x + 3, y + 1); cout << " *";
		Cursor(x + 6, y + 1); cout << " *";
		Cursor(x + 9, y + 1); cout << " *";
		Cursor(x + 12, y + 1); cout << " *";

		Cursor(x, y + 2); cout << "    *  *  *   ";
		Cursor(x, y + 3); cout << " *  *  *  *  *";

	}
}

/* Funciones Extras   */

//Ventana del juego
void Window() {
	Console::CursorVisible = false;
	Console::SetWindowSize(1, 1);
	Console::SetBufferSize(150, 40);
	Console::SetWindowSize(150, 40);
	Console::Clear();
}
#endif