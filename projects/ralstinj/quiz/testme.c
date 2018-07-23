/*
*This is James Ralstin's implementation for the testme random tester quiz
*Due: 7/22/18
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	int intVal;
	char returnVal;
	
	intVal = (rand() % (8 - 0 + 1)) + 0;
	
	switch(intVal){
		case 0:
			returnVal = '[';
			break;
		case 1:
			returnVal = '(';
			break;
		case 2:
			returnVal = '{';
			break;
		case 3:
			returnVal = ' ';
			break;
		case 4:
			returnVal = 'a';
			break;
		case 5:
			returnVal = 'x';
			break;
		case 6:
			returnVal = '}';
			break;
		case 7:
			returnVal = ')';
			break;
		case 8:
			returnVal = ']';
			break;
	}
	
    return returnVal;
}

char *inputString()
{
    // TODO: rewrite this function
	
	char returnString[6];
	int randVal, i;
	
	memset(returnString, '\0', sizeof(char)*6);
	
	for(i = 0; i < 6; i++){
	
		randVal = (rand() % (6 - 0 + 1)) + 0;
		
		if(i == 0){
		
			switch(randVal){
				case 0:
					strcpy(returnString,"r");
					break;
				case 1:
					strcpy(returnString,"e");
					break;
				case 2:
					strcpy(returnString,"s");
					break;
				case 3:
					strcpy(returnString,"t");
					break;
			}
		}else{
			switch(randVal){
				case 0:
					strcat(returnString,"r");
					break;
				case 1:
					strcat(returnString,"e");
					break;
				case 2:
					strcat(returnString,"s");
					break;
				case 3:
					strcat(returnString,"t");
					break;
			}
		}
	}
	
    return returnString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
