   include windows.inc
   include user32.inc
   include kernel32.inc
   include gdi32.inc
   
   includelib user32.lib
   includelib kernel32.lib
   includelib gdi32.lib


WinMain proto :DWORD,:DWORD,:DWORD,:DWORD


.data
   ClassName        db "MainWinClass",0
   AppName          db "Traffic lights",0
   RedBrush         dd  000ffh
   YellowBrush      dd  0fff0h
   GreenBrush       dd  0f000h
   GreyBrush        dd  808080h
   k                dd  0
   three            dd  3
   
.data?
   hInstance        HINSTANCE   ?
   CommandLine      LPSTR   ?
   ps   	        PAINTSTRUCT <>  ; неинициализированная структура
   hDC  	        HDC ?
   hRedBrush        dd  ?
   hYellowBrush     dd  ?
   hGreenBrush      dd  ?
   hGreyBrush       dd  ?
   crect            RECT    <>

