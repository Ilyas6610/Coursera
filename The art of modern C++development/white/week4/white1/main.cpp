#include <iostream>

using namespace std;

struct Specialization{
    Specialization(){};
    explicit Specialization(string s){
        value = s;
    };
    string value;
};

struct Course{
    Course(){};
    explicit Course(string s){
        value = s;
    };
    string value;
};

struct Week{
    Week(){};
    explicit Week(string s){
        value = s;
    };
    string value;
};

struct LectureTitle {
    LectureTitle(Specialization s, Course c, Week w){
        specialization = s.value;
        course = c.value;
        week = w.value;
    };
    string specialization;
    string course;
    string week;
};
