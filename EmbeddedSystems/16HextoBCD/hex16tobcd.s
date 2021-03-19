	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler	
Reset_Handler
	LDR r0, =n1
	LDR r7, =dst
	LDR r1, [r0]
	MOV r4, r1 ;copy the number in r4
	MOV r2, #0 ;stores the quotient
up	
	CMP r4, #0xA
	BCC store
	SUB r4, #0xA
	ADD r2, #1
	B up
store
	STRB r4, [r7], #1
	MOV r4, r2
	MOV r2, #0
	CMP r4, #0
	BNE up
	LDR r8, =ans
	LDR r7, =dst
	LDRB r2, [r7],#1
	LDRB r3, [r7],#1
	LSL r3, #4
	ORR r3, r2
	STRB r3, [r8],#1
	LDRB r2, [r7],#1
	LDRB r3, [r7],#1
	LSL r3, #4
	ORR r3,r2
	STRB r3, [r8],#1
	LDRB r3, [r7]
	STRB r3, [r8]
stop 
	B stop
n1 DCD 0x000000F
	AREA mydata, DATA, READWRITE 
dst DCD 0,0,0,0,0
ans DCD 0,0,0,0,0
	END