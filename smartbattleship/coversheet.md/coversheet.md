
Coversheet file for Smart Battleship

Project #10
By: Nadija Lohja
Date: Decemeber 2025

Requirements: I had to make two functions that allow a battleship program to chose "smart" hits based on previous moves, so it can accurately destroy ships.

Design: In my updateMemory and smartMove functions, I used a series of if else statements to code for different possibilities. In updateMemory, the if else statement parameters check the result of the last hit and the current mode so that I can code for specific scenarios. The smartMove is more general, coding only for the current direction, since the edge cases are taken care of by the updateMemory.

Implementation: In updateMemory, I made sure to update the row and column only until I got my first hit. Then I stopped updating it so that I could use that for a reference point to destroy the ship. I also used the memory.fireDist to keep track of how far away from the ship I got. Then, if I hit a miss, or a ship I didn't want to hit, I set the fire distance back to 1 so I could hit the shot next to my original shot and destroy the ship.

Testing: I probably did over one hundred tests over the past few days while coding this. While my program works perfectly, having the ability to find and destroy ships with amazing accuracy, there is one edge case that I could not code for, and that is if a ship is oriented vertically at the bottom of the board. If I hit that ship later in the game while I'm already destroying another ship, then happen to hit that ship again, it won't destroy the ship efficiently because it won't count the last shot on it as a shot, and won't increase the fire distance accurately. If I had more time, I might have been able to code some more if else statements to keep track to that previous hit, but with time running out and everything else working, I decided to submit the project.
