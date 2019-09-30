#include "LexicalAnalyzer.h"

/* main function */
void main(void)
{
	char file[FILE_NAME_SIZE];

	fputs("INPUT: ", stdout);
	scanf_s("%s",file, FILE_NAME_SIZE);
	Test(file);
}


