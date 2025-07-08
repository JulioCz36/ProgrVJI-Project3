#pragma once
#include <SFML/Graphics.hpp>
#include "Texto.h"
#include "Figura.h"
#include "Audio.h"

using namespace sf;
using namespace std;

class PanelOperacion{
	// Fondo negro semitransparente
	RectangleShape fondoNegro;

	// Elementos gráficos del panel: cartel y partes del reloj (esfera, centro y aguja)
	Figura cartel, s_reloj, c_reloj, aguja;

	// texto muestra la operacion a realizar
	Texto operacion;
	string operacionBase;

	// Sonidos
	Audio reloj, correcto,incorrecto;
	// Indica si estamos esperando a que termine de reproducirse un sonido
	bool esperandoSonido = false;
	// True si el sonido que se está reproduciendo es el de respuesta correcta
	bool esCorrecto = false;

	// Tiempo restante de la pregunta
	float tiempoRestante = 5.f;

	// Resultado correcto de la operación
	int resultado = 0;

	// Indica si se acabó el tiempo
	bool terminado = false;

	// jugador respondio bien
	bool gano = false;

public:
	PanelOperacion();
	// Actualiza el Panel cada frame
	void actualizar(float deltaTime);
	// Dibuja los textos del Panel en la ventana
	void dibujar(RenderWindow& w);

	// Comprueba si la respuesta del jugador 
	void verificarRespuesta(int respuestaJugador);

	// Actualiza el texto
	void actualizarTextoRespuesta(int respuestaJugador);

	// Devuelve el resultado
	int verResultado();

	// Devuelve si el tiempo se terminó o el jugador falló
	bool seTermino();
	// Devuelve si se gano la pregunta
	bool seGano();
};

