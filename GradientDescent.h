#ifndef GRADIENTDESCENT_H
#define GRADIENTDESCENT_H

#include <vector> // used to import the stl vector class
#include <fstream> // used to create an object to read and write fils
#include <string> // used to import the string object
#include <iostream> // used to take input output
using namespace std; // to void writing the scope resolution operator to access the std namespace

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