@echo off
REM Compila todos los archivos .cpp del directorio src/ hacia el ejecutable app.exe
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -I./include src/*.cpp -o app.exe
echo Compilacion finalizada exitosamente. Ejecuta app.exe para iniciar el sistema.
pause