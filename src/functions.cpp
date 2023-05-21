#include "functions.h"

namespace neuronFunctions {
	double sigm(double x) {
		return x / std::sqrt(1 + x * x);
	}

	double relu(double x) {
		return (x > 0) ? x : 0;
	}

	double linear(double x) {
		return x;
	}

	double step(double x) {
		return (x >= 0) ? 1 : 0;
	}

	double softplus(double x) {
		return std::log10(1 + std::pow(M_E, x));
	}

	double neuronFunction(double x, TYPE type) {
		switch (type)
		{
		case neuronFunctions::SIGM:
			return sigm(x);
		case neuronFunctions::RELU:
			return relu(x);
		case neuronFunctions::LINEAR:
			return linear(x);
		case neuronFunctions::STEP:
			return step(x);
		case neuronFunctions::SOFTPLUS:
			return softplus(x);
		}
	}
}