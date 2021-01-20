#include <iostream>
#include <cstring>

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
int my_strstr(char* source, char* target) 
{
	
	for (int i = 0; source[i] != 0; i++) 
	{
		for (int j = 0; source[i + j] == target[j]; j++) 
		{
			if (j+1 == my_strlen(target)) return i;
		}
	}
	return -1;
}
int charstr(char* source, char target) 
{ 
	int i = 0;
	for (; source[i] != target; i++);
	return i;
}
void destiny(char* str, char* newstr)
{ 
	chetnechet(str, newstr);
	char ric[4] { 'r','i','c' };
	char bit[4] { 'b','i','t' };
	char go[3] { 'g','o' };
	char ba[3]  { 'b','a' };	
	char p = 'p';
	if (my_strstr(newstr, ric) > -1) 
	{
		cout << endl << "Wealth = " << my_strstr(newstr, ric) * 100 / my_strlen(newstr) << "%" << endl;
	}
	if (my_strstr(newstr, bit) > -1)
	{
		cout << endl << "Gnida na " << my_strstr(newstr, bit) * 100 / my_strlen(newstr) << "%" << endl;
	}
	if (my_strstr(newstr, go) > -1)
	{
		cout << endl << "Life enjoyer na " << my_strstr(newstr, go) * 100 / my_strlen(newstr) << "%" << endl;
	}
	if (my_strstr(newstr, ba) > -1)
	{
		cout << endl << "Schizophrenia = " << my_strstr(newstr, ba) * 100 / my_strlen(newstr) << "%" << endl;
	}
	if (charstr(newstr, p) < my_strlen(newstr))
	{
		cout << endl << "Patau-dodik progression = " << charstr(newstr, p) * 100 / my_strlen(newstr) << "%";
	}
}


int main() 
{
	char str[25] = {};
	char newstr[50] = {};
	cin >> str;
	
	destiny(str, newstr);
	
	
	return 0;
}
