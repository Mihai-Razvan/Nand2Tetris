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
// push constant 6
@6
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 8
@8
D=A
@SP
A=M
M=D
@SP
M=M+1
// call Class1.set 2
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
@7     //ARG = SP - 5 - nArgs
D=A
@SP
D=M-D
@ARG
M=D
@SP     //LCL = SP
D=M
@LCL
M=D
@Class1.set     //goto functionName
0;JMP
(Sys.init$ret.0)     //(returnAddress)
// pop temp 0 // Dumps the return value
@SP
A=M
A=A-1
D=M
@5
M=D
@SP
M=M-1
// push constant 23
@23
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 15
@15
D=A
@SP
A=M
M=D
@SP
M=M+1
// call Class2.set 2
@Sys.init$ret.1     //push returnAddress
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
@7     //ARG = SP - 5 - nArgs
D=A
@SP
D=M-D
@ARG
M=D
@SP     //LCL = SP
D=M
@LCL
M=D
@Class2.set     //goto functionName
0;JMP
(Sys.init$ret.1)     //(returnAddress)
// pop temp 0 // Dumps the return value
@SP
A=M
A=A-1
D=M
@5
M=D
@SP
M=M-1
// call Class1.get 0
@Sys.init$ret.2     //push returnAddress
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
@Class1.get     //goto functionName
0;JMP
(Sys.init$ret.2)     //(returnAddress)
// call Class2.get 0
@Sys.init$ret.3     //push returnAddress
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
@Class2.get     //goto functionName
0;JMP
(Sys.init$ret.3)     //(returnAddress)
// label WHILE
(Sys.init$WHILE)
// goto WHILE
@Sys.init$WHILE
0;JMP
// function Class1.set 0
(Class1.set)
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
// pop static 0
@SP
A=M
A=A-1
D=M
@Class1.0
M=D
@SP
M=M-1
// push argument 1
@ARG
D=M
@1
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop static 1
@SP
A=M
A=A-1
D=M
@Class1.1
M=D
@SP
M=M-1
// push constant 0
@0
D=A
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
// function Class1.get 0
(Class1.get)
// push static 0
@Class1.0
D=M
@SP
A=M
M=D
@SP
M=M+1
// push static 1
@Class1.1
D=M
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
// function Class2.set 0
(Class2.set)
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
// pop static 0
@SP
A=M
A=A-1
D=M
@Class2.0
M=D
@SP
M=M-1
// push argument 1
@ARG
D=M
@1
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop static 1
@SP
A=M
A=A-1
D=M
@Class2.1
M=D
@SP
M=M-1
// push constant 0
@0
D=A
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
// function Class2.get 0
(Class2.get)
// push static 0
@Class2.0
D=M
@SP
A=M
M=D
@SP
M=M+1
// push static 1
@Class2.1
D=M
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
