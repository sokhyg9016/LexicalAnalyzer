#include "LexicalAnalyzer.h"

/* add nextChar to lexeme */
void add_Char()
{
	if (lexLen < LEXEME_SIZE - 1)
	{
		lexeme[lexLen++] = nextChar;
		lexeme[lexLen] = '\0';
	}
	else
		fprintf(stderr, "Error :: Lexeme is too Long.\n");
}

/* To get the next character of input and determine its character class*/
void get_Char()
{
	if ((nextChar = getc(fp)) != EOF)
	{
		if (isalpha(nextChar))
			charClass = LETTER;
		else if (isdigit(nextChar))
			charClass = DIGIT;
		else
			charClass = UNKNOWN;
	}
	else
		charClass = EOF;
}

/* To call getChar until it return a non-white_space characters*/
void get_Non_Blank()
{
	while (isspace(nextChar))
		get_Char();
}

/* To lookup operators and parentheses and return the token*/
int Look_Up(char ch)
{
	switch (ch)
	{
	case '(':
		add_Char();
		nextToken = LEFT_PAREN;
		break;

	case ')':
		add_Char();
		nextToken = RIGHT_PAREN;
		break;

	case '=':
		add_Char();
		nextToken = ASSIGN_OP;
		break;

	case ';':
		add_Char();
		nextToken = SEMI_COLON;
		break;

	case '+':
		add_Char();
		nextToken = ADD_OP;
		break;

	case '-':
		add_Char();
		nextToken = SUB_OP;
		break;

	case '*':
		add_Char();
		nextToken = MULT_OP;
		break;

	case '/':
		add_Char();
		nextToken = DIV_OP;
		break;

	default:
		add_Char();
		nextToken = EOF;
		break;
	}
	return nextToken;
}

int Lex()
{
	lexLen = 0;
	get_Non_Blank();

	switch (charClass)
	{
		case LETTER:
		{
			add_Char();
			get_Char();

			/* store & read data until the UNKNOWN or EOF. */
			while (charClass == LETTER || charClass == DIGIT)
			{
				add_Char();
				get_Char();
			}
			nextToken = IDENT;
			break;
		}		
		
		case DIGIT:
		{
			add_Char();
			get_Char();

			/* store & read data until the UNKNOWN or EOF. */
			while (charClass == DIGIT)
			{
				add_Char();
				get_Char();
			}
			nextToken = IDENT;
			break;
		}		
		
		case UNKNOWN:
		{
			Look_Up(nextChar);
			get_Char();
			break;
		}		
		
		case EOF:
		{
			nextToken = EOF;
			lexeme[0] = 'E';
			lexeme[1] = 'O';
			lexeme[2] = 'F';
			lexeme[3] = '\0';
			break;
		}
	}
	/* Print Output*/
	printf("Next token is %d, Next lexeme is %s\n", nextToken, lexeme);
	return nextToken;
}

void Test(const char* file_name)
{
	/* Open the input data file and process its contents */
	if ((err = fopen_s(&fp, file_name, "r")) != 0)
		printf("Error - cannnot open %s.\n", file_name);
	else
	{
		printf("[%s]: output\n", file_name);
		get_Char();

		do
		{
			Lex();
		} while (nextToken != EOF);
	}
}
