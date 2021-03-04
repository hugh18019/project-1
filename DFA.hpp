//
// Created by Hugh on 2/22/21.
//

#ifndef PROBLEM_1_DFA_HPP
#define PROBLEM_1_DFA_HPP

#include <vector>
#include <string>
#include <queue>


class dfa {
public:
    dfa();
    void initCurrent();
    std::queue<int> buffer;
    std::vector<char> alphabet { 'a', 'b', 'c', 'd' };


    std::string toStr( int v );
    int base4(const std::string s);

    bool isAccState( int state );
    void buildDFA( std::string prefix, int n, int k );


    void printDFA();

    int delta( int state, int input );
    std::vector<int> Current;
    std::vector<int> Next;

    int count( int n );
private:
    std::vector<int> dfaVector;
};

#endif //PROBLEM_1_DFA_HPP
