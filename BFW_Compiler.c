#include "BFW_Interpreter.c"

void BrainFuckwitCompiler()
{
	suint counter = 0;
	FILE *bfwFile = fopen("compiledbfwscript.c", "w+");
	fprintf(bfwFile, "#include <stdio.h>\n");
	fprintf(bfwFile, "#include <stdlib.h>\n");
	fprintf(bfwFile, "#include <time.h>\n\n");
	fprintf(bfwFile, "#define suint short unsigned int\n");
	fprintf(bfwFile, "#define MAX_SIZE 65536\n");
	fprintf(bfwFile, "#define CHECK_BOUNDS (counter > 0) && (counter < MAX_SIZE)\n");
	fprintf(bfwFile, "#define CELL TAPE[counter]\n");
	fprintf(bfwFile, "#define InlineSwap(a, b) ((b = a) (a = 0))\n\n");
	fprintf(bfwFile, "int main()\n{\n");
	fprintf(bfwFile, "srand(time(NULL));\nsuint TAPE[MAX_SIZE} = {0};\nsuint counter, binVal = 0;\n\n");
	while((counter < MAX_QUERY) && (query[counter] != 0))
	{
		switch(query[counter])
		{
			case '+':
			fprintf(bfwFile, "CELL++;\n"); break;
			
			case '-':
			fprintf(bfwFile, "CELL--;\n"); break;
			
			case '>':
			fprintf(bfwFile, "if(CHECK_BOUNDS){counter++;}\n"); break;
			
			case '<':
			fprintf(bfwFile, "if(CHECK_BOUNDS){counter--;}\n"); break;
			
			case '.':
			fprintf(bfwFile, "if(CELL > 255){printf(\"NaC\\n\");} else{printf(\"%%c \", (char)CELL)};\n"); break;
			
			case ':':
			fprintf(bfwFile, "printf(\"%%hu \", CELL);\n"); break;
			
			case ',':
			fprintf(bfwFile, "printf(\"Please enter a character here: \"); scanf(\" %%c\", (char)&CELL);\n"); break;
			
			case ';':
			fprintf(bfwFile, "printf(\"Please enter an integer here: \"); scanf(\" %%hu\", &CELL);\n"); break;
			
			case '/':
			fprintf(bfwFile, "if(counter > 1 && TAPE[counter + 1] == 0){InlineSwap(CELL, TAPE[counter + 1] );}\n"); break;
			
			case '\\':
			fprintf(bfwFile, "if(counter > (MAX_SIZE - 2) && TAPE[counter - 1] == 0){InlineSwap(CELL, TAPE[counter - 1] );}\n"); break;
			
			case '[':
			fprintf(bfwFile, "while(CELL != 0)\n{\n"); break;
			
			case ']':
			fprintf(bfwFile, "}\n"); break;
			
			case '!':
			fprintf(bfwFile, "CELL = 0;"); break;
			
			case '\?':
			fprintf(bfwFile, "CELL = (rand() %% 256) + 1;\n"); break;
			
			case '@':
			fprintf(bfwFile, "CELL *= 2;\n"); break;
			
			case '$':
			fprintf(bfwFile, "binVal = CELL; CELL = 0;\n"); break;
			
			case '#':
			fprintf(bfwFile, "CELL = binVal; binVal = 0;\n"); break;
			
			case '%':
			fprintf(bfwFile, "CELL *= binVal; binVal = 0;\n"); break;
			
			default: break;
		}
		counter++;
	}
	fprintf(bfwFile, "return 0;\n}");
	fclose(bfwFile);
	printw("Thy script compiled!\nDo keep in mind though, until I can figure out how to call GCC within C code, you'll have to build the program manaully.\nPress the any key to continue. "); refresh(); char dummy = getch();
}
