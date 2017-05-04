#include <iostream>
using namespace std;

#include "GradientDescent.h"

int main() {

	GradientDescent g;
	float m = 0;
	float b = 0;

	g.generateData("data.csv");
	g.batchTrain(&m, &b, 0.0001);

	cout << "Value for m in equation y = mx + b --> " << m << endl;

	cout << "Value for b in equation y = mx + b --> " << b << endl;


	return 1;
}