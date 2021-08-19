//#include "../../week1/red1/test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
struct Data{
    Data(T& val_, bool fl_, int prio_){
        val = move(val_);
        fl = fl_;
        prio = prio_;
    }
    T val;
    bool fl;
    int prio;
};

template <typename T>
class PriorityCollection {
public:
    using Id = int;

    PriorityCollection(){
        m.reserve(1000000);
    };

    // Добавить объект с нулевым приоритетом
    // с помощью перемещения и вернуть его идентификатор
    Id Add(T object){
        m.push_back(Data<T>{object, true, 0});
        s.insert(pair<int, Id>(0, cur_id));
        return cur_id++;
    };

    // Добавить все элементы диапазона [range_begin, range_end)
    // с помощью перемещения, записав выданные им идентификаторы
    // в диапазон [ids_begin, ...)
    template <typename ObjInputIt, typename IdOutputIt>
    void Add(ObjInputIt range_begin, ObjInputIt range_end,
           IdOutputIt ids_begin){
                for( auto it = range_begin; it != range_end; it++, ids_begin++ ){
                    m.push_back(Data{*it, true, 0});
                    s.insert(pair<int, Id>(0, cur_id));
                    *ids_begin = cur_id;
                    cur_id++;
                }
           }

    // Определить, принадлежит ли идентификатор какому-либо
    // хранящемуся в контейнере объекту
    bool IsValid(Id id) const{
        if( id >= cur_id || !m[id].fl  )
            return false;
        return true;
    }

    // Получить объект по идентификатору
    const T& Get(Id id) const{
        return m[id].val;
    }

    // Увеличить приоритет объекта на 1
    void Promote(Id id){
        auto it = s.find(pair<int, Id>(m[id].prio, id));//find_if(s.begin(), s.end(), [id](auto t){ return t.second == id; });
        s.insert(pair<int, Id>(it->first+1, it->second));
        m[id].prio++;
        s.erase(it);
    }

    // Получить объект с максимальным приоритетом и его приоритет
    pair<const T&, int> GetMax() const{
        auto it = prev(s.end());
        return {m[it->second].val, it->first};
    }

    // Аналогично GetMax, но удаляет элемент из контейнера
    pair<T, int> PopMax(){
        auto it = prev(s.end());
        pair<T, int> p = pair<T, int>(move(m[it->second].val), move(it->first));
        m[it->second].fl = false;
        s.erase(it);
        return move(p);
    }

private:
    set<pair<int, Id>> s;
    vector<Data<T>> m;
    int cur_id = 0;
};

