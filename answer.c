//Name: Alexis Dubois
//Student ID: 260743051

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main() {
	
	//payload loosk like : /cgi-bin/answer?input=answer
	char *data = getenv("QUERY_STRING");
	

	//assuming the payload looks like: "[URL]/answer?input=Command&gold=50"
	//separate the payload using tokens
	
	char *firstTok;
	int goldPc;
	char *command;
	firstTok = strtok(data,"=");
	if(strcmp(firstTok,"input")==0){
		command = strtok(NULL,"&");
		if(strtok(NULL,"=")==NULL) goldPc =10;
		else goldPc =atoi(strtok(NULL,""));
	} else {
		goldPc = atoi(strtok(NULL,"&"));
		if(strtok(NULL,"=")!=NULL) command = strtok(NULL,"");
	}


	//compare the command passed with potential options
	//NORTH SOUTH EAST WEST GOLD LINK
	
	printf("Content-Type:text/html\n\n");
	printf("<html>");
	printf("<body>");

	if(strcmp(command,"NORTH")==0) {
		//send user to the next room
		printf("<a href=\"http://cs.mcgill.ca/~bromer2/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go NORTH</a>",goldPc);
	} else if(strcmp(command,"SOUTH")==0) {
		//send user to next room
		printf("<a href=\"http://cs.mcgill.ca/~zyu29/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go SOUTH</a>",goldPc);
	} else if(strcmp(command,"EAST")==0) {
		//send user to next room
		printf("<a href=\"http://cs.mcgill.ca/~atan16/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go EAST</a>",goldPc);
	} else if(strcmp(command,"WEST")==0) {
		//send user to next room
		printf("<a href=\"http://cs.mcgill.ca/~yradev/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go WEST</a>",goldPc);
	} else if(strcmp(command,"GOLD")==0) {
		//send tu user to an other page where the gold number is shown
		//also include a hyper link to come back to the initial page

		 printf("You currently have %d gold pieces.<br /> <a href=\"http://cs.mcgill.ca/~aduboi8/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go back.</a>",goldPc,goldPc);
		

	} else if(strcmp(command,"LINK")==0 || strcmp(command,"Link")==0) {
		//user input the right answer
		goldPc += 10;
		printf("Correct! You have %d gold pieces. <br /><a href=\"http://cs.mcgill.ca/~aduboi8/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go back. </a>", goldPc, goldPc);	
	} else {
		//if the user's input doesn't match any of the possibilities, reduce the amount of gold by 5
		goldPc -= 5;
		printf("Wrong input. You have %d gold pieces left. <br /> <a href=\"http://cs.mcgill.ca/~aduboi8/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go back.</a>", goldPc, goldPc);
	}

	//check if the amount of gold is either 100 or 0 and send the user to the appropriate webpage
	if(goldPc >= 100) {
		//send user to page that displays "YOU WIN!"
		printf("You have won! <br /> <a href=\"http://cs.mcgill.ca/~aduboi8\">Press HERE to start a new game</a>");
	}
	if(goldPc <= 0) {
		//send user to a page that displays "YOU LOSE!"
		printf("You have lost! <br /> <a href=\"https://www.cs.mcgill.ca/~aduboi8\">Press HERE to start over</a>");
	}
	
	printf("</body>");
	printf("</html>");
}




