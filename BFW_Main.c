#include "BFW_Compiler.c"
#define FMAX 16

void HelpScreen()
{
	printw("Pressing \'e\' will let you type in a BrainFuckwit script.\n");
	printw("Pressing \'s\' will save the last script you made as a file.");
	printw("Pressing \'l\' lets you load a BrainFuckwit file.\n");
	printw("Pressing \'x\' loads up an example script, showcasing some of BrainFuckwit\'s capabilities.\n");
	printw("Pressing \'h\' brings up this screen.\n");
	printw("Pressing \'c\' compiles the script you made/loaded into C code.\n");
	printw("Pressing \'q\' exits the program.\n\n");
	printw("Press the any key to continue.\n Feel free to mash your face on the keyboard if you can't find it.\n");
	char dummy = getch();
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
		
		case 's':
		//SaveBFWFile(query);
		break;
		
		case 'h':
		HelpScreen();
		break;
		
		case 'q':
		printw("See you next time, provided you're not running away screaming!\n");
		refresh();
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
