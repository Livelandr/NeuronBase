#include "neuron.h"


Neuron::Neuron(neuronFunctions::TYPE activ) {
    activatorFunc = activ;
}

void Neuron::setActivatorFunc(neuronFunctions::TYPE activ) {
    activatorFunc = activ;
}

void Neuron::setWeight(double val) {
     weight = val;
}


void Neuron::addWeight(double _offset) {
    weight += _offset;
}

double Neuron::getLastValue() {
    return lastGeneratedValue;
}
double Neuron::getLastError() {
    return lastError;
}

void Neuron::setWeightOffsetSmoothing(double smooth) {
    weightOffsetSmoothing = smooth;
};

double Neuron::calculate(double input) {
     lastGeneratedValue = neuronFunctions::neuronFunction(input * weight, activatorFunc);
     return lastGeneratedValue;
}

void Neuron::train(double input, double expected) {
    calculate(input);
    lastError = expected - getLastValue();

    double correction = lastError * learningRate;

    addWeight(correction);
}
