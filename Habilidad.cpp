#pragma once
#include <ctime>
#include <stdlib.h>
#include "Habilidad.h"

CHabilidad::CHabilidad() {
    srand(time(NULL));
    ubicado = false;
    i = rand() % (FILAS - 2) + 1;
    j = rand() % (COLUMNAS - 2) + 1;
    indiceX = 0;
    indiceY = 0;
    tipoHabilidad = (rand() % 5) + 1;
    tiempoInicio = time(NULL); // Guardar el tiempo de inicio
    activo = true; // Habilidad activa inicialmente
    visible = false; // Habilidad empieza oculta
}
CHabilidad::~CHabilidad() {}

void CHabilidad::dibujar(Graphics^ g, Bitmap^ bmpHabilidad, const CanchaArray& cancha) {
if (!activo || !visible) return; // No dibujar si la habilidad ha expirado o está oculta

    Rectangle rectangulo = Rectangle(indiceX * ANCHOIMAGEN, indiceY * ALTOIMAGEN, ANCHOIMAGEN, ALTOIMAGEN);
    while (!ubicado) {
        if (cancha[i][j]->getTipo() == EElementos::rrompible) {
            ubicado = true;
        }
        else {
            if (j < COLUMNAS) {
                i++;
                if (i == (FILAS - 1)) {
                    i = 0;
                    j++;
                }
            }
        }
    }

    Rectangle zoom = Rectangle(j * ANCHOIMAGEN, i * ALTOIMAGEN, ANCHOIMAGEN, ALTOIMAGEN);
    g->DrawImage(bmpHabilidad, zoom, rectangulo, GraphicsUnit::Pixel);
}

void CHabilidad::animar() {
    if (!activo) return; // No animar si la habilidad ha expirado

    switch (tipoHabilidad) {
    case 1: indiceX = EHabilidades::bomba; break;
    case 2: indiceX = EHabilidades::fuego; break;
    case 3: indiceX = EHabilidades::quitaVida; break;
    case 4: indiceX = EHabilidades::velocidad; break;
    case 5: indiceX = EHabilidades::vida; break;
    }

    indiceY = (indiceY + 1) % 2; // Animación sencilla

    verificarDuracion(); // Comprobar si la habilidad debe desactivarse
}
//funcion para controlar la visibilidad de los habilidades
void CHabilidad::mostrar() {
    visible = true;
}
void CHabilidad::verificarDuracion() {
    if (difftime(time(NULL), tiempoInicio) >= 10) {
        activo = false; // Desactivar la habilidad después de 10 segundos
    }
}
