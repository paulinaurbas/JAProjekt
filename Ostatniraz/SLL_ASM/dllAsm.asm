;-------------------------------------------------------------------------

.data 
_blue	dq	0.299
_green	dq	0.587
_red	dq	0.114	
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
PUSH rax
PUSH rbx
mov rax, rdx ;szerokosc 
mov rbx, R8 ;wysokosc
mul rbx
mov rdx, 3 
mul rdx
mov rsi, rcx
add rax, rsi
mov rbx, 16
sub rax, rbx 
 
emms
PCMPEQW xmm7, xmm7
NegativeMainLoop:
cmp rsi, rax 
jae endNegativeLoop
movdqu xmm0, [rsi]
pxor xmm0, xmm7
movdqu [rsi], xmm0
add rsi, rbx
jmp NegativeMainLoop
endNegativeLoop:
emms
add rax, rbx
sub rax, rsi
mov rbx, 0FFFFFFFFh
sub rcx, 4
negativeSmallLoop:
cmp rax, 0
jng endSmallLoop
mov rdx, [rsi +rax] 
xor rdx, rbx 
mov [rsi +rax], rdx
sub rax, 4
jmp negativeSmallLoop
endSmallLoop:
POP RAX
POP RBX
POP RSI
ret
MyProc1 endp
END;-------------------------------------------------------------------------