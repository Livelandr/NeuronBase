#pragma once
#define _USE_MATH_DEFINES
#include <cmath>


namespace neuronFunctions {

	enum TYPE {
		SIGM,
		RELU,
		LINEAR,
		STEP,
		SOFTPLUS,
	};

	double sigm(double x);
	double relu(double x);
	double linear(double x);
	double step(double x);
	double softplus(double x);

	double neuronFunction(double x, TYPE type);


};