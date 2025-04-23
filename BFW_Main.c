#include "BFW_Compiler.c"

void HelpScreen()
{
	
}

void OkayYouEnterItThenDipshit()
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
