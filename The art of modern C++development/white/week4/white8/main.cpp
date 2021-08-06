#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <exception>

using namespace std;

class Rational {
public:
    Rational(): numerator(0), denominator(1){};

    Rational(long long num, long long denom){
        if (denom == 0)
            throw invalid_argument("Division by zero");
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
    if(lhs.Numerator() == 0)
        throw domain_error("Division by zero");
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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
