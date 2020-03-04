;-------------------------------------------------------------------------
; Assembler function for negative 
; Author: Paulina Urbas
; Data: 23.11.2019
;-------------------------------------------------------------------------
.data 

.CODE
DllEntry PROC hInstDLL:DWORD, reason:DWORD, reserved1:DWORD
mov eax, 1h
ret
DllEntry ENDP
; Arguments:
; RCX - address of first byte in bitmap array
; RDX - width
; R8 - height

MyProc1 PROC 
PUSH RSI ;save RSI
PUSH rax ;save RAX
PUSH rbx ;save RBX

mov rax, rdx ;width 
mov rbx, R8 ;height
mul rbx ;RAX <- picture size in points
mov rdx, 3 
mul rdx ;RAX <- picture size in baits 
mov rsi, rcx ;pointer to bitmap array 
add rax, rsi ;counter big loop
mov rbx, 16 
sub rax, rbx ;RAX <- big loop counter 
 
emms
PCMPEQW xmm7, xmm7 ;mm7 <- 0ffffffffffffffffh
NegativeMainLoop:
	cmp rsi, rax 
	jae endNegativeLoop
	movdqu xmm0, [rsi] ;take from table 16 
	pxor xmm0, xmm7 ;transfrom to negative
	movdqu [rsi], xmm0 ;save to table
	add rsi, rbx ;add 16 to pointer counter array
	jmp NegativeMainLoop 
endNegativeLoop:
	;sub rsi, 0
	add rax, 16
	sub rax, rsi 
	mov rcx, rax
	;add rax, rbx ;RAX pointing last bajt in array
	;sub rax, rsi ;rax <- amount of bites to transform
	;mov rbx, 0FFFFFFFFh 
	;sub rcx, 1
negativeSmallLoop:
	cmp rcx, 0
	je endSmallLoop

	mov al, [rsi]
	xor al, 255
	mov [rsi], al
	inc rsi
	dec rcx
	jmp negativeSmallLoop
;negatyw bitowo dla ka¿dego bitu osobno, rsi przetwarzam, odejmuje od rax, dodaje do rsi 1 
	;cmp rax, 0 ;check is there any bites to transform 
	;jng endSmallLoop
;	cmp rsi, rdx
	;mov rax, [rsi]  ;all times to the end
	;xor eax, 255 ;RDX xor 0fffffffffh
	;mov [], rax ;save tranformt bites to array
	;sub eax, 1 ;next 4 bites
	;jmp negativeSmallLoop
endSmallLoop:
POP RAX ;returning register 
POP RBX ;returing register
POP RSI ;returing register
ret
MyProc1 endp
END;-------------------------------------------------------------------------