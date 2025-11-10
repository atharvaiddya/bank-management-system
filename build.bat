@echo off
echo Compiling project...

REM %~dp0
set SRC=%~dp0src
set INCLUDE=%~dp0include
set OUT=%~dp0main.exe

gcc "%SRC%\main.c" "%SRC%\onboarding.c" -I"%INCLUDE%" -o "%OUT%"

echo Done! Run main.exe to start the program.
pause
