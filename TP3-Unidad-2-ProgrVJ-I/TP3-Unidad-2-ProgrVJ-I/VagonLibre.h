#pragma once
#include <SFML/Graphics.hpp>
#include "Figura.h"

using namespace sf;
using namespace std;

class VagonLibre {
    Figura sprite; // Sprite del vagón libre

public:
    VagonLibre(Vector2f pos);

    // Dibuja el vagón 
    void dibujar(RenderWindow& w);

    // Devuelve la hitbox
    FloatRect verBounds();

    // Devuelve la posición
    Vector2f verPos();
};


