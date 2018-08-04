CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

Assert.o: Assert.h Assert.c
	gcc -c Assert.c -g  $(CFLAGS)

unittest1: dominion.o rngs.o Assert.o unittest1.c
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o Assert.o $(CFLAGS)
	
unittest2: dominion.o rngs.o Assert.o unittest2.c
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o Assert.o $(CFLAGS)
	
unittest3: dominion.o rngs.o Assert.o unittest3.c
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o Assert.o $(CFLAGS)
	
unittest4: dominion.o rngs.o Assert.o unittest4.c
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o Assert.o $(CFLAGS)
	
cardtest1: dominion.o rngs.o Assert.o cardtest1.c
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o Assert.o $(CFLAGS)
	
cardtest2: dominion.o rngs.o Assert.o cardtest2.c
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o Assert.o $(CFLAGS)

cardtest3: dominion.o rngs.o Assert.o cardtest3.c
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o Assert.o $(CFLAGS)
	
cardtest4: dominion.o rngs.o Assert.o cardtest4.c
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o Assert.o $(CFLAGS)

randomtestcard1: dominion.o rngs.o Assert.o randomtestcard1.c
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o Assert.o $(CFLAGS)
	
randomtestcard2: dominion.o rngs.o Assert.o randomtestcard2.c
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o Assert.o $(CFLAGS)
	
playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
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

unittestresults: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 &> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestcard1results: randomtestcard1
	./randomtestcard1 &> randomtestcard1results.out
	gcov dominion.c >> randomtestcard1results.out
	cat dominion.c.gcov >> randomtestcard1results.out
	
randomtestcard2results: randomtestcard2
	./randomtestcard2 &> randomtestcard2results.out
	gcov dominion.c >> randomtestcard2results.out
	cat dominion.c.gcov >> randomtestcard2results.out
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
