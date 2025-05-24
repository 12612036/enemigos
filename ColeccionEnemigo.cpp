#include "ColeccionEnemigo.h"

vector<CEnemigo*> CColeccionEnemigo::getEnemigos() {
	return enemigos;
}

void CColeccionEnemigo::crearEnemigo() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	CEnemigo* enemigo = new CEnemigo();
	enemigos.push_back(enemigo);
}

void CColeccionEnemigo::dibujar(Graphics^ g, Bitmap^ bmpEnemigo, const CanchaArray& cancha) {
	for (int i = 0; i < enemigos.size(); i++) {
		enemigos.at(i)->dibujar(g, bmpEnemigo, cancha);
		enemigos.at(i)->animar();
	}
}