CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
	
cardtest1: dominion.o cardtest1.c
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o Assert.c $(CFLAGS)
	
cardtest4: dominion.o cardtest4.c
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o Assert.c $(CFLAGS)
	
cardtest5: dominion.o cardtest5.c
	gcc -o cardtest5 cardtest5.c -g dominion.o rngs.o Assert.c $(CFLAGS)
	
randomtestcard2: dominion.o randomtestcard2.c
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o Assert.c $(CFLAGS)
	
randomtestadventurer: dominion.o randomtestadventurer.c
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o Assert.c $(CFLAGS)
	
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

assign5testresults: randomtestadventurer randomtestcard2 cardtest1 cardtest4 cardtest5
	./cardtest1 &> assign5testresults.out
	./cardtest4 >> assign5testresults.out
	./cardtest5 >> assign5testresults.out
	./randomtestcard2 >> assign5testresults.out
	./randomtestadventurer >> assign5testresults.out
	gcov dominion.c >> assign5testresults.out
	cat dominion.c.gcov >> assign5testresults.out
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player cardtest1 cardtest4 cardtest5 randomtestcard2

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
	rm -rf *.dSYM
