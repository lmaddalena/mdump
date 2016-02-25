cl ../*.c /Fe:test.exe
lib.exe /out:mdump.lib mdump.obj
cl /LD ../mdump.c /Fe:mdump.dll
