#include "Enemigo.h"
#include <cstdlib>  // Para usar rand()
#include <ctime>    // Para inicializar rand()
CEnemigo::CEnemigo() {
    x = 0;
    y = 0;
    dx = VELOCIDADENEMIGO;
    dy = VELOCIDADENEMIGO;
    indiceX = 0;
    indiceY = 18;
    ubicado = false;
    estado = EEstadoEnemigo::Vivo;
    tipoEnemigo = (rand() % 5) + 1;
    srand(time(nullptr)); // Inicializa el generador de números aleatorios
}

CEnemigo::~CEnemigo() {}
//modificacion del juego de que aparezca en diferentes partes
bool CEnemigo::buscarLugar(const CanchaArray& cancha, int& i, int& j) {
    for (int intentos = 0; intentos < 50; intentos++) { // Intentamos encontrar una posición varias veces
        i = rand() % FILAS;

        j = rand() % COLUMNAS;

        if (cancha[i][j]->getTipo() == EElementos::libre) {
            return true;
        }
    }
    return false;
}
void CEnemigo::dibujar(Graphics^ g, Bitmap^ bmpEnemigo, const CanchaArray& cancha) {
    int px, py;
    bool existe = buscarLugar(cancha, px, py);

    if (existe && !ubicado) {
        x = py * ANCHOIMAGEN;
        y = px * ALTOIMAGEN;
    }
    ubicado = true;
    
    Rectangle rectangulo = Rectangle(indiceX * ANCHOIMAGEN, indiceY * ALTOIMAGEN, ANCHOIMAGEN, ALTOIMAGEN);
    Rectangle zoom = Rectangle(x, y, ANCHOIMAGEN * 0.9, ALTOIMAGEN * 0.9);
    g->DrawImage(bmpEnemigo, zoom, rectangulo, GraphicsUnit::Pixel);

    x += dx;
    if ((cancha[y / ALTOIMAGEN][(x + ANCHOIMAGEN) / ANCHOIMAGEN]->getTipo() == EElementos::rrompible) ||
        (cancha[y / ALTOIMAGEN][(x + ANCHOIMAGEN) / ANCHOIMAGEN]->getTipo() == EElementos::paredes) ||
        (cancha[y / ALTOIMAGEN][(x - 5) / ANCHOIMAGEN]->getTipo() == EElementos::rrompible) ||
        (cancha[y / ALTOIMAGEN][(x - 5) / ANCHOIMAGEN]->getTipo() == EElementos::paredes)) {
        dx *= -1;
    }
};

void CEnemigo::animar() {
    if (indiceX >= 0 && indiceX < 5) {
        indiceX++;
    }
    if (indiceX == 5) {
        while (indiceX != 0) {
            indiceX--;
        }
    }
}
