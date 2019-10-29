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
; R9 - width

MyProc1 PROC 
PUSH RSI ;save RSI
MOV RSI,RCX ;first argument to RSI - begin of array
ADD RSI, RDX ;Add begin to RSI
ADD R8, RCX
MOV RAX, R9 ;RAX = width
XOR RDX, RDX
PUSH RBX ;save RBX
MOV RBX, 4
DIV BX ;width/4
MOV R11, RDX ;#? R11 = width % 4
PUSH RDI
XOR RDI, RDI
emms
pcmpeqd MM7, MM7
NegativeLoop:
cmp rsi, rcx
jae negativeEndLoop
movq mm0, [rsi] ; pobierz z tablicy 56 bajt 
movq mm1, [rsi+8] 
movq mm2, [rsi+16]
movq mm3, [rsi+24]
movq mm4, [rsi+32]
movq mm5, [rsi+40]
movq mm6, [rsi+48]
pxor mm0, mm7
pxor mm1, mm7
pxor mm2, mm7
pxor mm3, mm7
pxor mm4, mm7
pxor mm5, mm7
pxor mm6, mm7
movq [rsi], mm0
movq [rsi+8], mm1
movq [rsi+16], mm2
movq [rsi+24], mm3
movq [rsi+32], mm4
movq [rsi+40], mm5
movq [rsi+48], mm6
add rsi, rbx
jmp NegativeLoop
negativeEndLoop:
emms
add rcx, rbx
sub rcx, rsi 
mov rbx, 0FFFFFFFFh
sub rcx, 4
negativeSmallLoop:
cmp rcx, 0
jng negativeEndLoop
;mov dword ptr [rsi +rcx]
;xor rax, ebx
;mov dword ptr [rsi +rcx]
sub ecx, 4
jmp negativeSmallLoop
negativeSmallLoopEnd:


ret
MyProc1 endp
END;-------------------------------------------------------------------------