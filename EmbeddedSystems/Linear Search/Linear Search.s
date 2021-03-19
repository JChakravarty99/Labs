	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN 
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R1, =ARR
	LDR R2, =ELE
	MOV R3, #10
	LDR R7, =result
	LDR R8, [R2]
Loop
	LDR R0, [R1], #4
	CMP R8, R0
	BEQ Store
	SUBS R3, #1
	BNE Loop
	MOV R4, #0
	STR R4, [R7], #1
	B STOP
Store
	MOV R4, #1
	MOV R5, #10
	SUBS R3, R5, R3
	STRB R4, [R7], #1
	STR R3, [R7]
STOP
	B STOP
ARR DCD 6,5,3,9,2,1,4,7,8,0
ELE DCD 4
	AREA mydata, DATA, READWRITE
result dcd 0
	END
	