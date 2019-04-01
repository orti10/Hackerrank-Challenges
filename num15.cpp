//Bit Array


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
      uint_fast64_t maxi = pow(2, 31);
    uint_fast64_t N, S, P, Q;    
    cin >> N >> S >> P >> Q;
    
    uint_fast64_t total = 1;
    uint_fast64_t prev = S % maxi;
    
    for(auto i=1; i<N; ++i) {
        uint_fast64_t x = (prev * P + Q) % maxi;
        if (x != prev) {
            prev = x;
            total++;
        } else {
            break;
        }
    }
    cout << total << endl;
    return 0;
}