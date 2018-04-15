#include "Calculadora.h"

Calculadora::Calculadora(Programa p): _prog(p){}

void Calculadora::asignarVariable(Id var, int val){
	_vars[var] = val;
}

int Calculadora::valorVariable(Id var) const{
	if(_vars.count(var)){
		return _vars.at(var);
	} else return 0;
}

#define _OPERAR(a,b,res,len,_stack, func){\
	a=0, b=0, res=0;                      \
	if(slen > 0){                         \
		a = _stack[slen - 1];             \
		_stack.pop_back();                \
		if(slen > 1){                     \
			b = _stack[slen - 2];         \
			_stack.pop_back();            \
		}                                 \
	}                                     \
	res = b func a;                       \
	_stack.push_back(res);                \
}

void Calculadora::ejecutar(Id rutina){
	Id r = rutina;

	for(int i = 0; i < _prog.longitud(r); i++){
		if(!_prog.esRutinaExistente(r)) return;
		// Instruccion instr = _prog.instruccion(rutina, i);
		Instruccion instr = _prog.instruccion(r, i);
		Operacion op = instr.operacion();
		int slen = _stack.size();
		int a=0, b=0, res=0;
		switch(op){
			case PUSH: _stack.push_back(instr.valor()); break;
			case ADD: _OPERAR(a,b,res,slen,_stack, +); break;
			case SUB: _OPERAR(a,b,res,slen,_stack, -); break;
			case MUL: _OPERAR(a,b,res,slen,_stack, *); break;
			case WRITE: _vars[instr.nombre()] = slen > 0 ? _stack[slen-1] : 0 ; _stack.pop_back(); break;
			case READ: _stack.push_back(_vars.count(instr.nombre()) ? _vars.at(instr.nombre()) : 0); break;
			case JUMPZ: if(!(slen == 0 || _stack[slen-1] == 0)){break;} // if !0 continue to JUMP
			case JUMP: r = instr.nombre(); i=-1; _stack.clear(); break;
			default: break;
		}
	}
}
