// 	push argument 1         
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
// 	pop pointer 1           
    @SP
    M=M-1
    A=M
    D=M
    @4
    M=D
// 	push constant 0         
    @0
    D=A
    @SP
    A=M
    M=D
    @SP
    M=M+1
// 	pop that 0              
    @THAT
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
// 	push constant 1   
    @1
    D=A
    @SP
    A=M
    M=D
    @SP
    M=M+1
// 	pop that 1              
    @THAT
    D=M
    @1
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
// 	push constant 2         
    @2
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
// label LOOP
(FibonacciSeries.LOOP)
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
// 	if-goto COMPUTE_ELEMENT 
    @SP
    M=M-1
    A=M
    D=M
    @FibonacciSeries.COMPUTE_ELEMENT
    D;JNE
// 	goto END                
    @FibonacciSeries.END
    0;JMP
// label COMPUTE_ELEMENT
(FibonacciSeries.COMPUTE_ELEMENT)
// 	push that 0
    @THAT
    D=M
    @0
    A=D+A
    D=M
    @SP
    A=M
    M=D
    @SP
    M=M+1
// 	push that 1
    @THAT
    D=M
    @1
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
// 	pop that 2
    @THAT
    D=M
    @2
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
// 	push pointer 1
    @4
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
// 	pop pointer 1 
    @SP
    M=M-1
    A=M
    D=M
    @4
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
// 	goto LOOP
    @FibonacciSeries.LOOP
    0;JMP
// label END
(FibonacciSeries.END)
(END)
    @END
    0;JMP
