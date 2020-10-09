#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_LIMIT 1024

//adds blank character to the beginning of the string
void strcat_beg(char *tape, char *input){
  for(;*tape;tape++);
  while(*input){
    *tape++ = *input;
    input++;
  }
  *tape++ = 0;
}

//adds blank character to the end of the string
void strcat_end(char *tape, char c){
  for(;*tape;tape++);
  *tape++ = c;
}

bool palindromeTuring(char *tape){
  //i will act as the pointer head of the tape
  //it is at 1 as it is assumed that the pointer
  //will start traversing from the first character
  //of the string
  int i = 1;
  //this part is checking if the string is empty or not
  if(tape[i] == '$'){
  	//reject state
  	return false;
  }
  else{
  	//move to next state by going left once
  	i--;
  }
  //move right once to position tape head
  i++;
  while(true){
    //here state is used to make the comparison
    //more generic since we need to compare the
    //characters back and forth in the string
    char state = tape[i];
    //replacing the tape symbol with blank symbol
    tape[i] = '$';
    printf("%s %c->%c,R\n", tape, state, tape[i]);
    //moving pointer right
    i++;
    if(tape[i]=='$'){
      //this condition is for odd palindromes
      //if the next right character after the
      //character replaced is a blank symbol
      //that means all characters are traversed
      //and the string was an odd palindrome 
      return true;
    }
    //traversing the string till we reach the blank
    //while not replacing anything
    while(tape[i] != '$'){
      printf("%s %c->%c,R\n", tape, tape[i], tape[i]);
      i++;
    }
    //after reaching the blank symbol we move
    //pointer one left so as the pointer is
    //pointing the last character of the string
    printf("%s %c->%c,L\n", tape, tape[i], tape[i]);
    i--;
    //if the character matches state symbol
    //then we replace the character with blank
    //symbol and move left, else we reach the 
    //not accepting state and return false
    if (tape[i] == state){
      tape[i] = '$';
      printf("%s %c->%c,L\n", tape, state, tape[i]);
      i--;
    }
    else{
      return false;
    }
    if(tape[i]=='$'){
      //condition for even palindromes, if after 
      //replacing the last character and moving
      //left we found blank character means all
      //characters are matched and its a palindrome
      return true;
    }
    //keep traversing backwards by not replacing
    //any character until we reach the first blank state  
    while(tape[i] != '$'){
      printf("%s %c->%c,L\n", tape, tape[i], tape[i]);
      i--;
    }
    //after reaching the blank state we go to right
    //once so that the pointer is at the first state
    //again and pointing the first non-blank character
    printf("%s %c->%c,R\n", tape, tape[i], tape[i]);
    i++;
  }
}

int main(int argc, char *argv[]) {

	if (argc != 2 )  
  { 
  	printf("Enter only one string as input\n"); 
  	return 0; 
  } 
  //printf("Give an input for the string (max char limit 1024):-");
  char input[MAX_LIMIT];
  /*fgets(input, MAX_LIMIT, stdin);*/
  strcpy(input, argv[1]);

  //$ will be the blank character here basically
  //so adding this before and after the string
  //just to give a visual idea that the string
  //in tape is surrounded by blank symbols
  char tape[] = "$";
  //adding the blank character before the string
  strcat_beg(tape, input);
  //adding the blank character after the string
  strcat_end(tape, '$');
  printf("tape: %s\n", tape);

  if(palindromeTuring(tape)){
    printf("Yes its a PALINDROME");
  }
  else{
    printf("No its not a PALINDROME");
  }
  printf("\n");
  return 0;
}

