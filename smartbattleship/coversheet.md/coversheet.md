
Coversheet file for Smart Battleship

Project #10
By: Nadija Lohja
Date: Decemeber 2025

Requirements: I had to make two functions that allow a battleship program to chose "smart" hits based on previous moves, so it can accurately destroy ships.

Design: In my updateMemory and smartMove functions, I used a series of if else statements to code for different possibilities. In updateMemory, the if else statement parameters check the result of the last hit and the current mode so that I can code for specific scenarios. The smartMove is more general, coding only for the current direction, since the edge cases are taken care of by the updateMemory.

Implementation: In updateMemory, I made sure to update the row and column only until I got my first hit. Then I stopped updating it so that I could use that for a reference point to destroy the ship.

Testing:
