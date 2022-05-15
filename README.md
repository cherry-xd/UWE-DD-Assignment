# UWE-DD-Assignment
UWE Digital Design Assignment
- This is a reverse polish notation calculator coded in c++ that is designed to run with an STM device  
- The file is run by compiling and running calculator.cpp inside visual studio


<h2>DOCUMENTATION:</h2>  
I created this calculator by first creating a stack.h file, which would outline the class that I would use to create my stack. The stack is under a similarly named 'stack.cpp' file. I ran into plenty of issues with this including some that totally broke my program and you are able to see the changes I made to fix these within the files version history. Developing the calculator.cpp file took a long time for me to wrap my head around but eventually I got to grips with it and understood exactly how the calculator should work in relation to the stack, troubleshooted all my bugs, and learned a lot about c++ in the process. I still feel like this is not the most efficient solution ever however I do not feel like it is still very efficient as it does not do anything unnecessary and I have tried to keep repeating code to a minimum.  
  
If i had got around to making the physical board I would have used the code located in the Display folder to utilise the GPIOs of the board in conjunction with buttons to allow for a custom input to the calculator file however I could not do this because my STM device is not being detected by the IDE so I cannot run any code on it and I have run out of time, but the calculator can still be used to calculate any 2 number equation as a string inputted in the main() function of calculator.cpp so at least the code works.
