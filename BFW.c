#include <ncurses.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define suint unsigned short int

/*
 Brainfuckwit Specification:
 Big 'ol tape, each cell set to 0. Negative values are allowed.
 A 1-value stack is also supported for easier operations.
 
 > : Hop over to the next cell.
 < : Hop over to the previous cell.
 + : Bump up current cell by 1.
 - : Bump down current cell by 1.
 [ : Skip past the next ] you see if the current cell's 0.
 ] : Go back to the last [ you saw if the current cell's 0.
 . : Outputs the current cell as an ASCII char.
 , : Overwrite the current cell's value with a ASCII char (from user).
 ':' : Outputs the current cell as a number.
 ';' : Overwrite the current cell's value with a nnumber (from user).
 $ : Replace cell with the bin's value, latter gets set back to 0.
 # : Put the cell's value in the bin, removing it from the cell.
 ? : Overwrite current cell with a random number from 1 to 255.
 ! : Resets the current cell back to 0.
 @ : Doubles the current cell.
 % : Multiplies the current cell by the bin's value.
     (This deletes the bin's value) (Does nothing if the bin is 0)
 / : If the next cell's 0, then shift the current cell ahead.
 \ : If the previous cell's 0, then shift the current cell back.
 */

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

void HelpScreen()
{
	
}

void OpenBFWFile()
{
	FILE *witfuck;
	char fileName[FMAX] = {0};
	printw("For reasons beyond my ability to care, ");
	printw("you only get a %hu-long filename. \n", FILENAME_MAX);
	printw("Please enter the name of the file you want to open: ");
	refresh();


	fclose(witfuck);
}

void SaveBFWFile(char q[])
{
	FILE *witfuck;
	char fileName[FMAX] = {0};
	printw("For reasons beyond my ability to care, ");
	printw("you only get a %hu-long filename. \n", FILENAME_MAX);
	printw("Please enter the name of the script you want to save: ");
	refresh();

	fclose(witfuck);
}

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

void OkayYouEnterItThenDipshit()
{
	
}

int main()
{
	srand(time(NULL));
	char selector = 'p';
	initscr();
	printw("Welcome to matrixDoppelganger's BrainFuckwit Program!!!\n");
	refresh();
	sleep(1);
	while(selector != 'q')
{
	clear();
	printw("Current Selector value is %c\n", selector);
	printw("Make your selection now. \nPress 'h' for help if you're lost: "); refresh();
	selector = getch(); printw("\n");
	switch(selector)
	{
		case 'e':
		OkayYouEnterItThenDipshit();
		break;
		
		case 'l':
		//OpenBFWFile();
		break;
		
		case 'h':
		HelpScreen();
		break;
		
		case 'q':
		printw("See you next time, provided you're not running away screaming!");
		sleep(1);
		break;
		
		default:
		printw("Gonna need an actual selection, yo.\n");
		refresh();
		sleep(1);
		break;
	}
}
refresh();
endwin();
return 0;
}
