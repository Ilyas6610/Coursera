#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human{
public:
    Human(const string type_, const string& Name_) :
        type(type_),
        Name(Name_)
    {}

    virtual void SingSong() const {};

    void Walk(string destination) const {
        cout << type << " : " << Name << " walks to: " << destination << endl;
        SingSong();
    }

    string GetType() const{
        return type;
    }

    string GetName() const{
        return Name;
    }

protected:
    const string type;
    const string Name;
};

class Student : public Human {
public:

    Student(const string& name, const string& favouriteSong) :
        Human("Student", name),
        FavouriteSong(favouriteSong)
    {}

    void Learn() const {
        cout << type << " : " << Name << " learns" << endl;
    }

    void SingSong() const {
        cout << type << " : " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Human{
public:

    Teacher(const string& name, const string& subject) :
        Human("Teacher", name),
        Subject(subject)
    {}

    void Teach() const{
        cout << type << " : " << Name << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public Human{
public:
    Policeman(const string& name) :
        Human("Policeman", name)
    {};

    void Check(const Human& h) const {
        cout << type << " : " << Name << " checks " << h.GetType() << ". " << h.GetType() << "\'s name is: " << h.GetName() << endl;
    }
};


void VisitPlaces(const Human& h, const vector<string>& places) {
    for (auto p : places) {
        h.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    t.Teach();
    VisitPlaces(p, {"Moscow", "London"});
    s.Learn();
    s.SingSong();
    p.Check(t);
    return 0;
}
