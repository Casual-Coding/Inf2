#include <iostream>
#include <algorithm>

class rational {
public:
    // Konstruktoren
    rational() : zaehler(0), nenner(1) {}
    rational(uint32_t num, uint32_t denom);

    // Getter-Funktionen
    uint32_t getZaehler() const { return zaehler; }
    uint32_t getNenner() const { return nenner; }

    // Operatoren
    rational operator+(const rational& other) const;
    rational operator-() const;
    rational operator-(const rational& other) const;
    rational operator*(const rational& other) const;
    rational operator/(const rational& other) const;

    // Vergleichsoperatoren
    bool operator==(const rational& other) const;
    bool operator<(const rational& other) const;

private:
    uint32_t zaehler;
    uint32_t nenner;

    // Hilfsfunktion für das kleinste gemeinsame Vielfache (LCM)
    static uint32_t lcm(uint32_t a, uint32_t b) {
        return (a / std::__gcd(a, b)) * b;  // C++17: std::gcd
    }
};

// Konstruktordefinition
rational::rational(uint32_t num, uint32_t denom) {
    if (denom == 0) {
        // Undefiniert: Nenner darf nicht 0 sein
        std::cerr << "Error: Denominator cannot be zero." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Bruch in normierter Form darstellen
    uint32_t gcd = std::__gcd(num, denom);  // C++17: std::gcd
    zaehler = num / gcd;
    nenner = denom / gcd;
}

// Operatorüberladungen
rational rational::operator+(const rational& other) const {
    uint32_t common_denom = lcm(nenner, other.nenner);
    uint32_t sum_num = zaehler * (common_denom / nenner) + other.zaehler * (common_denom / other.nenner);

    return rational(sum_num, common_denom);
}

rational rational::operator-() const {
    return rational(-zaehler, nenner);
}

rational rational::operator-(const rational& other) const {
    return *this + (-other);
}

rational rational::operator*(const rational& other) const {
    return rational(zaehler * other.zaehler, nenner * other.nenner);
}

rational rational::operator/(const rational& other) const {
    if (other.zaehler == 0) {
        // Undefiniert: Division durch Null
        std::cerr << "Error: Division by zero." << std::endl;
        exit(EXIT_FAILURE);
    }

    return rational(zaehler * other.nenner, nenner * other.zaehler);
}

// Vergleichsoperatoren
bool rational::operator==(const rational& other) const {
    return (zaehler == other.zaehler) && (nenner == other.nenner);
}

bool rational::operator<(const rational& other) const {
    uint32_t common_denom = lcm(nenner, other.nenner);
    uint32_t this_num = zaehler * (common_denom / nenner);
    uint32_t other_num = other.zaehler * (common_denom / other.nenner);

    return this_num < other_num;
}

// Testfunktion
int main() {
    rational r1(1, 2);
    rational r2(2, 3);

    rational sum = r1 + r2;
    std::cout << "Sum: " << sum.getZaehler() << "/" << sum.getNenner() << std::endl;

    rational diff = r1 - r2;
    std::cout << "Difference: " << diff.getZaehler() << "/" << diff.getNenner() << std::endl;

    rational prod = r1 * r2;
    std::cout << "Product: " << prod.getZaehler() << "/" << prod.getNenner() << std::endl;

    rational quotient = r1 / r2;
    std::cout << "Quotient: " << quotient.getZaehler() << "/" << quotient.getNenner() << std::endl;

    std::cout << "Is r1 equal to r2? " << (r1 == r2 ? "Yes" : "No") << std::endl;
    std::cout << "Is r1 less than r2? " << (r1 < r2 ? "Yes" : "No") << std::endl;

    return 0;
}
