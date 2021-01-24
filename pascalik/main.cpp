#include <iostream>
#pragma warning(disable : 4996)

using namespace std;


const int g_strMaxLength = 100;


int my_strstr(char* source, const char* target)
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
	if ((my_strstr(str, end) < my_strstr(str, begin)) ||
		my_strstr(str, end) == -1 ||
		my_strstr(str, begin) == -1)
	{
		return -1;
	}
	int result = 0;

	for (int i = my_strstr(str, begin) + 5; i < my_strstr(str, end); i++)
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
	FILE* f_ptr = fopen("testfile.txt", "r");
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