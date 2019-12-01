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
emms
add rax, rbx ;RAX pointing last bajt in array
sub rax, rsi ;rax <- amount of bites to transform
mov rbx, 0FFFFFFFFh 
sub rcx, 4
negativeSmallLoop:
cmp rax, 0 ;check is there any bites to transform 
jng endSmallLoop
cmp rsi, rdx
mov rdx, [rsi +rax]  ;all times to the end
xor rdx, rbx ;RDX xor 0fffffffffh
mov [rsi +rax], rdx ;save tranformt bites to array
sub rax, 4 ;next 4 bites
jmp negativeSmallLoop
endSmallLoop:
POP RAX ;returning register 
POP RBX ;returing register
POP RSI ;returing register
ret
MyProc1 endp
END;-------------------------------------------------------------------------