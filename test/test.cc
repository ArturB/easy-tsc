#include "../src/tsc.cc"
#include <iostream>
#include <cmath>

using namespace std;

int main( int argc, char* const argv[] )
{
    Tsc tsc;
    tsc.start();
    usleep(1000);
    tsc.stop();
    cout << tsc << endl;
}
