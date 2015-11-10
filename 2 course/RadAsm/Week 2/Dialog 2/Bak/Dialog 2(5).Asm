.386
.model flat,stdcall
option casemap:none

include Dialog 2.inc
include masm32.inc 
includelib masm32.lib


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
	mov		wc.style,CS_HREDRAW or CS_VREDRAW
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
	
	    invoke  GetDlgItem, hWin, IDC_LST1
	        mov     hList, eax
	    
		push	hWin
		pop		hWnd
	.elseif eax==WM_COMMAND
		mov		eax,wParam
		and		eax,0FFFFh
		.if eax==IDM_FILE_EXIT
			invoke SendMessage,hWin,WM_CLOSE,0,0
			
		.elseif (bx==IDC_LST1) && (ax==LBN_SELCHANGE)
	   	    invoke  SendMessage, hList, LB_GETCURSEL, 0, 0
	   	    mov     nIndex,eax
	        invoke  SendMessage, hList, LB_GETTEXT, nIndex, addr szBuffer
	   	    invoke  SendMessage, hEdit, WM_SETTEXT, 0, addr szBuffer
	   	    
		.elseif eax==IDM_HELP_ABOUT
			invoke ShellAbout,hWin,addr AppName,addr AboutMsg,NULL
			
		.elseif eax==IDM_INSERT
			invoke GetDlgItemText,hWin,IDC_EDT1,addr szBuffer, 300
			invoke SendDlgItemMessage, hWin,IDC_LST1, LB_ADDSTRING, 0, addr szBuffer 
			
		.elseif eax==IDM_REMOVE
			invoke CreateDialogParam,hInstance,IDD_DLG1, hWnd, addr RemoveDialog, NULL
            mov eax, 0
            
		.endif
;	.elseif eax==WM_SIZE
	.elseif eax==WM_CLOSE
		invoke DestroyWindow,hWin
	.elseif uMsg==WM_DESTROY
		invoke PostQuitMessage,NULL
	.else
		invoke DefWindowProc,hWin,uMsg,wParam,lParam
		ret
	.endif
	xor    eax,eax
	ret

WndProc endp


RemoveDialog proc DlgWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM

    mov eax,uMsg
    .if eax==WM_INITDIALOG
        invoke GetDlgItem, DlgWin, IDC_EDT2
        mov hEditDlg, eax
        mov eax,1
        ret
    .elseif eax==WM_COMMAND
        mov		eax,wParam
		and		eax,0FFFFh
    .if eax==IDC_BTN1
        invoke GetDlgItemText,DlgWin,IDC_EDT2,addr szBuffer, 300
        invoke atol,addr szBuffer
        mov tmp,eax
        invoke SendMessage, hList, LB_DELETESTRING, tmp, 0
        invoke EndDialog,DlgWin, 0
        mov eax, 0
    .endif
        mov eax,1
        ret
    .elseif eax==WM_CLOSE
        invoke EndDialog,DlgWin, 0
        mov eax,1
        ret
    .elseif uMsg==WM_DESTROY
		invoke PostQuitMessage,NULL
.else
    xor eax,eax
    ret
.endif
RemoveDialog endp


end start
