#pragma once
#include <SFML/Graphics.hpp>
#include "Figura.h"

using namespace sf;
using namespace std;

class Estacion {
    Figura sprite;   // Imagen o sprite que representa visualmente la estación

public:
    Estacion(const string& textura, Vector2f pos);

    // Dibuja la estación en la ventana indicada
    void dibujar(RenderWindow& w);

    // Detectar colisiones
    FloatRect verBounds();

    // Devuelve la posición actual del sprite en pantalla
    Vector2f verPos();
};

