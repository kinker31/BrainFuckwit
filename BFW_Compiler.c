#include "BFW_Interpreter.c"
#define CPATH_MAX 128

void BrainFuckwitCompiler()
{
	suint counter = 0;
	char path[CPATH_MAX]; 
	strcat(strcpy(path, getenv("HOME")), "/bfw/compiledbfwscript.c");
	FILE *bfwFile = fopen(path, "w+");
	if(bfwFile == NULL) {printw("Something went wrong! Aborting..."); refresh(); sleep(5); endwin(); abort();}
	fprintf(bfwFile, "#include <stdio.h>\n");
	fprintf(bfwFile, "#include <stdlib.h>\n");
	fprintf(bfwFile, "#include <time.h>\n\n");
	fprintf(bfwFile, "#define suint short unsigned int\n");
	fprintf(bfwFile, "#define MAX_SIZE 65536\n");
	fprintf(bfwFile, "#define CHECK_BOUNDS (counter > 0) && (counter < MAX_SIZE)\n");
	fprintf(bfwFile, "void InlineSwap(suint *a, suint *b) {*b = *a; *a = 0;}\n\n");
	fprintf(bfwFile, "int main()\n{\n");
	fprintf(bfwFile, "srand(time(NULL));\nsuint TAPE[MAX_SIZE] = {0};\nsuint counter, binVal = 0;\n\n");
	while((counter < MAX_QUERY) && (query[counter] != 0))
	{
		switch(query[counter])
		{
			case '+':
			fprintf(bfwFile, "TAPE[counter]++;\n"); break;
			
			case '-':
			fprintf(bfwFile, "TAPE[counter]--;\n"); break;
			
			case '>':
			fprintf(bfwFile, "if(CHECK_BOUNDS){counter++;}\n"); break;
			
			case '<':
			fprintf(bfwFile, "if(CHECK_BOUNDS){counter--;}\n"); break;
			
			case '.':
			fprintf(bfwFile, "if(TAPE[counter] > 255){printf(\"NaC\\n\");} else{printf(\"%%c \", (char)TAPE[counter]);}\n"); break;
			
			case ':':
			fprintf(bfwFile, "printf(\"%%hu \", TAPE[counter]);\n"); break;
			
			case ',':
			fprintf(bfwFile, "printf(\"Please enter a character here: \"); scanf(\" %%c\", (char)&TAPE[counter]);\n"); break;
			
			case ';':
			fprintf(bfwFile, "printf(\"Please enter an integer here: \"); scanf(\" %%hu\", &TAPE[counter]);\n"); break;
			
			case '/':
			fprintf(bfwFile, "if(counter > 1 && TAPE[counter + 1] == 0){InlineSwap(&TAPE[counter], &TAPE[counter + 1] );}\n"); break;
			
			case '\\':
			fprintf(bfwFile, "if(counter > (MAX_SIZE - 2) && TAPE[counter - 1] == 0){InlineSwap(&TAPE[counter], &TAPE[counter - 1] );}\n"); break;
			
			case '[':
			fprintf(bfwFile, "while(TAPE[counter] != 0)\n{\n"); break;
			
			case ']':
			fprintf(bfwFile, "}\n"); break;
			
			case '!':
			fprintf(bfwFile, "TAPE[counter] = 0;"); break;
			
			case '\?':
			fprintf(bfwFile, "TAPE[counter] = (rand() %% 256) + 1;\n"); break;
			
			case '@':
			fprintf(bfwFile, "TAPE[counter] *= 2;\n"); break;
			
			case '$':
			fprintf(bfwFile, "binVal = TAPE[counter]; TAPE[counter] = 0;\n"); break;
			
			case '#':
			fprintf(bfwFile, "TAPE[counter] = binVal; binVal = 0;\n"); break;
			
			case '%':
			fprintf(bfwFile, "TAPE[counter] *= binVal; binVal = 0;\n"); break;
			
			default: break;
		}
		counter++;
	}
	fprintf(bfwFile, "return 0;\n}");
	fclose(bfwFile);
	system("gcc -o ~/bfw/bfwProg ~/bfw/compiledbfwscript.c");
	printw("Done and done! (You can also see the script the program compiled over at ~/bfw.)\nPress any key to continue. "); 
	refresh(); (void) getch();
}
