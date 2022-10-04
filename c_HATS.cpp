#include <iostream>
#include <fstream>
#include <stdint.h>

#include <vector>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct LRBound {
    int left = 0;
    int right = 0;
};

struct Event {
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int ts = 0;
    bool polarity;
};

struct TrainingSample {
    std::vector<float> features;
    std::vector<int> labels;
};

int main(void) 
{
    // struct LRBound potato;
    // struct TrainingSample leg;
    // leg.features.push_back(15);
    // std::cout << "chicken val " << potato.left;
    // std::cout << "oof: " << potato.features.at(0);

    char data[1];
    ifstream infile("./dat/training/0/00002.bin", ios::in | ios::binary);
    if(!infile) {
        cout << "AYOOOO";
    }
    cout << "Ok we are trying to read";
    infile.read((char *) &data, sizeof(data));
    cout << "data" << data;
    // std::cout << "Reading data from file";
    // infile >> data;
    // std::cout << data;
    return 0;
}
