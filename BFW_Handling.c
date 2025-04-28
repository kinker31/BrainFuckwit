#include "BFW_Compiler.c"
#define FMAX 16

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
	clear();
	suint length = 0;
	
}

//True is for interactive mode, false is for direct terminal mode. The second argument is only used when the first one's false.
void OpenBFWFile(bool mode, char name[])
{
	FILE *witfuck;
	if(mode)
	{
	char fileName[FMAX] = {0};
	printw("For reasons beyond my ability to care, ");
	printw("you only get a %hu-long filename. \n", FILENAME_MAX);
	printw("Please enter the name of the file you want to open: "); refresh(); scanw(" %s", fileName);
	witfuck = fopen(fileName, "r");
	}
	else {witfuck = fopen(name, "r");}
	if(witfuck = NULL) {printw("File name invalid! Aborting..."); sleep(1); endwin(); abort();}
	fclose(witfuck);
}

void SaveBFWFile(char q[])
{
	FILE *witfuck;
	char fileName[FMAX] = {0};
	printw("For reasons beyond my ability to care, ");
	printw("you only get a %hu-long filename. \n", FILENAME_MAX);
	printw("Please enter the name of the script you want to save: "); refresh(); scanw(" %s", fileName);
	witfuck = fopen(fileName, "w");
	if(witfuck = NULL) {printw("File name invalid! Aborting..."); sleep(1); endwin(); abort();}
	
	fclose(witfuck);
}
