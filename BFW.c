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
 # : Put the cell's value in the  bin, removing it from the cell.
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
#define MAX_DEPTH 512

static short int TAPE[TAPE_SIZE] = {0};
short int binValue = 0;
short unsigned int depth = 0;
static char query[MAX_QUERY] = {0};

void HelpScreen()
{

}

void OpenBFWFile()
{
FILE *witfuck;
char fileName[32] = {0};
printw("Please enter the name of the file you want to open: ");
refresh();


fclose(witfuck);
}

void SaveBFWFile(char q[])
{
FILE *witfuck;
char fileName[32] = {0};
printw("Please enter the saved file's name: ");
refresh();

fclose(witfuck);
}

void BrainFuckwitInterpreter()
{



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
		OpenBFWFile();
		break;
		
		case 'h':
		HelpScreen();
		break;
		
		case 'q':
		selector = 'q';
		break;
		
		default:
		printw("Gonna need an actual selection, yo.\n");
		refresh();
		sleep(1);
		break;
	}
}
printw("See you next time, provided you're not running away screaming!");
refresh();
endwin();
return 0;
}
