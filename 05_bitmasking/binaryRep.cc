// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<8> b(27);
    cout << "-27\t" << b << endl;

    int x = (27) >> 1;
    cout << "-27>>1\t" << bitset<8>(x) << endl;
}