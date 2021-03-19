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
	LDR R0, N1
	LDR R1, N2
	LDR R2, =DST
	SUBS R3, R0, R1
	STR R3, [R2]

N1 DCD 10
N2 DCD 8
STOP
	B STOP
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
		