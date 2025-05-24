#include "Controladora.h"
#include "Jugador.h"

CControladora::CControladora() {
	cancha = new CCancha();
	jugador = new CJugador(ANCHOIMAGEN, ALTOIMAGEN);
	bombas = new CColeccionBomba();
	habilidades = new CColeccionHabilidad();
	enemigos = new CColeccionEnemigo();
	nivel = 3;
}

int CControladora::getNivel() {
	return nivel;
}

void CControladora::inicializar() {
	cancha->Inicializar();
}

void CControladora::Dibujar() {
	cancha->Inicializar();
};
void CControladora::dibujarCancha(Graphics^ g, Bitmap^ bmpPiso, Bitmap^ bmpIrrompible, Bitmap^ bmpRrompible, Bitmap^ bmpHabilidad) {
	cancha->PintarCancha(g, bmpPiso);
	cancha->PintarMatriz(g, bmpIrrompible, bmpRrompible);
	habilidades->dibujar(g, bmpHabilidad, cancha->getCancha());	
};

void CControladora::dibujarJugador(Graphics^ g, Bitmap^ bmpJugador) {
	jugador->dibujar(g, bmpJugador, cancha->getCancha());
}

void CControladora::adicionarBomba() {
	bombas->crearBomba(jugador->getX(), jugador->getY());
}

void CControladora::moverJugador(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, Bitmap^ bmpEnemigo) {
	bombas->dibujarBomba(g, bmpBomba, bmpExplosion, jugador->getX(), jugador->getY(), cancha->getCancha());
	jugador->mover(g, bmpJugador, cancha->getCancha());
	enemigos->dibujar(g, bmpEnemigo, cancha->getCancha());
}

CJugador* CControladora::getJugador() {
	return jugador;
}

void CControladora::crearHabilidades() {
	while (habilidades->getHabilidades().size() < nivel) {
	  habilidades->crearHabilidad();
	}
}

void CControladora::crearEnemigos() {
	while (enemigos->getEnemigos().size() < nivel) {
		enemigos->crearEnemigo();
	}
}

CColeccionHabilidad* CControladora::getColeccionHabilidades() {
	return habilidades;
}

CColeccionEnemigo* CControladora::getColeccionEnemigos() {
	return enemigos;
}
