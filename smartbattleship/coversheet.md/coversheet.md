
Coversheet file for Smart Battleship

Project #10
By: Nadija Lohja
Date: Decemeber 2025

Requirements: I had to make two functions that allow a battleship program to chose "smart" hits based on previous moves, so it can accurately destroy ships.

Design: In my updateMemory and smartMove functions, I used a series of if else statements to code for different possibilities. In updateMemory, the if else statement parameters check the result of the last hit and the current mode so that I can code for specific scenarios. The smartMove is more general, coding only for the current direction, since the edge cases are taken care of by the updateMemory.

Implementation: In updateMemory, I made sure to update the row and column only until I got my first hit. Then I stopped updating it so that I could use that for a reference point to destroy the ship. I also used the memory.fireDist to keep track of how far away from the ship I got. Then, if I hit a miss, or a ship I didn't want to hit, I set the fire distance back to 1 so I could hit the shot next to my original shot and destroy the ship.

Testing: I probably did over one hundred tests over the past few days while coding this. While my program works perfectly, having the ability to find and destroy ships with amazing accuracy, there is one edge case that I could not code for, and that is if a ship is oriented vertically at the bottom of the board. If I hit that ship later in the game while I'm already destroying another ship, then happen to hit that ship again, it won't destroy the ship efficiently because it won't count the last shot on it as a shot, and won't increase the fire distance accurately. If I had more time, I might have been able to code some more if else statements to keep track to that previous hit, but with time running out and everything else working, I decided to submit the project. I also briefly tried to code for multiple ships, however, it created so many bugs in my base code, that I decided I would rather have a working program that meets the parameters of the assignment, than a half working program that doesn't. I would love to figure out how to code for mutliple hit ships in the future, but with finals coming up, I doubt I will have time to do that. 

Outside Help: Dr. Fang was an immense help for this project. She provided some code for smartMove, and gave us permission to use this code in our projects, explaining that several students in the past have struggled with that portion and she wanted to help us have a starting point. The code she gave looked like this:

if (memory.mode == SEARCH && memory.fireDir == EAST)
{
  row = memory.hitRow;
  col = memoyr. hitCol;

  string move = "";

  move = move + (char)('A' + row);
  if ()
  {
    move = move + (char)('1' + col);
  }
  else
  {
    move = move + "10";
  }
}
Using this as a base, I was able to figure out how to impliment it in the rest of the cases in my code. At first, I also had my if else statement state what the mode and direction was, but then I realized that I only really needed the direction, since the code was all the same for each mode the computer was in. I will admit, since Dr. Fang gave us permission to use her code, I gave her code to three other students who were struggling. I wanted to mention this in case they submitted the code and it appeared that they were cheating, since there were only 4 of us who went to lab and recieved the code. I probably should have asked if it was alright if I gave them the code, but by the time i realized this, there wasn't any time to email and ask permission. I hope I did not violate any of the guidelines in the syllabus, I promise I was using my best judgement. I only gave them Dr. Fang's code, so they also had to figure out the other cases on their own, though one asked for further help to I gently guided them to the right answer without actually giving it away. 
My boyfriend, a lab assistant, and a friend's dad also helped me fact check my code to make sure my logic was sound. So, other than the portion that Dr. Fang provided, the entirety of the program was done by me. I only ever asked for help in varifying if my logic made sense, which it did.

AI Use: Miraculously, I did not need to use AI because of the generous help from Dr. Fang, my boyrfriend, the lab assistant, and my friend's dad.

Summary/Conclusion: This was definitely a challenging project, but I am very happy with how it turned out. The lab assistant helped me when my program was skipping positions when trying to destroy a ship, and with a starting point for what to look for in my addition statement in smartMove, I was able to fix the program and get it to work. It was a very triumphant moment when it could play fully, so while I am very exhausted from coding this smart battleship, I am also very satisfied.

Lessons Learned: I learned a lot about how to think logically and go line by line in code, and also about how a computer sees code. This project helped me to better understand what the computer sees, and how it can only see what I tell it. This helped me understand how to code for edge cases and all possible scenarios, which will be extremely useful for any future projects I do. I also learned patience in helping others struggle through similar problems that I was facing, and I'm glad I could help them, in any small way.

Time Spent: I spent somewhere between 20 to 25 hours on this project over the past few days.
