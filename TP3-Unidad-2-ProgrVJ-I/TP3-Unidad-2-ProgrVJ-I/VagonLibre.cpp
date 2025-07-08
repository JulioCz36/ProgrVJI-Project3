#include "VagonLibre.h"
VagonLibre::VagonLibre(Vector2f pos) {
    sprite.cargarImagen("assets/mundo/tren-vagones/vagon.png");
    sprite.quePosition(pos.x, pos.y);
}

void VagonLibre::dibujar(RenderWindow& w) {
    sprite.dibujar(w);
}

FloatRect VagonLibre::verBounds() {
    return sprite.verGlobalBounds();
}

Vector2f VagonLibre::verPos() {
    return sprite.verPosition();
}