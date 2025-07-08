#include "Partida.h"
#include <cstdlib> // rand()
#include <ctime>   // time()

Partida::Partida() {
	fondo.cargarImagen("assets/mundo/fondo.png");
    fondo.quePosition(400, 300);

    estacionSalida = new Estacion("assets/mundo/estacion1.png",Vector2f(100,145));
    estacionLlegada = new Estacion("assets/mundo/estacion2.png", Vector2f(700, 470));

    tren = new Tren(Vector2f(100, 198));

    //Insertamos la locomotora
    tren->Insertar(-1);
    //Insertamos 2 vagones
    tren->Insertar(rand() % 10);
    tren->Insertar(rand() % 10);

    generarVagones();
}
Partida::~Partida() {
    delete operaciones;
    delete estacionSalida;
    delete estacionLlegada;
    delete condicion;
    delete tren;
}

void Partida::actualizar(Juego& j) {
    float deltaTime = reloj.verReinicio();

    if (termino && condicion != nullptr) {
        condicion->actualizar(deltaTime);
    }
    else {

        trenYVagonesLibre(deltaTime);

        if (tren != nullptr && !pausarTren) {
            // Hitbox rapida (tendria que hacerlo en la clase Vagon)
            FloatRect trenBounds = tren->verBounds();
            hitbox = FloatRect(trenBounds.left, trenBounds.top, trenBounds.width / 2.f, trenBounds.height);
            if (tren->verificarSalidaPantalla()) {
                tren->reposicionar(82);
            }
            tren->actualizar(deltaTime);
        }else if (tren != nullptr && pausarTren) {
            tren->detenerSonido();
        }

        if (estacionLlegada->verBounds().intersects(hitbox) && tren->verPos().y == 526) {
            tren->detenerSonido();
            termino = true;
            condicion = new CondicionFinal(true);
        }
        else if (tren->TrenVacio()) {
            tren->detenerSonido();
            termino = true;
            condicion = new CondicionFinal(false);
        }
    }
}

void Partida::dibujar(RenderWindow& w){
	fondo.dibujar(w);
    if (estacionSalida != nullptr) {
        estacionSalida->dibujar(w);
    }
    for (int i = 0; i < 4; i++) {
        if (vagones[i] != nullptr) {
            vagones[i]->dibujar(w);
        }
    }


    if (tren != nullptr && estacionLlegada != nullptr) {
        if (tren->verPos().y < estacionLlegada->verPos().y) {
            // La locomotora está por arriba → primero tren, después estación llegada
            tren->dibujar(w);
            estacionLlegada->dibujar(w);
        }
        else {
            // La locomotora está más abajo → primero estación llegada, después tren
            estacionLlegada->dibujar(w);
            tren->dibujar(w);
        }
    }
    if (operaciones != nullptr) {
        operaciones->dibujar(w);
    }

    if (termino && condicion != nullptr) {
        condicion->dibujar(w);
    }
}
void Partida::procesoEventos(Juego& j, Event& event){
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::R && termino) {
		j.reiniciar();
	}
    //Recibe el resultado por el juegador y puedo eliminar si puso mal el numero
    if (operaciones != nullptr && escribiendoRespuesta && !termino) {
        if (event.text.unicode >= '0' && event.text.unicode <= '9') {
            int numero = event.text.unicode - '0';
            respuestaJugador = respuestaJugador * 10 + numero;
            operaciones->actualizarTextoRespuesta(respuestaJugador);
        }
        if (event.key.code == Keyboard::Return) {
            operaciones->verificarRespuesta(respuestaJugador);
            respuestaJugador = 0;

        }
        else if (event.key.code == Keyboard::BackSpace) {
            respuestaJugador /= 10;
            operaciones->actualizarTextoRespuesta(respuestaJugador);
        }
    }
}

void Partida::generarVagones(){
    for (int i = 0; i < 4; i++) {
        Vector2f pos;
        bool posValida = false;

        while (!posValida) {
            float x = 350 + static_cast<float>(rand()) / RAND_MAX * (750 - 400);
            int piso = rand() % 4;
            float y = 198 + piso * 82.f;

            pos = Vector2f(x, y);
            posValida = true;

            // Verificar distancia con los anteriores
            for (int j = 0; j < i; j++) {
                if (vagones[j] != nullptr) {
                    Vector2f posExistente = vagones[j]->verPos();
                    if (abs(posExistente.x - pos.x) < 144.f &&
                        posExistente.y == pos.y) { // mismo piso
                        posValida = false;
                        break;
                    }
                }
            }
        }

        vagones[i] = new VagonLibre(pos);
    }
}

void Partida::trenYVagonesLibre(float deltaTime){
       if (!escribiendoRespuesta) {
           for (int i = 0; i < 4; i++) {
               if (vagones[i] != nullptr && vagones[i]->verBounds().intersects(hitbox)) {
                  pausarTren = true;
                    operaciones = new PanelOperacion();
                    escribiendoRespuesta = true;
                    vagonActual = vagones[i];
                    break;
               }
           }
       }
        if (operaciones != nullptr) {
            operaciones->actualizar(deltaTime);

            if (operaciones->seGano() || operaciones->seTermino()) {
                if (operaciones->seGano()) {
                    tren->Insertar(operaciones->verResultado());
                    //tren->mostrarLista();
                }
                else {
                    tren->Borrar(tren->Ultimo());
                    //tren->mostrarLista();
                    respuestaJugador = 0;
                }

                // borrar vagonActual
                for (int i = 0; i < 4; i++) {
                    if (vagones[i] == vagonActual) {
                        delete vagones[i];
                        vagones[i] = nullptr;
                        break;
                    }
                }
                vagonActual = nullptr;

                pausarTren = false;
                escribiendoRespuesta = false;

                delete operaciones;
                operaciones = nullptr;

            }
        }
}








