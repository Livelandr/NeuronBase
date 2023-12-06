#pragma once
#include <vector>
#include "functions.h"

class Neuron {
private:
    double lastGeneratedValue = 0;
public:
    std::vector<double> weights;
    neuronFunctions::TYPE activatorFunc;
    double weightOffsetSmoothing = 1;

    Neuron(int weightCount, neuronFunctions::TYPE activ = neuronFunctions::LINEAR);

    void setWeightOffsetSmoothing(double smooth);

    void setActivatorFunc(neuronFunctions::TYPE activ);
    void setWeight(int index, double val);
    void setWeights(std::vector<double>& _weights);

    void addWeights(std::vector<double>& _offset);
    void revWeights(std::vector<double>& _offset);

    double getLastValue();

    double calculate(std::vector<double>& input);
};