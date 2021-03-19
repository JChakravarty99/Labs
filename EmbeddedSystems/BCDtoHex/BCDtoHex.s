	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10000000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =SRC
	LDR R1, [R0]
	LDR R2, =DST
	MOV R5,#0; stores final result in register. Works like sum
	MOV R3, #1; to get power of 10
	MOV R6, #8; counter coz 8 digits
	LDR R7, =0x0A
UP
	AND R4, R1, #0X0F; masking to get last 4 digits
	MLA R5, R4, R3, R5; #(R4*R3)+R5 to get the hex equivalent of those four digits 
	MUL R3, R7; #incrementing order by 10 to move to next digit
	LSR R1, R1, #4; moving to next 4 digits
	SUB R6, R6, #1; decrementing counter
	CMP R6, #0; checking counter
	BEQ exit; if (counter == 0) goto exit
	B UP; else continue loop
exit
	STR R5, [R2]; stores to memory
STOP
	B STOP
SRC DCD 0x00000098; given number is 98 = 1001 1000
	AREA mydata, DATA, READWRITE
DST DCD 0; ans should be 62 in hex
	END