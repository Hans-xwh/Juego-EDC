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

/* VARIABLES GLOBALES*/
// ===== VARIABLES DE BALA ===== //
bool balaActiva = false;
int balaX, balaY;
int balaDireccion;
bool puedeDisparar = true;       // control de cooldown
clock_t ultimoDisparo = 0;      // tiempo del último disparo
const int cooldownDisparo = 500; // 500ms = 0.5s entre disparos
const int velocidadBala = 1;

auto ultimoMovimientoBala = Clock::now();
const auto intervaloMovimientoBala = chrono::milliseconds(10); // Valor para mayor lentitud
// ============================ //
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
		ConsoleColor ColorRojo = ConsoleColor::DarkRed;
		ConsoleColor ColorNegro = ConsoleColor::Black;
		ConsoleColor ColorGrisOscuro = ConsoleColor::DarkGray;
		ConsoleColor ColorBlanco = ConsoleColor::White;
		ConsoleColor ColorAzul = ConsoleColor::Blue;
		ConsoleColor ColorGris = ConsoleColor::Gray;
		ConsoleColor ColorAzulOscuro = ConsoleColor::DarkBlue;
		/* Direccion a la izquierda  */
		if (posicion == 1) {
			if (frame == 1){
				// Sombrero 
				Pintar(x + 1, y,     " /^^^^\\ ",ColorNegro, ColorRojo);

				// Cabeza y cara
				Pintar(x + 2, y + 1, "| o o |", ColorGrisOscuro,ColorNegro);
				Pintar(x + 2, y + 2, "|  ^  |", ColorGrisOscuro,ColorNegro);

				// Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |",ColorNegro, ColorBlanco);
				Pintar(x+1, y + 4,   "--",ColorNegro, ColorAzul);             
				Pintar(x + 2, y + 4,  "|   |",ColorNegro, ColorAzul);       
				Pintar(x + 7, y + 4,        "--",ColorNegro, ColorAzul);        

				// Arma
		  Pintar(x - 1, y + 4,"==>",ColorNegro, ColorGris);     

				// Piernas
				Pintar(x + 2, y + 5, "/   \\",ColorNegro, ColorAzul);

				// Pies
				Pintar(x + 2, y + 6,"_",ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6,      "_",ColorNegro, ColorAzulOscuro);

			}

			if (frame == 2){
				//Sombrero
				Pintar(x + 1, y,    " /^^^^\\ ",ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o o |", ColorGrisOscuro,ColorNegro);
				Pintar(x + 2, y + 2, "|  -  |", ColorGrisOscuro,ColorNegro);

				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |",ColorNegro, ColorBlanco);

			  Pintar(x, y + 4,"-",ColorNegro, ColorAzul);            
				Pintar(x + 2, y + 4, "|   |",ColorNegro, ColorAzul);
				Pintar(x + 7, y + 4,        " -",ColorNegro, ColorAzul);             
				//Arma
			Pintar(x - 1, y + 4, "==>",ColorNegro, ColorGris);            
				//Piernas
				Pintar(x + 2, y + 5, "/    ",ColorNegro, ColorAzul);           
				Pintar(x + 5, y + 5,     " \\",ColorNegro, ColorAzul);            
				//pies
				Pintar(x + 2, y + 6,"_",ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6,      "_",ColorNegro, ColorAzulOscuro);
				

			}

			if (frame == 3){
				//Sombrero
				Pintar(x + 1, y,     " /^^^^\\ ",ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o_o |", ColorGrisOscuro,ColorNegro);
				Pintar(x + 2, y + 2, "|  o  |", ColorGrisOscuro,ColorNegro);

				Pintar(x + 2, y + 3, "| [_] |",ColorNegro, ColorBlanco);
				//Brazos y cuerpo
				Pintar(x-1, y + 4, "-",ColorNegro, ColorAzul);                  
				Pintar(x + 2, y + 4, "|   |",ColorNegro, ColorAzul);
				Pintar(x + 6, y + 4,        "--",ColorNegro, ColorAzul);           
				//Arma
			Pintar(x 	, y + 4, "==>",ColorNegro, ColorGris);            
				//Piernas
				Pintar(x + 2, y + 5, "    \\",ColorNegro, ColorAzul);        
				Pintar(x + 2, y + 5, "/",ColorNegro, ColorAzul);              
				//Pies 
				Pintar(x + 2, y + 6,"_",ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6,      "_",ColorNegro, ColorAzulOscuro);
				

			}

			if (frame == 4){
				//Sombrero
				Pintar(x + 1, y,   " /^^^^\\ ",ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| > < |", ColorGrisOscuro,ColorNegro);
				Pintar(x + 2, y + 2, "| [!] |", ColorGrisOscuro,ColorNegro); 
				//Cuerpo
				Pintar(x + 2, y + 3, "| [_] |",ColorNegro, ColorBlanco);
				//Arma y brazos
			Pintar(x - 1, y + 4,"==>",ColorNegro, ColorGris);        
				Pintar(x, y + 4,    "-",ColorNegro, ColorAzul);              
				Pintar(x + 2, y + 4, "|   |",ColorNegro, ColorAzul);
				Pintar(x + 7, y + 4,         "--",ColorNegro, ColorAzul);        

				//Piernas
				Pintar(x + 2, y + 5, "/ _ \\",ColorNegro, ColorAzul);
				//pies
				Pintar(x + 2, y + 6,"_",ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6,      "_",ColorNegro, ColorAzulOscuro);
			}

		}
		/* Direccion a la derecha */
		if (posicion == 2) {
			if (frame == 1) {
				// Sombrero 
				Pintar(x + 1, y,     " /^^^^\\ ",ColorNegro, ColorRojo);

				// Cabeza
				Pintar(x + 2, y + 1, "| o o |", ColorGrisOscuro,ColorNegro);
				Pintar(x + 2, y + 2, "|  ^  |", ColorGrisOscuro,ColorNegro);

				// Cuerpo
				Pintar(x + 2, y + 3, "| [_] |",ColorNegro, ColorBlanco);

				// Brazos y torzo
				Pintar(x + 6, y + 4,         "--",ColorNegro, ColorAzul);        
				Pintar(x + 2, y + 4, "|   |",ColorNegro, ColorAzul);       
			 Pintar(x, y + 4, "--",ColorNegro, ColorAzul);          

				// Arma 
				Pintar(x + 8, y + 4,         "<==",ColorNegro, ColorGris); 

				// Piernas
				Pintar(x + 2, y + 5, "/   \\",ColorNegro, ColorAzul);

				// Pies
				Pintar(x + 2, y + 6,"_",ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6,      "_",ColorNegro, ColorAzulOscuro);
			}

			if (frame == 2) {
				//Sombrero
				Pintar(x + 1, y,     " /^^^^\\ ",ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o o |", ColorGrisOscuro,ColorNegro);
				Pintar(x + 2, y + 2, "|  -  |", ColorGrisOscuro,ColorNegro);
				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |",ColorNegro, ColorBlanco);

				Pintar(x + 7, y + 4,          "--",ColorNegro, ColorAzul);              
				Pintar(x + 2, y + 4, "|   |",ColorNegro, ColorAzul);
			 Pintar(x , y + 4, " -",ColorNegro, ColorAzul);             
				//Arma
				Pintar(x + 7, y + 4,          "<==",ColorNegro, ColorGris);        
				//pierna
				Pintar(x + 2, y + 5, "/",ColorNegro, ColorAzul);
				Pintar(x + 5, y + 5, " \\",ColorNegro, ColorAzul);

				//pies
				Pintar(x + 2, y + 6, "_",ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6,      "_",ColorNegro, ColorAzulOscuro);
			}

			if (frame == 3) {
				//Sombrero
				Pintar(x + 1, y,    " /^^^^\\ ",ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| o_o |", ColorGrisOscuro,ColorNegro);
				Pintar(x + 2, y + 2, "|  o  |", ColorGrisOscuro,ColorNegro);
				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |",ColorNegro, ColorBlanco);

				Pintar(x + 8, y + 4,        "-",ColorNegro, ColorAzul);               
				Pintar(x + 2, y + 4, "|   |",ColorNegro, ColorAzul);
			   Pintar(x , y + 4,"--",ColorNegro, ColorAzul);               
				//arma
				Pintar(x + 7, y + 4,         "<==",ColorNegro, ColorGris);           
				//piernas
				Pintar(x + 2, y + 5, "/    ",ColorNegro, ColorAzul);           
				Pintar(x + 5, y + 5,    " \\",ColorNegro, ColorAzul);             
				//pies
				Pintar(x + 2, y + 6,"_",ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6,      "_",ColorNegro, ColorAzulOscuro);
			}

			if (frame == 4) {
				//Sombrero
				Pintar(x + 1, y,    " /^^^^\\ ",ColorNegro, ColorRojo);
				//Cabeza y cara
				Pintar(x + 2, y + 1, "| < > |", ColorGrisOscuro,ColorNegro);      
				Pintar(x + 2, y + 2, "| [!] |", ColorGrisOscuro,ColorNegro);  
				//Cuerpo y brazos
				Pintar(x + 2, y + 3, "| [_] |",ColorNegro, ColorBlanco);

				Pintar(x + 6, y + 4,      "--",ColorNegro, ColorAzul);               
				Pintar(x + 2, y + 4, "|   |",ColorNegro, ColorAzul);
				Pintar(x, y + 4,"--",ColorNegro, ColorAzul);  
				//ARma
				Pintar(x + 8, y + 4,        "<==",ColorNegro, ColorGris);
				//PIErnas
				Pintar(x + 2, y + 5, "/ _ \\",ColorNegro, ColorAzul);
				//pies
				Pintar(x + 2, y + 6,"_",ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6,      "_",ColorNegro, ColorAzulOscuro);
			}


		}
		if (posicion == 3) {
			if (frame == 1) {
				//Sombrero
				Pintar(x + 1, y + 0, "  /^\\  ",ColorNegro, ColorRojo);

				// Cabeza y cara
				Pintar(x + 2, y + 1, " (o o) ", ColorGrisOscuro,ColorNegro);
				Pintar(x + 2, y + 2, "  \\_/  ", ColorGrisOscuro,ColorNegro);

				// ARma
				Pintar(x + 4, y - 1,  " ^ ",ColorNegro, ColorGris);     
				Pintar(x + 4, y + 0,  " ||",ColorNegro, ColorGris);     

				// Cuerpo y brazos
				Pintar(x + 1, y + 3, "/",ColorNegro, ColorAzul);      
				Pintar(x + 6, y + 3, "\\",ColorNegro, ColorAzul);      

				Pintar(x + 2, y + 3, "|[_]|",ColorNegro, ColorBlanco);

				// Piernas 
				Pintar(x + 2, y + 5, "/   \\",ColorNegro, ColorAzul);

				//Pies
				Pintar(x + 2, y + 6,"_",ColorNegro, ColorAzulOscuro);
				Pintar(x + 6, y + 6,      "_",ColorNegro, ColorAzulOscuro);
			}
		}
	}

	void Borrar(int AntiguoX, int AntiguoY) {
		BorrarAnimacion(AntiguoX-1 , AntiguoY, 20, 7);
	}
};
/*=================================================================*/

/* Clase  Nubes*/
class Nubes {
private:
	int x;
	int y;
public:
	Nubes(int _x, int _y) : x(_x), y(_y) {}

	void setCursor(int nuevoX, int nuevoY){
		x = nuevoX;
		y = nuevoY;
	}
	void DibujarNube(int animacion) {
		ConsoleColor ColorGris = ConsoleColor::Gray;
		ConsoleColor ColorNegro = ConsoleColor::Black;
		ConsoleColor ColorAzul = ConsoleColor::Blue;
		ConsoleColor ColorAzulOscuro = ConsoleColor::DarkBlue;

		if (animacion == 1) {
			Pintar(x, y, "   ", ColorGris, ColorNegro);
			Pintar(x - 1, y + 1, "     ", ColorGris, ColorNegro);
			Pintar(x - 2, y + 2, " 5 + x ", ColorGris, ColorNegro);
			Pintar(x - 3, y + 3, "  =  10    ", ColorGris, ColorNegro);
		}
		if (animacion == 2) {
			Pintar(x - 1, y, "Quien", ColorGris, ColorNegro);
			Pintar(x - 2, y + 1, "  es  ", ColorGris, ColorNegro);
			Pintar(x - 3, y + 2, "   Dina  ", ColorGris, ColorNegro);
			Pintar(x - 4, y + 3, " Boluarte?", ColorGris, ColorNegro);
		}
		if (animacion == 3) {
			Pintar(x-1, y + 1, "      ", ColorGris, ColorNegro);
			Pintar(x - 2, y + 2, "        ", ColorGris, ColorNegro);
			Pintar(x - 3, y + 3, "         ", ColorGris, ColorNegro);
			Pintar(x - 4, y + 4, "           ", ColorGris, ColorNegro);
		}
		if (animacion == 4) {
			Pintar(x, y, "   ", ColorGris, ColorNegro);
			Pintar(x - 1, y + 1, "     ", ColorGris, ColorNegro);
			Pintar(x - 2, y + 2, "       ", ColorGris, ColorNegro);
			Pintar(x - 3, y + 3, "         ", ColorGris, ColorNegro);

			// Lluvia
			Pintar(x - 2, y + 4, "  |   |  ", ColorAzul, ColorAzulOscuro);
			Pintar(x - 1, y + 5, " |  | | ", ColorAzul, ColorAzulOscuro);
		}
	}
	void BorrarNube(int AntiguoX,int AntiguoY) {
		BorrarAnimacion(AntiguoX-4, AntiguoY, 20, 6);
	}
};

/*=================================================================*/


/* FUNCION DISPARAR */

void Disparar(int personajeX, int personajeY, int direccion) {
	clock_t ahora = clock();

	if (puedeDisparar && (ahora - ultimoDisparo) >= cooldownDisparo) {
		balaActiva = true;
		balaDireccion = direccion;

		// Posición inicial basada en la dirección del personaje
		if (direccion == 1) { // Izquierda
			balaX = personajeX - 3;
		}
		else { // Derecha
			balaX = personajeX + 9;
		}
		balaY = personajeY + 4; // Altura del arma

		ultimoDisparo = ahora;
		puedeDisparar = false;
	}
}

/*ACTUALIAZR BALA*/

void ActualizarBala() {
	auto ahora = Clock::now();

	if (!balaActiva) return;

	// Solo mover la bala si ha pasado el tiempo suficiente
	if (ahora - ultimoMovimientoBala >= intervaloMovimientoBala) {
		// 1. Borrar la bala
		Pintar(balaX, balaY, "  ", ConsoleColor::Blue, ConsoleColor::Blue);

		// 2. Mover la bala
		if (balaDireccion == 1) balaX -= velocidadBala; // Izquierda
		else balaX += velocidadBala;                   // Derecha

		// 3. Verificar límites
		if (balaX < 2 || balaX > 148) {
			balaActiva = false;
			return;
		}

		// 4. Dibujar la bala
		string simboloBala = (balaDireccion == 1) ? "<=" : "=>";
		Pintar(balaX, balaY, simboloBala, ConsoleColor::Black, ConsoleColor::Yellow);

		ultimoMovimientoBala = ahora; // Reiniciar el temporizador
	}
}




/*      Funcion Principal Main    */
int main() {
	setlocale(LC_ALL, "Spanish");
	Window();
	Piso(150);

	
	//Poner el tamaño de la consola, para que funcione en Win10
	Console::SetWindowSize(150, 40);
	Console::SetBufferSize(150, 50);
	

	//Personaje
	int x = 90; int y = 28;
	Personaje Marco(x, y);
	//Nubes
	int FormaNube1 = 1;
	int Nube_X_1 = 80; int Nube_Y_1 = 10;
	Nubes nube1(Nube_X_1, Nube_Y_1);

	int FormaNube2 = 2;
	int Nube_X_2 = 20; int Nube_Y_2 = 5;
	Nubes nube2(Nube_X_2, Nube_Y_2);

	int FormaNube3 = 3;
	int Nube_X_3 = 50; int Nube_Y_3 = 20;
	Nubes nube3(Nube_X_3, Nube_Y_3);

	int FormaNube4 = 4;
	int Nube_X_4 = 120; int Nube_Y_4 = 5;
	Nubes nube4(Nube_X_4, Nube_Y_4);

	nube1.DibujarNube(FormaNube1);
	nube2.DibujarNube(FormaNube2);
	nube3.DibujarNube(FormaNube3);
	nube4.DibujarNube(FormaNube4);

	int frame = 1;
	int posicion = 1;
	int animacion = 1;
	auto UltimoMomento = Clock::now();
	auto Intervalo = chrono::milliseconds(500);
	Marco.Dibujar(1,1);
	while (true) {
		bool moverse = false;
		//Coordenadas Nubes
		int AntiguoXNube1 = Nube_X_1; int AntiguoYNube1 = Nube_Y_1;
		int AntiguoXNube2 = Nube_X_2; int AntiguoYNube2 = Nube_Y_2;
		int AntiguoXNube3 = Nube_X_3; int AntiguoYNube3 = Nube_Y_3;
		int AntiguoXNube4 = Nube_X_4; int AntiguoYNube4 = Nube_Y_4;

		// Verificar cooldown del disparo
		if (!puedeDisparar) {
			clock_t ahora = clock();
			if (ahora - ultimoDisparo >= cooldownDisparo) {
				puedeDisparar = true;
			}
		}

		//Cordenadas Personaje
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
			else if ((Tecla == 'f' || Tecla == 'F' || Tecla == 32) && puedeDisparar)
			{
				Disparar(x, y, posicion);
				puedeDisparar = false; // Activa el cooldown
				ultimoDisparo = clock();
			}


			if (moverse == true) {
				Marco.Borrar(AntiguoX, AntiguoY);
				Marco.Dibujar(posicion, frame);
			}

		}
		auto ahora = Clock::now();
		
		/*ACTUALIZAR LAS BALAS */
		ActualizarBala(); 

		if (ahora - UltimoMomento >= Intervalo) {
			/*    Nubes   */
			
			//nube 1
			Nube_X_1--;
			nube1.setCursor(Nube_X_1, Nube_Y_1);
			nube1.BorrarNube(AntiguoXNube1, AntiguoYNube1);
			nube1.DibujarNube(FormaNube1);

			//nube 2
			Nube_X_2--;
			nube2.setCursor(Nube_X_2, Nube_Y_2);
			nube2.BorrarNube(AntiguoXNube2, AntiguoYNube2);
			nube2.DibujarNube(FormaNube2);

			//nube 3
			Nube_X_3--;

			nube3.setCursor(Nube_X_3, Nube_Y_3);
			nube3.BorrarNube(AntiguoXNube3, AntiguoYNube3);
			nube3.DibujarNube(FormaNube3);

			//nube 4
			Nube_X_4--;
			nube4.setCursor(Nube_X_4, Nube_Y_4);
			nube4.BorrarNube(AntiguoXNube4, AntiguoYNube4);
			nube4.DibujarNube(FormaNube4);

			/*===================*/

			//plantas
			for (int Columna : {20, 60, 100}) {
				BorrarAnimacion(Columna, 31, 15, 4);
				Vegetacion(animacion, Columna, 31);
			}

			animacion++;
			if (animacion >= 8) {
				animacion = 1;
			}
			//Restablecer intervalo
			UltimoMomento = ahora;
		}
	}

	/*LLAMAR A LA FUNCION BALA */


	return 0;
}
/*=========================================================*/


/* Funciones Extras   */

//Ventana del juego
void Window() {
	Console::CursorVisible = false;
	Console::BackgroundColor = ConsoleColor::Blue;
	Console::SetWindowSize(1, 1);
	Console::SetBufferSize(150, 40);
	Console::SetWindowSize(150, 40); 
	Console::Clear(); 
}

//Funcion que define los arbustos
void Vegetacion(int animacion, int x, int y) {
	//Definiendo colores de la planta
	ConsoleColor ColorVerde = ConsoleColor::DarkGreen;
	ConsoleColor ColorRojo = ConsoleColor::DarkRed;
	//Animacion 1 (Neutro)
	if (animacion == 1) {
		Pintar(x, y, "  ", ColorVerde, ColorRojo);
		Pintar(x + 3, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 6, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 9, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 12, y, "  ", ColorVerde, ColorRojo);

		Pintar(x, y + 1, "* ", ColorVerde, ColorRojo);
		Pintar(x + 3, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 6, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 9, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 12, y + 1, " *", ColorVerde, ColorRojo);

		Pintar(x, y + 2, "    *  *  *   ", ColorVerde, ColorRojo);
		Pintar(x, y + 3, " *  *  *  *  *", ColorVerde, ColorRojo);
	}
	//Animacion 2 (derecha)
	if (animacion == 2) {
		Pintar(x + 1, y, "  ", ColorVerde, ColorRojo);
		Pintar(x + 4, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 7, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 10, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 13, y, "  ", ColorVerde, ColorRojo);

		Pintar(x, y + 1, "* ", ColorVerde, ColorRojo);
		Pintar(x + 3, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 6, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 9, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 12, y + 1, " *", ColorVerde, ColorRojo);

		Pintar(x, y + 2, "    *  *  *   ", ColorVerde, ColorRojo);
		Pintar(x, y + 3, " *  *  *  *  *", ColorVerde, ColorRojo);

	}
	//Animacion 3(derecha)
	if (animacion == 3) {
		Pintar(x + 4, y, "  ", ColorVerde, ColorRojo);
		Pintar(x + 7, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 9, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 13, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 16, y, "  ", ColorVerde, ColorRojo);

		Pintar(x + 2, y + 1, "* ", ColorVerde, ColorRojo);
		Pintar(x + 5, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 8, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 11, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 14, y + 1, " *", ColorVerde, ColorRojo);

		Pintar(x, y + 2, "    *  *  *   ", ColorVerde, ColorRojo);
		Pintar(x, y + 3, " *  *  *  *  *", ColorVerde, ColorRojo);


	}
	//Animacion 4 (Derecha)
	if (animacion == 4) {
		Pintar(x + 1, y, "  ", ColorVerde, ColorRojo);
		Pintar(x + 4, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 7, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 10, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 13, y, "  ", ColorVerde, ColorRojo);

		Pintar(x, y + 1, "* ", ColorVerde, ColorRojo);
		Pintar(x + 3, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 6, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 9, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 12, y + 1, " *", ColorVerde, ColorRojo);

		Pintar(x, y + 2, "    *  *  *   ", ColorVerde, ColorRojo);
		Pintar(x, y + 3, " *  *  *  *  *", ColorVerde, ColorRojo);

	}
	//Animacion 5 (neutro)
	if (animacion == 5) {
		Pintar(x, y, "  ", ColorVerde, ColorRojo);
		Pintar(x + 3, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 6, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 9, y, "* ", ColorVerde, ColorRojo);
		Pintar(x + 12, y, "  ", ColorVerde, ColorRojo);

		Pintar(x, y + 1, "* ", ColorVerde, ColorRojo);
		Pintar(x + 3, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 6, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 9, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 12, y + 1, " *", ColorVerde, ColorRojo);

		Pintar(x, y + 2, "    *  *  *   ", ColorVerde, ColorRojo);
		Pintar(x, y + 3, " *  *  *  *  *", ColorVerde, ColorRojo);

	}
	//Animacion 6 (izquierda)
	if (animacion == 6) {
		Pintar((x + 1) - 2, y, "  ", ColorVerde, ColorRojo);
		Pintar((x + 4) - 2, y, "* ", ColorVerde, ColorRojo);
		Pintar((x + 7) - 2, y, "* ", ColorVerde, ColorRojo);
		Pintar((x + 10) - 2, y, "* ", ColorVerde, ColorRojo);
		Pintar((x + 13) - 2, y, "  ", ColorVerde, ColorRojo);

		Pintar(x, y + 1, "* ", ColorVerde, ColorRojo);
		Pintar(x + 3, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 6, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 9, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 12, y + 1, " *", ColorVerde, ColorRojo);

		Pintar(x, y + 2, "    *  *  *   ", ColorVerde, ColorRojo);
		Pintar(x, y + 3, " *  *  *  *  *", ColorVerde, ColorRojo);

	}
	//Animacion 7 (izquierda)

	if (animacion == 7) {
		Pintar((x + 1) - 3, y, "  ", ColorVerde, ColorRojo);
		Pintar((x + 4) - 3, y, "* ", ColorVerde, ColorRojo);
		Pintar((x + 7) - 3, y, "* ", ColorVerde, ColorRojo);
		Pintar((x + 10) - 3, y, "* ", ColorVerde, ColorRojo);
		Pintar((x + 13) - 3, y, "  ", ColorVerde, ColorRojo);

		Pintar(x - 1, y + 1, "* ", ColorVerde, ColorRojo);
		Pintar((x + 3) - 1, y + 1, " *", ColorVerde, ColorRojo);
		Pintar((x + 6) - 1, y + 1, " *", ColorVerde, ColorRojo);
		Pintar((x + 9) - 1, y + 1, " *", ColorVerde, ColorRojo);
		Pintar((x + 12) - 1, y + 1, " *", ColorVerde, ColorRojo);

		Pintar(x, y + 2, "    *  *  *   ", ColorVerde, ColorRojo);
		Pintar(x, y + 3, " *  *  *  *  *", ColorVerde, ColorRojo);


	}
	//Animacion 8 (izquierda)

	if (animacion == 8) {
		Pintar((x + 1) - 2, y, "  ", ColorVerde, ColorRojo);
		Pintar((x + 4) - 2, y, "* ", ColorVerde, ColorRojo);
		Pintar((x + 7) - 2, y, "* ", ColorVerde, ColorRojo);
		Pintar((x + 10) - 2, y, "* ", ColorVerde, ColorRojo);
		Pintar((x + 13) - 2, y, "  ", ColorVerde, ColorRojo);

		Pintar(x, y + 1, "* ", ColorVerde, ColorRojo);
		Pintar(x + 3, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 6, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 9, y + 1, " *", ColorVerde, ColorRojo);
		Pintar(x + 12, y + 1, " *", ColorVerde, ColorRojo);

		Pintar(x, y + 2, "    *  *  *   ", ColorVerde, ColorRojo);
		Pintar(x, y + 3, " *  *  *  *  *", ColorVerde, ColorRojo);

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
	try {
		Console::SetBufferSize(250, 50);

		Console::BackgroundColor = fondo;
		Console::ForegroundColor = ColorCaracteres;


		Console::SetCursorPosition(x, y);

		cout << caracter;
	}
	catch (...) {
		//Sexoooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
	}
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


//Sexoooooo
