#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

template<typename T>
class Polynomial{
    private:
        //this array holds the coefficients of polynomial
        vector<T> coefficients;
        int degree;

        // Helper function to remove leading zeroees and update degree
        void normalize() {
            while (coefficients.size() > 1 && coefficients.back() == T{}) {
                coefficients.pop_back();
            }
            degree = coefficients.size() - 1;
        }
    public:
        //default constructoor
        Polynomial(){
            degree = 0;
            coefficients = {0};
        }
        //parameterized constructor
        Polynomial(vector<T> coeff){
            if (coeff.empty()) {
                coefficients = {0};
                degree = 0;
            } else {
                coefficients = coeff; 
                normalize();
            }
        }
        
        //copy constructor
        Polynomial(const Polynomial<T> &p){
            coefficients = p.coefficients;
            degree = p.degree;
        }
        //Move Constructor
        Polynomial(Polynomial<T> &&p) noexcept {
            coefficients = std::move(p.coefficients);
            degree = p.degree;
            p.degree = 0;
            p.coefficients.clear();
        }
        //over load assignemment operator =
        Polynomial& operator=(const Polynomial<T> &p){
            //if both of them are exact same, then thhere cannot be assignment, we return *this only
            if(this != &p){
                coefficients = p.coefficients;
                degree = p.degree;
            }
            return *this;
        }
        
        T getCoefficient(int power) const{
            if(power < 0 || power > degree){
                return 0;   //out of bounds ke liye zero 
            }
            return coefficients[power];
        }
        //get dgree
        int getDegree() const{
            return degree;
        }
        T getConstant() const {
            if (coefficients.empty()) return 0;       // ⭐ FIX: safety check for empty vector
            return coefficients[0];
        }
        void setCoefficient(int power, T val){
            if (power < 0) return; 
            if (power >= coefficients.size()) {
                coefficients.resize(power + 1, T{});
            }
            coefficients[power] = val;
            normalize();
        }
        
        //overload +, -, * for polynomial arithmetic
        Polynomial operator+(const Polynomial &p) const {
            int n = std::max(this->coefficients.size(), p.coefficients.size());
            vector<T> res(n, T{});
            
            for(int i = 0; i < this->coefficients.size(); ++i){
                res[i] += this->coefficients[i];
            }
            for(int i = 0; i < p.coefficients.size(); ++i){
                res[i] += p.coefficients[i];
            }
            return Polynomial(res);
        }
        Polynomial operator- (const Polynomial<T> &p) const{
            int n = std::max(p.coefficients.size(), this->coefficients.size());
            vector<T> res(n, T{});
            for(int i = 0; i < this->coefficients.size(); ++i){
                res[i] += this->coefficients[i];
            }
            for(int i = 0; i < p.coefficients.size(); ++i){
                res[i] -= p.coefficients[i];
            }
            
            return Polynomial(res);
        }
        Polynomial operator*(const Polynomial& p) const {
            int n1 = coefficients.size();
            int n2 = p.coefficients.size();
            std::vector<T> res(n1 + n2 - 1, T{});

            for (int i = 0; i < n1; i++)
                for (int j = 0; j < n2; j++)
                    res[i + j] += coefficients[i] * p.coefficients[j];

            return Polynomial(res);
        }
        
};
#endif