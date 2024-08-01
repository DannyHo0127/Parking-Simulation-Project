date:
	g++ Date.cpp -c
parking:
	g++ ParkingWars.cpp -c 
compile:
	make date
	make parking
	g++ Date.o ParkingWars.o MysteryMachine.o Driver.cpp -o battle.out -Wall
run:
	./battle.out
clean:
	rm *.out
