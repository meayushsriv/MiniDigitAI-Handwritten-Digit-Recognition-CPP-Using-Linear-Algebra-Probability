#include "classifier.h"
#include "utils.h"
#include <iostream>

int main()
{
    std::vector<Sample> train_data = load_csv("data/mnist_train.csv");
    std::vector<Sample> test_data = load_csv("data/mnist_test.csv");

    NaiveBayesClassifier classifier;
    classifier.train(train_data);

    int correct = 0;
    for (const auto &s : test_data)
    {
        int pred = classifier.predict(s.pixels);
        if (pred == s.label)
            correct++;
    }

    std::cout << "Accuracy: " << (100.0 * correct / test_data.size()) << "%\n";
    return 0;
}
