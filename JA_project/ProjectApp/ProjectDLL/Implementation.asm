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
; Arguments:
; ECX - address of first byte in bitmap array
; EDX - begin of portion to convert - this must be the beginning of row
; E8 - end of portion to convert
; E9 - width

MyProc1 PROC 
PUSH ESI ;save R
MOV ESI,ECX ;wskaznik z obrzkiem
ADD ESI, EDX ;bit from whitch start
;ADD E8, ECX
;MOV EAX, E9 ;RAX = width

;NegativeLoop:
;cmp esi, ecx
;jae negativeEndLoop
;movq mm0, [esi] ; pobierz z tablicy 56 bajt 
;movq mm1, [esi+8] 
;movq mm2, [esi+16]
;movq mm3, [esi+24]
;movq mm4, [esi+32]
;movq mm5, [esi+40]
;movq mm6, [esi+48]
MyProc1 endp
END DllEntry ;-------------------------------------------------------------------------