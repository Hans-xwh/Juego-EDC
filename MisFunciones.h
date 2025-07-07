#pragma once

#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

/*======================================*/
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <chrono>  // Necesario para std::chrono
#include <thread>
/*======================================*/

/*======================================*/
using namespace std;
using namespace System;

//Para evitar colocar std:: cada vez que se emplea la liberia chrono
using namespace std::chrono;

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

//Para contar cuanto tiempo se tarda el jugador en completar el primer nivel
int cronometro = 0;

int contador_eliminados = 0;


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
int menu_matriz[FILAS][COLUMNAS] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,0,3,3,3,0,3,3,3,3,0,3,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,4,4,4,0,0,4,4,4,4,4,0,4,0,0,0,4,0,4,4,4,0,0,4,4,4,4,0,0,4,0,0,0,4,0,4,4,4,4,4,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,0,3,0,0,0,0,0,3,0,0,3,0,0,0,0,3,3,0,0,0,3,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,4,0,0,4,0,4,0,0,0,0,0,4,4,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,3,0,0,0,0,0,3,0,0,3,0,0,0,0,3,0,3,0,0,3,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,4,0,0,4,0,4,0,0,0,0,0,4,0,4,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,3,0,0,0,0,0,3,0,0,3,3,3,3,0,3,0,0,3,0,3,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,4,4,0,0,0,0,4,0,0,0,4,0,0,0,4,0,4,0,0,4,0,4,4,4,4,0,0,4,0,0,4,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,3,0,0,0,0,0,3,0,0,3,0,0,0,0,3,0,0,0,3,3,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,4,0,0,4,0,4,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,3,0,0,0,0,0,3,0,0,3,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,4,0,0,4,0,4,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,3,3,3,3,0,3,3,3,0,3,3,3,3,0,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,4,4,4,0,0,0,0,4,0,0,0,0,4,4,4,0,0,4,4,4,0,0,4,4,4,4,0,0,4,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0},
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },

//JUGAR
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,0,1,1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
/*======================================*/

int menu_dinamica[FILAS][COLUMNAS] = { 
{0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,4,4,4,1,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,5,5,5,0,0,5,5,5,0,0,5,5,0,0,5,5,5,0,0,0,0,5,0,0,0,0,5,5,0,0,0,0,5,0,0,0,0,5,5,0},
{0,0,0,0,0,0,0,0,0,0,0,4,4,1,1,1,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,5,0,0,5,0,0,5,0,0,5,0,0,5,0,5,0,0,5,0,0,5,0,5,0,0,5,0,0,5,0,0,5,0,5,0,0,5,0,0,5},
{0,0,0,0,0,0,0,0,0,0,0,4,1,4,1,4,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,5,0,0,5,0,0,5,0,0,0,5,0,0,0,5,0,0,5,0,5,0,0,0,5,0,5,0,0,5,0,5,0,0,0,5,0,5,0,0,5},
{0,0,0,0,0,0,0,0,0,0,0,4,4,4,1,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,5,0,0,5,0,0,5,0,0,0,0,5,0,0,5,0,0,5,0,5,5,5,5,5,0,5,5,5,0,0,5,5,5,5,5,0,5,5,5,0},
{0,0,0,0,0,0,0,0,0,0,0,4,4,4,1,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,5,0,0,5,0,0,5,0,0,0,0,0,5,0,5,5,5,0,0,5,0,0,0,5,0,5,0,0,5,0,5,0,0,0,5,0,5,0,0,5},
{0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,5,0,0,5,0,0,5,0,0,0,0,0,5,0,5,0,0,0,0,5,0,0,0,5,0,5,0,0,5,0,5,0,0,0,5,0,5,0,0,5},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,5,5,5,0,0,5,5,5,0,0,5,5,0,0,5,0,0,0,0,5,0,0,0,5,0,5,0,0,5,0,5,0,0,0,5,0,5,0,0,5},
{0,0,0,4,4,4,4,4,4,4,0,4,4,4,4,4,4,4,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,4,4,4,1,4,4,4,0,4,4,4,1,4,4,4,0,4,4,4,1,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,4,4,1,4,4,4,4,0,4,4,4,1,4,4,4,0,4,4,4,4,1,4,4,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,4,1,1,1,1,1,4,0,4,1,4,1,4,1,4,0,4,1,1,1,1,1,4,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,5,0,0,0,5,0,0,5,5,0,0,5,0,0,0,5,0,5,5,5,0,0,5,5,0},
{0,0,0,4,4,1,4,4,4,4,0,4,4,1,1,1,4,4,0,4,4,4,4,1,4,4,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,5,5,0,5,5,0,5,0,0,5,0,5,0,0,0,5,0,5,0,0,0,5,0,0,5},
{0,0,0,4,4,4,1,4,4,4,0,4,4,4,1,4,4,4,0,4,4,4,1,4,4,4,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,5,0,5,0,5,0,5,0,0,5,0,0,5,0,5,0,0,5,5,5,0,5,5,5,0},
{0,0,0,4,4,4,4,4,4,4,0,4,4,4,4,4,4,4,0,4,4,4,4,4,4,4,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,5,0,0,0,5,0,5,0,0,5,0,0,5,0,5,0,0,5,0,0,0,5,0,0,5},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,5,0,0,0,5,0,5,0,0,5,0,0,5,0,5,0,0,5,0,0,0,5,0,0,5},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,5,0,0,0,5,0,0,5,5,0,0,0,0,5,0,0,0,5,5,5,0,5,0,0,5},
{0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,4,4,1,1,1,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,4,4,1,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,4,4,1,1,1,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,4,4,1,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,4,4,1,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

/*======================================*/

int menu_creditos[FILAS][COLUMNAS] = { 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,4,0,0,4,0,0,0,4,0,0,0,4,0,0,0,0,4,0,0,4,4,4,0,0,0,0,0,4,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,0,4,4,4,4,4,0,4,4,4,4,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,4,0,0,4,0,0,4,0,4,0,0,4,4,0,0,0,4,0,4,0,0,0,4,0,0,0,0,4,0,0,0,0,0,4,0,0,4,0,4,0,0,4,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,4,0,0,4,0,4,0,0,0,4,0,4,0,4,0,0,4,0,4,4,0,0,0,0,0,0,0,4,0,0,0,0,0,4,0,4,0,0,0,4,0,4,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,4,4,4,4,0,4,4,4,4,4,0,4,0,0,4,0,4,0,0,0,4,0,0,0,0,0,0,4,0,0,4,0,0,4,0,4,4,4,4,4,0,4,0,0,0,0,0,0,4,0,0,0,4,4,4,4,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,4,0,0,4,0,4,0,0,0,4,0,4,0,0,0,4,4,0,0,0,0,4,4,0,0,0,0,4,0,4,0,4,0,4,0,4,0,0,0,4,0,4,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,4,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,4,0,0,4,0,4,0,0,0,4,0,4,0,0,0,0,4,0,0,0,0,0,4,0,0,0,0,4,4,0,0,0,4,4,0,4,0,0,0,4,0,4,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,4,0,0,4,0,4,0,0,0,4,0,4,0,0,0,0,4,0,0,4,4,4,0,0,0,0,0,4,0,0,0,0,0,4,0,4,0,0,0,4,0,4,4,4,4,0,0,0,4,0,0,0,4,4,4,4,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,4,0,0,0,0,4,0,0,0,4,0,0,0,4,4,4,4,4,0,4,4,4,4,4,0,0,0,4,0,0,0,0,4,4,4,0,0,0,0,0,4,4,4,4,4,0,0,0,4,0,0,0,4,0,4,4,4,4,4,0,4,0,0,0,4,0,4,0,0,0,4,0,4,4,4,4,4,0},
{0,0,4,4,0,0,4,4,0,0,4,0,4,0,0,0,0,4,0,0,0,0,0,4,0,0,0,0,4,0,4,0,0,4,0,0,0,4,0,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,4,0,0,0,4,0,0,0,4,0,0,0},
{0,0,4,0,4,4,0,4,0,4,0,0,0,4,0,0,0,4,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,4,4,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,4,0,0,0,4,0,0,0,4,0,0,0},
{0,0,4,0,0,0,0,4,0,4,4,4,4,4,0,0,0,4,0,0,0,0,0,4,0,0,0,4,4,4,4,4,0,0,0,4,0,0,0,0,0,0,4,0,4,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,4,4,4,4,0,4,0,0,0,4,0,0,0,4,0,0,0},
{0,0,4,0,0,0,0,4,0,4,0,0,0,4,0,0,0,4,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,0,4,4,0,0,0,0,4,0,0,4,4,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,4,0,0,0,4,0,0,0,4,0,0,0},
{0,0,4,0,0,0,0,4,0,4,0,0,0,4,0,0,0,4,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,0,0,4,0,0,0,0,4,0,0,0,4,4,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,4,0,4,0,0,0,4,0,0,0,4,0,0,0},
{0,0,4,0,0,0,0,4,0,4,0,0,0,4,0,0,0,4,0,0,0,4,4,4,4,4,0,4,0,0,0,4,0,0,4,4,4,0,0,0,0,0,4,4,4,4,4,0,4,0,4,4,4,4,4,0,4,4,4,4,4,0,4,0,0,0,4,0,4,4,4,4,4,0,4,4,4,4,4,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };


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
	case 3:
		Console::ForegroundColor = ConsoleColor::Green;
		break;
	case 4:
		Console::ForegroundColor = ConsoleColor::Yellow;
	default:
		break;
	case 5:
		Console::ForegroundColor = ConsoleColor::White;
		break;
	}
}

void Cursor(int x, int y) {
		Console::SetCursorPosition(x, y);
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

void MostrarCronometro(int segundos) {

	Console::BackgroundColor = ConsoleColor::Black;
	Console::ForegroundColor = ConsoleColor::White;

	// Posición donde quieres mostrar el cronómetro (ejemplo: esquina superior derecha)
	Cursor(130, 10);
	cout << "Cronometro: " << segundos << "s";
}


void loading() {
	Console::Clear();

	// Configuración inicial
	int barWidth = 50;  // Ancho de la barra de carga
	int barX = 50;      // Posición X centrada
	int barY = 20;      // Posición Y vertical

	// Dibujar marco de la barra de carga
	Console::ForegroundColor = ConsoleColor::White;
	Console::BackgroundColor = ConsoleColor::Black;
	Console::SetCursorPosition(barX - 2, barY - 1);
	cout << "CARGANDO JUEGO...";


	Console::SetCursorPosition(barX - 1, barY);
	cout << char(218); // Esquina superior izquierda (linea tipo esquina)

	for (int i = 0; i < barWidth; i++) {
		cout << char(196); // Línea horizontal (--)
	}
	cout << char(191); // Esquina superior derecha (linea tipo esquina)




	Console::SetCursorPosition(barX - 1, barY + 1);
	cout << char(179); // Línea vertical izquierda (|| en la izquierda)
	Console::SetCursorPosition(barX + barWidth, barY + 1);
	cout << char(179); // Línea vertical derecha (|| en la derecha)




	Console::SetCursorPosition(barX - 1, barY + 2);
	cout << char(192); // Esquina inferior izquierda (esquina izquierda abajo)

	for (int i = 0; i < barWidth; i++) {
		cout << char(196); // Línea horizontal abajo (---)
	}
	cout << char(217); // Esquina inferior derecha (esquina derecha abajo)


	// Animación de carga

	for (int progreso = 0; progreso <= barWidth; progreso++) {

		// Configurar color para la barra de progreso (fondo rojo)
		Console::BackgroundColor = ConsoleColor::Red;
		Console::ForegroundColor = ConsoleColor::Red;

		// Dibujar el progreso
		Console::SetCursorPosition(barX, barY + 1);
		for (int i = 0; i < progreso; i++) {
			cout << char(219); // Carácter de bloque sólido (ASCII 219)
		}

		// Mostrar porcentaje
		Console::ForegroundColor = ConsoleColor::White;
		Console::BackgroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(barX + barWidth + 3, barY + 1);
		cout << int((float)progreso / barWidth * 100) << "%";

		// Pequeña pausa para la animación
		Sleep(40); // 40ms entre cada incremento
	}

	// Mensaje final
	Console::SetCursorPosition(barX + 15, barY + 4);
	cout << "LISTO!";
	Sleep(100); // Esperar 100 milisengudos antes de continuar
}

void Dinamica() {
	Console::Clear();
	dibujar_mapa(menu_dinamica);
	Console::SetCursorPosition(40, 20);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "PRESIONA CUALQUIER TECLA PARA VOLVER AL MENU";
	_getch();
}

void Creditos() {
	Console::Clear();
	dibujar_mapa(menu_creditos);
	Console::ForegroundColor = ConsoleColor::White;

	Console::SetCursorPosition(90, 3);
	cout << "CODIGO DE ALUMNO: U202515004";

	Console::SetCursorPosition(90, 14);
	cout << "CODIGO DE ALUMNO: U202511404";

	
	Console::SetCursorPosition(50, 30);
	cout << "PRESIONA CUALQUIER TECLA PARA VOLVER AL MENU";
	_getch();
}



void IniciarJuego() {
	//VAMOS A COLOCAR UN MENU DE RECARGA DE UN PORCENTAJE 
	PlaySound(NULL, 0, 0); // Detener música del menú

	//Ejecuta la musica de loading
	PlaySound(TEXT("loading.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//Llama la funcion loading
	loading();

	PlaySound(NULL, 0, 0); // Detener música de loading

}

/*======================================*/
void seleccionar_opcion() {
	char tecla;
	//PARA QUE INGRESE EL NUMERO PARA SELECCIONAR UNA PARTE DEL MUNDO
	do
	{
		//SE LLAMA A LA FUNCION DE DIBUJAR VENTANA/MAPA
		dibujar_mapa(menu_matriz);
		tecla = _getch();
		if (tecla == '2')
		{
			Dinamica();
		}
		else if (tecla == '3')
		{
			Creditos();
		}
	} while (tecla != '1');
	IniciarJuego();
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
/* FUNCION DISPARAR BALA*/
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

/*======================================*/

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
			balaX = 148;	//evita colisiones accidentales con los enemigos -Hw
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

void Pajaro(int x, int y, int pregunta) {
	Console::BackgroundColor = ConsoleColor::DarkGreen;
	Console::ForegroundColor = ConsoleColor::DarkRed;
	Cursor(x + 5, y); cout << "/";
	Cursor(x + 4, y + 1); cout << "/";
	Cursor(x + 3, y + 2); cout << "//";
	Console::ForegroundColor = ConsoleColor::DarkRed;
	Cursor(x + 2, y + 3); cout << "<(o)";
	Console::ForegroundColor = ConsoleColor::DarkYellow;
	Cursor(x + 2, y + 4); cout << "(\\_\\\\";
	Cursor(x + 3, y + 5); cout << "(_\\_\\\\";
	Console::ForegroundColor = ConsoleColor::Black;
	Cursor(x + 4, y + 6); cout << "_|_";
	Console::BackgroundColor = ConsoleColor::DarkGray;
	Cursor(x, y + 7); cout << "               ";

	//Borrar pregunta
	Console::BackgroundColor = ConsoleColor::Blue;
	Cursor(x - 8, y - 5); cout << "                       ";
	Cursor(x - 8, y - 4); cout << "                       ";
	Cursor(x - 8, y - 3); cout << "                       ";
	Cursor(x - 8, y - 2); cout << "                       ";
	Console::BackgroundColor = ConsoleColor::DarkGray;
	

	if (pregunta == 1) {
		Cursor(x-2, y - 5);cout<<"Alli el cielo";
		Cursor(x - 8, y - 4); cout << "siempre esta nublado...";
		Cursor(x - 2, y - 3); cout << "pero el ceviche"; 
		Cursor(x - 2, y - 2); cout << "siempre brilla.";
	}
	if (pregunta == 2) {
		Cursor(x - 7, y - 5); cout << "En Peru y Argentina lo";
		Cursor(x - 6, y - 4); cout << "recuerdan con honor";
		Cursor(x - 2, y - 3); cout << ",fue general y";
		Cursor(x - 2, y - 2); cout << "libertador";
	}
	if (pregunta == 3) {

		Cursor(x - 3, y - 3); cout << " Es el doble";
		Cursor(x + 1, y - 2); cout << "de 28";
		
	}
	if (pregunta == 4) {
		Cursor(x - 7, y - 5); cout << "Su nombre empieza ";
		Cursor(x - 6, y - 4); cout << " como 'Aventura'";
		Cursor(x - 5, y - 3); cout << "y cruza la mitad de";
		Cursor(x - 2, y - 2); cout << " Sudamerica.";
	}
	if (pregunta == 5) {
		Cursor(x -1, y - 3); cout << "¿Matematica?";
	}
	if (pregunta == 6) {
		Cursor(x - 6, y - 5); cout << "El termina en 21...";
		Cursor(x - 6, y - 4); cout << "y esta muy cerca del";
		Cursor(x - 7, y - 3); cout << "inicio de la decada de ";
		Cursor(x - 2, y - 2); cout << "los 20";
	}
}

void Pantalla_perder() {
	Console::ForegroundColor = ConsoleColor::Green;
	Cursor(50, 1);
	cout << "HAS PERDIDO, LOS ALIENS GANAN";
	
	Cursor(20, 10); cout << "                                           :========:                                              ";
	Cursor(20, 11); cout << "                                        ..:::-########-:::..                                        ";
	Cursor(20, 12); cout << "                                      ...=####++++====*###=...                                      ";
	Cursor(20, 13); cout << "                                     ..*%#++++++==========*#+...                                    ";
	Cursor(20, 14); cout << "                                  ...*%*++++++==============+#*...                                  ";
	Cursor(20, 15); cout << "                                  .#%*+++++===================+#*.                                  ";
	Cursor(20, 16); cout << "                                  .#%*+++++===================+#*.                                  ";
	Cursor(20, 17); cout << "                                .++**+++++++===================+++=.                                ";
	Cursor(20, 18); cout << "                                .#%*+*******++========+++++++++==#*. ..                             ";
	Cursor(20, 19); cout << "                                .#%*+%@@@@@%++++====++++%@@@@@%==#*.                                ";
	Cursor(20, 20); cout << "                                .#%*+%@@@+.=@%========%@@@+.=@%==#*.                                ";
	Cursor(20, 21); cout << "                                .#%*+%@@@@@@@@@@====@@@@@@@@@@%==#*. ..                             ";
	Cursor(20, 22); cout << "                               ....#%*+%@@@@@@@@====@@@@@@@@#=+#*.....                              ";
	Cursor(20, 23); cout << "                                  .#%*+%@@@@@@@@====@@@@@@@@#=+#*.. ..                              ";
	Cursor(20, 24); cout << "                                  .#%*+**%@@@@@@====@@@@@@#*+=+#*.                                  ";
	Cursor(20, 25); cout << "                                  .+***++*######====######+==+++=.                                  ";
	Cursor(20, 26); cout << "                                    .*%*+===================+#*.                                    ";
	Cursor(20, 27); cout << "                                    .*%*+===================+#*.                                    ";
	Cursor(20, 28); cout << "                                     ..*%#+==+@@@@@@@@+==+*#+..                                     ";
	Cursor(20, 29); cout << "                                      ...+%#++==========#%+...                                      ";
	Cursor(20, 30); cout << "                                         ..=%#++======#%=..                                         ";
	Cursor(20, 31); cout << "                                          ..:=%%######=:..                                          ";
	Cursor(20, 32); cout << "                                             :++++++++:.                                            ";

	
	Sleep(5000);
	Console::Clear();
}
#endif
