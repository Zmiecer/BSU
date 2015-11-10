.386 
.model flat 


;.data
;k DWORD 0


.code 

PUBLIC @fast@12 
@fast@12 proc
	push ebp
	mov ebp, esp
	mov ebx, [ebp+8] ;третий параметр
	mov eax, ecx ;первый параметр   
	mov ecx, edx ;второй параметр   
	cdq
	mul ecx
	sub eax, ebx
	pop ebp
	ret 4
@fast@12 endp 



PUBLIC _stnd@12 
_stnd@12 proc
	push ebp
	mov ebp, esp
	mov eax, [ebp+8] ;первый параметр   
	mov ebx, [ebp+12] ;второй параметр 
	mov ecx, [ebp+16] ;третий параметр   
	cdq
	mul ebx
	sub eax, ecx
	pop ebp
	ret 12
_stnd@12 endp 



PUBLIC _decl 
_decl proc
	push ebp
	mov ebp, esp
	mov eax, [ebp+8] ;первый параметр   
	mov ebx, [ebp+12] ;второй параметр 
	mov ecx, [ebp+16] ;третий параметр   
	cdq
	mul ebx
	sub eax, ecx
	pop ebp
	ret
_decl endp 


end