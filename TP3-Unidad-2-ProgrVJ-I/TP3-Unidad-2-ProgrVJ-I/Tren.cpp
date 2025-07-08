#include "Tren.h"
#include <iostream>

Tren::Tren(Vector2f pos) : primero(nullptr), actual(nullptr), posTren(pos) {
    avance.cargar("assets/sonidos/tren_avanzando.wav");
    avance.quePitch(0.90f);
    avance.queVolumen(60);
}

Tren::~Tren() {
    pnodo aux;
    while (primero != nullptr) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}

bool Tren::TrenVacio() {
    return primero == nullptr;
}

int Tren::obtenerCantidadVagones() {
    int cont = 0;
    pnodo aux = primero;
    while (aux != nullptr) {
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}

void Tren::Insertar(int numeroVagon) {

    pnodo nuevo = new Vagon(numeroVagon);

    if (primero == nullptr) {
        primero = nuevo;
    }
    else {
        pnodo aux = primero;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void Tren::ordenarNodos() {
    if (primero == nullptr || primero->siguiente == nullptr) return;

    bool cambiado;

    do {
        cambiado = false;
        pnodo* actual = &primero; 

        while ((*actual)->siguiente != nullptr) {
            pnodo siguiente = (*actual)->siguiente;
            // Comparamos valores para ordenar de mayor a menor
            if ((*actual)->nroEnVagon > siguiente->nroEnVagon) {
                // Intercambiamos nodos
                (*actual)->siguiente = siguiente->siguiente;
                siguiente->siguiente = *actual;
                *actual = siguiente;
                cambiado = true;
            }
            else {
                actual = &((*actual)->siguiente);
            }
        }
    } while (cambiado);
}

void Tren::Borrar(int numeroVagon) {
    pnodo anterior = nullptr;
    pnodo aux = primero;

    while (aux != nullptr && aux->nroEnVagon != numeroVagon) {
        anterior = aux;
        aux = aux->siguiente;
    }

    if (aux == nullptr) return; // no encontrado

    if (anterior == nullptr) {
        primero = aux->siguiente;
    }
    else {
        anterior->siguiente = aux->siguiente;
    }

    delete aux;
}

int Tren::Ultimo() {
    if (primero == nullptr) return -1;

    pnodo aux = primero;
    while (aux->siguiente != nullptr) {
        aux = aux->siguiente;
    }
    return aux->nroEnVagon;
}


void Tren::actualizar(float deltaTime) {
    ordenarNodos();
    if (!avance.estaReproduciendo()) {
        avance.play();
    }
    float movimiento = velocidadX * deltaTime;

    pnodo aux = primero;
    float nextPosX = posTren.x + movimiento;
    while (aux != nullptr) {
        aux->sprite.quePosition(nextPosX, posTren.y);
        aux->actualizar();
        nextPosX -= aux->sprite.verGlobalBounds().width;
        aux = aux->siguiente;
    }
    posTren.x += movimiento;
}

void Tren::dibujar(RenderWindow& w) {
    pnodo aux = primero;
    while (aux != nullptr) {
        aux->dibujar(w);
        aux = aux->siguiente;
    }
}

bool Tren::verificarSalidaPantalla() {
    if (primero == nullptr) return false;

    pnodo ultimo = primero;
    while (ultimo->siguiente != nullptr) {
        ultimo = ultimo->siguiente;
    }

    float bordeDerechoUltimo = ultimo->sprite.verPosition().x - (ultimo->sprite.verGlobalBounds().width / 2.f);
    return bordeDerechoUltimo > 800.f;
}
void Tren::mostrarLista() {
    pnodo aux = primero;
    std::cout << "Vagones en el tren: ";
    while (aux != nullptr) {
        std::cout << aux->nroEnVagon << " ";
        aux = aux->siguiente;
    }
    std::cout << std::endl;
}


void Tren::reposicionar(float altoPaso) {
    if (primero != nullptr) {
        posTren.y += altoPaso;
        posTren.x = -40.f;

        pnodo aux = primero;
        float nextPosX = posTren.x;
        while (aux != nullptr) {
            aux->sprite.quePosition(nextPosX, posTren.y);
            aux->actualizar();
            nextPosX -= aux->sprite.verGlobalBounds().width;
            aux = aux->siguiente;
        }
    }
}
Vector2f Tren::verPos(){
    if (primero != nullptr)
        return primero->sprite.verPosition();
    return Vector2f(0, 0);
}
FloatRect Tren::verBounds(){
    if (primero != nullptr)
        return primero->sprite.verGlobalBounds();
    return FloatRect();
}
void Tren::quePos(Vector2f pos){
    if (primero != nullptr)
        primero->sprite.quePosition(pos.x, pos.y);
}

void Tren::detenerSonido() {
    avance.stop();
}





