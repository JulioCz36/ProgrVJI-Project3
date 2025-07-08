#pragma once
#include <SFML/Graphics.hpp>
#include "Texto.h"
#include "Audio.h"

using namespace sf;
using namespace std;

class CondicionFinal{

	// Fondo negro semitransparente
	RectangleShape fondoNegro;

	// texto muestra tiempo o estado, reinicio indica cómo reiniciar el juego
	Texto texto, reinicio;

	// Sonidos tic-tac,reinicio parpadeando,victoria, derrota
	Audio restart, win, over;

	// controlar el parpadeo
	float tiempoParpadeo = 0.f;
	// alternar visibilidad
	bool mostrarReinicio = false;

	bool reiniciar = false;
	// Guarda el valor anterior de mostrarReinicio
	bool mostrarReinicioAnterior = true;
	// tiempo desde que terminó la partida
	float tiempoDesdeFin = 0.f;

public:
	CondicionFinal(bool gano);
	// Actualiza el CondicionFinal cada frame
	void actualizar(float deltaTime);
	// Dibuja los textos del CondicionFinal en la ventana
	void dibujar(RenderWindow& w);
};

