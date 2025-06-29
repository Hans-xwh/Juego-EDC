#include "pch.h"
#include "MisFunciones.h"
#include "segundo_nivel.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <vector>
#include <chrono>
#include <locale>
#include <mmsystem.h>
//PARA COLOCAR UN BACKGROUND AL MENU SIMPLE
#include <stdlib.h>

//PARA EJECUTAR EL AUDIO
#pragma comment(lib, "winmm.lib") 
//Documentacion .NET ("https://learn.microsoft.com/en-us/dotnet/api/system.console?view=net-9.0")

using namespace System;
using namespace std;
using Clock = chrono::steady_clock;

/*  Protipo de funciones */
void Window();
void Piso(int columnas);
void Vegetacion(int animacion, int x, int y);
void Pintar(int x, int y, string caracter, ConsoleColor fondo, ConsoleColor ColorCaracteres);
void BorrarAnimacion(int x, int y, int columna, int fila);
void Cursor(int x, int y);
void Corazones(int CoorX, int CoorY);
/*=======================*/

/* Teclas */
enum Teclas { DERECHA = 77, IZQUIERDA = 75, ARRIBA = 72 };
/*----------*/


// ============================ //
/* Personaje Principal */
struct Personaje {
private:
	int x;
	int y;
	//nuevo
	int vida;
public:
	Personaje(int _x, int _y) : x(_x), y(_y) {
		vida = 3; //nuevo
	}
	void setCursor(int CursorX, int CursorY) {
		x = CursorX;
		y = CursorY;
		Console::SetCursorPosition(x, y);
	}
	void Dibujar(int posicion, int frame) {
		ConsoleColor ColorRojo = ConsoleColor::DarkRed;
		ConsoleColor ColorNegro = ConsoleColor::Black;
		ConsoleColor ColorGrisOscuro = ConsoleColor::DarkGray;
		ConsoleColor ColorBlanco = ConsoleColor::White;
		ConsoleColor ColorAzul = ConsoleColor::Blue;
		ConsoleColor ColorGris = ConsoleColor::Gray;
		ConsoleColor ColorAzulOscuro = ConsoleColor::DarkBlue;
		/* Direccion a la izquierda  */
		if (posicion == 1) {
			if (frame == 1) {
				// Sombrero 
				Pintar(x + 1, y, " /^^^^\\ ", ColorNegro, ColorRojo);

				// Cabeza y cara
				Pintar(x + 2, y + 1, "| o o |", ColorGrisOscuro, ColorNegro);
				Pintar(x + 2, y + 2, "|  ^  |", ColorGrisOscuro, ColorNegro);

				// Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |", ColorNegro, ColorBlanco);
				Pintar(x + 1, y + 4, "--", ColorNegro, ColorAzul);
				Pintar(x + 2, y + 4, "|   |", ColorNegro, ColorAzul);
				Pintar(x + 7, y + 4, "--", ColorNegro, ColorAzul);

				// Arma
				Pintar(x - 1, y + 4, "==>", ColorNegro, ColorGris);

				// Piernas
				Pintar(x + 2, y + 5, "/   \\", ColorNegro, ColorAzul);

				// Pies
				Pintar(x + 2, y + 6, "_", ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6, "_", ColorNegro, ColorAzulOscuro);

			}

			if (frame == 2) {
				//Sombrero
				Pintar(x + 1, y, " /^^^^\\ ", ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o o |", ColorGrisOscuro, ColorNegro);
				Pintar(x + 2, y + 2, "|  -  |", ColorGrisOscuro, ColorNegro);

				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |", ColorNegro, ColorBlanco);

				Pintar(x, y + 4, "-", ColorNegro, ColorAzul);
				Pintar(x + 2, y + 4, "|   |", ColorNegro, ColorAzul);
				Pintar(x + 7, y + 4, " -", ColorNegro, ColorAzul);
				//Arma
				Pintar(x - 1, y + 4, "==>", ColorNegro, ColorGris);
				//Piernas
				Pintar(x + 2, y + 5, "/    ", ColorNegro, ColorAzul);
				Pintar(x + 5, y + 5, " \\", ColorNegro, ColorAzul);
				//pies
				Pintar(x + 2, y + 6, "_", ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6, "_", ColorNegro, ColorAzulOscuro);


			}

			if (frame == 3) {
				//Sombrero
				Pintar(x + 1, y, " /^^^^\\ ", ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o_o |", ColorGrisOscuro, ColorNegro);
				Pintar(x + 2, y + 2, "|  o  |", ColorGrisOscuro, ColorNegro);

				Pintar(x + 2, y + 3, "| [_] |", ColorNegro, ColorBlanco);
				//Brazos y cuerpo
				Pintar(x - 1, y + 4, "-", ColorNegro, ColorAzul);
				Pintar(x + 2, y + 4, "|   |", ColorNegro, ColorAzul);
				Pintar(x + 6, y + 4, "--", ColorNegro, ColorAzul);
				//Arma
				Pintar(x, y + 4, "==>", ColorNegro, ColorGris);
				//Piernas
				Pintar(x + 2, y + 5, "    \\", ColorNegro, ColorAzul);
				Pintar(x + 2, y + 5, "/", ColorNegro, ColorAzul);
				//Pies 
				Pintar(x + 2, y + 6, "_", ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6, "_", ColorNegro, ColorAzulOscuro);


			}

			if (frame == 4) {
				//Sombrero
				Pintar(x + 1, y, " /^^^^\\ ", ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| > < |", ColorGrisOscuro, ColorNegro);
				Pintar(x + 2, y + 2, "| [!] |", ColorGrisOscuro, ColorNegro);
				//Cuerpo
				Pintar(x + 2, y + 3, "| [_] |", ColorNegro, ColorBlanco);
				//Arma y brazos
				Pintar(x - 1, y + 4, "==>", ColorNegro, ColorGris);
				Pintar(x, y + 4, "-", ColorNegro, ColorAzul);
				Pintar(x + 2, y + 4, "|   |", ColorNegro, ColorAzul);
				Pintar(x + 7, y + 4, "--", ColorNegro, ColorAzul);

				//Piernas
				Pintar(x + 2, y + 5, "/ _ \\", ColorNegro, ColorAzul);
				//pies
				Pintar(x + 2, y + 6, "_", ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6, "_", ColorNegro, ColorAzulOscuro);
			}

		}
		/* Direccion a la derecha */
		if (posicion == 2) {
			if (frame == 1) {
				// Sombrero 
				Pintar(x + 1, y, " /^^^^\\ ", ColorNegro, ColorRojo);

				// Cabeza
				Pintar(x + 2, y + 1, "| o o |", ColorGrisOscuro, ColorNegro);
				Pintar(x + 2, y + 2, "|  ^  |", ColorGrisOscuro, ColorNegro);

				// Cuerpo
				Pintar(x + 2, y + 3, "| [_] |", ColorNegro, ColorBlanco);

				// Brazos y torzo
				Pintar(x + 6, y + 4, "--", ColorNegro, ColorAzul);
				Pintar(x + 2, y + 4, "|   |", ColorNegro, ColorAzul);
				Pintar(x, y + 4, "--", ColorNegro, ColorAzul);

				// Arma 
				Pintar(x + 8, y + 4, "<==", ColorNegro, ColorGris);

				// Piernas
				Pintar(x + 2, y + 5, "/   \\", ColorNegro, ColorAzul);

				// Pies
				Pintar(x + 2, y + 6, "_", ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6, "_", ColorNegro, ColorAzulOscuro);
			}

			if (frame == 2) {
				//Sombrero
				Pintar(x + 1, y, " /^^^^\\ ", ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o o |", ColorGrisOscuro, ColorNegro);
				Pintar(x + 2, y + 2, "|  -  |", ColorGrisOscuro, ColorNegro);
				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |", ColorNegro, ColorBlanco);

				Pintar(x + 7, y + 4, "--", ColorNegro, ColorAzul);
				Pintar(x + 2, y + 4, "|   |", ColorNegro, ColorAzul);
				Pintar(x, y + 4, " -", ColorNegro, ColorAzul);
				//Arma
				Pintar(x + 7, y + 4, "<==", ColorNegro, ColorGris);
				//pierna
				Pintar(x + 2, y + 5, "/", ColorNegro, ColorAzul);
				Pintar(x + 5, y + 5, " \\", ColorNegro, ColorAzul);

				//pies
				Pintar(x + 2, y + 6, "_", ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6, "_", ColorNegro, ColorAzulOscuro);
			}

			if (frame == 3) {
				//Sombrero
				Pintar(x + 1, y, " /^^^^\\ ", ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o_o |", ColorGrisOscuro, ColorNegro);
				Pintar(x + 2, y + 2, "|  o  |", ColorGrisOscuro, ColorNegro);
				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |", ColorNegro, ColorBlanco);

				Pintar(x + 8, y + 4, "-", ColorNegro, ColorAzul);
				Pintar(x + 2, y + 4, "|   |", ColorNegro, ColorAzul);
				Pintar(x, y + 4, "--", ColorNegro, ColorAzul);
				//arma
				Pintar(x + 7, y + 4, "<==", ColorNegro, ColorGris);
				//piernas
				Pintar(x + 2, y + 5, "/    ", ColorNegro, ColorAzul);
				Pintar(x + 5, y + 5, " \\", ColorNegro, ColorAzul);
				//pies
				Pintar(x + 2, y + 6, "_", ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6, "_", ColorNegro, ColorAzulOscuro);
			}

			if (frame == 4) {
				//Sombrero
				Pintar(x + 1, y, " /^^^^\\ ", ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| < > |", ColorGrisOscuro, ColorNegro);
				Pintar(x + 2, y + 2, "| [!] |", ColorGrisOscuro, ColorNegro);
				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |", ColorNegro, ColorBlanco);

				Pintar(x + 6, y + 4, "--", ColorNegro, ColorAzul);
				Pintar(x + 2, y + 4, "|   |", ColorNegro, ColorAzul);
				Pintar(x, y + 4, "--", ColorNegro, ColorAzul);
				//ARma
				Pintar(x + 8, y + 4, "<==", ColorNegro, ColorGris);
				//PIErnas
				Pintar(x + 2, y + 5, "/ _ \\", ColorNegro, ColorAzul);
				//pies
				Pintar(x + 2, y + 6, "_", ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6, "_", ColorNegro, ColorAzulOscuro);
			}


		}
		if (posicion == 3) {
			if (frame == 1) {
				//Sombrero
				Pintar(x + 1, y + 0, "  /^\\  ", ColorNegro, ColorRojo);

				// Cabeza y cara
				Pintar(x + 2, y + 1, " (o o) ", ColorGrisOscuro, ColorNegro);
				Pintar(x + 2, y + 2, "  \\_/  ", ColorGrisOscuro, ColorNegro);

				// ARma
				Pintar(x + 4, y - 1, " ^ ", ColorNegro, ColorGris);
				Pintar(x + 4, y + 0, " ||", ColorNegro, ColorGris);

				// Cuerpo y brazos
				Pintar(x + 1, y + 3, "/", ColorNegro, ColorAzul);
				Pintar(x + 6, y + 3, "\\", ColorNegro, ColorAzul);

				Pintar(x + 2, y + 3, "|[_]|", ColorNegro, ColorBlanco);

				// Piernas 
				Pintar(x + 2, y + 5, "/   \\", ColorNegro, ColorAzul);

				//Pies
				Pintar(x + 2, y + 6, "_", ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6, "_", ColorNegro, ColorAzulOscuro);
			}
		}
	}

	void Borrar(int AntiguoX, int AntiguoY) {
		BorrarAnimacion(AntiguoX - 1, AntiguoY - 1, 12, 8);
	}
	//Nuevo 
	void DibujarVida() {
		int CoorX = 143; int CoorY = 1;
		if (vida == 3) {
			Corazones(CoorX, CoorY);
			Corazones(CoorX - 6, CoorY);
			Corazones(CoorX - 12, CoorY);
		}
		if (vida == 2) {
			Corazones(CoorX, CoorY);
			Corazones(CoorX - 6, CoorY);
		}
		if (vida == 1) {
			Corazones(CoorX, CoorY);
		}
		if (vida == 0) {
			Borrar(x, y);
		}
	}
	void BorrarCorazones(int x, int y) {
		BorrarAnimacion(x, y, 20, 4);
	}
	void setVida(int nuevaVida) {
		vida = nuevaVida;
	}
	//
};
/*=================================================================*/
/* Clase Enemigos*/
struct Enemigos {
private:
	int x;
	int y;
public:
	Enemigos() : x(6), y(29) {}
	Enemigos(int _x, int _y) : x(_x), y(_y) {}
	void setCursor(int nuevo_x, int nuevo_y) {
		x = nuevo_x;
		y = nuevo_y;
	}
	void DibujarEnemigo() {
		Console::BackgroundColor = ConsoleColor::Black;


		//Cabeza

		Cursor(x + 2, y); cout << "   ";
		Console::ForegroundColor = ConsoleColor::DarkRed;
		Cursor(x + 1, y + 1); cout << " \\ / ";
		//Ojos
		Cursor(x, y + 2); cout << "       ";
		Pintar(x + 2, y + 2, " ", ConsoleColor::DarkRed, ConsoleColor::DarkRed);
		Pintar(x + 4, y + 2, " ", ConsoleColor::DarkRed, ConsoleColor::DarkRed);
		Console::BackgroundColor = ConsoleColor::Black;
		//Cuerpo
		Cursor(x, y + 3); cout << "       ";

		//Brazos:
		Cursor(x + 1, y + 4); cout << " ";
		Cursor(x + 3, y + 4); cout << " ";
		Cursor(x + 5, y + 4); cout << " ";
		Cursor(x + 1, y + 5); cout << " ";
		Cursor(x + 3, y + 5); cout << " ";
		Cursor(x + 5, y + 5); cout << " ";


	}
	void BorrarEnemigo(int AntiguoX, int AntiguoY) {
		BorrarAnimacion(AntiguoX, AntiguoY, 10, 6);
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};


/*=================================================================*/


/* Clase  Nubes*/
struct Nubes {
private:
	int x;
	int y;
public:
	Nubes(int _x, int _y) : x(_x), y(_y) {}

	void setCursor(int nuevoX, int nuevoY) {
		x = nuevoX;
		y = nuevoY;
	}
	void DibujarNube(int animacion, string listaPreguntas[4]) {
		ConsoleColor ColorGris = ConsoleColor::Gray;
		ConsoleColor ColorNegro = ConsoleColor::Black;
		ConsoleColor ColorAzul = ConsoleColor::Blue;
		ConsoleColor ColorAzulOscuro = ConsoleColor::DarkBlue;
		Console::BackgroundColor = ConsoleColor::Gray;
		Console::ForegroundColor = ConsoleColor::Black;
		if (animacion == 1) {
			Cursor(x, y);         cout << "   ";
			Cursor(x - 1, y + 1); cout << "     ";
			Cursor(x - 2, y + 2); cout << listaPreguntas[0];
			Cursor(x - 3, y + 3); cout << "           ";


		}
		if (animacion == 2) {
			Cursor(x - 1, y);	  cout << "      ";
			Cursor(x - 2, y + 1); cout << "       ";
			Cursor(x - 3, y + 2); cout << listaPreguntas[1];
			Cursor(x - 4, y + 3); cout << "           ";
		}
		if (animacion == 3) {
			Cursor(x - 1, y + 1); cout << "      ";
			Cursor(x - 2, y + 2); cout << "        ";
			Cursor(x - 3, y + 3); cout << listaPreguntas[2];
			Cursor(x - 4, y + 4); cout << "           ";
		}
		if (animacion == 4) {
			Cursor(x, y); cout << "   ";
			Cursor(x - 1, y + 1); cout << "     ";
			Cursor(x - 2, y + 2); cout << listaPreguntas[3];
			Cursor(x - 3, y + 3); cout << "           ";

			// Lluvia
			Pintar(x - 2, y + 4, "  |   |  ", ColorAzul, ColorAzulOscuro);
			Pintar(x - 1, y + 5, " |  | | ", ColorAzul, ColorAzulOscuro);
		}
	}
	void BorrarNube(int AntiguoX, int AntiguoY) {
		BorrarAnimacion(AntiguoX - 4, AntiguoY, 17, 6);
	}
};


/*=================================================================*/


/* Preguntas */
struct Preguntas {
	void Pregunta1() {
		Console::BackgroundColor = ConsoleColor::Blue;
		Console::ForegroundColor = ConsoleColor::Black;
		Cursor(5, 0); cout << "                                                                                                _____ ";
		Cursor(5, 1); cout << " _____         _               _                    _ _       _      _     _    _____          |___  |";
		Cursor(5, 2); cout << "|     |_ _ ___| |   ___ ___   | |___    ___ ___ ___|_| |_ ___| |   _| |___| |  |  _  |___ ___ _ _|  _|";
		Cursor(5, 3); cout << "|   --| | | .'| |  | -_|_ -|  | | .'|  |  _| .'| . | |  _| .'| |  | . | -_| |  |   __| -_|  _| | |_|  ";
		Cursor(5, 4); cout << "|_____|___|__,|_|  |___|___|  |_|__,|  |___|__,|  _|_|_| |__,|_|  |___|___|_|  |__|  |___|_| |___|_|  ";
		Cursor(5, 5); cout << "                                               |_|                                                    ";

	}
	void Pregunta2() {
		Console::BackgroundColor = ConsoleColor::Blue;
		Console::ForegroundColor = ConsoleColor::Black;
		Cursor(5, 0); cout << "                                                                                                                    _____ ";
		Cursor(5, 1); cout << " _____     _            ___                _    _ _ _           _         _              _     _    _____          |___  |";
		Cursor(5, 2); cout << "|     |_ _|_|___ ___   |  _|_ _ ___    ___| |  | |_| |_ ___ ___| |_ ___ _| |___ ___    _| |___| |  |  _  |___ ___ _ _|  _|";
		Cursor(5, 3); cout << "|  |  | | | | -_|   |  |  _| | | -_|  | -_| |  | | | . | -_|  _|  _| .'| . | . |  _|  | . | -_| |  |   __| -_|  _| | |_|  ";
		Cursor(5, 4); cout << "|__  _|___|_|___|_|_|  |_| |___|___|  |___|_|  |_|_|___|___|_| |_| |__,|___|___|_|    |___|___|_|  |__|  |___|_| |___|_|  ";
		Cursor(5, 5); cout << "   |__|                                                                                                                   ";
	}
	void Pregunta3() {
		Console::BackgroundColor = ConsoleColor::Blue;
		Console::ForegroundColor = ConsoleColor::Black;
		Cursor(5, 0); cout << "   _  ___              _                  ____        ___ ___ ";
		Cursor(5, 1); cout << "  (_)/ __|  _ __ _ _ _| |_ ___   ___ ___ |__  | /\\/\\ ( _ )__ \\";
		Cursor(5, 2); cout << " / /| (_| || / _` | | \\  _/ _ \\ / -_|_-<   / /  >  < / _ \\ /_/";
		Cursor(5, 3); cout << " \\___\\___\\_,_\\__,_|_||_\\__\\___/ \\___/__/  /_/   \\/\\/ \\___/(_) ";
	}
	void Pregunta4() {
		Console::BackgroundColor = ConsoleColor::Blue;
		Console::ForegroundColor = ConsoleColor::Black;
		Cursor(5, 0); cout << "                                                                                                                    _____ ";
		Cursor(5, 1); cout << " _____         _                   _        _                     _                      _     _    _____          |___  |";
		Cursor(5, 2); cout << "|     |_ _ ___| |   ___ ___    ___| |   ___|_|___    _____ ___   | |___ ___ ___ ___    _| |___| |  |  _  |___ ___ _ _|  _|";
		Cursor(5, 3); cout << "|   --| | | .'| |  | -_|_ -|  | -_| |  |  _| | . |  |     |_ -|  | | .'|  _| . | . |  | . | -_| |  |   __| -_|  _| | |_|  ";
		Cursor(5, 4); cout << "|_____|___|__,|_|  |___|___|  |___|_|  |_| |_|___|  |_|_|_|___|  |_|__,|_| |_  |___|  |___|___|_|  |__|  |___|_| |___|_|  ";
		Cursor(5, 5); cout << "                                                                           |___|                                          ";

	}
	void Pregunta5() {
		Console::BackgroundColor = ConsoleColor::Blue;
		Console::ForegroundColor = ConsoleColor::Black;
		Cursor(5, 0); cout << "  _  ___                                  _                                          _         _   _        ___ ";
		Cursor(5, 1); cout << " (_)/ __|___ _ __  _ __  ___ _ _  ___ _ _| |_ ___   _ _  ___   __ ___ _ __ _  _ _ _ (_)__ __ _| |_(_)_ ____|__ \\";
		Cursor(5, 2); cout << "/ /| (__/ _ \\ '  \\| '_ \\/ _ \\ ' \\/ -_) ' \\  _/ -_) | ' \\/ _ \\ / _/ _ \\ '  \\ || | ' \\| / _/ _` |  _| \\ V / _ \\/_/";
		Cursor(5, 3); cout << "\\___\\___\\___/_|_|_| .__/\\___/_||_\\___|_||_\\__\\___| |_||_\\___/ \\__\\___/_|_|_\\_,_|_||_|_\\__\\__,_|\\__|_|\\_/\\___(_) ";
		Cursor(5, 4); cout << "                  |_|                                                                                           ";


	}
	void Pregunta6() {
		Console::BackgroundColor = ConsoleColor::Blue;
		Console::ForegroundColor = ConsoleColor::Black;
		Cursor(5, 0); cout << "  _    _   /\\/|       _         _                       _             _        ___           _____ ";
		Cursor(5, 1); cout << " (_)  /_\\ |/\\/  ___  (_)_ _  __| |___ _ __  ___ _ _  __| |___ _ _  __(_)__ _  | _ \\___ _ _ _/_/__ \\";
		Cursor(5, 2); cout << "/ /_ / _ \\| ' \\/ _ \\ | | ' \\/ _` / -_) '_ \\/ -_) ' \\/ _` / -_) ' \\/ _| / _` | |  _/ -_) '_| || |/_/";
		Cursor(5, 3); cout << "\\___/_/ \\_\\_||_\\___/ |_|_||_\\__,_\\___| .__/\\___|_||_\\__,_\\___|_||_\\__|_\\__,_| |_| \\___|_|  \\_,_(_) ";
		Cursor(5, 4); cout << "                                     |_|                                                           ";

	}

	void DibujarPregunta(int pregunta) {

		switch (pregunta) {
		case 1:
			Pregunta1();
			break;
		case 2:
			Pregunta2();
			break;
		case 3:
			Pregunta3();
			break;
		case 4:
			Pregunta4();
			break;
		case 5:
			Pregunta5();
			break;
		case 6:
			Pregunta6();
			break;

		default:
			break;
		}

	}
	void BorrarPregunta(int x, int y) {
		BorrarAnimacion(x, y, 123, 6);
	}
};
/*=======================================================*/

/*      Funcion Principal Main    */
int main() {
	//setlocale(LC_ALL, "Spanish");
	Window();
	PlaySound(TEXT("horizon.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	//SE LLAMA A LA FUNCION SELECCIONAR LA OPCION
	seleccionar_opcion();

	//SE CONFIGURA QUE EL FONDO ESE AZUL DESPUES DE PRESIONAR LA TECLA 1
	Console::BackgroundColor = ConsoleColor::Blue;
	Console::Clear();  // Limpia la consola
	PlaySound(TEXT("musica.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	Piso(150);
	

	//Personaje
	int x = 90; int y = 28;
	Personaje Marco(x, y);
	Marco.DibujarVida();  //nuevo
	bool EstarVivo = true;
	int vida = 3;

	/* Preguntas */
	Preguntas pregunta;
	int NumeroPregunta = 1;
	pregunta.DibujarPregunta(NumeroPregunta);

	//Alternativas
	string AlternativasPregunta1[4] = { "Arequipa", "  Cusco  ", "Trujillo  ", "  Lima  " };
	string AlternativasPregunta2[4] = { "Tupac Amaru II", "Miguel Grau", "San Martin", "Simon Bolivar" };
	string AlternativasPregunta3[4] = { "    54   ", "    56   ", "    64   ", "    58   " };
	string AlternativasPregunta4[4] = { "Urubamba", "Ucayali", "Amazonas", "Mantaro" };
	string AlternativasPregunta5[4] = { "Emisor", "Receptor", "Mensaje","Ecuacion" };
	string AlternativasPregunta6[4] = { "   1821  ","   1810  ", "   1824  ", "   1830  " };
	//Respuestas

	/*======================*/
	//Pajaro

	Pajaro(135, 15, NumeroPregunta);

	/* Nubes */

	//Nube 1
	int direccionNube1 = 1;
	int FormaNube1 = 1;
	int Nube_X_1 = 110; int Nube_Y_1 = 6;
	int Respuesta1 = 3;
	Nubes nube1(Nube_X_1, Nube_Y_1);

	//Nube 2
	int direccionNube2 = 1;
	int FormaNube2 = 2;
	int Nube_X_2 = 30; int Nube_Y_2 = 10;
	int Respuesta2 = 2;
	Nubes nube2(Nube_X_2, Nube_Y_2);

	//nube 3
	int direccionNube3 = 1;
	int FormaNube3 = 4;
	int Nube_X_3 = 110; int Nube_Y_3 = 14;
	int Respuesta3 = 1;
	Nubes nube3(Nube_X_3, Nube_Y_3);

	//Nube 4
	int direccionNube4 = 1;
	int FormaNube4 = 3;
	int Nube_X_4 = 50; int Nube_Y_4 = 19;
	int Respuesta4 = 1;

	Nubes nube4(Nube_X_4, Nube_Y_4);


	//Dibujar Nubes
	nube1.DibujarNube(FormaNube1, AlternativasPregunta1);
	nube2.DibujarNube(FormaNube2, AlternativasPregunta1);
	nube3.DibujarNube(FormaNube3, AlternativasPregunta1);
	nube4.DibujarNube(FormaNube4, AlternativasPregunta1);

	/*==========================================*/

	//Controlar tiempo y animaciones 
	int frame = 1;
	int posicion = 1;
	int animacion = 1;
	auto UltimoMomentoNube = Clock::now();
	auto Intervalo = chrono::milliseconds(500);
	Marco.Dibujar(1, 1);

	/* Enemigos */
	auto UltimoMomentoEnemigo = Clock::now();
	auto UltimoMomentoEnemigoFuerte = Clock::now();

	auto IntervaloEnemigos = chrono::milliseconds(6000);
	auto IntervaloEnemigosFuertes = chrono::milliseconds(15000);
	Enemigos ListaEnemigosFuertes[1];
	Enemigos ListaEnemigos[2];
	int TamañoListaEnemigos = sizeof(ListaEnemigos) / sizeof(ListaEnemigos[0]);
	int TamañoListaEnemigosFuertes = sizeof(ListaEnemigosFuertes) / sizeof(ListaEnemigosFuertes[0]);
	bool enemigosCreados = false;
	bool enemigosFuertesCreados = false;
	int IndiceEnemigos = 0; int IndiceEnemigosFuertes = 0;
	int nuevoXEnemigo = 0;
	/*========================================*/

	while (true) {
		bool BalaNube = false;
		bool CambioPregunta = false;
		bool moverse = false;
		bool VerificarDaño = false;
		//Coordenadas Nubes
		int AntiguoXNube1 = Nube_X_1; int AntiguoYNube1 = Nube_Y_1;
		int AntiguoXNube2 = Nube_X_2; int AntiguoYNube2 = Nube_Y_2;
		int AntiguoXNube3 = Nube_X_3; int AntiguoYNube3 = Nube_Y_3;
		int AntiguoXNube4 = Nube_X_4; int AntiguoYNube4 = Nube_Y_4;

		//Coordenadas Personaje
		int AntiguoX = x; int AntiguoY = y;


		// Verificar cooldown del disparo
		if (!puedeDisparar) {
			clock_t ahora = clock();
			if (ahora - ultimoDisparo >= cooldownDisparo) {
				puedeDisparar = true;
			}
		}

		if (_kbhit()) {
			int Tecla = _getch();
			if (Tecla == 0 || Tecla == 224) {
				Tecla = _getch();
				if (Tecla == static_cast<int>(Teclas::DERECHA) && EstarVivo == true) {
					x++;
					posicion = 2;
					frame++;
					if (frame > 4) {
						frame = 1;
					}
					moverse = true;
				}
				if (Tecla == static_cast<int>(Teclas::IZQUIERDA) && EstarVivo == true) {
					x--;
					posicion = 1;
					frame++;
					if (frame > 4) {
						frame = 1;
					}
					moverse = true;
				}
				if (Tecla == static_cast<int>(Teclas::ARRIBA) && EstarVivo == true) {
					posicion = 3;
					frame = 1;
					Marco.Dibujar(posicion, frame);
					// Disparar hacia arriba (direcciónHorizontal = 0, direcciónVertical = 1)
					Disparar(x, y, 0, 1);
				}
				Marco.setCursor(x, y);
			}
			else if ((Tecla == 'f' || Tecla == 'F' || Tecla == 32) && puedeDisparar && EstarVivo == true)
			{
				// Disparo horizontal normal (F o Espacio)
				Disparar(x, y, posicion, 0); // direcciónVertical = 0 (sin disparo vertical)
				puedeDisparar = false; // Activa el cooldown
				ultimoDisparo = clock();
			}



			if (moverse == true) {
				Marco.Borrar(AntiguoX, AntiguoY);
				Marco.Dibujar(posicion, frame);
			}

		}
		/*ACTUALIZAR LAS BALAS */

		ActualizarBala();

		auto ahora = Clock::now();


		if (ahora - UltimoMomentoEnemigo >= IntervaloEnemigos && IndiceEnemigos < TamañoListaEnemigos) {
			int EnemigoX = 6; int EnemigoY = 29;
			ListaEnemigos[IndiceEnemigos] = Enemigos(EnemigoX, EnemigoY);
			ListaEnemigos[IndiceEnemigos].DibujarEnemigo();
			enemigosCreados = true;
			IndiceEnemigos++;
			UltimoMomentoEnemigo = ahora;
		}

		if (ahora - UltimoMomentoEnemigoFuerte >= IntervaloEnemigosFuertes && IndiceEnemigosFuertes < TamañoListaEnemigosFuertes) {
			int EnemigoX = 134; int EnemigoY = 29;
			ListaEnemigosFuertes[IndiceEnemigosFuertes] = Enemigos(EnemigoX, EnemigoY);
			ListaEnemigosFuertes[IndiceEnemigosFuertes].DibujarEnemigo();
			enemigosFuertesCreados = true;
			IndiceEnemigosFuertes++;
			UltimoMomentoEnemigoFuerte = ahora;
		}


		if (ahora - UltimoMomentoNube >= Intervalo) {
			/*    Nubes   */
			//nube 1
			Nube_X_1 -= 1 * direccionNube1;
			//Rebote de nubes
			if (Nube_X_1 >= 110 || Nube_X_1 <= 10) {
				direccionNube1 *= -1;
			}

			nube1.setCursor(Nube_X_1, Nube_Y_1);
			nube1.BorrarNube(AntiguoXNube1, AntiguoYNube1);
			if (NumeroPregunta == 1) {
				nube1.DibujarNube(FormaNube1, AlternativasPregunta1);
			}if (NumeroPregunta == 2) {
				nube1.DibujarNube(FormaNube1, AlternativasPregunta2);
			}if (NumeroPregunta == 3) {
				nube1.DibujarNube(FormaNube1, AlternativasPregunta3);
			}if (NumeroPregunta == 4) {
				nube1.DibujarNube(FormaNube1, AlternativasPregunta4);
			}if (NumeroPregunta == 5) {
				nube1.DibujarNube(FormaNube1, AlternativasPregunta5);
			}if (NumeroPregunta == 6) {
				nube1.DibujarNube(FormaNube1, AlternativasPregunta6);
			}

			//nube 2
			Nube_X_2 += 1 * direccionNube2;
			//Rebote de nubes

			if (Nube_X_2 >= 110 || Nube_X_2 <= 10) {
				direccionNube2 *= -1;
			}
			nube2.setCursor(Nube_X_2, Nube_Y_2);
			nube2.BorrarNube(AntiguoXNube2, AntiguoYNube2);
			if (NumeroPregunta == 1) {
				nube2.DibujarNube(FormaNube2, AlternativasPregunta1);
			}if (NumeroPregunta == 2) {
				nube2.DibujarNube(FormaNube2, AlternativasPregunta2);
			}if (NumeroPregunta == 3) {
				nube2.DibujarNube(FormaNube2, AlternativasPregunta3);
			}if (NumeroPregunta == 4) {
				nube2.DibujarNube(FormaNube2, AlternativasPregunta4);
			}if (NumeroPregunta == 5) {
				nube2.DibujarNube(FormaNube2, AlternativasPregunta5);
			}if (NumeroPregunta == 6) {
				nube2.DibujarNube(FormaNube2, AlternativasPregunta6);
			}


			//nube 3
			Nube_X_3 += 1 * direccionNube3;
			//Rebote de nubes

			if (Nube_X_3 >= 120 || Nube_X_3 <= 10) {
				direccionNube3 *= -1;
			}
			nube3.setCursor(Nube_X_3, Nube_Y_3);
			nube3.BorrarNube(AntiguoXNube3, AntiguoYNube3);
			if (NumeroPregunta == 1) {
				nube3.DibujarNube(FormaNube3, AlternativasPregunta1);
			}
			if (NumeroPregunta == 2) {
				nube3.DibujarNube(FormaNube3, AlternativasPregunta2);
			}if (NumeroPregunta == 3) {
				nube3.DibujarNube(FormaNube3, AlternativasPregunta3);
			}if (NumeroPregunta == 4) {
				nube3.DibujarNube(FormaNube3, AlternativasPregunta4);
			}if (NumeroPregunta == 5) {
				nube3.DibujarNube(FormaNube3, AlternativasPregunta5);
			}if (NumeroPregunta == 6) {
				nube3.DibujarNube(FormaNube3, AlternativasPregunta6);
			}

			//nube 4
			Nube_X_4 -= 1 * direccionNube4;
			//Rebote de nubes
			if (Nube_X_4 >= 110 || Nube_X_4 <= 10) {
				direccionNube4 *= -1;
			}
			nube4.setCursor(Nube_X_4, Nube_Y_4);
			nube4.BorrarNube(AntiguoXNube4, AntiguoYNube4);
			if (NumeroPregunta == 1) {
				nube4.DibujarNube(FormaNube4, AlternativasPregunta1);
			}if (NumeroPregunta == 2) {
				nube4.DibujarNube(FormaNube4, AlternativasPregunta2);
			}if (NumeroPregunta == 3) {
				nube4.DibujarNube(FormaNube4, AlternativasPregunta3);
			}if (NumeroPregunta == 4) {
				nube4.DibujarNube(FormaNube4, AlternativasPregunta4);
			}if (NumeroPregunta == 5) {
				nube4.DibujarNube(FormaNube4, AlternativasPregunta5);
			}if (NumeroPregunta == 6) {
				nube4.DibujarNube(FormaNube4, AlternativasPregunta6);
			}

			/*===================*/

			//plantas
			for (int Columna : {4, 130}) {
				BorrarAnimacion(Columna, 31, 15, 4);
				Vegetacion(animacion, Columna, 31);
			}

			animacion++;
			if (animacion >= 8) {
				animacion = 1;
			}


			/*  Movimiento enemigos */

			//Enemigo Normal
			if (enemigosCreados == true) {
				for (int i = 0; i < TamañoListaEnemigos; i++) {
					int AntiguoXEnemigo = ListaEnemigos[i].getX();
					int AntiguoYEnemigo = ListaEnemigos[i].getY();

					nuevoXEnemigo = AntiguoXEnemigo;
					int nuevoYEnemigo = AntiguoYEnemigo;
					if (nuevoXEnemigo <= x) {
						nuevoXEnemigo++;
					}
					if (nuevoXEnemigo >= x) {
						nuevoXEnemigo--;
					}
					ListaEnemigos[i].setCursor(nuevoXEnemigo, nuevoYEnemigo);
					ListaEnemigos[i].BorrarEnemigo(AntiguoXEnemigo, AntiguoYEnemigo);
					ListaEnemigos[i].DibujarEnemigo();
					/*
					if (nuevoXEnemigo+10 == x) {
						vida--;
						VerificarDaño = true;
					}
					*/

				}
			}
			//Enemigos fuertes
			if (enemigosFuertesCreados == true) {
				for (int i = 0; i < TamañoListaEnemigosFuertes; i++) {
					int AntiguoXEnemigo = ListaEnemigosFuertes[i].getX();
					int AntiguoYEnemigo = ListaEnemigosFuertes[i].getY();

					int NuevoXEnemigo = AntiguoXEnemigo;
					int NuevoYEnemigo = AntiguoYEnemigo;

					if (NuevoXEnemigo < x) {
						NuevoXEnemigo++;
					}
					if (NuevoXEnemigo > x) {
						NuevoXEnemigo--;
					}
					ListaEnemigosFuertes[i].setCursor(NuevoXEnemigo, NuevoYEnemigo);
					ListaEnemigosFuertes[i].BorrarEnemigo(AntiguoXEnemigo, AntiguoYEnemigo);
					ListaEnemigosFuertes[i].DibujarEnemigo();
					/*
					if (NuevoXEnemigo - 10 == x) {
						vida--;
						VerificarDaño = true;
					}
					*/
				}
			}
			if (inmortal > 0) { //Contador de inmortalidad.
				inmortal--;
				Marco.DibujarVida();
			}
			/*=========================*/
			//Restablecer intervalo
			UltimoMomentoNube = ahora;
		}
		//Sleep(10);

		/* Colisiones   */ 
		/*Console::SetCursorPosition(0, 0);
		cout << balaX;
		Console::SetCursorPosition(0, 1);
		cout << inmortal << endl;
		cout << "PlayerX: " << x << endl;
		cout << "NuevoEnemigoX: " << nuevoXEnemigo; */
		for (int i = 0; i < TamañoListaEnemigos; i++) {
			int enemigoX, enemigoY;
			enemigoX = ListaEnemigos[i].getX() + 6;
			enemigoY = ListaEnemigos[i].getY();

			if (balaX == ListaEnemigos[i].getX() + 6) {
				ListaEnemigos[i].BorrarEnemigo(ListaEnemigos[i].getX(), enemigoY);
			}
		}
		//Enemigos -> Jugador
		if (nuevoXEnemigo + 7 == x + 2 && inmortal == 0) {	//hay que ajustar esto
			vida--;
			VerificarDaño = true;
			inmortal = 7;	//Este numero ajusta el tiempo de inmortalidad
			//crash();
		}

		//MOSTRAR EL NUMERO DE PREGUNTAS CONTESTADAS
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(125, 7);
		int contador_respuestas = NumeroPregunta - 1;
		cout << "Preguntas Contestadas: " << contador_respuestas;


		//Colision Balas / Nubes
		if (NumeroPregunta == 1) {
			if (balaX >= Nube_X_3 - 5 && balaX <= Nube_X_3 + 5 &&
				balaY >= Nube_Y_3 && balaY <= Nube_Y_3 + 4) 
			{
				CambioPregunta = true;
				balaActiva = false;
				NumeroPregunta++;
				Pajaro(135, 15, NumeroPregunta);
			}
		}

		if (NumeroPregunta == 2) {
			if (balaX >= Nube_X_4 - 5 && balaX <= Nube_X_4 + 5 &&
				balaY >= Nube_Y_4 && balaY <= Nube_Y_4 + 4) {
				CambioPregunta = true;
				balaActiva = false;
				NumeroPregunta++;
				Pajaro(135, 15, NumeroPregunta);
			}
		}
		// Pregunta 3 (nube 2)
		if (NumeroPregunta == 3) {
			if (balaX >= Nube_X_2 - 5 && balaX <= Nube_X_2 + 5 &&
				balaY >= Nube_Y_2 && balaY <= Nube_Y_2 + 4) {
				CambioPregunta = true;
				balaActiva = false;
				NumeroPregunta++;
				Pajaro(135, 15, NumeroPregunta);
			}
		}
		// Pregunta 4 (nube 4)
		if (NumeroPregunta == 4) {
			if (balaX >= Nube_X_4 - 5 && balaX <= Nube_X_4 + 5 &&
				balaY >= Nube_Y_4 && balaY <= Nube_Y_4 + 4) {
				CambioPregunta = true;
				balaActiva = false;
				NumeroPregunta++;
				Pajaro(135, 15, NumeroPregunta);
			}
		}
		// Pregunta 5 (nube 3)
		if (NumeroPregunta == 5) {
			if (balaX >= Nube_X_3 - 5 && balaX <= Nube_X_3 + 5 &&
				balaY >= Nube_Y_3 && balaY <= Nube_Y_3 + 4) {
				CambioPregunta = true;
				balaActiva = false;
				NumeroPregunta++;
				Pajaro(135, 15, NumeroPregunta);
			}
		}
		// Pregunta 6 (nube 1)
		if (NumeroPregunta == 6) {
			if (balaX >= Nube_X_1 - 5 && balaX <= Nube_X_1 + 5 &&
				balaY >= Nube_Y_1 && balaY <= Nube_Y_1 + 4) {
				CambioPregunta = true;
				balaActiva = false;
				NumeroPregunta++;
				Pajaro(135, 15, NumeroPregunta);
			}
		}


		if (CambioPregunta == true && NumeroPregunta == 2) {
			pregunta.BorrarPregunta(5, 0);
			pregunta.DibujarPregunta(NumeroPregunta);
		}
		if (CambioPregunta == true && NumeroPregunta == 3) {

			pregunta.BorrarPregunta(5, 0);
			pregunta.DibujarPregunta(NumeroPregunta);
		}
		if (CambioPregunta == true && NumeroPregunta == 4) {
			pregunta.BorrarPregunta(5, 0);
			pregunta.DibujarPregunta(NumeroPregunta);
		}
		if (CambioPregunta == true && NumeroPregunta == 5) {
			pregunta.BorrarPregunta(5, 0);
			pregunta.DibujarPregunta(NumeroPregunta);
		}
		if (CambioPregunta == true && NumeroPregunta == 6) {
			pregunta.BorrarPregunta(5, 0);
			pregunta.DibujarPregunta(NumeroPregunta);
		}
		if (CambioPregunta == true && NumeroPregunta == 7) {
			pregunta.BorrarPregunta(5, 0);
			cout << "Has ganado";
		}



		/*=================================*/
		//Comprobar daño al jugador
		if (vida == 2 && VerificarDaño == true) {
			Marco.setVida(2);
			Marco.BorrarCorazones(130, 1);
			Marco.DibujarVida();
		}
		if (vida == 1 && VerificarDaño == true) {
			Marco.setVida(1);
			Marco.BorrarCorazones(130, 1);
			Marco.DibujarVida();
		}
		if (vida == 0 && VerificarDaño == true) {
			EstarVivo = false;
			Marco.setVida(0);
			Marco.BorrarCorazones(130, 1);
			Marco.DibujarVida();


			Console::BackgroundColor = ConsoleColor::Black;
			Console::ForegroundColor = ConsoleColor::White;
			Console::Clear();
			// Ejecutar segundo nivel al perder
			ejecutar_segundo_nivel();
			break;
		}
		// Verificar si se respondieron todas las preguntas
		if (NumeroPregunta == 7) {
			Console::BackgroundColor = ConsoleColor::Black;
			Console::ForegroundColor = ConsoleColor::White;
			Console::Clear();
			Console::SetCursorPosition(48, 15);
			cout << "¡Felicidades! Has respondido todas las preguntas correctamente!";
			Sleep(1000);
			Console::SetCursorPosition(50, 20);
			cout << "ES LA HORA DEL LABERINTO";
			Sleep(3000);

			// Ejecutar segundo nivel al completar todas las preguntas
			ejecutar_segundo_nivel();
			break;
		}
	}

	return 0;
}
/*=========================================================*/
