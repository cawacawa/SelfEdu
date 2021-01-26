#include <iostream>
#include <ctime>

using namespace std;


int g_minValue, g_maxValue;

int** newMatrix(int rows, int cols) 
{
	int** MATRIX = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		MATRIX[i] = new int[cols];
	}
	return MATRIX;
}
void deleteMatrix(int** MATRIX, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] MATRIX[i];
	}
	delete[] MATRIX;
}
void PrintMatrix(int** MATRIX, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << MATRIX[i][j] << "   ";
		}
		cout << endl;
	}
}
void FillMatrixRandom(int** MATRIX, int rows, int cols)
{
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			MATRIX[i][j] = rand() % g_maxValue * 2 + g_minValue;
		}
	}
}
int** newTransposedMatrix(int** MATRIX, int rows, int cols)
{
	int** transposed = newMatrix(cols, rows);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{ 
			transposed[j][i] = MATRIX[i][j];  
		}
	}
	return transposed;
}

int main() 
{
	int Rows, Cols;
	cout << " rows and cols: ";
	cin >> Rows >> Cols;
	cout << " min and max: ";
	cin >> g_minValue >> g_maxValue;
	
	int** mtrx = newMatrix(Rows, Cols);
	FillMatrixRandom(mtrx, Rows, Cols);
	PrintMatrix(mtrx, Rows, Cols);
	cout << endl;
	int** tmtrx = newTransposedMatrix(mtrx, Rows, Cols);
	PrintMatrix(tmtrx, Cols, Rows);
	
	
	deleteMatrix(mtrx, Rows);
	deleteMatrix(tmtrx, Cols);
	return 0;
}