#pragma once
#include <vector>
#include "functions.h"

class Neuron {
private:
    double lastGeneratedValue = 0;
    double lastError;
public:
    double weight = 1;
    neuronFunctions::TYPE activatorFunc;
    double weightOffsetSmoothing = 1;
    double learningRate = 0.01;

    Neuron(neuronFunctions::TYPE activ = neuronFunctions::LINEAR);

    void setWeightOffsetSmoothing(double smooth);

    void setActivatorFunc(neuronFunctions::TYPE activ);
    void setWeight(double val);
    void addWeight(double _offset);
    void train(double input, double expected);

    double getLastValue();
    double getLastError();

    double calculate(double input);
};
