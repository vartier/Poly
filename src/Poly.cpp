#include "Poly.h"


Poly::Poly()
{
    //ctor
}

Poly::Poly(int n)
{

}

Poly::~Poly()
{

}

Poly::Poly(const Poly& other)
{
    //copy ctor
}

int Poly::GetPoly()
{
    const int tMAX = 20;
    char polyName;
    double tab[tMAX];
    for (int i = 0; i<tMAX; i++)
    {
        tab[i] = 0;
    }
    std::cout << "Wpisz wielomian zgodnie ze wzorem: W(x)=1x^3-2x^2+2x^1+3x^0" << std::endl;
    std::cin >> std::ws;

    int c = std::cin.peek();
    if ((isdigit(c)))
    {
        std::cout << "Zle wejscie.";
        return 1;
    }
    if ( std::isdigit(c) )
    {
        std::cout << "Zle wejscie.";
        return 1;
    }
    else
    {
        std::cin >> polyName;
    }
    std::cin >> std::ws;
    std::cin.ignore(4,'=');


/// WPISYWANIE WIELOMIANU po znaku =
    int n; //Wspolczynnik
    int p; //Potega (indeks)
    int onceloop=0;  // do make maks greaterst factor;
    int maks;        // greatest factor;

    do
    {
        onceloop++;
        c = std::cin.peek();
        if (!(isdigit(c)))
        {
            if ((c != '-') and (c!='+'))
            {
                std::cout << "Zle wejscie...";
                return 1;
            }
        }

        std::cin >> n;


        std::cin.ignore(3,'^');
        c = std::cin.peek();
        if (!(isdigit(c)))
        {
            std::cout << "Zle wejscie.";
            return 1;
        }
        else
        {
            std::cin >> p;
        }

        tab[p] = n;

        if (onceloop == 1)
        {
            maks=p;
        }
    }
    while(p!=0);

    this->polyArray = new double[maks];
    this->p_name = polyName;
    this->p_size = maks;

    for (int i = 0; i<=maks; i++)
    {
        polyArray[i] = tab[i];
    }
}

void Poly::ShowPoly()
{
    std::cout << this->p_name << "(x) = ";
    for (int i = p_size; i>=0; i--)
        std::cout << polyArray[i]<<"x^"<< i;
    std::cout<<std::endl;

}

Poly& Poly::operator=(const Poly& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

Poly& Poly::operator+(const Poly & b) const
{
    double tab[20];
    Poly T = new Poly();
    int lb = b.p_size;
    int la = this->p_size;
    if (lb > la)
    {
        T=b;
    }
    else
    {
        T=*this;
    }
    int mi = std::min (la,lb);
    int ma = std::max (la,lb);

    if (lb >la)
    for (int i = 0; i<=mi; i++)
    {
        tab[i] += this->polyArray[i];
    }
    else
    for (int i = 0; i<=mi; i++)
    {
        T[i] += b.polyArray[i];
    }
    return T; ////////////TU BŁĄD

}

Poly& Poly::operator-(const Poly & b) const
{
//NOOP yet
}

Poly& Poly::operator*(double b) const
{
}
double Poly::operator()(double b) const
{
    /*
        double sum = 0;
        for (int i = this->GetSize()-1 ; i>0; i--)
        {
            sum+=(*this)[i];
            sum*=b;
        }
        if( this->GetSize() > 0 )
        {
            sum+=(*this)[0];
        }
        else
        {
            return 0;
        }
        return sum;*/
}

std::ostream & operator<<(std::ostream & s, const Poly & p)
{

}
