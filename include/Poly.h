#ifndef POLY_H
#define POLY_H
#include <iostream>


class Poly
{
    public:
        Poly();
        Poly(int n);
        virtual ~Poly();

        Poly(const Poly& other);

        int GetPoly();
        void ShowPoly();

        int Getp_size() { return p_size; }
        void Setp_size(int val) { p_size = val; }

        char Getp_name() { return p_name; }
        void Setp_name(char val) { p_name = val; }



        Poly& operator=(const Poly& other);
        Poly& operator+(const Poly& b) const;
        Poly& operator-(const Poly& b) const;
        //Polynominal& operator*(const Poly& b) const;
        Poly& operator*(double b) const;
        double operator()(double b) const;

    protected:
    private:
        int p_size;
        char p_name;
        double * polyArray;
};

Poly& operator*(double a, const Poly & b);

std::ostream & operator<<(std::ostream & s, const Poly & p);

#endif // POLY_H
