#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char symbols[100][10] = {""};
int symtop = 0;
int symref[100] = {0};
int symreftop = 0;
char yyy;
int isKeyword(char buffer[ ]) {
	char keyword[33][10] = {
		"auto", "break", "case", "char", "const", "continue", "default", "do", "double",
		"else", "enum", "extern", "float", "for", "goto","if", "int", "long", "register",
		"return", "short", "signed", "sizeof", "static", "switch", "struct", "typedef",
		"union", "unsigned", "void", "volitile", "while", "printf",
	};
	int i, flag = 0;
	for (i=0; i<33; i++){
		if (strcmp(keyword[i], buffer)==0){
			flag = 1;
			break;
		}
	}

	return flag;
}

int isDetected(char buffer[ ]){
	int flag = 0;
	for (int i=0; i<100; i++){
		if (strcmp(symbols[i], buffer) == 0){
			flag = 1;
			break;
		}
		if (strcmp(symbols[i],"") == 0){
			break;
		}
	}
	return flag;
}

// int findIndex(char buffer[ ]){
// 	for (int i=0 i<)
// }

void main(){
	char ch, ch1, buffer[50], operator[]  = {'+', '=', '*', '/', '%'};
	char opname[5][3] = {"AD","EQ", "ML", "DV", "MD"};
	FILE *fp;
	FILE *op;
	op = fopen("symtab.txt", "w");
	if (op == NULL){
		printf("Error while creating SYMBOLS.txt!!\n");
	}
	int i, j=0, l=1;
	fp = fopen("code.txt", "r");
	if (fp == NULL){
		printf("Error while opening file!!\n");
		exit(0);
	}
	else {
		printf("Lexeme\tLine\tToken\n");
		while ((ch = fgetc(fp)) != EOF) {
			// Checking for arithmetic operator
			for (i=0; i<5; ++i) {
				if (ch==operator[i]){
					// char name = opname[i];
					printf("%c\t%d\tArithmetic Operator, %s\n", ch,l, opname[i]);
					break;
				}
			}
			if (i==5){
				if(isalnum(ch)){
					if (isdigit(ch) && j == 0){
					yyy=ch;
					 }
					else {
						buffer[j++] = ch;
						ch1 = fgetc(fp);
						if (isalnum(ch1))
							fseek(fp, -1, SEEK_CUR);
						else {
							fseek(fp, -1, SEEK_CUR);
							buffer[j] = '\0';
							if (isKeyword(buffer) == 1) {
								printf("%s\t%d\tKeyword\n", buffer, l);
								j = 0;
							}
							else {
								if (strcmp(buffer, "main") != 0 && strcmp(buffer, "HELLO") != 0 && strcmp(buffer, "World") != 0){
									// printf("%s\t\t%d\t\tIdentifier, %d\n", buffer, l, symreftop);
									
									if (!isDetected(buffer)){
										symreftop++;
										// symbols[symtop++] = buffer;
										for (int k=0; k<strlen(buffer); k++){
										symbols[symtop][k] = buffer[k];
										}
										// symbols[symtop][++k]
										symtop++;
										fprintf(op, "%d", symtop);
										fprintf(op, "\t");
										fprintf(op, buffer);
										if(strcmp(buffer,"c")==0){
											fprintf(op,"\t%i",atoi(yyy));
										}
										else{
											fprintf(op,"\t-");
										}
										fprintf(op, "\n");
									}
									for (int k=0;k<100; k++){
										if (strcmp(symbols[k], buffer)== 0)
										printf("%s\t%d\tIdentifier, %d\n", buffer, l, k+1);
									}
								}
									j = 0;
							}
						}
					}
				}
				if (ch == '>'){
					ch1 = fgetc(fp);
					if (ch1 == '='){
						printf("%c%c\t%d\tRelational Operator, GE\n", ch, ch1, l);
					}
					else {
						fseek(fp, -1, SEEK_CUR);
						printf("%c\t%d\tRelational Operator, GT\n", ch, l);
					}
				} else if (ch == '<'){
					ch1 = fgetc(fp);
					if (ch1 == '='){
						printf("%c%c\t%d\tRelational Operator, LE\n", ch, ch1, l);
					}
					else {
						fseek(fp, -1, SEEK_CUR);
						printf("%c\t%d\tRelational Operator, LT\n", ch, l);
					}
				}
				// if (ch == '<' || ch == '>'){
				// 	ch1 = fgetc(fp);
				// 	if (ch1 == '=')
				// 		printf("%c%c\t\t%d\t\tRelational Operator\n", ch, ch1, l);
				// 	else {
				// 		fseek(fp, -1, SEEK_CUR);
				// 		printf("%c\t\t%d\t\tRelational Operator\n", ch, l);
				// 	}
				// }
				else if (ch == '=') {
					ch1 = fgetc(fp);
					if (ch1 == '='){
						printf("%c%c\t%d\tRelational Operator, EQ\n", ch, ch1, l);
					}
					else {
						fseek(fp, -1, SEEK_CUR);
						printf("%c\t%d\tAssignment Operator\n", ch, l);
					}
				}
				if (ch == '\n')
					l++;
			}
		}
	}
}

