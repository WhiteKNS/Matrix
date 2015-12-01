
#include<iostream>
#include<stack>
#include<vector>
#include <ctime>
#include <iterator>
#include <fstream>
#include "MatrixLogic.h"

using namespace std;




	long Matrix::getMaxResult(){
		return maxResult;
	}


	long  Matrix::getResult(){
		return result;
	}


	void  Matrix::PrintFirstFieldToFile(){
		fout.open("results.txt", ios_base::out | ios_base::app);
		if (!fout.is_open())
		{
			cerr << "Can't open this file!" << endl;

		}
		else
		{
			for (int i = 0; i < Lines; i++, fout << "\n"){
				for (int j = 0; j < Columns; j++) {
					fout << Field[i][j];
				}
			}
			fout << "\n\n\n";
		}

		fout.close();

	}

	void  Matrix::PrintMaxResultToFile(){
		fout.open("results.txt", ios_base::out | ios_base::app);
		if (!fout.is_open())
		{
			cerr << "Can't open this file!" << endl;
		}
		else{
			fout << "\nThe best result is: " << getMaxResult() << endl;
		}

		fout.close();
	}

	void  Matrix::getPrintFinalField(){
		for (int i = 0; i < Lines; i++, cout << "\n"){
			for (int j = 0; j < Columns; j++) {
				cout << FinalField[i][j];
			}
		}
	}


	void  Matrix::Initialize(){
		for (int i = 0; i < Lines; i++){
			for (int j = 0; j < Columns; j++) {
				Field[i][j] = rand() % 6;
				BoolField[i][j] = 1;
				FinalField[i][j] = 0;
			}
		}
	}


	void Matrix::ClearBool(){
		for (int i = 0; i < Lines; i++){
			for (int j = 0; j < Columns; j++) {
				BoolField[i][j] = 1;
			}
		}
	}

	void Matrix::PrintField(){
		for (int i = 0; i < Lines; i++, cout << "\n"){
			for (int j = 0; j < Columns; j++) {
				cout << Field[i][j];
			}
		}
	}


	void Matrix::PrintBool(){
		for (int i = 0; i < Lines; i++, cout << "\n"){
			for (int j = 0; j < Columns; j++) {
				cout << BoolField[i][j];
			}
		}
	}


	void const Matrix::MethodPush(int const i, int const j){
		StackLines.push(i + 1);
		StackLines.push(i);
		StackLines.push(i);
		StackLines.push(i - 1);
		StackColumns.push(j);
		StackColumns.push(j + 1);
		StackColumns.push(j - 1);
		StackColumns.push(j);
		StackCounter.push(4);
	}

	bool const Matrix::Check(int const lineStack, int const columnStack, int  **BoolField){
		if (lineStack < 0 || lineStack >= Lines || columnStack < 0 || columnStack >= Columns) { return false; }
		else if (BoolField[lineStack][columnStack] == 0) { return false; }
		else return true;
	}


	long  Matrix::Result(){
		result = 0;
		int Line;
		int Column;
		int x = 1;

		for (int i = vecLines.size() - 1; i >= 0; i--) {

			Line = vecLines.at(i);
			Column = vecColumns.at(i);

			if (BoolField[Line][Column] == 0){
				result += Field[Line][Column] * x;
				x *= 10;
			}
		}
		return result;
	}

	long Matrix::FindMaxResult(){
		if (Result() > maxResult){
			maxResult = getResult();
			for (int i = 0; i < Lines; i++){
				for (int j = 0; j < Columns; j++){
					if (BoolField[i][j] == 0) FinalField[i][j] = Field[i][j];
					else FinalField[i][j] = 0;
				}
			}
		}
		return maxResult;
	}


	void const Matrix::SaveAllToFile()
	{
		fout.open("results.txt", ios_base::out | ios_base::app);
		if (!fout.is_open())
		{
			cerr << "Can't open this file!" << endl;

		}
		else{
			for (int i = 0; i < Lines; i++){
				for (int j = 0; j < Columns; j++){
					if (BoolField[i][j] == 0) fout << Field[i][j];
					else fout << 0;
				}
				fout << "\n\n\n";
			}

			fout << "Result is " << result << "\n\n" << endl;
		}

		fout.close();

	}



	void const Matrix::PrintFinalFieldToFile(){
		fout.open("results.txt", ios_base::out | ios_base::app);
		if (!fout.is_open())
		{
			cerr << "Can't open this file!" << endl;
		}
		else{
			for (int i = 0; i < Lines; i++, fout << "\n"){
				for (int j = 0; j < Columns; j++){
					fout << FinalField[i][j];
				}
			}
		}

		fout.close();
	}


	void  Matrix::IfSumIsEqualToTen(int const &LineStack, int const &ColumnStack, int &Line, int&Column, int &Sum){

		BoolField[LineStack][ColumnStack] = 0;
		vecLines.push_back(LineStack);
		vecColumns.push_back(ColumnStack);

		FindMaxResult();
		SaveAllToFile();

		BoolField[LineStack][ColumnStack] = 1;
		Line = StLine.top();
		StLine.pop();
		Column = StColumn.top();
		StColumn.pop();
		Sum -= Field[LineStack][ColumnStack];
		vecLines.pop_back();
		vecColumns.pop_back();
		vecLines.pop_back();
		vecColumns.pop_back();
	}


	void  Matrix::IfSumGreaterThatTen(int const& LineStack, int const& ColumnStack, int &Line, int &Column, int &Sum){

		BoolField[LineStack][ColumnStack] = 1;

		if (!vecLines.empty()) {
			vecLines.pop_back();
		}
		if (!vecColumns.empty()) {
			vecColumns.pop_back();
		}

		Line = StLine.top();
		StLine.pop();
		Column = StColumn.top();
		StColumn.pop();
		Sum -= Field[LineStack][ColumnStack];
	}


	void Matrix::IfCanCheckThisCell(int &LineStack, int &ColumnStack){
		counter = StackCounter.top();
		LineStack = StackLines.top();
		StackLines.pop();
		ColumnStack = StackColumns.top();
		StackColumns.pop();
		counter = StackCounter.top();
		StackCounter.pop();
		StackCounter.push(--counter);
	}

	void  Matrix::IfCanntCheckCell(int &LineStack, int &ColumnStack, int &Sum, int &Line, int &Column){
		counter = StackCounter.top();
		Sum -= Field[Line][Column];
		BoolField[Line][Column] = 1;
		StLine.pop();
		StColumn.pop();
		Line = StLine.top();
		StLine.pop();
		Column = StColumn.top();
		StColumn.pop();
		StackCounter.pop();
		vecLines.pop_back();
		vecColumns.pop_back();

	}

	void Matrix::Method(int const &i, int const &j, int &Sum){
		int Line = i;
		int Column = j;
		int LineStack = -5;
		int ColumnStack = -5;

		StLine.push(Line);
		StColumn.push(Column);

		BoolField[Line][Column] = 0;

		if (!StackLines.empty()) {

			if (StackCounter.top() > 0) {
				IfCanCheckThisCell(LineStack, ColumnStack);
			}
			else {

				IfCanntCheckCell(LineStack, ColumnStack, Sum, Line, Column);
				Method(Line, Column, Sum);
			}
		}
		else { End = true;  return; }
		if (End) return;

		if (Check(LineStack, ColumnStack, BoolField)){

			vecLines.push_back(Line);
			vecColumns.push_back(Column);
			if (End) return;
			Sum += Field[LineStack][ColumnStack];


			if (Sum == 10){

				IfSumIsEqualToTen(LineStack, ColumnStack, Line, Column, Sum);

				Method(Line, Column, Sum);
			}

			if (Sum > 10){

				IfSumGreaterThatTen(LineStack, ColumnStack, Line, Column, Sum);

				Method(Line, Column, Sum);
			}

			if (Sum < 10){

				BoolField[LineStack][ColumnStack] = 0;

				MethodPush(LineStack, ColumnStack);

				Method(LineStack, ColumnStack, Sum);
			}
		}

		else {

			if (!StLine.empty()) StLine.pop();

			if (!StColumn.empty()) StColumn.pop();

			Method(Line, Column, Sum);
		}


	}

	void Matrix::StackClear(stack<int> &st){
		while (!st.empty()){
			st.pop();
		}
	}

	void  Matrix::Clear(){
		vecLines.clear();
		vecColumns.clear();
		StackClear(StLine);
		StackClear(StColumn);
		StackClear(StackLines);
		StackClear(StackColumns);
		StackClear(StackCounter);
		StackClear(FinalStackColumns);
		StackClear(FinalStackLines);
		ClearBool();
	}


	Matrix::Matrix(){
		Lines = 5;
		Columns = 5;
		BoolField = new int *[Lines];
		for (int i = 0; i < Lines; i++){
			BoolField[i] = new int[Columns];
		}

		Field = new int *[Lines];
		for (int i = 0; i < Lines; i++){
			Field[i] = new int[Columns];
		}

		FinalField = new int *[Lines];
		for (int i = 0; i < Lines; i++){
			FinalField[i] = new int[Columns];
		}



		End = false;
		counter = 4;
		result = 0;
		maxResult = 0;

		fout.open("results.txt", ios_base::trunc);
		fout.close();
	}

	Matrix::Matrix(int const Lines, int const Columns){

		this->Lines = Lines;
		this->Columns = Columns;

		BoolField = new int *[Lines];
		for (int i = 0; i < Lines; i++){
			BoolField[i] = new int[Columns];
		}

		Field = new int *[Lines];
		for (int i = 0; i < Lines; i++){
			Field[i] = new int[Columns];
		}

		FinalField = new int *[Lines];
		for (int i = 0; i < Lines; i++){
			FinalField[i] = new int[Columns];
		}


		End = false;
		counter = 4;
		result = 0;
		maxResult = 0;

		fout.open("results.txt", ios_base::trunc);
		fout.close();
	}

	Matrix::Matrix(const Matrix &obj)
	{
		cout << "\nКонструктор копирования\n";
	}

	Matrix::~Matrix()
	{
		for (int i = 0; i < Lines; i++){
			delete[] Field[i];
			delete[] BoolField[i];
			delete[] FinalField[i];
		}

		delete[] Field;
		delete[] BoolField;
		delete[] FinalField;
	}

	void  Matrix::Main(){

		int Sum;

		Initialize();
		PrintField();
		PrintFirstFieldToFile();

		for (int i = 0; i < Lines; i++){
			for (int j = 0; j < Columns; j++){
				//cout << "Start!!!\n\n\n\n\n" << endl;
				End = false;
				int k = i; int l = j;
				Clear();
				MethodPush(k, l);
				Sum = Field[i][j];
				Method(i, j, Sum);
			}
		}

		if (getMaxResult() == 0){
			cerr << "It's no combinations, that give us result is equal to 10" << endl;
			return;
		}

		cout << endl << endl;
		getPrintFinalField();
		PrintFinalFieldToFile();
		PrintMaxResultToFile();
		cout << "\nThe best result is: " << getMaxResult() << endl;

	}