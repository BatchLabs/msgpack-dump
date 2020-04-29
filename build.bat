if not exist ".\obj\\" mkdir obj
cl.exe src/*.c /EHsc /Fe:msgpack-dump.exe /Fo".\obj\\"