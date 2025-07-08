#include "Estacion.h"

Estacion::Estacion(const string& textura, Vector2f pos) {
    sprite.cargarImagen(textura);
    sprite.quePosition(pos.x, pos.y);
}

void Estacion::dibujar(RenderWindow& w) {
    sprite.dibujar(w);
}

FloatRect Estacion::verBounds() {
    return sprite.verGlobalBounds();
}

Vector2f Estacion::verPos(){
    return sprite.verPosition();
}
