#include <iostream>


using namespace std;


const int g_strMaxLength = 100;


int myStrstr(char* source, const char* target)
{
	for (int i = 0; source[i] != 0; i++)
	{
		for (int j = 0; source[i + j] == target[j]; j++)
		{
			if (j + 1 == strlen(target)) return i;
		}
	}
	return -1;
}
int targetSum(char* str)
{

	const char* begin = "BEGIN";
	const char* end = "END";
	if ((myStrstr(str, end) < myStrstr(str, begin)) ||
		myStrstr(str, end) == -1 ||
		myStrstr(str, begin) == -1)
	{
		return -1;
	}
	int result = 0;

	for (int i = myStrstr(str, begin) + 5; i < myStrstr(str, end); i++)
	{
		if (str[i] > '0' && str[i] <= '9')
		{
			result += str[i] - '0';
		}
	}
	return result;
}

int main()
{
	FILE* f_ptr = 0; 
	fopen_s(&f_ptr, "testfile.txt", "r");
	if (f_ptr == NULL)
	{
		cout << "error, didn't open the file";
		return -1;
	}

	char filestr[g_strMaxLength]{};
	fread(filestr, sizeof(char), g_strMaxLength, f_ptr);


	cout << targetSum(filestr);


	fclose(f_ptr);
	return 0;
}