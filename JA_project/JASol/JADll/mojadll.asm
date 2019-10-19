;-------------------------------------------------------------------------
.386 
.MODEL FLAT, STDCALL
OPTION CASEMAP:NONE
INCLUDE C:\masm32\include\windows.inc
.CODE
DllEntry PROC hInstDLL:HINSTANCE, reason:DWORD, reserved1:DWORD
mov eax, TRUE 
ret
DllEntry ENDP
;------------------------------------------------------------------------- 
;To jest przyk³adowa funkcja. Jest tutaj, aby pokazaæ, ;gdzie nale¿y umieszczaæ w³asne funkcje w bibliotece DLL
;-------------------------------------------------------------------------
MyProc1 proc x: DWORD, y: DWORD
xor eax,eax 
mov eax,x 
mov ecx,y 
ror ecx,1 
shld eax,ecx,2
jnc ET1
mul y 
ret 
ET1: 
Mul x 
Neg y 
ret
MyProc1 endp

MyProc2 proc x: DWORD

mov ax, si
mov edi, ebx
add esi, ebp
add cl, ch
mov ah, 2
mov bp, 0
add cx, 100h
add ebx, 0ffh

MyProc2 endp

END DllEntry ;-------------------------------------------------------------------------