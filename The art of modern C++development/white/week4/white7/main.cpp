#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include<vector>

using namespace std;

class Rational {
public:
    Rational(): numerator(0), denominator(1){};

    Rational(long long num, long long denom){
        long long a = max(abs(num), abs(denom)), b = min(abs(num),abs(denom)), k;
        while( b != 0 ){
            k = a%b;
            a = b;
            b = k;
        }
        if(denom*num < 0){
            numerator = -(abs(num)/a);
            denominator = abs(denom)/a;
        }else{
            numerator = abs(num)/a;
            denominator = abs(denom)/a;
        }

    };

    int Numerator() const{
        return numerator;
    };
    int Denominator() const{
        return denominator;
    };
private:
    int numerator;
    int denominator;
};

Rational operator+(const Rational rhs, const Rational lhs){
    return Rational(rhs.Numerator()*lhs.Denominator() + lhs.Numerator()*rhs.Denominator(), rhs.Denominator() * lhs.Denominator());
}

Rational operator-(const Rational rhs, const Rational lhs){
    return Rational(rhs.Numerator()*lhs.Denominator() - lhs.Numerator()*rhs.Denominator(), rhs.Denominator() * lhs.Denominator());
}

Rational operator*(const Rational rhs, const Rational lhs){
    return Rational(rhs.Numerator() * lhs.Numerator(), rhs.Denominator() * lhs.Denominator());
}

Rational operator/(const Rational rhs, const Rational lhs){
    return Rational(rhs.Numerator() * lhs.Denominator(), rhs.Denominator() * lhs.Numerator());
}

istream& operator>>(istream& input, Rational& r){
    if(input){
        int num, denom;
        char s;
        if(!(input >> num))
            return input;
        if(!(input >> s) || s != '/')
            return input;
        if(!(input >> denom))
            return input;
        r = Rational(num, denom);
    }
    return input;
}

ostream& operator<<(ostream& output, const Rational& r){
    output << r.Numerator() << '/' << r.Denominator();
    return output;
}

bool operator==(const Rational rhs, const Rational lhs){
    return (rhs.Numerator() == lhs.Numerator()) && (rhs.Denominator() == lhs.Denominator());
}


bool operator<(const Rational rhs, const Rational lhs){
    return (rhs.Numerator()*lhs.Denominator()) < (lhs.Numerator()*rhs.Denominator());
}

int main() {
    {
        Rational a(12, 3);
        Rational b(3, -4);
        Rational c = a * b;
        cout << c << endl;
    }
    return 0;
}
