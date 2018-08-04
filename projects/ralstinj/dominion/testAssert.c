#include "Assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char myOp[3];
	int val1 = 3;
	int val2 = 3;

	int result;
	
	
	memset(myOp, '\0', 3);
	strcpy(myOp,"==");
	result = Assert(val1, val2, myOp);

 	memset(myOp, '\0', 3);
	strcpy(myOp,">=");
	result = Assert(val1, val2, myOp);
	
	memset(myOp, '\0', 3);
	strcpy(myOp,"<=");
	result = Assert(val1, val2, myOp);
	
	memset(myOp, '\0', 3);
	strcpy(myOp,">");
	result = Assert(val1, val2, myOp);
	
	memset(myOp, '\0', 3);
	strcpy(myOp,"<");
	result = Assert(val1, val2, myOp);
	
return 0;
}
