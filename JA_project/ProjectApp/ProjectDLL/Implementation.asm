;-------------------------------------------------------------------------
.386 
.MODEL FLAT, STDCALL
OPTION CASEMAP:NONE
INCLUDE C:\masm32\include\windows.inc
.data 
_blue	dq	0.299
_green	dq	0.587
_red	dq	0.114	
.CODE
DllEntry PROC hInstDLL:HINSTANCE, reason:DWORD, reserved1:DWORD
mov eax, TRUE 
ret
DllEntry ENDP
;------------------------------------------------------------------------- 
;To jest przyk³adowa funkcja. Jest tutaj, aby pokazaæ, ;gdzie nale¿y umieszczaæ w³asne funkcje w bibliotece DLL
;-------------------------------------------------------------------------
; Arguments:
; RCX - address of first byte in bitmap array
; RDX - begin of portion to convert - this must be the beginning of row
; R8 - end of portion to convert
; R9 - width

MyProc1 PROC
PUSH ESI ;save RSI
MOV ESI,ECX ;first argument to RSI - begin of array
ADD ESI, EDX ;Add begin to RSI
MyProc1 endp
END DllEntry ;-------------------------------------------------------------------------