#include "BFW_Handling.c"

void HelpScreen()
{
	clear();
	printw("Pressing \'e\' will let you type in a BrainFuckwit script.\n");
	printw("Pressing \'x\' loads up an example script, showcasing some of BrainFuckwit\'s capabilities.\n");
	printw("Pressing \'i\' runs the interpreter on a script you made/loaded.\n");
	printw("Pressing \'c\' runs the compiler on a script you made/loaded\n");
	printw("Pressing \'h\' brings up this screen.\n");
	printw("Pressing \'q\' exits the program.\n\n");
	printw("Press the any key to continue.\nFeel free to mash your face on the keyboard if you can't find it.\n");
	char dummy = getch();
}

void InteractiveHandler()
{
	char selector = 'p';
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
			LaunchBFWEditor();
			break;
			
			case 'x':
			OpenBFWFile(false, "examplescript.bfw");
			printw("Example script loaded! Whever you want to interpret or compile it is up to you.\nPress the any key to continue..."); refresh(); char dummy = getch();
			break;
			
			case 'i':
			if(query[0] != 0){BrainFuckwitInterpreter(query);}
			break;
			
			case 'c':
			if(query[0] != 0){BrainFuckwitCompiler(query);}
			break;
			
			case 'h':
			HelpScreen();
			break;
			
			case 'q':
			printw("See you next time!\n");
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
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	initscr();
	if(argc > 1)
	{
		//argv[1][1] should be the second character of the second argument, ideally i or c.
		char value = argv[1][1];
		switch (value)
		{
			case 'c':
			OpenBFWFile(false, argv[2]);
			BrainFuckwitCompiler(query);
			break;
			
			case 'i':
			OpenBFWFile(false, argv[2]);
			BrainFuckwitInterpreter(query);
			break;
			
			default:
			printw("Usage case: bfw [-c|-i|] [(filename).bfw] (Press any key to exit.)"); refresh(); char dummy = getch();
			break;
		}
	}
	else{InteractiveHandler();}
	endwin();
	return 0;
}
