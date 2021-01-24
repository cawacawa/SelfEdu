#include <iostream>
#include <ctime>

using namespace std;

int rows, cols;
int MIN, MAX ;

void PrintArray(int** arr)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "   ";
		}
		cout << endl;
	}
}
void FillArrayRandom(int** arr)
{
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % MAX * 2 + MIN;
		}
	}
}

int main() 
{
	cout << " rows and cols: ";
	cin >> rows >> cols;
	cout << " min and max: ";
	cin >> MIN >> MAX;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
	    arr[i] = new int[cols];
	}
	
	FillArrayRandom(arr);
	PrintArray(arr);
	
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}