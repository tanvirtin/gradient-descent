#include "GradientDescent.h"

void GradientDescent::generateData(string fileName) {
	ifstream file; // ifstream object declared
	file.open(fileName); // file pointer pointing to the file
	string out; // strings in each line of a file will be assigned to out
	// loop till file.oef() doesn't return a false
	while (!file.eof()) {
		vector<float> temp;
		int i = 0;
		string yString = "";		
		string xString = "";
		getline(file, out); // a single line from the file is read and put inside the string object called out
		while (out[i] != ',') {
			yString += out[i];
			++i;
		}
		++i; // this is done to avoid the ',' as the previous while loop breaks
			// at ','
		while (out[i]) { // while out[i] is not NULL
			xString += out[i];
			++i;
		}
		temp.push_back(stof(yString));
		temp.push_back(stof(xString));
		points.push_back(temp);
	}
	file.close(); // close the file that was opened
}

void GradientDescent::displayData() {
	for (int i = 0; i < points.size(); ++i) {
		for (int j = 0; j < points[i].size(); ++j) {
			if (j == 0) cout << "Y-axis: ";
			else cout << "X-axis: ";
			cout << points[i][j] << endl;
		}
		cout << endl;
	}
}


void GradientDescent::gradDesc(float* m, float* b, float learningRate) {
	float gradM = 0; // gradient of M to be accumulated
	float gradB = 0; // gradient of B to be accumulated

	// declaration of the x and y coordinates
	float x = 0; 
	float y = 0;

	// iterating over the dataset and grabbing values of x and y and calculating
	// the partial derivative of the cost function with respect to the m and then
	// with respect with b

	for (int i = 0; i < points.size(); ++i) {
		// assigning the x and y values from the multidimentional array
		x = points[i][0];
		y = points[i][1];

		gradM += -(x * (y - ((*m * x) + *b)));
		gradB += -(y - ((*m * x) + *b));
	}

	// type casting an int to a float for the size which is n in the formula
	float n = static_cast<float>(points.size());

	// averaging the gradient
	gradM = gradM * (2.0 / n);
	gradB = gradB * (2.0 / n);

	// learning the new m and b value
	*m = *m - (gradM * learningRate);
	*b = *b - (gradB * learningRate);
}

void GradientDescent::batchTrain(float* m, float* b, float learningRate) {

	float rM = 0; // value to change starts at 0
	float rB = 0; // value to change starts at 0

	for (int i = 0; i < 10000; ++i)
		gradDesc(&rM, &rB, learningRate);

	*m = rM;
	*b = rB;

}