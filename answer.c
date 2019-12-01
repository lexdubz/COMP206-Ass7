//Name: Alexis Dubois
//Student ID: 260743051

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main() {
	
	//payload loosk like : /cgi-bin/answer?input=answer
	char *data = getenv("QUERY_STRING");
	char north[]="NORTH",south[]="SOUTH",east[]="EAST",west[]="WEST",gold[]="GOLD",answer[]="LINK";
	

	//create a token seperated array to extract the payload data
	char *tokens = strtok(data,"=&?");
	char input[10];
	
	//paste the payload into an array
	int i=0;
	while(tokens != NULL) {
		input[i] = *tokens;	
		tokens = strtok(NULL,"=&?");
		i++;
	}
	//assuming the payload looks like: [URL]/answer?input=Command&gold=50
	//the first token contains the url and program name - so everything before the '?'
	//the second token contains the name of the CGI variable we ask the user to fill-out
	//the third token contains the user's input
	//the fourth and fifth tokens are potentially optional, we must check to make sure
	//the fourth field is the CGI hidden variable
	//the fifth field is the amount of gold - don't assume it's an int
	
	char *command = &input[2];
	
	int goldPc;
	//check if an amount of gold was provided, if not we will assume 10
	if(&input[4] == NULL) {
		goldPc = 10;
	} else {
		sscanf(&input[4],"%d", &goldPc);
	}

	//compare the command passed with potential options
	//NORTH SOUTH EAST WEST GOLD LINK

	if(strcmp(command,north)==0) {
		//send user to the next room
		printf("<html><a href=\"https://www.cs.mcgill.ca/~bromer2/cgi-bin/addgold?gold=%d\">Press HERE to go NORTH</a></html>",goldPc);
	} else if(strcmp(command,south)==0) {
		//send user to next room
		printf("<html><a href=\"https://www.cs.mcgill.ca/~zyu29/cgi-bin/addgold?gold=%d\">Press HERE to go SOUTH</a></html>",goldPc);
	} else if(strcmp(command,east)==0) {
		//send user to next room
		printf("<html><a href=\"https://www.cs.mcgill.ca/~atan16/cgi-bin/addgold?gold=%d\">Press HERE to go EAST</a></html>",goldPc);
	} else if(strcmp(command,west)==0) {
		//send user to next room
		printf("<html><a href=\"https://www.cs.mcgill.ca/~yradev/cgi-bin/addgold?gold=%d\">Press HERE to go WEST</a></html>",goldPc);
	} else if(strcmp(command,gold)==0) {
		//send tu user to an other page where the gold number is shown
		//also include a hyper link to come back to the initial page

		printf("Content-Type:text/html\n\n");
		printf("<html>");
		printf("<body><h5>You currently have %d gold pieces.<\\h5><\\body>",goldPc);
		printf("</html>");


	} else if(strcmp(tokens,answer)==0) {
		//user input the right answer
		goldPc += 10;	
	} else {
		//if the user's input doesn't match any of the possibilities, reduce the amount of gold by 5
		goldPc -= 5;
	}

	//check if the amount of gold is either 100 or 0 and send the user to the appropriate webpage
	if(goldPc == 100) {
		//send user to page that displays "YOU WIN!"
		printf("<html><a href=\"https://www.cs.mcgill.ca/~aduboi8/win.html\"></html>");
	}
	if(goldPc <= 0) {
		//send user to a page that displays "YOU LOSE!"
		printf("<html><a href=\"https://www.cs.mcgill.ca/~aduboi8/lose.html\"></html>");
	}


}




