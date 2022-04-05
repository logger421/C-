#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

typedef double element;
typedef double* elementPointer;

class Polynomial {
private:
    element *w;
    int degree;
public:
    Polynomial();
    Polynomial(int size);
    
    void operator =(Polynomial p);
    Polynomial operator +( Polynomial &p );
    Polynomial operator -( Polynomial &p );
    Polynomial operator *( Polynomial &p );
    double horner(double x);

    elementPointer returnPointer();
    int getDegree();
    friend ostream &operator<<(ostream &ost, const Polynomial &p);
    friend istream &operator>>(std::istream &ist, Polynomial &p);
};

int main() {
    cout << "Podaj stopien 1 wielomianu: ";
    int stopien;
    cin >> stopien;
    Polynomial p1(stopien);
    cin >> p1;
    cout << "Wielomian 1:\n" << p1 << endl;

    cout << "Podaj stopien 2 wielomianu: ";
    cin >> stopien;
    Polynomial p2(stopien);
    cin >> p2;
    cout << "Wielomian 2\n" << p2 << endl;
    
    Polynomial result;
    
    result = p1 + p2;
    cout << "p1 + p2 = " << result << endl;
    result = p1-p2;
    cout << "p1 - p2 = " << result << endl;
    result = p1*p2;
    cout << "p1 * p2 = " << result << endl;

    cout << "p1(x = 2)= " << p1.horner(2) << endl;
    cout << "p1(x = 3)= " << p1.horner(3) << endl;
    cout << "p1(x = 4)= " << p1.horner(4) << endl;
    cout << "\n";
    return 0;
}

// ############### Metody pomocnicze ############### //

ostream &operator<<(ostream &ost, const Polynomial &p) {
    bool check = false;
    for (int i = 0; i <= p.degree; i++)
        if(p.w[i] != 0)
            check = true;
    if (check == true)
    {
        for (int i = 0; i <= p.degree; i++)
        {
            if (p.w[i] == 0)
                continue;
            else if (i == 0)
                cout << showpos << p.w[i];
            else
                cout << showpos << p.w[i] << "x^(" << i << ")";
        }
    }
    else
        cout << 0;
    return ost;
}

istream &operator>>(std::istream &ist, Polynomial &p) {
        unsigned n;
        char c1, c2;
        element a;
        elementPointer coefficients = p.returnPointer();
        int size = p.getDegree();
        for (int i = 0; i < size + 1; i++) {
            ist>>a>>c1>>c2>>n;
            assert(c1 == 'x' && c2 == '^');
            if( (n >= 0) && (n <= size))
                coefficients[n] += a;
            else
                cout << "Błąd wprowadzania danych\n";
        }
        return ist;
}

Polynomial::Polynomial() {
    degree = 0;
    w = new element[degree + 1];
    for(int i = 0; i < degree + 1; i++)
        w[i] = 0;
}

Polynomial::Polynomial(int size) {
    degree = size;
    w = new element[degree + 1];
    
    for(int i = 0; i < size + 1; i++)
        w[i] = 0;
}

int Polynomial::getDegree() {
    return this->degree;
}
elementPointer Polynomial::returnPointer() {
    return this->w;
}

void Polynomial::operator=(Polynomial p) {
    delete [] w; 
    this->degree = p.getDegree(); 
    this->w = p.returnPointer(); 
}

// ############### Operacje na wielomianach ############### //
Polynomial Polynomial::operator +(Polynomial &p) {
    int size1 = this->degree;
    int size2 = p.getDegree();
    int resultSize = size1 > size2 ? size1 : size2;
    
    Polynomial result(resultSize);
    elementPointer resultCoefficients = result.returnPointer();
    elementPointer secondCoefficients = p.returnPointer();

    for(int i = 0; i <= resultSize; i++) {
        if(size1 > size2) {
            if(i <= size2)
                resultCoefficients[i] = w[i] + secondCoefficients[i];
            else
                resultCoefficients[i] = w[i];
        }
        else if(size1 < size2) {
            if(i <= size1)
                resultCoefficients[i] = w[i] + secondCoefficients[i];
            else
                resultCoefficients[i] = secondCoefficients[i];
        }
        else
            resultCoefficients[i] = w[i] + secondCoefficients[i];
    }
    return result;
}

Polynomial Polynomial::operator -(Polynomial &p) {
    int size1 = this->degree;
    int size2 = p.getDegree();
    int resultSize = size1 > size2 ? size1 : size2;
    
    Polynomial result(resultSize);
    elementPointer resultCoefficients = result.returnPointer();
    elementPointer secondCoefficients = p.returnPointer();

    for(int i = 0; i <= resultSize; i++) {
        if(size1 > size2) {
            if(i <= size2)
                resultCoefficients[i] = w[i] - secondCoefficients[i];
            else
                resultCoefficients[i] = w[i];
        }
        else if(size1 < size2) {
            if(i <= size1)
                resultCoefficients[i] = w[i] - secondCoefficients[i];
            else
                resultCoefficients[i] = (-1)*secondCoefficients[i];
        }
        else
            resultCoefficients[i] = w[i] - secondCoefficients[i];
    }
    return result;
}

Polynomial Polynomial::operator*(Polynomial &p) {
    int resultDegree = this->degree + p.getDegree();
    Polynomial result(resultDegree);

    elementPointer resultCoefficients = result.returnPointer();
    elementPointer secondCoefficients = p.returnPointer();

    for(int i = 0; i <= degree; i++) {
        for(int j = 0; j <= p.getDegree(); j++)
            resultCoefficients[i+j] += w[i] * secondCoefficients[j];
    }
    return result;
}

double Polynomial::horner(double x) {
    double result = w[degree];

    for( int i = degree - 1; i >= 0; i--)
        result = result * x + w[i];
    return result;
}
