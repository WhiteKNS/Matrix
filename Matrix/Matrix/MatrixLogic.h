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

	stack<int> StLine; //здесь храним текущую линию и столбик

	stack<int> StColumn;

	stack<int> StackLines; //здесь хранятся точки для окружения(4)

	stack<int> StackColumns;// (4)

	stack<int> StackCounter; //здесь счетчик для подсчета точек окружения

	stack<int> FinalStackLines; //

	stack<int> FinalStackColumns;

	vector<int> vecLines;//здесь удачные ходы

	vector<int> vecColumns;

	bool End;//флаг конца игры

	int counter;

	long result; // результат

	long maxResult; //максимальный результат

	ofstream fout;// файл для записи


	long getMaxResult(); //геттеры

	long getResult();

	void PrintFirstFieldToFile(); //печать начального поля в файл

	void PrintMaxResultToFile();//печать максимального результата в файл

	void getPrintFinalField(); // поле с лучшим результатом на экран

	void Initialize(); //начальная инициализация

	void ClearBool(); //очистка данных

	void PrintField(); //вывод на экран поля

	void PrintBool(); //вывод на экран превдобулевого поля

	void const MethodPush(int const i, int const j);//здесь храним точки окружения

	bool const Check(int const lineStack, int const columnStack, int  **BoolField);//проверка, можем ли походить сюда?

	long Result(); //подсчет результата

	long FindMaxResult(); //находим максимальный результат

	void const SaveAllToFile();//все в файл

	void const PrintFinalFieldToFile();//печать  в файл лучшего результата

	void IfSumIsEqualToTen(int const &LineStack, int const &ColumnStack, int &Line, int&Column, int &Sum); //если сумма равна 10

	void IfSumGreaterThatTen(int const& LineStack, int const& ColumnStack, int &Line, int &Column, int &Sum); //если сумма больше 10

	void IfCanCheckThisCell(int &LineStack, int &ColumnStack);//есть ли еще для текущей точки точки окружения?

	void IfCanntCheckCell(int &LineStack, int &ColumnStack, int &Sum, int &Line, int &Column);

	void Method(int const &i, int const &j, int &Sum);//основной метод поиска ходов

	void StackClear(stack<int> &st); //метод для очистки стека

	void Clear(); //очистить все текущие данные

public:

	Matrix();//конструктор

	Matrix(int const Lines, int const Columns); //конструктор

	Matrix(const Matrix &obj); //конструктор копирования

	~Matrix(); //деструктор

	void Main(); //управляющий метод
};

#endif
