//Name: Alexis Dubois
//Student ID: 260743051

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main() {
	
	//capture the gold element in the payload
	char *data = getenv("QUERY_STRING");
	char *tokens = strtok(data, "=&?");
	char input[10];
	//payload looks like: [URL]/addgold?gold=integer
	int i=0;
	while(tokens != NULL) {
		sscanf(tokens,"%s", &input[i]);
		tokens = strtok(NULL,"=&?");
		i++;
	}
	//the integer for gold should be in the index 2
	int gold = atoi(&input[2]);


	//open the index.html file of the target webpage and print to the screen 
	FILE *p = fopen("index.html","rt");
	char line[1000];
	fgets(line,999,p);
	
	char *flag = "<form";

	while(!feof(p)) {
		//search for the form tag in each line, if we find it we insert our new tag right after
		char *ptr = strstr(line, flag);
		if( ptr != NULL) {
			printf("%s",line);
			printf("<input type=\"hidden\" name=\"gold\" value=\"%d\"",gold);
		} else {
			printf("%s",line);
		}
		//read the next line into the buffer
		fgets(line,999,p);
	}

	fclose(p);

}

