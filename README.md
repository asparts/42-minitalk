42cursus - minitalk

Project Information
About
The purpose of this project is to code a small data exchange program using UNIX signals.

Mandatory part:
 - Produce server & client executables
 - Client must communicate a string passed as a parameter to server (referenced by its process ID) which then displays it
 - Use SIGUSR1 & SIGUSR2 signals ONLY

Allowed Functions
malloc
free
write
getpid
signal
sigemptyset & sigaddset
sigaction
pause
kill
sleep
usleep
exit
