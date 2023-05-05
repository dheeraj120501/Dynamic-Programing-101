1:
	g++ .\01.cpp -o .\01.exe
	.\01.exe $(n)

2:
	g++ .\02.cpp -o .\02.exe
	.\02.exe $(l) $(p) $(q) $(r)

.PHONY: 1 2