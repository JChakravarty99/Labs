	AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE, READONLY
	ENTRY
	EXPORT Reset_Handler

Reset_Handler
	LDR R0, =SRC
	LDR R1, =1
	LDR R2, =10
ini	STR R1, [R0], #4
	ADD R1, #1
	SUBS R2, #1
	BNE ini
	LDR R0, =SRC
	LDR R1, =SRC
	ADD R1, #36
	MOV R2, #5
up	LDR R3, [R0]
	LDR R4, [R1]
	STR R3, [R1], #-4
	STR R4, [R0], #1
	SUBS R2, #1
	BNE up

STOP
	B STOP
	AREA mydata, DATA, READWRITE
SRC DCD 0
	END