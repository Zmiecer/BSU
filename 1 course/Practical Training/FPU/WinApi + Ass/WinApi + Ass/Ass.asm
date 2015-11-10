; sqrt, sin, log2
.386 

PUBLIC _fsqrt
.model flat
.data
.code
_fsqrt proc
cld
push ebp
mov ebp, esp
fld qword ptr [ebp+8]
fsqrt
pop ebp
ret
_fsqrt endp



PUBLIC _fsin
.model flat
.code
_fsin proc
cld
push ebp
mov ebp, esp
fld qword ptr [ebp+8]
fsin
pop ebp
ret
_fsin endp



PUBLIC _flog2
.model flat
.code
_flog2 proc
cld
push ebp
mov ebp, esp
fld1
fld qword ptr [ebp+8]
fyl2x
pop ebp
ret
_flog2 endp


end