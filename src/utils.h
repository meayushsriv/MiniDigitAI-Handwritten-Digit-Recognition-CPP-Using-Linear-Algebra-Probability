#pragma once
#include <vector>
#include <string>

struct Sample
{
    std::vector<double> pixels;
    int label;
};

std::vector<Sample> load_csv(const std::string &filename);
std::vector<double> dot(const std::vector<double> &a, const std::vector<double> &b);
