#include "Fraction.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>

void testConstruction(){
  Fraction a(1, 2);
  Fraction b(5);
  Fraction c(2, 4);
  Fraction d(2, -4);

  assert(a == Fraction(1, 2));
  assert(b == Fraction(5));
  assert(c == Fraction(1, 2));
  assert(d == Fraction(-1, 2));
}

void testZeroDenominator(){
  bool thrown = false;

  try{
    Fraction invalid(3, 0);
  }
  catch(const std::invalid_argument&){
    thrown = true;
  }

  assert(thrown);
}

void testArithmetic(){
  assert(Fraction(1, 2) + Fraction(1, 3) == Fraction(5, 6));
  assert(Fraction(3, 4) - Fraction(1, 4) == Fraction(1, 2));
  assert(Fraction(2, 3) * Fraction(3, 5) == Fraction(2, 5));
  assert(Fraction(2, 3) / Fraction(4, 5) == Fraction(5, 6));
}

void testCompoundOperators(){
  Fraction a(1, 2);
  Fraction b(1, 3);

  a += b;
  assert(a == Fraction(5, 6));

  a -= b;
  assert(a == Fraction(1, 2));
}

void testComparison(){
  Fraction a(1, 2);
  Fraction b(2, 4);
  Fraction c(3, 4);

  assert(a == b);
  assert(a != c);
  assert(a < c);
  assert(a <= b);
  assert(c > a);
  assert(c >= a);
}

void testOutput(){
  std::ostringstream out;

  out << Fraction(3, 4);

  assert(out.str() == "3/4");
}

void testInput(){
  Fraction f(0, 1);
  std::istringstream valid("7/8");

  valid >> f;

  assert(valid);
  assert(f == Fraction(7, 8));
}

void testInvalidInput(){
  Fraction f(1, 2);
  std::istringstream invalid("3/0");

  invalid >> f;

  assert(!invalid);
  assert(f == Fraction(1, 2));
}

int main(){
  testConstruction();
  testZeroDenominator();
  testArithmetic();
  testCompoundOperators();
  testComparison();
  testOutput();
  testInput();
  testInvalidInput();

  std::cout << "All tests passed\n";

  return 0;
}
