// Bootstrap
@256
D=A
@SP
M=D
@Bootstraping$ret.Sys.init     //push returnAddress
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL     //push LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG     //push ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS     //push THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT     //push THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@5     //ARG = SP - 5 - nArgs
D=A
@SP
D=M-D
@ARG
M=D
@SP     //LCL = SP
D=M
@LCL
M=D
@Sys.init     //goto functionName
0;JMP
(Bootstraping$ret.Sys.init)     //(returnAddress)
// function Sys.init 0
(Sys.init)
// push constant 4
@4
D=A
@SP
A=M
M=D
@SP
M=M+1
// call Main.fibonacci 1   // computes the 4'th fibonacci element
@Sys.init$ret.0     //push returnAddress
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL     //push LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG     //push ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS     //push THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT     //push THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@6     //ARG = SP - 5 - nArgs
D=A
@SP
D=M-D
@ARG
M=D
@SP     //LCL = SP
D=M
@LCL
M=D
@Main.fibonacci     //goto functionName
0;JMP
(Sys.init$ret.0)     //(returnAddress)
// label WHILE
(Sys.init$WHILE)
// goto WHILE              // loops infinitely
@Sys.init$WHILE
0;JMP
// function Main.fibonacci 0
(Main.fibonacci)
// push argument 0
@ARG
D=M
@0
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// push constant 2
@2
D=A
@SP
A=M
M=D
@SP
M=M+1
// lt                     // checks if n<2
@SP
A=M-1
D=M
A=A-1
D=M-D
@Main.fibonacci$COMPARE_TRUE_LABEL_0
D;JLT
D=0
@Main.fibonacci$COMPARE_CONTINUE_LABEL_0
0;JMP
(Main.fibonacci$COMPARE_TRUE_LABEL_0)
D=-1
(Main.fibonacci$COMPARE_CONTINUE_LABEL_0)
@SP
A=M-1
A=A-1
M=D
@SP
M=M-1
// if-goto IF_TRUE
@SP
A=M-1
D=M
@SP
M=M-1
@Main.fibonacci$IF_TRUE
D;JNE
// goto IF_FALSE
@Main.fibonacci$IF_FALSE
0;JMP
// label IF_TRUE          // if n<2, return n
(Main.fibonacci$IF_TRUE)
// push argument 0
@ARG
D=M
@0
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// return
@LCL     //endFrame = LCL
D=M
@5
M=D
@5     //retAddr= = *(endFrame - 5)
D=A
@5
A=M-D
D=M
@6
M=D
@SP     //*ARG = pop()
A=M-1
D=M
@SP
M=M-1
@ARG
A=M
M=D
@ARG     //SP = ARG + 1
D=M
@SP
M=D+1
@1     //THAT = *(endFrame - 1)
D=A
@5
A=M-D
D=M
@THAT
M=D
@2     //THIS= *(endFrame - 2)
D=A
@5
A=M-D
D=M
@THIS
M=D
@3     //ARG = *(endFrame - 3)
D=A
@5
A=M-D
D=M
@ARG
M=D
@4     //LCL = *(endFrame - 4)
D=A
@5
A=M-D
D=M
@LCL
M=D
@6     //goto retAddr
A=M
0;JMP
// label IF_FALSE         // if n>=2, returns fib(n-2)+fib(n-1)
(Main.fibonacci$IF_FALSE)
// push argument 0
@ARG
D=M
@0
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// push constant 2
@2
D=A
@SP
A=M
M=D
@SP
M=M+1
// sub
@SP
A=M-1
D=M
A=A-1
D=M-D
@SP
A=M-1
A=A-1
M=D
@SP
M=M-1
// call Main.fibonacci 1  // computes fib(n-2)
@Main.fibonacci$ret.0     //push returnAddress
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL     //push LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG     //push ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS     //push THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT     //push THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@6     //ARG = SP - 5 - nArgs
D=A
@SP
D=M-D
@ARG
M=D
@SP     //LCL = SP
D=M
@LCL
M=D
@Main.fibonacci     //goto functionName
0;JMP
(Main.fibonacci$ret.0)     //(returnAddress)
// push argument 0
@ARG
D=M
@0
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// push constant 1
@1
D=A
@SP
A=M
M=D
@SP
M=M+1
// sub
@SP
A=M-1
D=M
A=A-1
D=M-D
@SP
A=M-1
A=A-1
M=D
@SP
M=M-1
// call Main.fibonacci 1  // computes fib(n-1)
@Main.fibonacci$ret.1     //push returnAddress
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL     //push LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG     //push ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS     //push THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT     //push THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@6     //ARG = SP - 5 - nArgs
D=A
@SP
D=M-D
@ARG
M=D
@SP     //LCL = SP
D=M
@LCL
M=D
@Main.fibonacci     //goto functionName
0;JMP
(Main.fibonacci$ret.1)     //(returnAddress)
// add                    // returns fib(n-1) + fib(n-2)
@SP
A=M-1
D=M
A=A-1
D=D+M
@SP
A=M-1
A=A-1
M=D
@SP
M=M-1
// return
@LCL     //endFrame = LCL
D=M
@5
M=D
@5     //retAddr= = *(endFrame - 5)
D=A
@5
A=M-D
D=M
@6
M=D
@SP     //*ARG = pop()
A=M-1
D=M
@SP
M=M-1
@ARG
A=M
M=D
@ARG     //SP = ARG + 1
D=M
@SP
M=D+1
@1     //THAT = *(endFrame - 1)
D=A
@5
A=M-D
D=M
@THAT
M=D
@2     //THIS= *(endFrame - 2)
D=A
@5
A=M-D
D=M
@THIS
M=D
@3     //ARG = *(endFrame - 3)
D=A
@5
A=M-D
D=M
@ARG
M=D
@4     //LCL = *(endFrame - 4)
D=A
@5
A=M-D
D=M
@LCL
M=D
@6     //goto retAddr
A=M
0;JMP
