.386 
PUBLIC @Remainder@8 
.model flat 
.code 
@Remainder@8 proc   
mov eax,ecx ;������ ��������   
mov ecx,edx ;������ ��������   
cdq   
idiv ecx   
mov eax,edx   
ret
@Remainder@8 endp 
end  