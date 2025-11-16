#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Polynomial {
private:
    vector<T> coefficients; // coeff[i] = coefficient of x^i

    void normalize() {
        while (coefficients.size() > 1 && coefficients.back() == T{}) {
            coefficients.pop_back();
        }
    }

public:

    // Default constructor
    Polynomial() : coefficients(1, T{}) {}

    // Construct from vector
    Polynomial(const vector<T>& coeff) : coefficients(coeff) {
        if (coefficients.empty()) coefficients.push_back(T{});
        normalize();
    }

    // Copy constructor
    Polynomial(const Polynomial& other) = default;

    // Move constructor
    Polynomial(Polynomial&& other) noexcept 
        : coefficients(std::move(other.coefficients))
    {
        other.coefficients = { T{} };
    }

    // Copy assignment
    Polynomial& operator=(const Polynomial& p) {
        if (this != &p)
            coefficients = p.coefficients;
        return *this;
    }

    int getDegree() const { 
        return static_cast<int>(coefficients.size()) - 1; 
    }

    T getCoefficient(int power) const {
        return (power < 0 || power >= coefficients.size())
            ? T{} : coefficients[power];
    }

    void setCoefficient(int power, T value) {
        if (power >= coefficients.size())
            coefficients.resize(power + 1, T{});
        coefficients[power] = value;
        normalize();
    }

    Polynomial operator+(const Polynomial& p) const {
        int n = max(coefficients.size(), p.coefficients.size());
        vector<T> res(n, T{});

        for (int i = 0; i < coefficients.size(); i++)
            res[i] += coefficients[i];
        for (int i = 0; i < p.coefficients.size(); i++)
            res[i] += p.coefficients[i];

        return Polynomial(res);
    }

    Polynomial operator-(const Polynomial& p) const {
        int n = max(coefficients.size(), p.coefficients.size());
        vector<T> res(n, T{});

        for (int i = 0; i < coefficients.size(); i++)
            res[i] += coefficients[i];
        for (int i = 0; i < p.coefficients.size(); i++)
            res[i] -= p.coefficients[i];

        return Polynomial(res);
    }

    Polynomial operator*(const Polynomial& p) const {
        int n = coefficients.size() + p.coefficients.size() - 1;
        vector<T> res(n, T{});

        for (int i = 0; i < coefficients.size(); i++)
            for (int j = 0; j < p.coefficients.size(); j++)
                res[i + j] += coefficients[i] * p.coefficients[j];

        return Polynomial(res);
    }

    friend ostream& operator<<(ostream& os, const Polynomial& poly) {
        for (int i = 0; i < poly.coefficients.size(); i++) {
            os << poly.coefficients[i];
            if (i > 0) os << "x^" << i;
            if (i + 1 != poly.coefficients.size()) os << " + ";
        }
        return os;
    }
};

#endif
