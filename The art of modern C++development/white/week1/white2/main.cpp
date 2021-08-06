#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double A, B, C;
    cin >> A >> B >> C;
    if( A == 0 ){
        if( B == 0 ){
            if( C != 0 ){
                return 0;
            }
        }else if( B != 0 ){
            if( C == 0 ){
                cout << 0 << endl;
            }else if( C != 0 ){
                cout << -C/B << endl;
            }
        }
    }else if (A != 0){
        if( B == 0 ){
            if( C == 0 ){
                cout << 0 << endl;
            }else if( C != 0 ){
                if ((C < 0 && A > 0) || (C > 0 && A < 0))
                    cout << sqrt(-C/A) << ' ' << -sqrt(-C/A) << endl;
                else
                    return 0;
            }
        }else if(B != 0){
            if( C == 0 ){
                cout << 0 << ' ' << -B/A << endl;
            }else if( C != 0 ){
                double D = B*B - 4*A*C;
                if( D > 0 )
                    cout << (-B + sqrt(D))/(2*A) << ' ' << (-B - sqrt(D))/(2*A) << endl;
                else if (D == 0)
                    cout << -B/(2*A) << endl;
            }
        }
    }
    return 0;
}
