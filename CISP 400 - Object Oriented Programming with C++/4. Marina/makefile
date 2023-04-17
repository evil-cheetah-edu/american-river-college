main: Boat.o Marina.o main.o MotorPowered.o MusclePowered.o SailPowered.o Ski.o CabinCruiser.o Kayak.o Shanty.o TrailerSailer.o
	g++ Boat.o MotorPowered.o MusclePowered.o SailPowered.o Ski.o CabinCruiser.o Kayak.o Shanty.o TrailerSailer.o Marina.o main.o -o main
main.o: main.cpp Marina.o MusclePowered.o MotorPowered.o SailPowered.o Ski.o CabinCruiser.o Kayak.o Shanty.o TrailerSailer.o
	g++ -pedantic -Wall main.cpp -c
Marina.o: Marina.h Marina.cpp MotorPowered.o MusclePowered.o SailPowered.o Ski.o CabinCruiser.o Kayak.o Shanty.o TrailerSailer.o
	g++ -pedantic Marina.cpp -c
TrailerSailer.o: TrailerSailer.h TrailerSailer.cpp SailPowered.o
	g++ -pedantic -Wall TrailerSailer.cpp -c
Shanty.o: Shanty.h Shanty.cpp MusclePowered.o
	g++ -pedantic -Wall Shanty.cpp -c
Kayak.o: Kayak.h Kayak.cpp MusclePowered.o
	g++ -pedantic -Wall Kayak.cpp -c
CabinCruiser.o: CabinCruiser.h CabinCruiser.cpp MotorPowered.o
	g++ -pedantic -Wall CabinCruiser.cpp -c
Ski.o: Ski.h Ski.cpp MotorPowered.o
	g++ -pedantic -Wall Ski.cpp -c
SailPowered.o: SailPowered.h SailPowered.cpp
	g++ -pedantic -Wall SailPowered.cpp -c
MusclePowered.o: MusclePowered.h MusclePowered.cpp
	g++ -pedantic -Wall MusclePowered.cpp -c
MotorPowered.o: MotorPowered.h MotorPowered.cpp
	g++ -pedantic -Wall MotorPowered.cpp -c