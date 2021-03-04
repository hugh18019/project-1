//
// Created by Hugh on 2/25/21.
//

#include "DFA.hpp"
#include <string>
#include <iostream>


dfa::dfa() {
    dfaVector.push_back(0);
}

void dfa::initCurrent() {
    int m = dfaVector.size();
    Current.push_back(0);
    for( int i = 0; i < m - 1; i++ ) {
        Current.push_back(1);
    }
}

std::string dfa::toStr( int v ) {
    std::string s;
    while (v) {
        auto rem = v%4;
        char c;
        if (rem > 0) {
            c = rem-1+'a';
        } else {
            c = 'd';
        }
        s.insert(s.begin(), c);
        v /= 4;
        if (rem == 0) {
            v -= 1;
        }
    }
    return s;
}

int dfa::base4(const std::string s) {
    int v = 0;
    for (size_t i = 0; i < s.length(); i++) {
        v += (s[i]-'a'+1) * pow(4, s.length()-i-1);
    }
    return v;
}

int dfa::delta(int state, int input) {
    auto temp = toStr(state);
    auto temp2 = toStr(input);
    std::string temp3 = temp + temp2;
    if( temp3.size() < 6 )
        return base4(temp3);
    int st = base4(temp3);
    if( isAccState( st ) )
        return st;
    return 0;
}

bool dfa::isAccState(int state) {
    auto temp = toStr( state );
    for( auto each : alphabet ) {
        int count = 0;
        for( auto j : temp ) {
            if( each == j ) {
                count++;
            }
        }
        if( count == 0 )
            return false;
    }
    return true;
}

void dfa::buildDFA(std::string prefix, int n, int k) {
    if( k == 0 ) {
        auto temp = base4(prefix);
        dfaVector.push_back(temp);
        return;
    }
    for( int i = 0; i < n; i++ ) {
        std::string newPrefix;
        newPrefix = prefix + alphabet[i];
        buildDFA( newPrefix, n, k - 1 );
    }
}

void dfa::printDFA() {
    for( auto each : dfaVector ) {
        std::cout << each << std::endl;
    }
}

int dfa::count(int n) {

    int k = alphabet.size();
    int m = Current.size();
    Next.resize( m );

    int tmp;
    for (int c = 1; c <= n; c++) {
        for (int j = 0; j < m; j++) {
            tmp = 0;
            for (int s = 0; s <= k; s++) {
                if( delta(j, s) != 0 )
                    tmp = tmp + Current[delta(j, s)];
            }
            Next[j] = tmp;
        }
        for (int j = 0; j < m; j++) {
            Current[j] = Next[j];
        }
    }

    return Current[0];
}

