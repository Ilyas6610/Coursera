#include <vector>
#include <algorithm>
#include <iostream>

void PrintStats(vector<Person> persons){
    int median_age = ComputeMedianAge(persons.begin(), persons.end());
    auto it = partition(persons.begin(), persons.end(),
                        [](const Person& x){
                        return x.gender == Gender::FEMALE;
                        });
    int fmedian_age = ComputeMedianAge(persons.begin(), it);
    int mmedian_age = ComputeMedianAge(it, persons.end());
    auto it2 = partition(persons.begin(), it,
                   [](const Person& x){
                    return x.is_employed == true;
                   });
    auto it3 = partition(it, persons.end(),
                   [](const Person& x){
                    return x.is_employed == true;
                   });
    int efmedian_age = ComputeMedianAge(persons.begin(), it2);
    int uefmedian_age = ComputeMedianAge(it2, it);
    int emmedian_age = ComputeMedianAge(it, it3);
    int uemmedian_age = ComputeMedianAge(it3, persons.end());

    cout << "Median age = " << median_age << '\n'
    << "Median age for females = " << fmedian_age << '\n'
    << "Median age for males = " << mmedian_age << '\n'
    << "Median age for employed females = " << efmedian_age << '\n'
    << "Median age for unemployed females = " << uefmedian_age << '\n'
    << "Median age for employed males = " << emmedian_age << '\n'
    << "Median age for unemployed males = " << uemmedian_age;
};
