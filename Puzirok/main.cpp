#include <iostream>
#include <ctime>

void fillArrRandom(int* arr, int size) 
{
	const int maxNumberInArray = 9;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % maxNumberInArray + 1;
	}
}
void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
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
void mySwap(int &a, int &b)
{
	if (&a != &b) 
	{
		int tmp = 0;
		tmp = a;
		a = b;
		b = tmp;
	}
}
void psort(int* arr, int size)
{
	for (int i = 0; i < size; i++) 
	{
		bool flag = true;
		for (int j = 0; j < size - (i + 1); j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				flag = false;
				mySwap(arr[j], arr[j + 1]);
			}
		}
		if (flag) 
		{
			break;
		}
	}
}
int main() 
{
	srand(time(NULL));
	int size = 0;
	std::cout << "Enter array size: ";
	std::cin >> size;
	int* arr = new int[size];


	fillArrRandom(arr, size);
	printArr(arr, size);
	std::cout << std::endl << "Min: " << min(arr, size);
	std::cout << std::endl << "Max: " << max(arr, size);
	psort(arr, size);
	std::cout << std::endl << "Sorted array: ";
	printArr(arr, size);


	delete[] arr;
	return 0;
}