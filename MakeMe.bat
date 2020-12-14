@echo off
set ROOT=c:/ultra
call %ROOT%\setupgcc.bat
call %ROOT%\setuplib.bat
make
pause
