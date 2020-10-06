#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 *
 */

int main() {
	srand(time(NULL));	
	char tab_int[30];
	int random_number = rand() % 127;
	char hex[3];
	printf("%d\n",random_number);
	sprintf(hex,"%02x",random_number);
	printf("%s\n",hex);
	return(0);
}
