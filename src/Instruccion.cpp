#include "Instruccion.h"

// Precondición: la operación es PUSH
Instruccion::Instruccion(Operacion op, int v): _op(op), _val(v){}

// Precondición: la operación es ADD, SUB o MUL
Instruccion::Instruccion(Operacion op): _op(op){}

// Precondición: la operación es READ, WRITE, JUMP o JUMPZ
Instruccion::Instruccion(Operacion op, Id n): _op(op), _var(n){}

Operacion Instruccion::operacion() const{ return _op;}

// Precondición: la operación es PUSH
int Instruccion::valor(void) const{ return _val;}

// Precondición: la operación es READ, WRITE, JUMP o JUMPZ
Id Instruccion::nombre() const{ return _var;}
