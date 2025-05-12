#include "BFW_Compiler.c"
#define FMAX 17

//True is for interactive mode, false is for direct terminal mode. The second argument is only used when the first one's false.
void OpenBFWFile(bool mode, char name[])
{
	FILE *witfuck;
	if(mode)
	{
		char fileName[FMAX] = {0};
		printw("\nFor reasons beyond my ability to care, you only get a %hu-long filename. \n", (FMAX - 1));
		printw("Please enter the name of the file you want to open: "); refresh(); scanw(" %16s", fileName);
		char fullName[CPATH_MAX];
		strcat(strcpy(fullName, getenv("HOME")), "/bfw/");
		strcat(fullName, fileName);
		witfuck = fopen(fullName, "r");
	}
	else {witfuck = fopen(name, "r");}
	if(witfuck == NULL) {printw("File name invalid! Aborting..."); sleep(1); endwin(); abort();}
	fgets(query, sizeof(query), witfuck);
	fclose(witfuck);
}

void SaveBFWFile(char q[])
{
	FILE *witfuck;
	char fileName[FMAX] = {0};
	printw("\nFor reasons beyond my ability to care, you only get a %hu-long filename. \n", (FMAX - 1));
	printw("Please enter the name of the script you want to save: "); refresh(); scanw(" %16s", fileName);
	char fullName[CPATH_MAX];
	strcat(strcpy(fullName, getenv("HOME")), "/bfw/");
	strcat(fullName, fileName);
	witfuck = fopen(fullName, "w");
	if(witfuck == NULL) {printw("File name invalid! Aborting..."); sleep(1); endwin(); abort();}
	fputs(query, witfuck);
	fclose(witfuck);
}


void EditorHelpScreen()
{
	clear();
	printw("Type in any of the 18 specifcation characters as you would a notepad-like program.\n");
	printw("Pressing \'c\' clears the entire script, letting you start over again.\n");
	printw("Pressing \'h\' brings up this screen.\nPress the any key to go back to the editor.\n");
	printw("Pressing \'q\' q quits the editor.");
	refresh(); (void) getch(); 
}

void ShowCurrentScript(suint l)
{
	if(l == 0){return;}
	for(suint i = 0; i < l; i++) {printw("%c", query[i]);}
	printw(" "); refresh();
}

void ClearCurrentScript(suint *l) 
{ 
	for(suint i = 0; i < *l; i++)
	{ query[i] = 0; }
	*l = 0;
}

void LaunchBFWEditor()
{
	suint length = 0; char value = 'p';
	while(value != 'q')
	{
		clear();
		printw("Press h for help on how to use the mini-IDE.\n");
		printw("Your current code: "); ShowCurrentScript(length);
		value = getch();
		switch(value)
		{
			//Case tower because switchboards only stop on break;
			case '+':
			case '-':
			case '>':
			case '<':
			case '.':
			case ':':
			case ',':
			case ';':
			case '[':
			case ']':
			case '!':
			case '\?':
			case '/':
			case '\\':
			case '$':
			case '#':
			case '@':
			case '%':
			query[length] = value;
			length++; break;
			case '\b':
			query[length] = 0;
			length--; break;
			break;
			case 'c':
			ClearCurrentScript(&length);
			break;
			case 'h':
			EditorHelpScreen();
			break;
			case 'q':
			default: break;
		}
	}
	printw("\nPress y if you want to save your script to a file. "); 
	refresh(); value = getch();
	if(value == 'y') {SaveBFWFile(query);}
}

