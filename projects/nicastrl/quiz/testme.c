#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    
    /*Goal - identify the ASCII chars worth testing, bound this range in rand,
    convert to char, return 
    OR- just limit to the end result cases
    
    I will go with the latter since we don't get value out of testing the chars
    that aren't of note in the testme function
    */
    char possibleChars[9] = {'[', ']', '(', ')', '{', '}', ' ', 'x', 'a' };
    
    return (possibleChars[rand()%9]);
}

char *inputString()
{
    // TODO: rewrite this function
    
    /*
    Goal - limit the string output to a fixed length (5 chars + \0), 
    limit chars as much as possible as 25^5 is nearly 12MM and that will 
    excceed the 5 min limit
    */
    
    char myString[6];
    myString[5] = '\0';
    
    //fill in the 5 random 
    char possibleChars[8] = {'R', 'E', 'S', 'T', 'r', 'e', 's', 't'};
    
    //fill the array with results
    int i;
    for (i = 0; i < 5; i++)
      myString[i] = possibleChars[rand()%8];
    
    char *result = myString;
    return result;
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
