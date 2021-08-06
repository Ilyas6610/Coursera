#include <iostream>
#include <deque>

using namespace std;

void addBrackets(deque<string>& d){
    d.push_back("(");
    d.push_front(")");
}

int op_prio(const string& s){
    if( s == "+" || s == "-" )
        return 1;
    else
        return 2;
}

int main()
{
    int x, n;
    cin >> x >> n;
    deque<string> d;
    int last_prio = 2;
    d.push_back(to_string(x));
    for( int i = 0; i < n; i++ ){
        string s = "";
        cin >> s;
//      addBrackets(d); без оптимизации
        if( op_prio(s) > last_prio )
            addBrackets(d);
        last_prio = op_prio(s);
        d.push_front(" " + s + " ");
        s = "";
        cin >> s;
        d.push_front(s);
    }
    while(!d.empty()){
        cout << d.back();
        d.pop_back();
    }
    return 0;
}
