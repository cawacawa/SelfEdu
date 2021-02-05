#include <iostream>
#include <ctime>

using namespace std;


void fillArrRandom(int* arr, int size) 
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}
int min(int* arr, int size)
{
	int i = 0, j = 0;
	for (; i < size; i++) 
	{
		for (j = 0; j < size; j++) 
		{
			if (arr[i] > arr[j])
			{
				break;
			}
		}
		if (j == size) 
		{
			return arr[i];
		}
	}
	return -1;
}
int max(int* arr, int size)
{
	int i = 0, j = 0;
	for (; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				break;
			}
		}
		if (j == size)
		{
			return arr[i];
		}
	}
	return -1;
}
void sort(int* arr, int size)
{
	int buff = 0;
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] > arr[j]) 
			{
				buff = arr[i];
				arr[i] = arr[j];
				arr[j] = buff;
			}
		}
	}
}

int main() 
{
	const int size = 7;
	int arr[size] = {};
	fillArrRandom(arr, size);
	printArr(arr, size);
	cout << endl;
	sort(arr, size);
	printArr(arr, size);

	return 0;
}