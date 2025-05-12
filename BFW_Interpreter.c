#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define suint unsigned short int

#define TAPE_SIZE 65536
#define MAX_QUERY 1024
#define MAX_LOOPS 128

static char query[MAX_QUERY] = {0};

#define WITHIN_BOUNDS (counter > 0) || (counter < (TAPE_SIZE - 1))
// We don't need to worry about another value,
// as the interpreter makes sure one of them is zero before swapping.
void InlineSwap(suint *a, suint *b) { *b = *a; *a = 0; }

//false emulates normal Brainfuck, true lets you input a suint directly
void InterpreterInput(bool type, suint *input)
{
	suint value = 0;
	char typeStr[7] = "a char";
	if(type) {strcpy(typeStr, "an int");}
	printw("Please input %s: ", typeStr); refresh();
	if(!type) {value = (suint)getch();}
	else {scanw(" %hu", &value);}
	*input = value;
}

//False is for '[', true is for ']'.
void BracketLogic(bool type, suint* c)
{
	suint depth = 1;
	static suint loops = 0;
	char a = '['; char b = ']';
	if (type){ a = ']'; b = '[';}
	while(query[*c] != b && depth != 0)
	{
		if(type){(*c)--;} else{(*c)++;}
		if(query[*c] == a) {depth++;}
		if(query[*c] == b) {depth--; if(type){loops++;} else{loops = 0;}}
		if(loops > MAX_LOOPS)
		{
			printw("Way too much looping for my liking! Aborting...\n"); 
			refresh(); sleep(1); endwin(); abort();
		}
	}
}

void BrainFuckwitInterpreter()
{
	suint TAPE[TAPE_SIZE] = {0};
	suint counter, binValue, pointy = 0;
	while((counter < MAX_QUERY) && (query[counter] != 0))
	{
		
		switch(query[counter])
		{
			case '+':
			TAPE[pointy]++; break;
			
			case '-':
			TAPE[pointy]--; break;
			
			case '>':
			if(WITHIN_BOUNDS){pointy++;} break;
			
			case '<':
			if(WITHIN_BOUNDS){pointy--;} break;
			
			case '.':
			if(TAPE[pointy] > 255){printw("NaC "); refresh(); break;}
			printw("%c ", TAPE[pointy]); refresh(); break;
			break;
			
			case ',':
			InterpreterInput(false, &TAPE[pointy]);
			break;
			
			case ':':
			printw("%hu ", TAPE[pointy]); refresh(); break;
			
			case ';':
			InterpreterInput(true, &TAPE[pointy]);
			break;
			
			case '/':
			if((counter > (TAPE_SIZE - 2)) && (TAPE[pointy + 1] == 0))
			{InlineSwap(&TAPE[pointy], &TAPE[pointy + 1]);}
			break;
			
			case '\\':
			if((counter > 1) && (TAPE[pointy - 1] == 0))
			{InlineSwap(&TAPE[pointy], &TAPE[pointy - 1]);}
			break;
			
			case '!':
			TAPE[pointy] = 0; break;
			
			case '\?':
			TAPE[pointy] = (rand() % 256) + 1; break;
			
			case '@':
			TAPE[pointy] *= 2; break;
			
			case '#':
			binValue = TAPE[pointy]; TAPE[pointy] = 0; break;
			
			case '$':
			TAPE[pointy] = binValue; binValue = 0; break;
			
			case '%':
			TAPE[pointy] *= binValue; binValue = 0; break;
			
			case '[':
			if(TAPE[pointy] == 0){BracketLogic(false, &counter);}
			break;
			
			case ']':
			if(TAPE[pointy] != 0) {BracketLogic(true, &counter);}
			break;
			
			default: break;
		}
		counter++;
	}
	printw("The interpreter has finished! Press the any key to continue. "); 
	refresh(); (void) getch();
}
