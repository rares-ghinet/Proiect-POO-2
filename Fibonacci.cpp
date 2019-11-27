#include "Fibonacci.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

///Vector

Vector::Vector(int dim)
{
    this->dim=dim;
    try
    {
     this->a=new int[dim];
    }
    catch(bad_alloc dim)
    {
        cout<<"Eroare la alocare"<<endl;
        exit(EXIT_FAILURE);
    }
}

Vector::Vector(const Vector& Obj)
{
    this->dim=Obj.dim;
    this->a=new int[dim];
    for(int i=0;i<dim;i++)
        a[i]=Obj.a[i];
}

Vector::~Vector()
{
    try
    {
       dim=0;
       delete[]a;

       if(dim!=0){throw dim;}
    }

    catch(int dim)
    {
        cout<<"Exceptie: dim!=0"<<endl;
        exit(EXIT_FAILURE);
    }
}

Vector& Vector::operator=(const Vector& Obj)
{
    if(this==&Obj)
        return *this;
    dim=Obj.dim;
    delete[]a;
    a=new int[dim];
    for(int i=0;i<dim;i++)
        a[i]=Obj.a[i];
    return *this;
}

istream& operator>>(istream& in, Vector& Obj)
{
    in>>Obj.dim;
    delete[]Obj.a;
    Obj.a=new int[Obj.dim];
    for(int i=0;i<Obj.dim;i++)
        in>>Obj.a[i];
    return in;
}

ostream& operator<<(ostream& out, const Vector& Obj)
{
    for(int i=0;i<Obj.dim;i++)
        out<<Obj.a[i]<<" ";
    return out;
}

int& Vector::operator[](int pos)
{
    return a[pos];
}

int Vector::operator[](int pos) const
{
    return a[pos];
}

int Vector::size() const
{
    return dim;
}

void Vector::resize(int new_dim)
{
    if(new_dim==dim){return;}
    Vector aux(*this);
    delete a;
    a=new int[new_dim];
    for(int i=0;i<min(new_dim,dim); ++i)
        a[i]=aux[i];
    for(int i=dim;i<new_dim;++i)
        a[i]=0;
    dim=new_dim;
}

///Nr_Natural_Mare

Nr_Natural_Mare::Nr_Natural_Mare(int nr_cif)
{
    try
    {
      this->nr_cif=nr_cif;
      if(nr_cif<0)
      {
          throw nr_cif;
      }
    }
    catch(int nr_cif)
    {
        cout<<"Exceptie: nr_cif<0"<<endl;
        exit(EXIT_FAILURE);
    }
    this->v=Vector(nr_cif);
    //cout << "Constructor B" << endl;
}

Nr_Natural_Mare::Nr_Natural_Mare(const Nr_Natural_Mare& Obj)
{
    this->nr_cif=Obj.nr_cif;
    this->v=Obj.v;
}

Nr_Natural_Mare::~Nr_Natural_Mare()
{
    try
    {
         nr_cif=0;
         if(nr_cif!=0)
         {
             throw nr_cif;
         }
    }
    catch(int nr_cif)
    {
        cout<<"Exceptie: Destructor failure!"<<endl;
        exit(EXIT_FAILURE);
    }
    //cout << "Destructor B" << endl;
}

Nr_Natural_Mare& Nr_Natural_Mare::operator=(const Nr_Natural_Mare& Obj)
{
    if(this==&Obj)
        return *this;
    nr_cif=Obj.nr_cif;
    v=Obj.v;
    return *this;
}

istream& operator>>(istream& in, Nr_Natural_Mare& Obj)
{
    in>>Obj.v;
    Obj.nr_cif=Obj.v.size();
    return in;
}

ostream& operator<<(ostream& out, const Nr_Natural_Mare& Obj)
{
    out<<Obj.v;
    return out;
}

Nr_Natural_Mare Nr_Natural_Mare::operator+(const Nr_Natural_Mare& Obj) const
{
    Nr_Natural_Mare suma(max(nr_cif, Obj.nr_cif));
    int transport=0;
    int cifra_self=nr_cif-1, cifra_obj=Obj.nr_cif-1, cifra_sum=0;
    while(cifra_self>=0 && cifra_obj>=0) {
        int val=v[cifra_self--]+Obj[cifra_obj--]+transport;
        transport=val/10;
        suma[suma.nr_cif- cifra_sum++ - 1]=val%10;
    }
    while(cifra_self>=0)
    {
        int val=v[cifra_self--]+transport;
        transport=val/10;
        suma[suma.nr_cif - cifra_sum++ - 1]=val%10;
    }
    while(cifra_obj>=0)
    {
        int val=Obj[cifra_obj--]+transport;
        transport=val/10;
        suma[suma.nr_cif - cifra_sum++ - 1] =val%10;
    }
    if(transport!=0)
    {
        Nr_Natural_Mare aux(suma);
        suma.v.resize(++suma.nr_cif);
        for(int i=suma.nr_cif - 1;i>=0;--i)
            suma[i]=suma.v[i - 1];
        suma[0]=transport;
    }
    return suma;
}

bool Nr_Natural_Mare::operator==(const Nr_Natural_Mare& Obj) const
{
    if(nr_cif!=Obj.nr_cif)
        return false;
    for(int i=0;i<nr_cif;++i)
        if(v[i]!=Obj[i])
            return false;
    return true;
}

bool Nr_Natural_Mare::operator<(const Nr_Natural_Mare& Obj) const
{
    if(nr_cif!=Obj.nr_cif)
        return nr_cif<Obj.nr_cif;
    for(int i=0;i<nr_cif;++i)
        if(v[i]!=Obj[i])
            return v[i]<Obj[i];
    return false;
}

bool Nr_Natural_Mare::operator<=(const Nr_Natural_Mare& Obj) const
{
    if(nr_cif!=Obj.nr_cif)
        return nr_cif<Obj.nr_cif;
    for(int i=0;i<nr_cif;++i)
        if(v[i]==Obj[i])
            continue;
        else
            return v[i]<Obj[i];
    return true;
}

int& Nr_Natural_Mare::operator[](int pos)
{
    return v[pos];
}

int Nr_Natural_Mare::operator[](int pos) const
{
    return v[pos];
}

///Nr_Fibonacci_Mare

Nr_Fibonacci_Mare::~Nr_Fibonacci_Mare()
{
    //cout << "Destructor D" << endl;
}


Nr_Fibonacci_Mare& Nr_Fibonacci_Mare::operator=(const Nr_Fibonacci_Mare& Obj)
{
    if(this==&Obj)
        return *this;
    nr_cif=Obj.nr_cif;
    v=Obj.v;
    return *this;
}

istream& operator>>(istream& in, Nr_Fibonacci_Mare& Obj)
{
    in>>Obj.v;
    Obj.nr_cif=Obj.v.size();
    return in;
}

ostream& operator<<(ostream& out, const Nr_Fibonacci_Mare& Obj)
{
    out<<Obj.v;
    return out;
}

void Nr_Fibonacci_Mare::afis() const
{
    cout<<*this<<"="<<" "; ///Afisare
    ///Incercare de descompunere! Nu functioneaza cum trebuie!
    /*
    Nr_Fibonacci_Mare a,b,c,Sum(1),zero(1),unu(1);
    zero[0]=0;
    unu[0]=1;
    Sum[0]=0;
    while(Sum<*this)
    {
        a=zero;
        b=unu;
        while(Sum+a+b<=*this)
        {
            c=a+b;
            a=b;
            b=c;
        }
        if(Sum+c==*this)
            cout<<c;
        else
            cout<<c<<"+"<<" ";
        Sum=Sum+c;
    }
    */


}


