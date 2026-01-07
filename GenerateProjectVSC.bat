@echo off
REM === Step 1: go to project folder ===
cd /d F:\dev\Auralite

REM === Step 2: generate VS solution (optional) ===
vendor\bin\premake\premake5.exe vs2022

REM === Step 3: load x64 Developer environment ===
call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" -arch=x64

REM === Step 4: open VS Code in project folder ===
code .
