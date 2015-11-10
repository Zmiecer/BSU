.586
.model flat,stdcall
option casemap:none

   include Traffic lights.inc


.code

start:
	invoke GetModuleHandle, NULL
	mov    hInstance,eax
	
	invoke GetCommandLine
	mov    CommandLine,eax
	
	invoke WinMain, hInstance,NULL,CommandLine, SW_SHOWDEFAULT
	invoke ExitProcess,eax

WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD
	LOCAL wc:WNDCLASSEX
	LOCAL msg:MSG
	LOCAL hwnd:HWND
	
	mov   wc.cbSize,SIZEOF WNDCLASSEX
	mov   wc.style, CS_HREDRAW or CS_VREDRAW
	mov   wc.lpfnWndProc, OFFSET WndProc
	mov   wc.cbClsExtra,NULL
	mov   wc.cbWndExtra,NULL
	push  hInstance
	pop   wc.hInstance
	mov   wc.hbrBackground,COLOR_BTNFACE+1
	mov   wc.lpszMenuName,NULL
	mov   wc.lpszClassName,OFFSET ClassName
	
	invoke LoadIcon,NULL,IDI_APPLICATION
	mov   wc.hIcon,eax
	mov   wc.hIconSm,eax
	
	invoke LoadCursor,NULL,IDC_ARROW
	mov   wc.hCursor,eax
	
	invoke RegisterClassEx, addr wc
	INVOKE CreateWindowEx,NULL,ADDR ClassName,ADDR AppName,\
           WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,\
           CW_USEDEFAULT,215,640,NULL,NULL,\
           hInst,NULL
	mov   hwnd,eax
	
	invoke ShowWindow, hwnd,SW_SHOWNORMAL
	invoke UpdateWindow, hwnd
	
	.WHILE TRUE
		invoke GetMessage, ADDR msg,NULL,0,0
		.BREAK .IF (!eax)
		invoke TranslateMessage, ADDR msg
		invoke DispatchMessage, ADDR msg
	.ENDW
	
	mov     eax,msg.wParam
	ret
WinMain endp

WndProc proc hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
	
	.if uMsg==WM_DESTROY
	    invoke DeleteObject, hRedBrush
	    invoke DeleteObject, hYellowBrush
	    invoke DeleteObject, hGreenBrush
	    invoke DeleteObject, hGreyBrush
		invoke KillTimer,hWnd,NULL
		invoke PostQuitMessage,NULL
		
	.elseif uMsg==WM_CREATE
		invoke SetTimer,hWnd,NULL,1000,NULL
		
		invoke  CreateSolidBrush, RedBrush
        mov     hRedBrush, eax
        invoke  CreateSolidBrush, YellowBrush
        mov     hYellowBrush, eax
        invoke  CreateSolidBrush, GreenBrush
        mov     hGreenBrush, eax
        invoke  CreateSolidBrush, GreyBrush
        mov     hGreyBrush, eax
        
        
    .elseif uMsg==WM_PAINT
	    invoke  BeginPaint, hWnd, addr ps
	    mov     hDC, eax
	    
	    invoke GetClientRect,hWnd,OFFSET crect
	    mov eax, crect.bottom
	    mov GreenBottom, eax
	    
	    mov eax, crect.bottom
	    sub eax, crect.top
	    cdq
	    div three
	    mov RedBottom, eax
	    mul two
	    mov YellowBottom, eax
	    
	    mov eax, crect.right
	    sub eax, crect.left
	    mov diam, eax
	    
	    .if RedBottom > eax
	        mov eax, diam
	        mov RedBottom, eax
	        mul two
	        mov YellowBottom, eax
	        
	        mov eax, diam
	        mul three
	        mov GreenBottom, eax
	    .endif
	    	    
	    invoke SelectObject,hDC,hGreyBrush
	    invoke  Ellipse, hDC, 0, 0, RedBottom, RedBottom                ;Red
	    invoke  Ellipse, hDC, 0, RedBottom, RedBottom, YellowBottom      ;Yellow
	    invoke  Ellipse, hDC, 0, YellowBottom, RedBottom, GreenBottom    ;Green
	    
	    .if k<2
	        invoke SelectObject,hDC,hRedBrush
	        invoke  Ellipse, hDC, 0, 0, RedBottom, RedBottom                    ;Red
	        .if k==1
	            invoke SelectObject,hDC,hYellowBrush
	            invoke  Ellipse, hDC, 0, RedBottom, RedBottom, YellowBottom      ;Yellow
	        .endif            
	        
        .elseif k==2
	        invoke SelectObject,hDC,hGreenBrush
	        invoke  Ellipse, hDC, 0, YellowBottom, RedBottom, GreenBottom        ;Green
	        
	    .elseif k==3
            invoke SelectObject,hDC,hYellowBrush
	        invoke  Ellipse, hDC, 0, RedBottom, RedBottom, YellowBottom          ;Yellow
	             
	    .endif
	    
	    invoke  EndPaint, hWnd, addr ps
	
	.elseif uMsg==WM_TIMER
        inc k
        and k, 3
        invoke InvalidateRect,hWnd,NULL,TRUE
            
	.else
		invoke DefWindowProc,hWnd,uMsg,wParam,lParam		
		ret
		
	.endif
	
	xor eax,eax
	ret
WndProc endp


end start
