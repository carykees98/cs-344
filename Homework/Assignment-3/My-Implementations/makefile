all: power maxsum clean

maxsum: maxsum.o
	g++ main_maxsum.cpp maxsum.o -o maxsum

maxsum.o: 
	g++ -c maxsum.cpp

power: power.o
	g++ main_power.cpp power.o -o power

power.o:
	g++ -c power.cpp

clean:
	rm *.o