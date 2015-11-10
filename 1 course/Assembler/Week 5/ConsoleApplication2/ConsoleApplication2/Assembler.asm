.386 
.model flat
.code 
 


PUBLIC _func
_func proc

push ebp
mov ebp, eax
mov ecx, 3

start:
cmp byte ptr [ebp], '0'
je comp
add ebp, 1
loop start
jmp fin

comp:
mov byte ptr [ebp], '1'
add ebp, 1
loop start

fin:

pop ebp
ret
_func endp



;/////////////////////////////////////////////////////////////////////////////////////////////////

PUBLIC _space
_space proc

push ebp
mov ebp, eax
mov ecx, 8
mov eax, 1
sub ebp, 1

start:
add ebp, 1
cmp byte ptr [ebp], ' '
je comp
loop start
jmp fin

comp:
add eax, 1
loop start

fin:

pop ebp
ret
_space endp



end