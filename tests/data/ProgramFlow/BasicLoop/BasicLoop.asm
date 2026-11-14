// 	push constant 0    
    @0
    D=A
    @SP
    A=M
    M=D
    @SP
    M=M+1
// 	pop local 0         
    @LCL
    D=M
    @0
    D=D+A
    @R13
    M=D
    @SP
    M=M-1
    A=M
    D=M
    @R13
    A=M
    M=D
// label LOOP
(BasicLoop.LOOP)
// 	push argument 0     
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
// 	push local 0
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
// 	add
    @SP
    A=M
    A=A-1
    D=M
    A=A-1
    D=D+M
    M=D
    D=A
    @SP
    M=D+1
// 	pop local 0	        
    @LCL
    D=M
    @0
    D=D+A
    @R13
    M=D
    @SP
    M=M-1
    A=M
    D=M
    @R13
    A=M
    M=D
// 	push argument 0
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
// 	push constant 1
    @1
    D=A
    @SP
    A=M
    M=D
    @SP
    M=M+1
// 	sub
    @SP
    A=M
    A=A-1
    D=M
    A=A-1
    D=M-D
    M=D
    D=A
    @SP
    M=D+1
// 	pop argument 0      
    @ARG
    D=M
    @0
    D=D+A
    @R13
    M=D
    @SP
    M=M-1
    A=M
    D=M
    @R13
    A=M
    M=D
// 	push argument 0
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
// 	if-goto LOOP        
    @SP
    M=M-1
    A=M
    D=M
    @BasicLoop.LOOP
    D;JNE
// 	push local 0        
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
(END)
    @END
    0;JMP
