#include <iostream>
#include <fstream>
#include <vector>
#include "Fibonacci.h"
ifstream f("date.in");
using namespace std;
int main()
{
    int n,i;
    f>>n;
    cout<<"S-au citit "<<n<<" numere din fisier!"<<endl<<endl;
    vector <Nr_Fibonacci_Mare> p;
    Nr_Fibonacci_Mare x;
    for(i=1;i<=n;i++)
    {
        f>>x;                             ///! nu am reusit sa descopar de ce nu merge citirea/afisarea
        p.push_back(x);                   ///!!!! dupa ce se citeste n -> se citeste nr de elemente si cifrele numarului CU SPATIU INTRE ELE (eventual pe aceeasi linie)
        ///cout<<"Element citit!"<<endl;           ///ex: n=2
    }                                              ///2    3 4
                                                   ///3    4 5 6
    cout<<"Numerele Fibonacci sunt:"<<endl;
    for(Nr_Fibonacci_Mare i:p)
    {
        i.afis();
        cout<<endl;
    }

}
