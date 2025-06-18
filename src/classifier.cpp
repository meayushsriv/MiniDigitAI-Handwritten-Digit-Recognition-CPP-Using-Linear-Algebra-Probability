#include "classifier.h"
#include <cmath>
#include <numeric>

NaiveBayesClassifier::NaiveBayesClassifier(int classes) : num_classes(classes) {}

void NaiveBayesClassifier::train(const std::vector<Sample> &data)
{
    feature_size = data[0].pixels.size();
    mean.assign(num_classes, std::vector<double>(feature_size, 0.0));
    var.assign(num_classes, std::vector<double>(feature_size, 1e-5));
    prior.assign(num_classes, 0);

    std::vector<int> count(num_classes, 0);

    for (const auto &s : data)
    {
        prior[s.label]++;
        count[s.label]++;
        for (size_t i = 0; i < feature_size; ++i)
            mean[s.label][i] += s.pixels[i];
    }

    for (int c = 0; c < num_classes; ++c)
        for (int i = 0; i < feature_size; ++i)
            mean[c][i] /= count[c];

    for (const auto &s : data)
        for (int i = 0; i < feature_size; ++i)
        {
            double diff = s.pixels[i] - mean[s.label][i];
            var[s.label][i] += diff * diff;
        }

    for (int c = 0; c < num_classes; ++c)
        for (int i = 0; i < feature_size; ++i)
            var[c][i] /= count[c];

    for (int c = 0; c < num_classes; ++c)
        prior[c] /= data.size();
}

int NaiveBayesClassifier::predict(const std::vector<double> &input) const
{
    double best_prob = -1e9;
    int best_class = -1;

    for (int c = 0; c < num_classes; ++c)
    {
        double log_prob = std::log(prior[c]);
        for (int i = 0; i < feature_size; ++i)
        {
            double x = input[i];
            double m = mean[c][i], v = var[c][i];
            log_prob += -0.5 * std::log(2 * M_PI * v) - ((x - m) * (x - m)) / (2 * v);
        }
        if (log_prob > best_prob)
        {
            best_prob = log_prob;
            best_class = c;
        }
    }
    return best_class;
}
