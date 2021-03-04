#include <iostream>
#include "DFA.hpp"

int main() {
    dfa a;

    for( int i = 1; i <= 5; i++ ) {
        a.buildDFA("", 4, i );
    }
    a.printDFA();
    a.initCurrent();
    int result = a.count( 6 );
    std::cout << result << std::endl;

}
