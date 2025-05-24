#pragma once
#include "Items.h"
#include "Cancha.h"
#include <ctime>
using namespace System::Drawing;
class CHabilidad {
    int i;
    int j;

    int indiceX;
    int indiceY;

    int tipoHabilidad;
    bool ubicado;
    bool activo;        // Indica si la habilidad sigue activa
    bool visible;       // Nueva variable para controlar si la habilidad es visible
    time_t tiempoInicio; // Almacena el momento en que la habilidad se activa

public:
    CHabilidad();
    ~CHabilidad();

    void dibujar(Graphics^ g, Bitmap^ bmpHabilidad, const CanchaArray& cancha);
    void animar();
    void verificarDuracion(); // Nueva funci�n para controlar la duraci�n
    void mostrar(); // Nueva funci�n para hacer visible la habilidad cuando sea necesario
    bool esVisible() { return visible; } // Funci�n para verificar visibilidad
};

   