// push constant 111
@111
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 333
@333
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 888
@888
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop static 8
@SP
A=M
A=A-1
D=M
@Foo.8
M=D
@SP
M=M-1
// pop static 3
@SP
A=M
A=A-1
D=M
@Foo.3
M=D
@SP
M=M-1
// pop static 1
@SP
A=M
A=A-1
D=M
@Foo.1
M=D
@SP
M=M-1
// push static 3
@Foo.3
D=M
@SP
A=M
M=D
@SP
M=M+1
// push static 1
@Foo.1
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
// push static 8
@Foo.8
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
