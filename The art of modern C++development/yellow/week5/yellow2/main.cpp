#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <math.h>
#include <sstream>
#include <iomanip>

using namespace std;

class Figure{
public:
    Figure(const string& s) : name(s) {};
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;

protected:
    const string name;
};

class Rect : public Figure{
public:
    Rect(const string& s, int& w_, int& h_):
        Figure(s),
        w(w_),
        h(h_)
    {};

    string Name() const override{
        return name;
    };

    double Perimeter() const override{
        return 2*w + 2*h;
    }

    double Area() const override{
        return w*h;
    }

private:
    const int w, h;

};

class Triangle : public Figure{
public:
    Triangle(const string& s, int x_, int y_, int z_):
        Figure(s),
        x(x_),
        y(y_),
        z(z_)
    {};

    string Name() const override{
        return name;
    };

    double Perimeter() const override{
        return x + y + z;
    }

    double Area() const override{
        double p = Perimeter()/2.;
        return sqrt(p*(p-x)*(p-y)*(p-z));
    }

private:
    const int x, y, z;

};

class Circle : public Figure{
public:
    Circle(const string& s, int r_):
        Figure(s),
        r(r_)
    {};

    string Name() const override{
        return name;
    };

    double Perimeter() const override{
        return 2*pi*r;
    }

    double Area() const override{
        return pi*r*r;
    }

private:
    const int r;
    const double pi = 3.14;

};

shared_ptr<Figure> CreateFigure(istream& is){
    string name;
    is >> name;
    if( name == "RECT" ){
        int w, h;
        is >> w >> h;
        return make_shared<Rect>(name, w, h);
    }else if ( name == "TRIANGLE" ){
        int x, y, z;
        is >> x >> y >> z;
        return make_shared<Triangle>(name, x, y, z);
    }else if ( name == "CIRCLE" ){
        int r;
        is >> r;
        return make_shared<Circle>(name, r);
    }
}
