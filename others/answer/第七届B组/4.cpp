#include <stdio.h>
#include <string.h>

void StringInGrid(int width, int height, const char* s)
{
	int i,k;
	char buf[1000];
	strcpy(buf, s);
	if(strlen(s)>width-2) buf[width-2]=0;
	
	printf("+");
	for(i=0;i<width-2;i++) printf("-");
	printf("+\n");
	
	for(k=1; k<(height-1)/2;k++){
		printf("|");
		for(i=0;i<width-2;i++) printf(" ");
		printf("|\n");
	}
	
	printf("|");
	printf("%*s%s%*s",(width-strlen(buf)-2)/2," ",buf,(width-strlen(buf)-2)/2," ");//_____________________________________________);  //МоїХ
	          
	printf("|\n");
	
	for(k=(height-1)/2+1; k<height-1; k++){
		printf("|");
		for(i=0;i<width-2;i++) printf(" ");
		printf("|\n");
	}	
	
	printf("+");
	for(i=0;i<width-2;i++) printf("-");
	printf("+\n");	
}

int main()
{
	StringInGrid(20,6,"abcd1234");
	return 0;
}

