#ifndef __BUNCH_OF_KEYS_HPP__
#define __BUNCH_OF_KEYS_HPP__

#include <iostream>
using namespace std;

class BunchOfKeys {
    public:
        BunchOfKeys();

        void add();
        void shake();
    
    private:
        int n_keys;
};

#endif