/***********************
Lexical Analyzer Program

> Date: 2019. 09. 20
> Program Description:
1.This program read the data from file and print some
  tokens and lexemes.
2. [input]: input file(input.txt)
3. [output]: tokens and lexemes

************************/

#pragma once
#include <stdio.h>
#include <ctype.h>

#define LEXEME_SIZE 100

/* Character Classes 
/**********************
1. LETTER(A-Z/a-Z)
2. DIGIT(0-9)
3. UNKNOWN(Identifiers, etc..)
**********************/

#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token Codes */ 
/***************
1. int values
2. Identifiers(variable names)
3. assign operator(=)
4. Add, Sub, Mult, Div(+, -, *, /)
5. Left, Right parentheses('(', ')')
6. Semicolon(;)
****************/

#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26
#define SEMI_COLON 27

/* Test function macro */
#define FILE_NAME_SIZE 100

/* Global declarations*/
/* Variables */
int charClass;
char lexeme[LEXEME_SIZE];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE* fp;
errno_t err;

/* Function Declarations */
void add_Char();
void get_Char();
void get_Non_Blank();
int Look_Up(char ch);
int Lex();

/* Test Func*/
void Test(const char* file_name);


