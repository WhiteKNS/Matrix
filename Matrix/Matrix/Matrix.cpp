#include<iostream>
#include<stack>
#include<vector>
#include <ctime>
#include <iterator>
#include <fstream>
#include "MatrixLogic.h"

using namespace std;


int main(){
	srand((unsigned)time(NULL));
	int Line, Column;
	cout << "Input number of lines!" << endl;
	cin >> Line;
	cout << "Input number of columns!" << endl;
	cin >> Column;
	Matrix matrix(Line, Column);
	matrix.Main();
	return 0;
}