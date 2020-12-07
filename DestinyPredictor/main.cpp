#include <iostream>

using namespace std;

int my_strlen(char * str) 
{
	int i = 0;
	while (str[i]!=0) 
	{
        i++;
	}
	return i;
}
void chet(char* str, char* newstr)
{   
	int mid = my_strlen(str) / 2;
	char buffb[12] = {};
	char buffa[12] = {};
	int i = 0;
	while (i!=(my_strlen(str)/2)+1)
	{
		buffb[i++] = str[mid++];		
	} 
	int j = 0;
	while (j != my_strlen(str) / 2)
	{
		buffa[j] = str[j];
		j++;
	} 
	i = 0;
	j = 0;	
	for (; i < my_strlen(buffb); i++)
	{
		newstr[i] = buffb[i];
	}
	for (; i < 2 * my_strlen(buffb), j < my_strlen(buffb); i++, j++)
	{
		newstr[i] = buffa[j];
	}
	j = 0;
	for (; i < 3 * my_strlen(buffb), j < my_strlen(buffb); i++, j++)
	{
		newstr[i] = buffa[j];
	}
	j = 0;
	for (; i < 4 * my_strlen(buffb), j < my_strlen(buffb); i++, j++)
	{
		newstr[i] = buffb[j];
	}
	
}
void nechet(char* str, char* newstr)
{
	int i = 0, j = my_strlen(str)-1;
	for (; i < my_strlen(str), j >= 0; i++, j--)
	{
		newstr[i] = str[j];
	}
	
}
void chetnechet(char* str, char* newstr) 
{
	if (my_strlen(str) % 2 == 0)
	{
		chet(str, newstr);
	}
	else 
	{
		nechet(str, newstr);
	}
	cout << endl << newstr;
}

int main() 
{
	char str[25] = {};
	char newstr[50] = {};
	cin >> str;
	
	chetnechet(str,newstr);
	
	return 0;	
	
}
