// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(LOOP)
@16384
D=A
@index
M=D

(DRAW_PIXEL)
@24576
D=M
@DRAW_WHITE
D;JEQ             //else will continue on DRAW_BLACK

(DRAW_BLACK)
@index
A=M
M=-1
@CONTINUE
0;JMP

(DRAW_WHITE)
@index
A=M
M=0

(CONTINUE)
@index
M=M+1
D=M
@24576
D=D-A
@LOOP
D;JEQ
@DRAW_PIXEL    //else we haven't finished with all screen
0;JMP