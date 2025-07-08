#include "Juego.h"

int main() {
	srand(static_cast<unsigned>(time(0)));

	Juego juego;

	juego.jugar();

	return 0;
}