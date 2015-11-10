.386 
.model flat 

.data
k DWORD 0
s DWORD 1
x DWORD 0

.code 


PUBLIC _dividers 
_dividers proc
	push ebp
	mov ebp, esp
	mov eax, [ebp+8] ;первый параметр   
	mov ebx, [ebp+12] ;второй параметр
	mov s, ebx
	mov x, eax

	mov esi, 2
	cdq
	div esi
	mov ecx, eax

	mov esi, 1

start:
	mov eax, x
	cdq
	div esi
	cmp edx, 0
	jz moving
	inc esi
	loop start
	jmp endend

moving:
	inc k
	mov dword ptr [ebx+4], esi
	inc esi
	add ebx, 4
	loop start

endend:
	mov eax, s
	mov ebx, k
	mov dword ptr [eax], ebx
	pop ebp
	ret
_dividers endp 


end