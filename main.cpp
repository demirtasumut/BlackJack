#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(unsigned(time(nullptr)));

    cout << "Hello, World!" << std::endl;
    cout << flush;
    return 0;
}