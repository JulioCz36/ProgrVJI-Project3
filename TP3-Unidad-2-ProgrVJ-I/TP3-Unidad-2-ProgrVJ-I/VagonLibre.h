#pragma once
#include <SFML/Graphics.hpp>
#include "Figura.h"

using namespace sf;
using namespace std;

class VagonLibre {
    Figura sprite; // Sprite del vag�n libre

public:
    VagonLibre(Vector2f pos);

    // Dibuja el vag�n 
    void dibujar(RenderWindow& w);

    // Devuelve la hitbox
    FloatRect verBounds();

    // Devuelve la posici�n
    Vector2f verPos();
};


