#pragma once
#include <SFML/Graphics.hpp>

#include "CondicionFinal.h"
#include "PanelOperacion.h"
#include "Figura.h"
#include "Reloj.h"
#include "Escenas.h"
#include "Estacion.h"
#include "Tren.h"
#include "VagonLibre.h"

using namespace sf;
using namespace std;

class Escena;

class Partida : public Escena {
	Figura fondo;             // Sprite que representa el fondo visual
	
	Reloj reloj;                    // Cron�metro para medir el deltaTime entre frames

	Estacion* estacionSalida = nullptr;   // Estaci�n de donde parte el tren
	Estacion* estacionLlegada = nullptr;  // Estaci�n de llegada del tren

	Tren* tren;                     // Tren que se mueve por la pantalla
	FloatRect hitbox;               // Rect�ngulo para detectar colisiones del tren con vagones o estaciones
	bool pausarTren = false;        // Flag para pausar el movimiento del tren

	VagonLibre* vagones[4];         // Array de punteros a los vagones libres en pantalla
	VagonLibre* vagonActual = nullptr;   // Vagon que est� actualmente seleccionado para responder

	PanelOperacion* operaciones = nullptr; // Panel que muestra la operaci�n al jugador
	int respuestaJugador = 0;              // Respuesta que el jugador va escribiendo
	bool escribiendoRespuesta = false;     // Flag que indica si el jugador est� respondiendo

	CondicionFinal* condicion = nullptr;   // Condici�n final: si gan� o perdi�
	bool termino = false;                  // Indica si la partida termin�

	// Actualiza la l�gica de tren y vagones libres cada frame
	void trenYVagonesLibre(float deltaTime);
	// Genera los vagones libres que aparecen para interactuar
	void generarVagones();
public:
	Partida();
	~Partida();

	// actualizaci�n de la escena.
	void actualizar(Juego& j) override;
	// Dibuja elementos visibles en pantalla.
	void dibujar(RenderWindow& w) override;
	// Procesa la entrada del jugador y eventos del sistema.
	void procesoEventos(Juego& j, Event& event) override;
};

