#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "allocations.h"


char* createDynStr(const char* msg)
{
	char* str;
	char temp[100] = { 0 };
	printf("Enter %s: ", msg);
	scanf("%s", temp);

	str = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	if (!str)
		return NULL;
	strcpy(str, temp);

	return str;
}


char* myGets(char* buffer, int size)
{
	char* ok;
	if (buffer != NULL && size > 0)
	{
		do {
			ok = fgets(buffer, size, stdin);
		} while (ok && ((strlen(buffer) <= 1) && (iscntrl(buffer[0]))));
		if (ok)
		{
			char* back = buffer + strlen(buffer);
			//trim end ctrl chars
			while ((buffer < back) && (iscntrl(*--back)));
			*(back + 1) = '\0';
			return buffer;
		}
		

		buffer[0] = '\0';
	}
	return NULL;
}

void makeUpper(char* str,int size)
{
	str[0] = toupper(str[0]);
	for (int i = 1; i < size; i++)
	{
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
	}
}

void cutSpace(char* str)
{
	char* words = strtok(str, " ");
	char result[256] = "";
	while(words)
	{
		strcat(result, words);
		strcat(result, " ");
		words = strtok(NULL, " ");
	}
	result[strlen(result) - 1] = '\0';
	strcpy(result, str);
}

int isNum(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}



void* safeRealloc(void* base, size_t newByteCount)
{
	void* temp = realloc(base, newByteCount);
	if (!temp)
		free(base);
	return temp;
}

