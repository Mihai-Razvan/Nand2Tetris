// push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop local 0         // initializes sum = 0
@LCL
D=M
@0
D=D+A
@SP
A=M
M=D
A=A-1
D=M
@SP
A=M
A=M
M=D
@SP
M=M-1
// label LOOP_START
(LOOP_START)
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
// push local 0
@LCL
D=M
@0
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// add
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
// pop local 0	        // sum = sum + counter
@LCL
D=M
@0
D=D+A
@SP
A=M
M=D
A=A-1
D=M
@SP
A=M
A=M
M=D
@SP
M=M-1
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
// pop argument 0      // counter--
@ARG
D=M
@0
D=D+A
@SP
A=M
M=D
A=A-1
D=M
@SP
A=M
A=M
M=D
@SP
M=M-1
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
// if-goto LOOP_START  // If counter != 0, goto LOOP_START
@SP
A=M-1
D=M
@SP
@LOOP_START
D;JNE
// push local 0
@LCL
D=M
@0
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
