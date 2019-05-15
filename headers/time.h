#ifndef V1_1_TIME_H
#define V1_1_TIME_H

#include<chrono>
#include<iostream>
#include<fstream>

class Time
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> pradzia_;
    std::chrono::time_point<std::chrono::high_resolution_clock> pabaiga_;
    std::chrono::duration<double> skirtumas_;
public:
    void Start_clock();
    void Stop_clock();
    void Get_time(std::ofstream&, int&);
};

#endif //V1_1_TIME_H