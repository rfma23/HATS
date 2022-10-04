#include "iostream"
#include "vector"

struct LRBound {
    int left = 0;
    int right = 0;
};

struct Event {
    int x = 0;
    int y = 0;
    int ts = 0;
    int polarity = 0;
};

struct TrainingSample {
    std::vector<float> features;
    std::vector<int> labels;
};

int main(void) 
{
    struct LRBound chicken;
    struct TrainingSample leg;
    leg.features.push_back(15);
    std::cout << "chicken val " << chicken.left;
    std::cout << "oof: " << leg.features.at(0);
    return 0;
}

