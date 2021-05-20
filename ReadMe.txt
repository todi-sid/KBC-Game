ReadMe for assignment submitted by 2019B2PS0991P

_________________________________________________________________________________________________________________________________________________________________________________________________________________

Practical Section No: P9
Assignment Question Attempted: 1

_________________________________________________________________________________________________________________________________________________________________________________________________________________

TEAM:

1. 2019B2PS0991P          Siddarth Todi
2. 2019B3PS0465P          Manan Rajiv Agrawal
3. 2019A2PS0008P          Madeha Gull

_________________________________________________________________________________________________________________________________________________________________________________________________________________

Description Of How To Run The Code And Observe The Output:


1. The exe file is 2019B2PS0991P_P9.exe and the .c file is 2019B2PS0991P_P9.c

2. The input files are:
            S1_question.txt
            S2_question.txt
            S3_question.txt
            S4_question.txt
     Each one of these files contain a set of 16 questions (15 regular questions, one question to be used when Flip The Question lifeline is used). We've prepared four different sets, each of 16 questions, to be used in the game. When the user starts the game, any one of the four is chosen randomly and questions from that set are displayed.

We have attached a executable file also.If it shows some error you can generate one by compiling our code as shown below

To Compile The Code:
            gcc 2019B2PS0991P_P9.c
            ./a.out

3. On running the code, a list will be displayed showing the prize money received on passing each question number along with the available lifelines. 
     Intermediate levels will be displayed in yellow and the others in red.
     The user will be prompted to press any key to start the game.

4. Once the game starts, questions will be displayed along with four options(A,B,C,D) for each question. Out of these four, only one is correct.
     You have to enter the alphabet(case insensitive) corresponding to the option which you think is correct.
     If you enter a key other than A, B, C, D, Q, S, 1 or 2, a message saying 'Please enter a valid character' is displayed and the question with its options is displayed again.

5. Two lifelines will be available to assist you in case you're stuck on a question:
     50-50 and Flip The Question
           a) 50-50:
               On using this lifeline, the number of options displayed will be reduced from four to two, out of which one will be correct.
           b) Flip The Question:
                This lifeline will replace the question on screen with a new one.
    To use the 50-50 lifeline, you can press 1.
    To use the Flip The Question lifeline, you can press 2.

6. Each lifeline can be used only once throughout the game(even if used at the same time).

7. If your entered option for a question is correct, corresponding prize money will be displayed on the screen and you'll be prompted to enter any key to continue the game.
     If it's wrong, the game stops and the amount you've won is reduced to 
           a) the previous intermediate level you crossed
                                                or
           b) to zero if no intermediate levels have been crossed yet.

8. You also have the option to quit the game if you don't know the answer and lifelines also aren't helping. On quitting, amount of the previous crossed level(may be a regular level or an intermediate one) will be won by you. 
     To quit, press Q/q.

9. To check your progress, press S/s key. The level you're currently at will be displayed in blue, those you have crossed will be displayed in green and the remaining ones in red(yellow if they're intermediate levels). You'll then be asked to press Enter key to return to the game.


_________________________________________________________________________________________________________________________________________________________________________________________________________________

Contributions Of The Team Members:

Siddarth Todi (2019B2PS0991P) :
     Built the file handling system, incorporated it in the code.
     Built Flip The Question lifeline function, incorporated it in the code.
     Helped randomize the set of questions that will be used.
     Prepared question set 3 and 4. 

Madeha Gull (2019A2PS0008P) :
     Wrote the code for displaying all the information, incorporating all the circumstances(usage of a lifeline, entering the wrong option, not being able to use a lifeline more than once, etc). 
     Built the ShowProgress function, incorporated it in the code. 
     Built the Quit function, incorporated it in code.
     Prepared question set 1.

Manan Rajiv Agrawal (2019B3PS0465P) :
     Built the function for checking the answer, incorporated it in code.
     Built the 50-50 lifeline, incorporated it in the code. 
     Incorporated colours, enhanced the presentation, structure and user-friendly-ness of the program.
     Prepared question set 2.


_________________________________________________________________________________________________________________________________________________________________________________________________________________
