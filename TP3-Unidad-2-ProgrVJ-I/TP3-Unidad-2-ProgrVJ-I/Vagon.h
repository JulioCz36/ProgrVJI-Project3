#pragma once
#include <SFML/Graphics.hpp>
#include "Figura.h"
#include "Texto.h"

using namespace sf;
using namespace std;

class Vagon {
    int nroEnVagon;          // N�mero del vag�n 
    Vagon* siguiente;        // Puntero al siguiente vag�n 
    Figura sprite;          // Imagen del vag�n o locomotora
    Texto numero;           // Texto que muestra el n�mero

public:
    Vagon(int nro, Vagon* sig = nullptr) : nroEnVagon(nro), siguiente(sig) {
        if (nro == -1) {
            // Si el n�mero es -1, se trata de la locomotora
            sprite.cargarImagen("assets/mundo/tren-vagones/locomotora.png");
        }
        else {
            sprite.cargarImagen("assets/mundo/tren-vagones/vagon.png");

            // Inicializamos el texto del n�mero que mostrar� el vag�n
            numero.inicializar(30);  
            numero.queColor(Color(255, 215, 0)); 
            numero.queTexto(to_string(nro));     
        }
    }
    ~Vagon() = default;

    // Dibuja el vag�n y su n�mero
    void dibujar(RenderWindow& w) {
        sprite.dibujar(w);
        numero.dibujar(w);
    };

    // Actualiza la posici�n del texto 
    void actualizar() {
        Vector2f posVagon = sprite.verPosition();
        numero.quePosicion(posVagon.x, posVagon.y);
    }

    // Declaramos a Tren como clase amiga 
    friend class Tren;
};

