#include "utils.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Sample> load_csv(const std::string &filename)
{
    std::ifstream file(filename);
    std::vector<Sample> data;
    std::string line;

    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string val;
        Sample s;
        getline(ss, val, ',');
        s.label = std::stoi(val);

        while (getline(ss, val, ','))
        {
            s.pixels.push_back(std::stod(val) / 255.0); // normalize pixel
        }
        data.push_back(s);
    }
    return data;
}

std::vector<double> dot(const std::vector<double> &a, const std::vector<double> &b)
{
    std::vector<double> result(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        result[i] = a[i] * b[i];
    return result;
}
