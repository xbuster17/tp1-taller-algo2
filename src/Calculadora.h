#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__

#include <iostream>
#include <vector>
#include <map>

#include "Utiles.h"

#include "Programa.h"

class Calculadora {
public:
	Calculadora(Programa p);
	void asignarVariable(Id var, int val);
	void ejecutar(Id rutina);
	int valorVariable(Id variable) const;

private:
	std::map<Id, int> _vars;
	Programa _prog;
	std::vector<int> _stack;
};

#endif /*__CALCULADORA_H__*/

