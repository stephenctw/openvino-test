
#pragma once
#include <atomic>
struct DetectionResult
{
    int count;
    int maleCount;
    int femaleCount;
    //std::vector<int> label;
    //std::vector<float> confidence;
    //std::vector<int> age;
    
    DetectionResult(){}
    DetectionResult(int max)
    {
        count = 0;
        maleCount = 0;
        femaleCount = 0;
        //label.resize(max, 0);
        //confidence.resize(max, 0.0);        
        //age.resize(max, 0);
    }
};

int foo(std::atomic<DetectionResult>* result);