
.386
.model flat
.code


PUBLIC @fast@8
@fast@8 proc
mov eax, ecx; ������ ��������
mov ecx, edx; ������ ��������

mov ebx, eax
sub ecx, 1
cmp ecx, 0
je probb

start:
	cdq
	imul ebx
	loop start
	jmp endd
probb:
	jmp endd
endd:
ret


@fast@8 endp



end