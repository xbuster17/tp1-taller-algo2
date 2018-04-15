#include "gtest/gtest.h"

#include "../src/Instruccion.h"
#include "../src/Programa.h"
#include "../src/Calculadora.h"


TEST(test_calculadora, suma) {
    Programa p;
    p.agregarInstruccion("a", Instruccion(PUSH, 10));
    p.agregarInstruccion("a", Instruccion(PUSH, 20));
    p.agregarInstruccion("a", Instruccion(ADD));
    p.agregarInstruccion("a", Instruccion(WRITE, "z"));

    Calculadora c(p);
    c.ejecutar("a");
    EXPECT_EQ(c.valorVariable("z") == 30, true);
}


TEST(test_calculadora, resta) {
    Programa p;
    p.agregarInstruccion("a", Instruccion(PUSH, 10));
    p.agregarInstruccion("a", Instruccion(PUSH, 20));
    p.agregarInstruccion("a", Instruccion(SUB));
    p.agregarInstruccion("a", Instruccion(WRITE, "z"));

    Calculadora c(p);
    c.ejecutar("a");
    EXPECT_EQ(c.valorVariable("z") == -10, true);
}


TEST(test_calculadora, mult) {
    Programa p;
    p.agregarInstruccion("a", Instruccion(PUSH, 10));
    p.agregarInstruccion("a", Instruccion(PUSH, 20));
    p.agregarInstruccion("a", Instruccion(MUL));
    p.agregarInstruccion("a", Instruccion(WRITE, "z"));

    Calculadora c(p);
    c.ejecutar("a");
    EXPECT_EQ(c.valorVariable("z") == 200, true);
}


TEST(test_calculadora, read_write) {
    Programa p;
    p.agregarInstruccion("A", Instruccion(READ, "n"));
    p.agregarInstruccion("A", Instruccion(WRITE, "m"));

    Calculadora c(p);
    c.asignarVariable("n", 10);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("n") == 10, true);
    EXPECT_EQ(c.valorVariable("m") == 10, true);
}


TEST(test_calculadora, rwjumpz) {
    Programa p;
    p.agregarInstruccion("FIN", Instruccion(PUSH, 10));
    p.agregarInstruccion("FIN", Instruccion(WRITE, "m"));
    p.agregarInstruccion("A", Instruccion(READ, "n"));
    p.agregarInstruccion("A", Instruccion(PUSH, 1));
    p.agregarInstruccion("A", Instruccion(SUB));
    p.agregarInstruccion("A", Instruccion(WRITE, "n"));
    p.agregarInstruccion("A", Instruccion(READ, "n"));
    p.agregarInstruccion("A", Instruccion(JUMPZ, "FIN"));
    p.agregarInstruccion("A", Instruccion(JUMP, "A"));

    Calculadora c(p);
    c.asignarVariable("n", 10);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("n") == 0, true);
    EXPECT_EQ(c.valorVariable("m") == 10, true);
}


TEST(test_calculadora, ejemplo) {
    Programa p;
    p.agregarInstruccion("MAIN", Instruccion(READ, "x"));
    p.agregarInstruccion("MAIN", Instruccion(PUSH, 2));
    p.agregarInstruccion("MAIN", Instruccion(ADD));
    p.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c(p);
    c.asignarVariable("x", 38);
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x") == 40, true);
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x") == 42, true);
}


TEST(test_calculadora, write0) {
    Programa p;
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    Calculadora c(p);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x") == 0, true);
}


TEST(test_calculadora, run0) {
    Programa p;
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    Calculadora c(p);
    c.asignarVariable("x", 555);
    c.ejecutar("VACIO");
    EXPECT_EQ(c.valorVariable("x") == 555, true);
}

