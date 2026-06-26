#include "Fraction.h"

#include <iostream>
#include <numeric>
#include <stdexcept>

Fraction::Fraction(int numerator, int denominator)
  : numerator(numerator), denominator(denominator) {
  if(denominator == 0)
    throw std::invalid_argument("denominator cannot be zero");

  normalize();
}

Fraction::Fraction(int numerator)
  : Fraction(numerator, 1) {
}

int Fraction::num() const {
  return numerator;
}

int Fraction::den() const {
  return denominator;
}

void Fraction::normalize(){

	if(denominator < 0){
		numerator = -1 * numerator;
		denominator = -1 * denominator;
	}
	int mcd = std::gcd(numerator, denominator);
	numerator = numerator / mcd;
	denominator = denominator / mcd;
}

Fraction& Fraction::operator+=(const Fraction& other){
  // TODO: implementar suma compuesta.
  (void)other;
	numerator	= numerator * other.den() + other.num() * denominator;
	denominator = denominator * other.den();
	normalize();
  return *this;
}

Fraction& Fraction::operator-=(const Fraction& other){
  // TODO: implementar resta compuesta.
  (void)other;
	numerator = numerator * other.den() - other.num() * denominator;
	denominator = denominator * other.den();
	normalize();
  return *this;
}

Fraction operator+(Fraction a, const Fraction& b){
  (void)b;
  return a += b;
}

Fraction operator-(Fraction a, const Fraction& b){
  // TODO: reutilizar operator-=.
  (void)b;
  return a -= b;
}

Fraction operator*(const Fraction& a, const Fraction& b){
  // TODO: implementar multiplicacion.
  (void)a;
  (void)b;
  return Fraction(0, 1);
}

Fraction operator/(const Fraction& a, const Fraction& b){
  // TODO: implementar division y rechazar division por fraccion cero.
  (void)a;
  (void)b;
  return Fraction(0, 1);
}

bool operator==(const Fraction& a, const Fraction& b){
  // TODO: implementar igualdad.
  (void)a;
  (void)b;
	if(a.num() == b.num() && a.den() == b.den())
		return true;
  return false;
}

bool operator!=(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator==.
  (void)a;
  (void)b;
  return false;
}

bool operator<(const Fraction& a, const Fraction& b){
  // TODO: implementar usando productos cruzados.
  (void)a;
  (void)b;
  return false;
}

bool operator<=(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator< y operator==.
  (void)a;
  (void)b;
  return false;
}

bool operator>(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator<.
  (void)a;
  (void)b;
  return false;
}

bool operator>=(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator<.
  (void)a;
  (void)b;
  return false;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f){
  // TODO: imprimir con el formato numerador/denominador.
  (void)f;
  return os;
}

std::istream& operator>>(std::istream& is, Fraction& f){
  // TODO: leer con el formato numerador/denominador.
  // Si la entrada es invalida, marcar failbit y no modificar f.
  (void)f;
  return is;
}
