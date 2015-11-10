.386
.model flat,stdcall
option casemap:none

include Individual.inc

.code

start:

	invoke GetModuleHandle,NULL
	mov    hInstance,eax
	invoke GetCommandLine
	invoke InitCommonControls
	mov		CommandLine,eax
	invoke WinMain,hInstance,NULL,CommandLine,SW_SHOWDEFAULT
	invoke ExitProcess,eax

WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD
	LOCAL	wc:WNDCLASSEX
	LOCAL	msg:MSG

	mov		wc.cbSize,sizeof WNDCLASSEX
	mov		wc.style, CS_HREDRAW or CS_VREDRAW or CS_DBLCLKS
	mov		wc.lpfnWndProc,offset WndProc
	mov		wc.cbClsExtra,NULL
	mov		wc.cbWndExtra,DLGWINDOWEXTRA
	push	hInst
	pop		wc.hInstance
	mov		wc.hbrBackground,COLOR_BTNFACE+1
	mov		wc.lpszMenuName,IDM_MENU
	mov		wc.lpszClassName,offset ClassName
	invoke LoadIcon,NULL,IDI_APPLICATION
	mov		wc.hIcon,eax
	mov		wc.hIconSm,eax
	invoke LoadCursor,NULL,IDC_ARROW
	mov		wc.hCursor,eax
	invoke RegisterClassEx,addr wc
	invoke CreateDialogParam,hInstance,IDD_DIALOG,NULL,addr WndProc,NULL
	invoke ShowWindow,hWnd,SW_SHOWNORMAL
	invoke UpdateWindow,hWnd
	.while TRUE
		invoke GetMessage,addr msg,NULL,0,0
	  .BREAK .if !eax
		invoke TranslateMessage,addr msg
		invoke DispatchMessage,addr msg
	.endw
	mov		eax,msg.wParam
	ret

WinMain endp

WndProc proc hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM

	mov		eax,uMsg
	.if eax==WM_INITDIALOG
		push	hWin
		pop		hWnd
		invoke  GetDlgItem, hWin, IDC_LST1
        mov     hList, eax
		
        invoke SendDlgItemMessage, hWin,IDC_LST1, LB_ADDSTRING, 0, addr one
        invoke SendDlgItemMessage, hWin,IDC_LST1, LB_ADDSTRING, 0, addr two
        invoke SendDlgItemMessage, hWin,IDC_LST1, LB_ADDSTRING, 0, addr three
        invoke SendDlgItemMessage, hWin,IDC_LST1, LB_ADDSTRING, 0, addr four
        invoke SendDlgItemMessage, hWin,IDC_LST1, LB_ADDSTRING, 0, addr five
        invoke SendDlgItemMessage, hWin,IDC_LST1, LB_ADDSTRING, 0, addr six
        invoke SendDlgItemMessage, hWin,IDC_LST1, LB_ADDSTRING, 0, addr seven
        invoke SendDlgItemMessage, hWin,IDC_LST1, LB_ADDSTRING, 0, addr eight
        invoke SendDlgItemMessage, hWin,IDC_LST1, LB_ADDSTRING, 0, addr nine
        invoke SendDlgItemMessage, hWin,IDC_LST1, LB_ADDSTRING, 0, addr ten
	   	    	
	.elseif eax==WM_COMMAND
		mov     eax, wParam
        mov     bx, ax	; LOWORD(wParam) – control identifier
        shr     eax, 16	; HIWORD(wParam) –  notification code 
        
	    .if (bx==IDC_LST1); && (ax==LBN_DBLCLK)
   	            invoke  SendMessage, hList, LB_GETCURSEL, 0, 0
   	            mov     nIndex, eax
                invoke  SendMessage, hList, LB_GETTEXT, nIndex, addr szBuffer
    	        pop     eax
    	        	        	        
        .endif
		
		.if bx==IDM_FILE_EXIT
			invoke SendMessage,hWin,WM_CLOSE,0,0
			
		.elseif bx==IDM_HELP_ABOUT
			invoke ShellAbout,hWin,addr AppName,addr AboutMsg,NULL
			
		.elseif bx==IDC_LST1 && (ax==LBN_DBLCLK)
		    invoke SendDlgItemMessage, hWin, IDC_LST1, LB_DELETESTRING, nIndex, 0
		    invoke SendDlgItemMessage, hWin, IDC_LST2, LB_ADDSTRING, 0, addr szBuffer
            
		.endif
;	.elseif eax==WM_SIZE
	
	.elseif ax==WM_CLOSE
		invoke DestroyWindow, hWin
		
	.elseif uMsg==WM_DESTROY
		invoke PostQuitMessage, NULL
		
	.else
		invoke DefWindowProc, hWin, uMsg, wParam, lParam
		ret
		
	.endif
	xor    eax,eax
	ret

WndProc endp

end start
