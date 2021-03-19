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
	LDR R0, =N1
	LDR R1, =RES
	LDR R2, [R0]
	BL Fact
	STR R2, [R1]
STOP 
	B STOP
Fact
	PUSH {R3, LR}
	MOV R3, R2
	CMP R2, #0
	BNE down
	MOV R2, #1
	B down1
down
	SUB R2, #1
	BL Fact
	MOV R4, R3
	MUL R2, R4
down1
	POP {R3, LR}
	BX LR
N1 DCD 0x4
	AREA mydata, DATA, READWRITE
RES DCD 0
	END
	
