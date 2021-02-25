#include <iostream>
#include <ctime>

int g_minValue = 0, g_maxValue = 0;

int** newMatrix(int rows, int cols) 
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	return matrix;
}
void deleteMatrix(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
void printMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << "   ";
		}
		std::cout << std::endl;
	}
}
void fillMatrixRandom(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = rand() % g_maxValue * 2 + g_minValue;
		}
	}
}
int** transposeMatrix(int** matrix, int** transposed, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{ 
			transposed[j][i] = matrix[i][j];  
		}
	}
	return transposed;
}

int main() 
{
	srand(time(NULL));
	int rows = 0, cols = 0;
	std::cout << " rows and cols: ";
	std::cin >> rows >> cols;
	std::cout << " min and max: ";
	std::cin >> g_minValue >> g_maxValue;
	
	int** mtrx = newMatrix(rows, cols);
	fillMatrixRandom(mtrx, rows, cols);
	printMatrix(mtrx, rows, cols);
	std::cout << std::endl;
	int** tmtrx = newMatrix(cols, rows);
	transposeMatrix(mtrx,tmtrx, rows, cols);
	printMatrix(tmtrx, cols, rows);
	
	
	deleteMatrix(mtrx, rows);
	deleteMatrix(tmtrx, cols);
	return 0;
}