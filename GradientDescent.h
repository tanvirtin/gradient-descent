#ifndef GRADIENTDESCENT_H
#define GRADIENTDESCENT_H

#include <vector> // used to import the stl vector class
#include <fstream> // used to create an object to read and write fils
#include <string> // used to import the string object
#include <iostream> // used to take input output
using namespace std; // to void writing the scope resolution operator to access the std namespace


// The basic idea is to reduce the cost function by descending down the gradient of the cost function
// with respect to one of the variables in the cost funciton. 

// cost = 1/N * sigma ((y - mx + b) ** 2)

// the partial differentiation of cost with respect to x and b should give us a direction
// from the reseult to descent our gradient accordingly to plot the best curve to fit through
// the data points


class GradientDescent {

	public:
		void generateData(string);
		void displayData();
		void batchTrain(float*, float*, float); // takes in a m and b value and the learning rate

	private:
		void gradDesc(float*, float*, float); // takes in a m and b value and the learning rate 
		vector<vector<float>> points;

};

#endif