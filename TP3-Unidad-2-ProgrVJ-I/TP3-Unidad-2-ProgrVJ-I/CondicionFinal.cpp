#include "CondicionFinal.h"

CondicionFinal::CondicionFinal(bool gano) {

	// Configurar texto principal

	win.cargar("assets/sonidos/win.wav");
	win.queVolumen(60);
	over.cargar("assets/sonidos/game-over.wav");
	over.queVolumen(60);

	if (gano) {
		texto.inicializar(65);
		texto.queColor(Color(0, 173, 17));
		texto.quePosicion(400, 300);
		texto.queTexto("< You win >");
		win.play();
	}else{
		texto.inicializar(55);
		texto.queColor(Color(170, 0, 20));
		texto.quePosicion(400, 300);
		texto.queTexto("} Game Over }");
		over.play();
	}

	// Configurar texto de reinicio
	reinicio.inicializar(18);
	reinicio.quePosicion(680,400);
	reinicio.queColor(Color::White);
	reinicio.queTexto("R to restart");

	restart.cargar("assets/sonidos/button-R.wav");
	restart.queVolumen(40);
}

void CondicionFinal::actualizar(float deltaTime) {
		// Esperar 2 segundos antes de comenzar el parpadeo del mensaje de reinicio
		tiempoDesdeFin += deltaTime;
		if (tiempoDesdeFin >= 2.f) {
			reiniciar = true;
			tiempoParpadeo += deltaTime;

			// Alternar visibilidad del mensaje de reinicio cada 0.5 segundos
			if (tiempoParpadeo >= 0.5f) {
				mostrarReinicioAnterior = mostrarReinicio;
				mostrarReinicio = !mostrarReinicio;
				tiempoParpadeo = 0.f;

				// Reproducir sonido solo al aparecer el mensaje
				if (!mostrarReinicioAnterior && mostrarReinicio) {
					restart.play();
				}
			}
		}
}
void CondicionFinal::dibujar(RenderWindow& w) {
	fondoNegro.setSize(Vector2f(w.getSize()));
	fondoNegro.setFillColor(Color(0, 0, 0, 200));
	w.draw(fondoNegro);

	texto.dibujar(w);

	if (mostrarReinicio) {
		reinicio.dibujar(w);
	}
}

