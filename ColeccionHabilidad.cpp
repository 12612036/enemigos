#include "ColeccionHabilidad.h"
#include <thread>
#include <chrono>

vector<CHabilidad*> CColeccionHabilidad::getHabilidades() {
	return habilidades;
}

void CColeccionHabilidad::crearHabilidad() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	CHabilidad* habilidad = new CHabilidad();
	habilidades.push_back(habilidad);
}

void CColeccionHabilidad::dibujar(Graphics^ g, Bitmap^ bmpHabilidad, const CanchaArray& cancha) {
	for (int i = 0; i < habilidades.size(); i++) {
		habilidades.at(i)->dibujar(g, bmpHabilidad, cancha);
		habilidades.at(i)->animar();
		for (auto& habilidad : habilidades) { // Iteración optimizada
			if (habilidad->esVisible()) {  // Solo dibuja si la habilidad es visible

			}
		}
	}

}