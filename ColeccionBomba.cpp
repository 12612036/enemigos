#include "ColeccionBomba.h"

CColeccionBomba::CColeccionBomba() {
	totalBombas = 1;
}

//int CColeccionBomba::getCantidadBombas() {
//    return bombas.size();  // Retorna el número total de bombas activas
//}


void CColeccionBomba::crearBomba(int x, int y) {
	if (bombas.size() < totalBombas) {
		CBomba* nuevaBomba = new CBomba(x, y);
		bombas.push_back(nuevaBomba);
	}
}

//void CColeccionBomba::dibujarBomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int jugadorX, int jugadorY, const CanchaArray& cancha) {
//	for (int i = 0; i < bombas.size(); i++) {
//		switch (bombas.at(i)->getEstado()) {
//		case EBomba::puesto:
//			bombas.at(i)->dibujar(g, bmpBomba, jugadorX, jugadorY, cancha);
//			bombas.at(i)->animar();
//			break;
//		case EBomba::explosion:
//			bombas.at(i)->dibujarExplosion(g, bmpExplosion, cancha);
//			bombas.at(i)->animarExplosion();
//			break;
//		case EBomba::explotado:
//			bombas.erase(bombas.begin() + i);
//			break;
//		}
//	}
//}
 void CColeccionBomba::dibujarBomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int jugadorX, int jugadorY, const CanchaArray& cancha) {
for (int i = 0; i < bombas.size(); ) { // No se incrementa i automáticamente
    switch (bombas[i]->getEstado()) {
    case EBomba::puesto:
        bombas[i]->dibujar(g, bmpBomba, jugadorX, jugadorY, cancha);
        bombas[i]->animar();
        break;
    case EBomba::explosion:
        bombas[i]->dibujarExplosion(g, bmpExplosion, cancha);
        bombas[i]->animarExplosion();
        break;
    case EBomba::explotado:
        delete bombas[i]; // Libera memoria antes de eliminar la referencia
        bombas.erase(bombas.begin() + i);
        continue; // Evita incrementar `i`, pues el tamaño de la lista cambió
    }
    i++; // Solo incrementar si no se eliminó una bomba
}
}



vector<CBomba*> CColeccionBomba::getBombas() {
	return bombas;
}
