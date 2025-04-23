#include <ncurses.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define suint unsigned short int

#define TAPE_SIZE 65536
#define MAX_QUERY 1024
#define MAX_DEPTH 8
#define MAX_LOOPS 128
#define FMAX 16

static char query[MAX_QUERY] = {0};

#define WITHIN_BOUNDS (counter > 0) || (counter < (TAPE_SIZE - 1))
#define SWAP_LOWBOUNDS (counter > 1) && (TAPE[pointy - 1] == 0)
#define SWAP_HIGHBOUNDS (counter > (TAPE_SIZE - 2)) && (TAPE[pointy + 1] == 0)

// We don't need to worry about another value,
// as the interpreter makes sure one of them is zero before swapping.
void InlineSwap(suint *a, suint *b) { *b = *a; *a = 0; }

void BrainFuckwitInterpreter(char q[])
{
	suint TAPE[TAPE_SIZE] = {0};
	suint depth, loops, counter, binValue, pointy = 0;
	while((counter < MAX_QUERY) && (q[counter] != 0))
	{
		switch(q[counter])
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
			//TODO: Figure out if input should be a function or not
			break;
			
			case ':':
			printw("%hu ", TAPE[pointy]); refresh(); break;
			
			case ';':
			//TODO: Figure out if input should be a function or not
			break;
			
			case '/':
			if(SWAP_HIGHBOUNDS)
			{InlineSwap(&TAPE[pointy], &TAPE[pointy + 1]);}
			break;
			
			case '\\':
			if(SWAP_LOWBOUNDS)
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
			if(TAPE[pointy] == 0)
			{
				depth++;
				while((q[counter] != ']') || (depth != 0))
				{
					counter++;
					if(q[counter] == '[') {depth++;}
					if(q[counter] == ']') {depth--; loops = 0;}
					if(depth > MAX_DEPTH)
					{
						printw("Like I've got the time to tawdle through THAT many brackets. Aborting...\n");
						refresh(); sleep(1); abort();
					}
				}
			}
			break;
			
			case ']':
			if(TAPE[pointy] != 0)
			{
				if(depth == 0) 
				{
					printw(" LOL BUG???\n"); 
					refresh();sleep(1); abort();
				}
				depth++;
				while((q[counter] != '[') || (depth != 0))
				{
					counter--;
					if(q[counter] == ']') {depth++;}
					if(q[counter] == '[') {depth--;}
					if(depth > MAX_DEPTH)
					{
						printw("Like I've got the time to tawdle through THAT many brackets. Aborting...\n");
						refresh(); sleep(1); abort();
					}
				}
				if(loops > MAX_LOOPS) 
				{
					printw("Way too much looping for my liking! Aborting...\n"); 
					refresh(); sleep(1); abort();
				}
				loops++;
				}
			break;
			
			default: break;
		}
		counter++;
	}
}
