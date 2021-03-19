	AREA RESET,DATA,READONLY
	EXPORT __Vectors

__Vectors
	DCD 0x40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R6, =Result
	MOV R2, #00
	LDR R0, =Value
	LDR R0, [R1]
up
	CMP R1, #0xA
	BCC store
	SUB R1, #0xA
	ADD R2, #01
	B up
store
	ADD R1, #0x30
	STRB R1, [R6], #1
	MOV R1, R2
	MOV R2, #0
	CMP R1, #0xA
	BCS up
	ADD R1, #0x30
	STRB R1, [R6]
STOP
	B STOP
Result DCD 25
	AREA mydata, DATA, READONLY
Value DCD 0
	END
	
	
