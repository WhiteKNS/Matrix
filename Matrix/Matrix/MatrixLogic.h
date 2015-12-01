#ifndef MATRIXLOGIC_H
#define MATRIXLOGIC_H


#include<iostream>
#include<stack>
#include<vector>
#include <ctime>
#include <iterator>
#include <fstream>

using namespace std;

class Matrix{

	int Lines;
	int Columns;
	int **Field;


	int **BoolField;

	int **FinalField;

	stack<int> StLine; //���������� ���������� �������

	stack<int> StColumn;

	stack<int> StackLines; //���������� ���������(4)

	stack<int> StackColumns;//���������� (4)

	stack<int> StackCounter; //�� 1 ����� � � ������ 4 ����

	stack<int> FinalStackLines; //���� ��� �������� ��������� �����������

	stack<int> FinalStackColumns;

	vector<int> vecLines;

	vector<int> vecColumns;

	bool End;

	int counter;

	long result; // ������������� ���������

	long maxResult; //���� ���������

	ofstream fout;// ���� � ������������


	long getMaxResult();

	long getResult();

	void PrintFirstFieldToFile();

	void PrintMaxResultToFile();

	void getPrintFinalField();

	void Initialize();

	void ClearBool();

	void PrintField();

	void PrintBool();

	void const MethodPush(int const i, int const j);

	bool const Check(int const lineStack, int const columnStack, int  **BoolField);

	long Result();

	long FindMaxResult();

	void const SaveAllToFile();

	void const PrintFinalFieldToFile();

	void IfSumIsEqualToTen(int const &LineStack, int const &ColumnStack, int &Line, int&Column, int &Sum);

	void IfSumGreaterThatTen(int const& LineStack, int const& ColumnStack, int &Line, int &Column, int &Sum);

	void IfCanCheckThisCell(int &LineStack, int &ColumnStack);

	void IfCanntCheckCell(int &LineStack, int &ColumnStack, int &Sum, int &Line, int &Column);

	void Method(int const &i, int const &j, int &Sum);

	void StackClear(stack<int> &st);

	void Clear();

public:

	Matrix();

	Matrix(int const Lines, int const Columns);

	Matrix(const Matrix &obj);

	~Matrix();

	void Main();
};

#endif