#include "neuron.h"


Neuron::Neuron(int weightCount, neuronFunctions::TYPE activ) {
    weights.resize(weightCount);
    activatorFunc = activ;
}

void Neuron::setActivatorFunc(neuronFunctions::TYPE activ) {
    activatorFunc = activ;
}

void Neuron::setWeight(int index, double val) {
     weights[index] = val;
}

void Neuron::setWeights(std::vector<double>& _weights) {
    weights = _weights;
}

void Neuron::addWeights(std::vector<double>& _offset) {
    for (int i = 0; i < _offset.size(); i++) {
        weights[i] += _offset[i];
    }
}

void Neuron::revWeights(std::vector<double>& _offset) {
    for (int i = 0; i < _offset.size(); i++) {
        weights[i] -= _offset[i];
    }
}

double Neuron::GetLastValue() {
    return lastGeneratedValue;
}


void Neuron::setWeightOffsetSmoothing(double smooth) {
    weightOffsetSmoothing = smooth;
};

double Neuron::calculate(std::vector<double>& input) {
     int count = (input.size() <= weights.size()) ? count = input.size() : count = weights.size();

     double sum = 0;

     for (int i = 0; i < count; i++) {
        sum += input[i] * weights[i];
     }
     lastGeneratedValue = neuronFunctions::neuronFunction(sum, activatorFunc);
     return lastGeneratedValue;
}
