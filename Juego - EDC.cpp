#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <vector>
#include <chrono>
#include <locale>

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
/*=======================*/

/* Teclas */
enum Teclas { DERECHA = 77, IZQUIERDA = 75 ,ARRIBA = 72};
/*----------*/

/* Personaje Principal */
class Personaje {
private:
	int x;
	int y;
public:
	Personaje(int _x, int _y) : x(_x), y(_y) {}
	void setCursor(int CursorX, int CursorY) {
		x = CursorX;
		y = CursorY;
		Console::SetCursorPosition(x, y);
	}
	void Dibujar(int posicion, int frame) {
		Console::BackgroundColor = ConsoleColor::DarkMagenta;
		Console::ForegroundColor = ConsoleColor::Black;
		/* Direccion a la izquierda  */
		if (posicion == 1) {
			if (frame == 1){
				// Sombrero 
				Pintar(x + 1, y,     " /^^^^\\ ", ConsoleColor::Black, ConsoleColor::DarkRed);

				// Cabeza y cara
				Pintar(x + 2, y + 1, "| o o |", ConsoleColor::DarkGray, ConsoleColor::Black);
				Pintar(x + 2, y + 2, "|  ^  |", ConsoleColor::DarkGray, ConsoleColor::Black);

				// Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |", ConsoleColor::Black, ConsoleColor::White);
				Pintar(x+1, y + 4,   "--", ConsoleColor::Black, ConsoleColor::Blue);             
				Pintar(x + 2, y + 4,  "|   |", ConsoleColor::Black, ConsoleColor::Blue);       
				Pintar(x + 7, y + 4,        "--", ConsoleColor::Black, ConsoleColor::Blue);        

				// Arma
		  Pintar(x - 1, y + 4,"==>", ConsoleColor::Black, ConsoleColor::Gray);     

				// Piernas
				Pintar(x + 2, y + 5, "/   \\", ConsoleColor::Black, ConsoleColor::Blue);

				// Pies
				Pintar(x + 2, y + 6,"_", ConsoleColor::Black, ConsoleColor::DarkBlue);
				Pintar(x + 6, y + 6,      "_", ConsoleColor::Black, ConsoleColor::DarkBlue);

			}

			if (frame == 2){
				//Sombrero
				Pintar(x + 1, y,    " /^^^^\\ ", ConsoleColor::Black, ConsoleColor::DarkRed);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o o |", ConsoleColor::DarkGray, ConsoleColor::Black);
				Pintar(x + 2, y + 2, "|  -  |", ConsoleColor::DarkGray, ConsoleColor::Black);

				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |", ConsoleColor::Black, ConsoleColor::White);

			  Pintar(x, y + 4,"-", ConsoleColor::Black, ConsoleColor::Blue);            
				Pintar(x + 2, y + 4, "|   |", ConsoleColor::Black, ConsoleColor::Blue);
				Pintar(x + 7, y + 4,        " -", ConsoleColor::Black, ConsoleColor::Blue);             
				//Arma
			Pintar(x - 1, y + 4, "==>", ConsoleColor::Black, ConsoleColor::Gray);            
				//Piernas
				Pintar(x + 2, y + 5, "/    ", ConsoleColor::Black, ConsoleColor::Blue);           
				Pintar(x + 5, y + 5,     " \\", ConsoleColor::Black, ConsoleColor::Blue);            
				//pies
				Pintar(x + 2, y + 6,"_", ConsoleColor::Black, ConsoleColor::DarkBlue);
				Pintar(x + 6, y + 6,      "_", ConsoleColor::Black, ConsoleColor::DarkBlue);
				

			}

			if (frame == 3){
				//Sombrero
				Pintar(x + 1, y,     " /^^^^\\ ", ConsoleColor::Black, ConsoleColor::DarkRed);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o_o |", ConsoleColor::DarkGray, ConsoleColor::Black);
				Pintar(x + 2, y + 2, "|  o  |", ConsoleColor::DarkGray, ConsoleColor::Black);

				Pintar(x + 2, y + 3, "| [_] |", ConsoleColor::Black, ConsoleColor::White);
				//Brazos y cuerpo
				Pintar(x-1, y + 4, "-", ConsoleColor::Black, ConsoleColor::Blue);                  
				Pintar(x + 2, y + 4, "|   |", ConsoleColor::Black, ConsoleColor::Blue);
				Pintar(x + 6, y + 4,        "--", ConsoleColor::Black, ConsoleColor::Blue);           
				//Arma
			Pintar(x 	, y + 4, "==>", ConsoleColor::Black, ConsoleColor::Gray);            
				//Piernas
				Pintar(x + 2, y + 5, "    \\", ConsoleColor::Black, ConsoleColor::Blue);        
				Pintar(x + 2, y + 5, "/", ConsoleColor::Black, ConsoleColor::Blue);              
				//Pies 
				Pintar(x + 2, y + 6,"_", ConsoleColor::Black, ConsoleColor::DarkBlue);
				Pintar(x + 6, y + 6,      "_", ConsoleColor::Black, ConsoleColor::DarkBlue);
				

			}

			if (frame == 4){
				//Sombrero
				Pintar(x + 1, y,   " /^^^^\\ ", ConsoleColor::Black, ConsoleColor::DarkRed);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| > < |", ConsoleColor::DarkGray, ConsoleColor::Black);
				Pintar(x + 2, y + 2, "| [!] |", ConsoleColor::DarkGray, ConsoleColor::Black); 
				//Cuerpo
				Pintar(x + 2, y + 3, "| [_] |", ConsoleColor::Black, ConsoleColor::White);
				//Arma y brazos
			Pintar(x - 1, y + 4,"==>", ConsoleColor::Black, ConsoleColor::Gray);        
				Pintar(x, y + 4,    "-", ConsoleColor::Black, ConsoleColor::Blue);              
				Pintar(x + 2, y + 4, "|   |", ConsoleColor::Black, ConsoleColor::Blue);
				Pintar(x + 7, y + 4,         "--", ConsoleColor::Black, ConsoleColor::Blue);        

				//Piernas
				Pintar(x + 2, y + 5, "/ _ \\", ConsoleColor::Black, ConsoleColor::Blue);
				//pies
				Pintar(x + 2, y + 6,"_", ConsoleColor::Black, ConsoleColor::DarkBlue);
				Pintar(x + 6, y + 6,      "_", ConsoleColor::Black, ConsoleColor::DarkBlue);
			}

		}
		/* Direccion a la derecha */
		if (posicion == 2) {
			if (frame == 1) {
				// Sombrero 
				Pintar(x + 1, y,     " /^^^^\\ ", ConsoleColor::Black, ConsoleColor::DarkRed);

				// Cabeza
				Pintar(x + 2, y + 1, "| o o |", ConsoleColor::DarkGray, ConsoleColor::Black);
				Pintar(x + 2, y + 2, "|  ^  |", ConsoleColor::DarkGray, ConsoleColor::Black);

				// Cuerpo
				Pintar(x + 2, y + 3, "| [_] |", ConsoleColor::Black, ConsoleColor::White);

				// Brazos y torzo
				Pintar(x + 6, y + 4,         "--", ConsoleColor::Black, ConsoleColor::Blue);        
				Pintar(x + 2, y + 4, "|   |", ConsoleColor::Black, ConsoleColor::Blue);       
			 Pintar(x, y + 4, "--", ConsoleColor::Black, ConsoleColor::Blue);          

				// Arma 
				Pintar(x + 8, y + 4,         "<==", ConsoleColor::Black, ConsoleColor::Gray); 

				// Piernas
				Pintar(x + 2, y + 5, "/   \\", ConsoleColor::Black, ConsoleColor::Blue);

				// Pies
				Pintar(x + 2, y + 6,"_", ConsoleColor::Black, ConsoleColor::DarkBlue);
				Pintar(x + 6, y + 6,      "_", ConsoleColor::Black, ConsoleColor::DarkBlue);
			}

			if (frame == 2) {
				//Sombrero
				Pintar(x + 1, y,     " /^^^^\\ ", ConsoleColor::Black, ConsoleColor::DarkRed);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o o |", ConsoleColor::DarkGray, ConsoleColor::Black);
				Pintar(x + 2, y + 2, "|  -  |", ConsoleColor::DarkGray, ConsoleColor::Black);
				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |", ConsoleColor::Black, ConsoleColor::White);

				Pintar(x + 7, y + 4,          "--", ConsoleColor::Black, ConsoleColor::Blue);              
				Pintar(x + 2, y + 4, "|   |", ConsoleColor::Black, ConsoleColor::Blue);
			 Pintar(x , y + 4, " -", ConsoleColor::Black, ConsoleColor::Blue);             
				//Arma
				Pintar(x + 7, y + 4,          "<==", ConsoleColor::Black, ConsoleColor::Gray);        
				//pierna
				Pintar(x + 2, y + 5, "/", ConsoleColor::Black, ConsoleColor::Blue);
				Pintar(x + 5, y + 5, " \\", ConsoleColor::Black, ConsoleColor::Blue);

				//pies
				Pintar(x + 2, y + 6, "_", ConsoleColor::Black, ConsoleColor::DarkBlue);
				Pintar(x + 6, y + 6,      "_", ConsoleColor::Black, ConsoleColor::DarkBlue);
			}

			if (frame == 3) {
				//Sombrero
				Pintar(x + 1, y,    " /^^^^\\ ", ConsoleColor::Black, ConsoleColor::DarkRed);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o_o |", ConsoleColor::DarkGray, ConsoleColor::Black);
				Pintar(x + 2, y + 2, "|  o  |", ConsoleColor::DarkGray, ConsoleColor::Black);
				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |", ConsoleColor::Black, ConsoleColor::White);

				Pintar(x + 8, y + 4,        "-", ConsoleColor::Black, ConsoleColor::Blue);               
				Pintar(x + 2, y + 4, "|   |", ConsoleColor::Black, ConsoleColor::Blue);
			   Pintar(x , y + 4,"--", ConsoleColor::Black, ConsoleColor::Blue);               
				//arma
				Pintar(x + 7, y + 4,         "<==", ConsoleColor::Black, ConsoleColor::Gray);           
				//piernas
				Pintar(x + 2, y + 5, "/    ", ConsoleColor::Black, ConsoleColor::Blue);           
				Pintar(x + 5, y + 5,    " \\", ConsoleColor::Black, ConsoleColor::Blue);             
				//pies
				Pintar(x + 2, y + 6,"_", ConsoleColor::Black, ConsoleColor::DarkBlue);
				Pintar(x + 6, y + 6,      "_", ConsoleColor::Black, ConsoleColor::DarkBlue);
			}

			if (frame == 4) {
				//Sombrero
				Pintar(x + 1, y,    " /^^^^\\ ", ConsoleColor::Black, ConsoleColor::DarkRed);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| < > |", ConsoleColor::DarkGray, ConsoleColor::Black);      
				Pintar(x + 2, y + 2, "| [!] |", ConsoleColor::DarkGray, ConsoleColor::Black);  
				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |", ConsoleColor::Black, ConsoleColor::White);

				Pintar(x + 6, y + 4,      "--", ConsoleColor::Black, ConsoleColor::Blue);               
				Pintar(x + 2, y + 4, "|   |", ConsoleColor::Black, ConsoleColor::Blue);
				Pintar(x, y + 4,"--", ConsoleColor::Black, ConsoleColor::Blue);  
				//ARma
				Pintar(x + 8, y + 4,        "<==", ConsoleColor::Black, ConsoleColor::Gray);
				//PIErnas
				Pintar(x + 2, y + 5, "/ _ \\", ConsoleColor::Black, ConsoleColor::Blue);
				//pies
				Pintar(x + 2, y + 6,"_", ConsoleColor::Black, ConsoleColor::DarkBlue);
				Pintar(x + 6, y + 6,      "_", ConsoleColor::Black, ConsoleColor::DarkBlue);
			}


		}
		if (posicion == 3) {
			if (frame == 1) {
				//Sombrero
				Pintar(x + 1, y + 0, "  /^\\  ", ConsoleColor::Black, ConsoleColor::DarkRed);

				// Cabeza y cara
				Pintar(x + 2, y + 1, " (o o) ", ConsoleColor::DarkGray, ConsoleColor::Black);
				Pintar(x + 2, y + 2, "  \\_/  ", ConsoleColor::DarkGray, ConsoleColor::Black);

				// ARma
				Pintar(x + 4, y - 1,  " ^ ", ConsoleColor::Black, ConsoleColor::Gray);     
				Pintar(x + 4, y + 0,  " ||", ConsoleColor::Black, ConsoleColor::Gray);     

				// Cuerpo y brazos
				Pintar(x + 1, y + 3, "/", ConsoleColor::Black, ConsoleColor::Blue);      
				Pintar(x + 6, y + 3, "\\", ConsoleColor::Black, ConsoleColor::Blue);      

				Pintar(x + 2, y + 3, "|[_]|", ConsoleColor::Black, ConsoleColor::White);

				// Piernas 
				Pintar(x + 2, y + 5, "/   \\", ConsoleColor::Black, ConsoleColor::Blue);

				//Pies
				Pintar(x + 2, y + 6,"_", ConsoleColor::Black, ConsoleColor::DarkBlue);
				Pintar(x + 6, y + 6,      "_", ConsoleColor::Black, ConsoleColor::DarkBlue);
			}
		}
	}

	void Borrar(int AntiguoX, int AntiguoY) {
		BorrarAnimacion(AntiguoX-1 , AntiguoY, 20, 7);
	}
};
/*=================================================================*/


/*      Funcion Principal Main    */
int main() {
	setlocale(LC_ALL, "Spanish");
	Window();
	Piso(150);

	int x = 90; int y = 28;
	Personaje Marco(x, y);
	int frame = 1;
	int posicion = 1;
	int animacion = 1;
	auto UltimoMomento = Clock::now();
	auto Intervalo = chrono::milliseconds(500);
	Marco.Dibujar(1,1);
	while (true) {
		bool moverse = false;
		
		int AntiguoX = x; int AntiguoY = y;
		if (_kbhit()) {
			int Tecla = _getch();
			if (Tecla == 0 || Tecla == 224) {
				Tecla = _getch();
				if (Tecla == static_cast<int>(Teclas::DERECHA)) {
					x++;
					posicion = 2;
					frame++;
					if (frame > 4) {
						frame = 1;
					}
					moverse = true;
				}
				if (Tecla == static_cast<int>(Teclas::IZQUIERDA)) {
					x--;
					posicion = 1;
					frame++;
					if (frame > 4) {
						frame = 1;
					}
					moverse = true;
				}
				if (Tecla == static_cast<int>(Teclas::ARRIBA)) {
					posicion = 3;   
					frame = 1;         
					Marco.Dibujar(posicion, frame);
				}
				Marco.setCursor(x, y);
			}
			if (moverse == true) {
				Marco.Borrar(AntiguoX, AntiguoY);
				Marco.Dibujar(posicion, frame);
			}

		}
		auto ahora = Clock::now();
		if (ahora - UltimoMomento >= Intervalo) {

			for (int Columna : {20, 60, 100}) {
				BorrarAnimacion(Columna, 31, 15, 4);
				Vegetacion(animacion, Columna, 31);
			}
			animacion++;
			if (animacion >= 8) {
				animacion = 1;
			}
			UltimoMomento = ahora;
		}
	}
	return 0;
}
/*=========================================================*/


/* Funciones Extras   */

//Ventana del juego
void Window() {
	Console::CursorVisible = false;
	Console::BackgroundColor = ConsoleColor::Blue;
	Console::SetWindowSize(1, 1);
	Console::SetBufferSize(150, 40); //Comando obtenido con Chat-GTP
	Console::SetWindowSize(150, 40);  //Comando obtenido con Chat-GTP
	Console::Clear();  //Comando obtenido con Chat-GTP
}

//Funcion que define los arbustos
void Vegetacion(int animacion, int x, int y) {
	//Definiendo colores de la planta
	Console::BackgroundColor = ConsoleColor::DarkGreen;
	Console::ForegroundColor = ConsoleColor::DarkRed;
	//Animacion 1 (Neutro)
	if (animacion == 1) {
		Pintar(x, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 3, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 6, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 9, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 12, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 1, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 3, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 6, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 9, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 12, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 2, "    *  *  *   ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x, y + 3, " *  *  *  *  *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
	}
	//Animacion 2 (derecha)
	if (animacion == 2) {
		Pintar(x + 1, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 4, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 7, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 10, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 13, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 1, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 3, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 6, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 9, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 12, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 2, "    *  *  *   ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x, y + 3, " *  *  *  *  *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

	}
	//Animacion 3(derecha)
	if (animacion == 3) {
		Pintar(x + 4, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 7, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 9, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 13, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 16, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x + 2, y + 1, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 5, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 8, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 11, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 14, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 2, "    *  *  *   ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x, y + 3, " *  *  *  *  *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);


	}
	//Animacion 4 (Derecha)
	if (animacion == 4) {
		Pintar(x + 1, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 4, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 7, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 10, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 13, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 1, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 3, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 6, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 9, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 12, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 2, "    *  *  *   ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x, y + 3, " *  *  *  *  *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

	}
	//Animacion 5 (neutro)
	if (animacion == 5) {
		Pintar(x, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 3, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 6, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 9, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 12, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 1, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 3, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 6, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 9, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 12, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 2, "    *  *  *   ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x, y + 3, " *  *  *  *  *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

	}
	//Animacion 6 (izquierda)
	if (animacion == 6) {
		Pintar((x + 1) - 2, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 4) - 2, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 7) - 2, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 10) - 2, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 13) - 2, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 1, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 3, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 6, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 9, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 12, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 2, "    *  *  *   ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x, y + 3, " *  *  *  *  *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

	}
	//Animacion 7 (izquierda)

	if (animacion == 7) {
		Pintar((x + 1) - 3, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 4) - 3, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 7) - 3, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 10) - 3, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 13) - 3, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x - 1, y + 1, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 3) - 1, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 6) - 1, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 9) - 1, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 12) - 1, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 2, "    *  *  *   ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x, y + 3, " *  *  *  *  *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);


	}
	//Animacion 8 (izquierda)

	if (animacion == 8) {
		Pintar((x + 1) - 2, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 4) - 2, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 7) - 2, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 10) - 2, y, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar((x + 13) - 2, y, "  ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 1, "* ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 3, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 6, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 9, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x + 12, y + 1, " *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

		Pintar(x, y + 2, "    *  *  *   ", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);
		Pintar(x, y + 3, " *  *  *  *  *", ConsoleColor::DarkGreen, ConsoleColor::DarkRed);

	}
}

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

//Funcion pintar + cursor + cout
void Pintar(int x, int y, string caracter, ConsoleColor fondo, ConsoleColor ColorCaracteres) {
	
	Console::BackgroundColor = fondo;
	Console::ForegroundColor = ColorCaracteres;

	Console::SetCursorPosition(x, y);

	cout << caracter;
}
//Funcion borrar animacion
void BorrarAnimacion(int x, int y, int columna, int fila) {
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {
			Pintar(x + j, y + i, " ", ConsoleColor::Blue, ConsoleColor::Blue);
		}
	}
}
/*======================================*/
