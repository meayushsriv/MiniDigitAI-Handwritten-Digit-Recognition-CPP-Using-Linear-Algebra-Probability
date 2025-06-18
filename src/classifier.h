#pragma once
#include <vector>
#include "utils.h"

class NaiveBayesClassifier
{
    int num_classes;
    int feature_size;
    std::vector<std::vector<double>> mean, var;
    std::vector<double> prior;

public:
    NaiveBayesClassifier(int classes = 10);
    void train(const std::vector<Sample> &data);
    int predict(const std::vector<double> &input) const;
};
