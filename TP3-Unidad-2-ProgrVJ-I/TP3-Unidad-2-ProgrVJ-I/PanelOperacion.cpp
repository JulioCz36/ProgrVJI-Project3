#include "PanelOperacion.h"
#include <iostream>

PanelOperacion::PanelOperacion() {

	int a = rand() % 10;
	int b = rand() % 10;
	int c = rand() % 10;
	resultado = a + b + c;

	operacion.inicializar(25);
	operacion.quePosicion(400, 310);
	operacionBase = to_string(a) + " + " + to_string(b) + " + " + to_string(c);
	operacion.queTexto(operacionBase + " = ?");

	cartel.cargarImagen("assets/mundo/operacion/cartel.png");
	cartel.quePosition(400,300);

	s_reloj.cargarImagen("assets/mundo/operacion/reloj.png");
	s_reloj.queEscala(0.3, 0.3);
	s_reloj.quePosition(cartel.verPosition().x - 170, cartel.verPosition().y - cartel.verGlobalBounds().height / 2);

	aguja.cargarImagen("assets/mundo/operacion/aguja.png");
	aguja.queEscala(0.3, 0.3);
	aguja.queOrigin(16.f / 2.f, 74.f);
	aguja.quePosition(s_reloj.verPosition().x , s_reloj.verPosition().y + 15);

	c_reloj.cargarImagen("assets/mundo/operacion/centro_aguja.png");
	c_reloj.queEscala(0.3, 0.3);
	c_reloj.quePosition(s_reloj.verPosition().x, s_reloj.verPosition().y + 16);

	reloj.cargar("assets/sonidos/tic-tac.wav");
	reloj.quePitch(0.28f);
	reloj.queVolumen(80);

	correcto.cargar("assets/sonidos/correcto.wav");
	correcto.queVolumen(60);

	incorrecto.cargar("assets/sonidos/incorrecto.wav");
	incorrecto.queVolumen(60);
}

void PanelOperacion::actualizar(float deltaTime) {
	if (esperandoSonido) {
		reloj.stop();
		if (esCorrecto && !correcto.estaReproduciendo()) {
			gano = true;
			esperandoSonido = false;
		}
		else if (!esCorrecto && !incorrecto.estaReproduciendo()) {
			terminado = true;
			esperandoSonido = false;
		}
	}else if (!(terminado || gano)) {
		// Si no se está reproduciendo el reloj, arrancarlo
		if (!reloj.estaReproduciendo()) {
			reloj.play();
		}

		// Reducir tiempo restante
		tiempoRestante -= deltaTime;
		if (tiempoRestante <= 0.f) {
			tiempoRestante = 0.f;
			// Se acabó el tiempo → reproducir incorrecto
			incorrecto.play();
			esperandoSonido = true;
			esCorrecto = false;
		}
	}

	// Actualizar rotación de la aguja siempre
	float porcentaje = tiempoRestante / 6.f;
	float angulo = porcentaje * -360.f ;
	aguja.queRotation(angulo);
}
void PanelOperacion::dibujar(RenderWindow& w) {
	fondoNegro.setSize(Vector2f(w.getSize()));
	fondoNegro.setFillColor(Color(0, 0, 0, 200));
	w.draw(fondoNegro);

	cartel.dibujar(w);
	operacion.dibujar(w);

	s_reloj.dibujar(w);
	aguja.dibujar(w);
	c_reloj.dibujar(w);
}

void PanelOperacion::verificarRespuesta(int respuestaJugador) {
	if (!esperandoSonido) { 
		if (respuestaJugador == resultado) {
			correcto.play();
			esperandoSonido = true;
			esCorrecto = true;
		}
		else {
			incorrecto.play();
			esperandoSonido = true;
			esCorrecto = false;
		}
	}
}
void PanelOperacion::actualizarTextoRespuesta(int respuestaJugador) {
	operacion.queTexto(operacionBase + " = " + to_string(respuestaJugador));
}
int PanelOperacion::verResultado() {
	return resultado;
}


bool PanelOperacion::seTermino() {
	return terminado;
}
bool PanelOperacion::seGano() {
	return gano;
}

