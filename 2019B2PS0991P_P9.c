#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

//Declaration of the function which will Check the final option in all cases includng lifelines also
void Check(char, int, int); 

//Declaration of the function for the lifeline:50-50
void Fifty(int, int);  

//Declaration of the function of the lifeline:Flip the Question
void Flip(int);

//For the display of question and its corresponding options
void printOptions(int,int); 

//Quit game option
void quitGame(int); 

//To display the user's status
void showProgress(int);

//To generate two random numbers used in 50-50 lifeline
void GenerateTwoRandom(int *, int *);

//For text color display
void red();
void green();
void yellow();
void blue();
void cyan();
void reset();

char bufferString[100]; //Use for printing string numeric values in different colors

//Prize values
char *prize[15] = {"1,000", "3,000", "5,000", "10,000", "20,000", "40,000", "80,000", "1,00,000", "3,20,000", "6,40,000", "12,50,000", "25,00,000", "50,00,000", "1 CRORE", "2 CRORES"};

//count1,count2 are counters to check whether the lifeline has been applied once,count1-50-50 and count2-Flip the Question
int count1 = 0, count2 = 0; 

//To get answer character from user at different places
char ans;

//Variables declared(String arrays) for questions,respective options and correct answer character.
char *questions[16],*optionA[16],*optionB[16],*optionC[16],*optionD[16],correctCh[16];

int main()
{
  //To clear screen
  system("clear");

  //Printing instructions and all the primary informations

  cyan("\n\n                                          Welcome to Kaun Banega Crorepati\n\n\n");
  printf(" Instruction:-In the timeline,yellow levels are the intermediate levels , if you give a wrong answer you will win a amount alotted to its lower intermediate level.\n\n");
  printf("             -If answer is wrong in any first 4 level,No amount will be credited. \n\n");
  printf("             -Progress chart can be seen at any stage by clicking S/s OR will be shown if you quit or give awrong answer.\n\n");
  printf("             -In the progress chart the green levels will be the cleared ones and the blue level will be the current level.\n\n");
  printf("             -You can quit at any stage by clicking Q/q where you will win the amount alotted till the previous level played.\n\n");
  printf("             -Rest of the informations will be shared as the game proceeds.\n\n");

  for (int i = 14; i >= 0; i--)
  {
    //sprintf-is used to convert the printf statement into a string so that used our color functions,-2 for allignment adjustment
    sprintf(bufferString," %-2d  Rs. %s \n", i + 1, prize[i]);

    if (i == 3 || i == 8 || i == 14) //To display the intermediate levels
    {
      yellow(bufferString);
    }
    else  //Rest of the levels
    {
      red(bufferString);
    }
  }

  printf("\n       Available lifelines\n");
  printf("\n 50-50 : 2 wrong options will be removed");
  printf("\n Flip the question : To change the question");
  printf("\n\n NOTE:Each lifeline can be used only once and both can be used even at the same level\n\n");

  printf("\n Press Enter/Any key to Start ");
  getchar();

  //To generate a random number srand()-used,so that a different number is generated every run(may be same) 
  srand(time(0));

  //To generate random numbers in between 0-3 including 0 and 3
  int a=rand()%4;
  
  //file pointer
  FILE *ftr;

  //Comman comment for the all text files below
  //Considering each element sepearted by ";"
  //1st element is the question , next 4 elemnets is its corresponding options , and the next one is the correct option character (This set of 6 elements is being used for each questions one after another in order for 15 questions and one flip question at the last of each file)

  //We have 4 set of questions , according to the random number ,we are selecting any one set and using it in your code

  if(a==0){
      ftr=fopen("S1_question.txt","r");
  }
  else if(a==1){
      ftr=fopen("S2_question.txt","r");
  }
  else if(a==2){
      ftr=fopen("S3_question.txt","r");
  }
  else{
      ftr=fopen("S4_question.txt","r");
  }

  fseek(ftr, 0, 2);    /* file pointer at the end of file */
  int size = ftell(ftr);   /* take a position of file pointer un size variable */   

  // To bring the file pointer to the starting of the file
  rewind(ftr);

  char buff[size],*token;

  //To copy the file content into the buff variable
  fscanf(ftr,"%[^\n]%*c",buff);

  //To get the words seperated by ";" in buff variable
  token=strtok(buff,";");

  int j=0;

  //This cycle is being repeated for each question including the question required for flip the question lifeline
  while(token!=NULL){
      questions[j]=token;
      token=strtok(NULL,";");

      optionA[j]=token;
      token=strtok(NULL,";");

      optionB[j]=token;
      token=strtok(NULL,";");

      optionC[j]=token;
      token=strtok(NULL,";");

      optionD[j]=token;
      token=strtok(NULL,";");

      correctCh[j]=token[0];
      token=strtok(NULL,";");

      j++;
  }

  //To close the respective opened file
  fclose(ftr);

  for (int i = 0; i < 15; i++)
  {

    if(i>=1){
      printf(" Press Enter/Any key to play the next round ");
      getchar();
    }

    //To clear the screen for the display of each individual question
    system("clear");


    //label to repeat the content if the user enters a wrong character
    repeatInMain:

      printOptions(i,i);

      //To store the user's answer
      scanf("\n%c", &ans);
      ans=toupper(ans); 

      if (ans == '1' && count1==0)
      {
        Fifty(i, i);
      }
      else if (ans == '2' && count2==0)
      {
        Flip(i);
      }
      else if(ans=='A'||ans=='B'||ans=='C'||ans=='D')
      {
        Check(ans, i, i);
      }
      else if (ans == 'Q')
      {
        quitGame(i);
      }    
      else if (ans == 'S')
      {
        showProgress(i);
        printf("\n Press Enter to return to game...  ");
        getchar();
        system("clear");
        goto repeatInMain;
      }
      
      else{
        system("clear");
        red("\n Please enter a valid character\n");
        goto repeatInMain;
      }
    getchar();
  }
  return 0;
} //End of main()


void GenerateTwoRandom(int *rand1, int *rand2)
{
  srand(time(0));

  //Both rand1 and rand2 will take random number in the range 1-4 including 1 and 4
  int num = (rand() % (4)) + 1;
  *rand1 = num;

  num = (rand() % (4)) + 1;
  *rand2 = num;

  //Both the random number should not be equal because we need to print 2 options in 50-50 lifeline
  while (*rand1 == *rand2)
  {
    num = (rand() % (4)) + 1;
    *rand2 = num;
  }
}//End of GenerateTwoRandom()

//k is representing the index at questions array and i is for the present level(different only in the case of the "flip the question" lifeline)
void Fifty(int i, int k)
{ 
    count1++;
    int rand1, rand2;
    GenerateTwoRandom(&rand1, &rand2);

    //Both the random are in the range 1-4 , if we add 64 , we will get 65-68 , which is the ASCII value of range A-D

    //If rand2 does not correspond to the correct option Character , we neet to set rand1 such that it corresponds to the correct opion Character
    if (rand2 + 64 != correctCh[k])
    {
      rand1 = correctCh[k] - 64;
    }

    if (rand1 != 1 && rand2 != 1)
    {
      optionA[k] = " ";
    }
    if (rand1 != 2 && rand2 != 2)
    {
      optionB[k] = " ";
    }
    if (rand1 != 3 && rand2 != 3)
    {
      optionC[k] = " ";
    }
    if (rand1 != 4 && rand2 != 4)
    {
      optionD[k] = " ";
    }

    //To clear the screen for display the display of question with 2 options
    system("clear"); 

    //Label to repeat if user enters a wrong key
    repeatInFifty:

      printOptions(k,k);
      scanf("\n %c", &ans);
      ans=toupper(ans);
      if (ans == '2' && count2==0)
      {
        Flip(i);
      }

      //To check whether the user entered a character among the 2 options displayed
      else if((strcmp(optionA[k]," ")!=0 && ans=='A')||(strcmp(optionB[k]," ")!=0 && ans=='B')||(strcmp(optionC[k]," ")!=0 && ans=='C')||(strcmp(optionD[k]," ")!=0 && ans=='D'))
      {
        Check(ans, i, k);
      }

      else if (ans == 'Q')
      {
        quitGame(i);
      }    
      else if (ans == 'S')
      {
        showProgress(i);
        printf("\n Press Enter to return to game...  ");
        getchar();
        system("clear");
        goto repeatInFifty;
      }
      else{
        red("\n Please enter a valid character\n");
        system("clear");
        goto repeatInFifty;
      }
}//End of Fifty()

void Flip(int i) //i is for representing the current level
{ 
    count2++;

    //To clear the screen for the display of the fliped question with its corresponding options
    system("clear");


    repeatInFlip:

      //15 is the index number because the question for flip the question index is stored at the last
      printOptions(i,15);
      scanf("\n %c", &ans);
      ans=toupper(ans);
      if (ans == '1'&& count1==0)
      {
        Fifty(i, 15);
      }
      else if(ans=='A'||ans=='B'||ans=='C'||ans=='D')
      {
        Check(ans, i, 15);
      }
      else if (ans == 'Q')
      {
        quitGame(i);
      }    
      else if (ans == 'S')
      {
        showProgress(i);
        printf("\n Press Enter to return to game...  ");
        getchar();
        system("clear");
        goto repeatInFlip;
      }
      else{
        red("\n Please enter a valid character \n");
        system("clear");
        goto repeatInFlip;
      }
}//End of Flip

//i represents the present level and k respresent the index(different only in the case of "flip the question" lifeline)
void printOptions(int i,int k) 
{
  sprintf(bufferString,"\n\n Question %d \n\n ", i + 1);
  yellow(bufferString);
  blue(questions[k]);
  printf("\n\n");

  //-25 for allignment adjustment
  cyan(" Option A: ");
  printf("%-25s", optionA[k]);
  cyan("     Option B: ");
  printf("%s", optionB[k]);
  cyan("\n Option C: ");
  printf("%-25s", optionC[k]);
  cyan("     Option D: ");
  printf("%s", optionD[k]);

  printf("\n\n Please select your correct option");

  //print statement according to the usage of lifelines
  if(!count1 || !count2)
  {
    yellow("\n                 OR  \n ");
    if(!count1 && !count2){
      printf("Press 1 for 50-50  OR  Press 2 to Flip the Question ");
    }
    else if(!count1){
      printf("Press 1 for 50-50 ");
    }else{
      printf("Press 2 to Flip the Question ");
    }
  }else{
    printf(" ");
  }

  yellow("\n                 OR  \n ");
  printf("Press Q/q to quit the game");
  yellow("\n                 OR  \n ");
  printf("Press S/s to see your progress \n ");

}//End of printOptions()

//Function definition to check the given answer character in all cases including lifelines
void Check(char ans, int i, int k)  //ans represent the given answer character,i represents the present level and k represent the index in correct array
{ 
  ans = toupper(ans);
  if (ans == correctCh[k])
  {
     sprintf(bufferString, " Congratulation!! Your Answer is Correct\n You Won Rs.%s\n\n", prize[i]);
     green(bufferString);

     if(i==14){
       green(" HURRAH !! You have won the complete game\n\n");
     }

  }
  else
  {
    red("\n Your Answer is Wrong\n\n");
    printf(" Correct option : %c\n\n",correctCh[k]);

    //For the display of the final progress
    showProgress(i);

    //To calculate the intermediate stage amount
    char *total;
    if (i <= 3)
    {
      total = "0";
    }
    else if (i >= 4 && i <= 8)
    {
      total = prize[3];
    }
    else
    {
      total = prize[8];
    }
    printf("\n\n Total amount won:Rs %s\n\n", total);

    //To end the game once the answer is wrong
    exit(0);
  }
}//End of Check()

void quitGame(int i){

  //To display the final progress
  showProgress(i);

  if(i==0){
    printf("\n Thank You For Playing!!!! \n\n ");
    exit(0);
  }
  sprintf(bufferString, "\n Congratulation!! You have Won Rs.%s\n\n Thank You For Playing!!!!\n\n ", prize[i-1]);
  green(bufferString);

  //To end the game as opted by the user
  exit(0);
}//End of quitGame()

void showProgress(int current){
  for (int i = 14; i >= 0; i--)
  {
    sprintf(bufferString," %-2d  Rs. %-9s \n", i + 1, prize[i]); //Allignment adjustment done
    if(i <= current){

      //To display the current level in blue
      if(i==current){
        blue(bufferString);
      }

      //To display the passed intermediate levels in normal text color
      else if (i == 3 || i == 8){
        printf("%s",bufferString);
      }

      //To display the passed levels in green
      else
      {
        green(bufferString);
      }
      
    }

    //Rest of the levels are left as it was before 
    else if (i == 3 || i == 8 || i == 14)
    {
      yellow(bufferString);
    }
    else
    {
      red(bufferString);
    }
  }
  getchar();
}//End of progress

//ANSI Color codes are used for different colors
void red(char *input)
{
  printf("\033[1;31m");
  printf("%s", input);
  reset();
}

void green(char *input)
{
  printf("\033[1;32m");
  printf("%s", input);
  reset();
}

void yellow(char *input)
{
  printf("\033[1;33m");
  printf("%s", input);
  reset();
}

void blue(char *input)
{
  printf("\033[1;34m");
  printf("%s", input);
  reset();
}

void cyan(char *input)
{
  printf("\033[1;36m");
  printf("%s", input);
  reset();
}
 
//to display the normal color again 
void reset()   
{
  printf("\033[0m");
}
//END OF THE PROGRAM 
