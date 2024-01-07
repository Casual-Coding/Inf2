#include <iostream>
#include <cmath>

class complex_number {
private:
    double real;
    double imag;

public:
    // Konstruktoren
    complex_number();
    complex_number(double r);
    complex_number(double r, double i);

    // Funktionen
    double calculateMagnitude() const;

    // ‹berladung von Operatoren
    complex_number operator+(const complex_number& other) const;
    complex_number operator*(const complex_number& other) const;
};

// Definitionen der Konstruktoren
complex_number::complex_number() : real(0.0), imag(0.0) {}
complex_number::complex_number(double r) : real(r), imag(0.0) {}
complex_number::complex_number(double r, double i) : real(r), imag(i) {}

// Definitionen der Funktionen
double complex_number::calculateMagnitude() const {
    return std::sqrt(real * real + imag * imag);
}

// ‹berladung von Operatoren
complex_number complex_number::operator+(const complex_number& other) const {
    return complex_number(real + other.real, imag + other.imag);
}

complex_number complex_number::operator*(const complex_number& other) const {
    return complex_number(
        real * other.real - imag * other.imag,
        real * other.imag + imag * other.real
    );
}

// Testfunktion, erstellt erst beide komplexe Zahlen, dann werden diese multipliziert und zum schluﬂ der Betrag gebildet
int main() {
    complex_number z1(2.0, 3.0);
    complex_number z2(1.0, 2.0);

    complex_number result = z1 * z2;

    std::cout << "Result: " << result.calculateMagnitude() << std::endl;

    return 0;
}
