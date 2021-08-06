#include <iostream>

using namespace std;

int main()
{
    uint64_t n, R, W, H, D, sum = 0;
    cin >> n >> R;
    for( size_t i = 0; i < n; i++ )
    {
        cin >> W >> H >> D;
        sum += (W*H*D*R);
    }
    cout << sum << endl;
    return 0;
}
