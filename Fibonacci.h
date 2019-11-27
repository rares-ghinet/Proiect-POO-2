#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Vector {
        int *a;
        int dim;
    public:
        friend class Nr_Natural_Mare;
        Vector(int dim=0);
        Vector(const Vector&);
        ~Vector();
        Vector& operator=(const Vector&);
        friend istream& operator>>(istream&, Vector&);
        friend ostream& operator<<(ostream&, const Vector&);

        int& operator[](int pos);
        int operator[](int pos) const;
        int size()const;
        void resize(int dim);
};

class Nr_Natural_Mare
{
    protected:
        int nr_cif;
        Vector v;
    public:
        Nr_Natural_Mare(int nr_cif=0);
        Nr_Natural_Mare(const Nr_Natural_Mare&);
        virtual ~Nr_Natural_Mare();
        Nr_Natural_Mare& operator=(const Nr_Natural_Mare&);
        friend istream& operator>>(istream&, Nr_Natural_Mare&);
        friend ostream& operator<<(ostream&, const Nr_Natural_Mare&);

        Nr_Natural_Mare operator+(const Nr_Natural_Mare&)const;
        bool operator==(const Nr_Natural_Mare&)const;
        bool operator<(const Nr_Natural_Mare&)const;
        bool operator<=(const Nr_Natural_Mare&)const;
        int& operator[](int pos);
        int operator[](int pos)const;
};

class Nr_Fibonacci_Mare: public Nr_Natural_Mare
{

    public:
        Nr_Fibonacci_Mare(int nr_cif=0):Nr_Natural_Mare(nr_cif) {/*cout << "Constructor D" << endl;*/}
        Nr_Fibonacci_Mare(const Nr_Natural_Mare& Obj):Nr_Natural_Mare(Obj) {}
        ~Nr_Fibonacci_Mare();
        Nr_Fibonacci_Mare& operator=(const Nr_Fibonacci_Mare&);
        friend istream& operator>>(istream&, Nr_Fibonacci_Mare&);
        friend ostream& operator<<(ostream&, const Nr_Fibonacci_Mare&);

        virtual void afis()const;
};



#endif






