#pragma once
#include <SFML/Graphics.hpp>
#include "Escenas.h"
using namespace sf;
using namespace std;
class Escena;

// Clase principal que maneja la ventana, la escena actual y el ciclo general del juego.
class Juego{
	RenderWindow w;         // Ventana principal del juego
	Escena* actual;         // escena actual en ejecuci�n
	Escena* prox = nullptr; // pr�xima escena a cargar

	// Actualiza la l�gica de la escena.
	void actualizar();

	// Dibuja todos los elementos de la escena.
	void dibujar();

	// Procesa los eventos teclado y los pasa a la escena.
	void procesoEventos();

	// Cambia la escena actual por una nueva
	void cambiarScena(Escena* scena_nueva);

public:
	Juego();
	~Juego();
	// bucle principal del juego: procesa eventos, actualiza l�gica y dibuja.
	void jugar();

	// Reinicia el juego.
	void reiniciar();
};

