#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *handle=fopen(argv[1], "r+");
	if(handle==NULL)
		exit(2);
	printf("pti4ki");
	char buffer;
	int i;
	while((buffer=getc(handle))!=EOF){
		if(buffer=='*')
			i++;
		else
			i=0;
		if(i==4){
			fseek(handle, -4, 1);
			fprintf(handle, "%s", argv[2]);
			break;
		}
	}
	fclose(handle);
	return 0;
}