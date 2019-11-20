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
; RDX - begin of portion to convert - this must be the beginning of row
; R8 - end of portion to convert

MyProc1 PROC 
PUSH RSI ;save RSI
PUSH rax
PUSH rbx
mov rsi, rcx 
mov rax, RDX ;do rax pierwszy bit od ktorego zaczniemy 
add rax, R8 ;do rax dodajemy ostatni bit
mov rdx, 3 ;wartosc 3 do rdx
mul rdx ;RAX <- wielkosc obrazka w bajtach
add rax, rsi
mov rbx, 56
sub rax, rbx ;rax <- licznik petli 
emms
PCMPEQW xmm7, xmm7
NegativeMainLoop:
cmp rsi, rax 
jae endNegativeLoop
movdqu xmm0, [rsi]
movdqu xmm1, [rsi+8]
movdqu xmm2, [rsi+16]
movdqu xmm3, [rsi+24]
movdqu xmm4, [rsi+32]
movdqu xmm5, [rsi+40]
movdqu xmm6, [rsi+48]

pxor xmm0, xmm7
pxor xmm1, xmm7
pxor xmm2, xmm7
pxor xmm3, xmm7
pxor xmm4, xmm7
pxor xmm5, xmm7
pxor xmm6, xmm7

movdqu [rsi], xmm0
movdqu [rsi+8], xmm1 
movdqu [rsi+16], xmm2
movdqu [rsi+24], xmm3 
movdqu [rsi+32], xmm4
movdqu [rsi+40], xmm5
movdqu [rsi+48], xmm6 
add rsi, rbx
jmp NegativeMainLoop
endNegativeLoop:
emms
add rax, rbx
sub rax, rsi
mov rbx, 0FFFFFFFFh
sub ecx, 4
negativeSmallLoop:
cmp rax, 0
jng endSmallLoop
mov rdx, [rsi +rax] 
xor rdx, rbx 
mov [rsi +rax], rdx
sub rax, 4
jmp negativeSmallLoop
endSmallLoop:
POP RBX
POP RSI
POP RAX
ret
MyProc1 endp
END;-------------------------------------------------------------------------