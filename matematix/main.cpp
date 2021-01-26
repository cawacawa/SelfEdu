#include <iostream>
#include <ctime>

using namespace std;

int g_Rows, g_Cols;
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
void deleteMatrix(int** MATRIX)
{
	for (int i = 0; i < g_Rows; i++)
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
void FillMatrixRandom(int** MATRIX)
{
	srand(time(NULL));
	for (int i = 0; i < g_Rows; i++)
	{
		for (int j = 0; j < g_Cols; j++)
		{
			MATRIX[i][j] = rand() % g_maxValue * 2 + g_minValue;
		}
	}
}
int** newTransposedMatrix(int** MATRIX)
{
	int** transposed = newMatrix(g_Cols, g_Rows);
	for (int i = 0; i < g_Rows; ++i)
	{
		for (int j = 0; j < g_Cols; ++j) 
		{ 
			transposed[j][i] = MATRIX[i][j];  
		}
	}
	return transposed;
}

int main() 
{
	cout << " rows and cols: ";
	cin >> g_Rows >> g_Cols;
	cout << " min and max: ";
	cin >> g_minValue >> g_maxValue;
	
	int** mtrx = newMatrix(g_Rows, g_Cols);
	FillMatrixRandom(mtrx);
	PrintMatrix(mtrx, g_Rows, g_Cols);
	cout << endl;
	int** tmtrx = newTransposedMatrix(mtrx);
	PrintMatrix(tmtrx, g_Cols, g_Rows);
	
	
	deleteMatrix(mtrx);
	deleteMatrix(tmtrx);
	return 0;
}