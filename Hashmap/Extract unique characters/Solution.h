#include <unordered_map>
string uniqueChar(string str)
{
	// Write your code here
	unordered_map<char, bool> exists;
	int index = 0;
	int strLength = str.size();
	char resultStr[strLength];
	for (int i = 0; i<strLength; i++)
	{
		if (exists.count(str[i])>0)
		{			
			continue;
		}
		resultStr[index] = str[i];
		exists[str[i]] = true;
		index++;
	}	
	resultStr[index] = '\0';
	return resultStr;
}