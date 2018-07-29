#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Assert(int val1, int val2, char op[3]){

	if(strcmp("==",op) == 0){
		
		if(val1 == val2){
			printf("TEST PASS, %d AND %d ARE EQUAL\n", val1, val2);
			fflush(stdout);
		}else{
			printf("TEST FAIL, %d AND %d ARE NOT EQUAL\n", val1, val2);
			fflush(stdout);
		}
		
 	}else if(strcmp(">=", op) == 0){
		
		if(val1 >= val2){
			printf("TEST PASS, %d IS GREATER THAN OR EQUAL TO %d\n", val1, val2);
			fflush(stdout);
		}else{
			printf("TEST FAIL, %d IS NOT GREATER THAN OR EQUAL TO %d\n",val1, val2);
			fflush(stdout);
		}
		
	}else if(strcmp("<=", op) == 0){
		
		if(val1 <= val2){
			printf("TEST PASS, %d IS LESSER THAN OR EQUAL TO %d\n", val1, val2);
			fflush(stdout);
		}else{
			printf("TEST FAIL, %d IS NOT LESSER THAN OR EQUAL TO %d\n",val1, val2);
			fflush(stdout);
		}
		
	}else if(strcmp("<", op) == 0){
		
		if(val1 < val2){
			printf("TEST PASS, %d IS LESS THAN %d\n", val1, val2);
			fflush(stdout);
		}else{
			printf("TEST FAIL, %d IS NOT LESS THAN %d\n",val1, val2);
			fflush(stdout);
		}
		
	}else if(strcmp(">", op) == 0){
		
		if(val1 > val2){
			printf("TEST PASS, %d IS GREATER THAN %d\n", val1, val2);
			fflush(stdout);
		}else{
			printf("TEST FAIL, %d IS NOT GREATER THAN %d\n",val1, val2);
			fflush(stdout);
		}
		
	}else if(strcmp("!=", op) == 0){
		
		if(val1 != val2){
			printf("TEST PASS, %d IS NOT EQUAL TO %d\n", val1, val2);
			fflush(stdout);
		}else{
			printf("TEST FAIL, %d IS EQUAL TO %d\n",val1, val2);
			fflush(stdout);
		}
		
	}

return 0;
}
