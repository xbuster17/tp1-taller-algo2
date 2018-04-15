#include "Programa.h"
// Agrega una instrucción a la rutina indicada.
// Si la rutina indicada no existe, crea una nueva rutina
// con dicho nombre.
void Programa::agregarInstruccion(Id idRutina, Instruccion instruccion){
	_rutinas[idRutina].push_back(instruccion);
}

// Devuelve True si idRutina representa una rutina existente.
bool Programa::esRutinaExistente(Id idRutina) const{
	return _rutinas.count(idRutina);
}

// Devuelve la longitud (cantidad de instrucciones) de la rutina indicada.
// Precondición: esRutinaExistente(idRutina)
int Programa::longitud(Id idRutina) const{
	if (Programa::esRutinaExistente(idRutina)){
		return _rutinas.at(idRutina).size();
	}
	else return 0;
}

// Devuelve la i-ésima instrucción de la rutina indicada.
// Precondición:
//   esRutinaExistente(idRutina) && 0 <= i && i < longitud(idRutina)
Instruccion Programa::instruccion(Id idRutina, int i) const{
	return _rutinas.at(idRutina)[i];
}
