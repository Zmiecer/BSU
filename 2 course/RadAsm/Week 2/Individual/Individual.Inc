include windows.inc
include user32.inc
include kernel32.inc
include shell32.inc
include comctl32.inc
include comdlg32.inc

includelib user32.lib
includelib kernel32.lib
includelib shell32.lib
includelib comctl32.lib
includelib comdlg32.lib

WinMain				PROTO :DWORD,:DWORD,:DWORD,:DWORD
WndProc				PROTO :DWORD,:DWORD,:DWORD,:DWORD

IDD_DIALOG			equ 1000

IDM_MENU			equ 10000
IDM_FILE_EXIT		equ 10001
IDM_HELP_ABOUT		equ 10101
IDM_INSERT          equ 10002

IDC_LST1            equ 1001
IDC_LST2            equ 1002

.const

ClassName			db 'DLGCLASS',0
AppName				db 'Dialog as main',0
AboutMsg			db 'MASM32 RadASM Dialog as main',13,10,'Copyright © MASM32 2001',0

.data?

hInstance			dd ?
CommandLine			dd ?
hWnd				dd ?
hList               dd ?
tmp                 dd ?

hEdit               dd ?

.data

szBuffer        db  300 dup(' ')
one             db  '1', 0
two             db  '2', 0
three           db  '3', 0
four            db  '4', 0
five            db  '5', 0
six             db  '6', 0
seven           db  '7', 0
eight           db  '8', 0
nine            db  '9', 0
ten             db  '10', 0
k               dd  1
nIndex          dd  -1
