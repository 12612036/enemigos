#pragma once
#include <vector>
#include <thread>
#include <chrono>
#include "Enemigo.h"

using namespace std;

class CColeccionEnemigo {
	vector<CEnemigo*> enemigos;

public:
	vector<CEnemigo*> getEnemigos();	
	void crearEnemigo();	
	void dibujar(Graphics^ g, Bitmap^ bmpEnemigo, const CanchaArray& cancha);
};
