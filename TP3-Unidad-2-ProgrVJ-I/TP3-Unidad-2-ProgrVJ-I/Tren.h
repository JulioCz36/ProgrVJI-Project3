#pragma once
#include <SFML/Graphics.hpp>
#include "Figura.h"
#include "Audio.h"

using namespace sf;
using namespace std;

#include "Vagon.h"

typedef Vagon* pnodo;

class Tren {
private:
    pnodo primero;        // Puntero al primer nodo de la lista (locomotora)
    pnodo actual;         // Puntero auxiliar usado para recorridos o inserciones

    float velocidadX = 220.f;   // Velocidad de desplazamiento 
    Vector2f posTren;     // Posición general del tren

    Audio avance;         // Sonido de avance
public:
    Tren(Vector2f pos);
    //libera memoria de los nodos
    ~Tren();

    // Valor del último nodo
    int Ultimo();

    // Inserta un nuevo nodo
    void Insertar(int v);

    // Ordena los nodos
    void ordenarNodos();

    // Borra el nodo vagón x valor
    void Borrar(int v);

    // Devuelve si el tren no tiene nodos
    bool TrenVacio();

    // Devuelve la cantidad total de nodos
    int obtenerCantidadVagones();

    // Dibuja todos los nodos 
    void dibujar(RenderWindow& w);

    // Actualiza posiciones, reproduce sonido
    void actualizar(float deltaTime);

    // Verifica salió de la pantalla
    bool verificarSalidaPantalla();

    // Muestra por consola los valores
    void mostrarLista();

    // Reposiciona el tren
    void reposicionar(float altoPaso);

    // Devuelve la posición 
    Vector2f verPos();

    // Devuelve la colisión del tren
    FloatRect verBounds();

    // Nueva posición del tren
    void quePos(Vector2f pos);

    // Detiene el sonido de avance
    void detenerSonido();

};

