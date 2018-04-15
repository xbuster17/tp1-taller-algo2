#ifndef __PROGRAMA_H__
#define __PROGRAMA_H__

#include <iostream>
#include <vector>
#include <string>

#include "Instruccion.h"

// La clase Programa sirve para representar una secuencia de instrucciones.
//
//     Programa programa;
//
//     programa.agregarInstruccion("A", Instruccion(OP_PUSH, 10));
//     programa.agregarInstruccion("A", Instruccion(OP_PUSH, 20));
//     programa.agregarInstruccion("A", Instruccion(OP_ADD));
//     programa.agregarInstruccion("A", Instruccion(OP_JUMP, "A"));
//
//     programa.agregarInstruccion("B", Instruccion(OP_PUSH, 30));
//     programa.agregarInstruccion("B", Instruccion(OP_WRITE, "x"));
//
// Corresponde a las siguientes rutinas:
//
//     --- A ---
//       push(10)
//       push(20)
//       add
//       jump(A)
//
//     --- B ---
//       push(30)
//       write(x)
typedef std::vector<Instruccion> rutina;

class Programa {
public:
	// Inicialmente no hay ninguna rutina.
	Programa(){}

	// Agrega una instrucción a la rutina indicada.
	// Si la rutina indicada no existe, crea una nueva rutina
	// con dicho nombre.
	void agregarInstruccion(Id idRutina, Instruccion instruccion);

	// Devuelve True si idRutina representa una rutina existente.
	bool esRutinaExistente(Id idRutina) const;

	// Devuelve la longitud (cantidad de instrucciones) de la rutina
	// indicada.
	int longitud(Id idRutina) const;
	// Precondición: esRutinaExistente(idRutina)

	// Devuelve la i-ésima instrucción de la rutina indicada.
	// Precondición:
	Instruccion instruccion(Id idRutina, int i) const;
	//   esRutinaExistente(idRutina) && 0 <= i && i < longitud(idRutina)
private:
	std::map<std::string, rutina> _rutinas;

};

#endif /*__PROGRAMA_H__*/

