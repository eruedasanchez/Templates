#include "gtest/gtest.h"
#include "../src/Templates.hpp"      // Se cambia Templates.cpp por Templates.hpp para poder correr los tests con cualquier clase
#include <string>

using namespace std;

TEST(Base, cuadrado) {
  EXPECT_EQ(cuadrado(5), 25);
  EXPECT_EQ(cuadrado(10), 100);
  EXPECT_EQ(cuadrado(1), 1);
}

TEST(Base, contiene) {
  EXPECT_TRUE(contiene(string("Hola todos"), 't'));
  EXPECT_TRUE(contiene(string("Hola todos"), 'H'));
  EXPECT_TRUE(contiene(string("Hola todos"), ' '));
  EXPECT_FALSE(contiene(string("Hola todos"), 'h'));
  EXPECT_TRUE(contiene(vector<int>({1, 5, 3, 2, 9}), 3));     // Agrego este test para probar con otro tipo
  EXPECT_FALSE(contiene(vector<int>({1, 5, 3, 2, 9}), 8));    // Agrego este test para probar con otro tipo
}

/**** Casos de tests ejercicio 1 y 2 funcionando correctamente :) ****/
