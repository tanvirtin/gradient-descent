#include "GradientDescent.h"

void GradientDescent::generateData(string fileName) {

	ifstream file; // ifstream object declared

	file.open(fileName); // file pointer pointing to the file

	string out; // strings in each line of a file will be assigned to out

	// loop till file.oef() doesn't return a NULL
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
