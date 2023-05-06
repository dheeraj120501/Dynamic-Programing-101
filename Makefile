1:
	g++ .\01.cpp -o .\01.exe
	.\01.exe $(n)

2:
	g++ .\02.cpp -o .\02.exe
	.\02.exe $(l) $(p) $(q) $(r)

3:
	g++ .\03.cpp -o .\03.exe
	.\03.exe $(n)

4:
	g++ .\04.cpp -o .\04.exe
	.\04.exe $(n)

.PHONY: 1 2 3 4