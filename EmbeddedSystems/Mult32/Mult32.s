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
	LDR R1, =Value1
	LDR R2, =Value2
	UMULL R3, R4, R2, R1
	LDR R2, =Result
	STR R4, [R2]
	ADD R2, #4
	STR R3, [R2]
STOP
	B STOP
Value1 DCD 0X54000000
Value2 DCD 0X10000002
	AREA mydata, DATA, READWRITE
Result DCD 0 
	END
	