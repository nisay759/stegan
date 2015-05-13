CC= gcc
CFLAGS= -Wall
TEST_TXT= test_txt
TEST_STG= test_stg
STEGAN= stegan


all: $(STEGAN)
test: $(TEST_TXT) $(TEST_STG)

$(STEGAN): main.c stegin.o stegout.o image.o txt.o tab2Ddynamique.o enfouir.o extraire.o callbacks.o
	$(CC) $(CFLAGS) main.c -o $(STEGAN) `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -rdynamic stegin.o image.o txt.o tab2Ddynamique.o enfouir.o stegout.o extraire.o callbacks.o; mv $(STEGAN) ../binary

$(TEST_TXT): test_txt.c txt.o
	$(CC) $(CFLAGS) -o $(TEST_TXT) test_txt.c txt.o; mv $(TEST_TXT) ../test

$(TEST_STG): test_stg.c txt.o image.o extraire.o tab2Ddynamique.o
	$(CC) $(CFLAGS) test_stg.c -o $(TEST_STG) image.o extraire.o txt.o tab2Ddynamique.o; mv $(TEST_STG) ../test

stegin.o: stegin.c
	$(CC) $(CFLAGS) -c stegin.c

stegout.o: stegout.c
	$(CC) $(CFLAGS) -c stegout.c

image.o: image.c
	$(CC) $(CFLAGS) -c image.c

txt.o: txt.c
	$(CC) $(CFLAGS) -c txt.c

enfouir.o: enfouir.c
	$(CC) $(CFLAGS) -c enfouir.c

extraire.o: extraire.c
	$(CC) $(CFLAGS) -c extraire.c

tab2Ddynamique.o: tab2Ddynamique.c
	$(CC) $(CFLAGS) -c tab2Ddynamique.c 

callbacks.o: callbacks.c
	$(CC) $(CFLAGS) -c callbacks.c `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -rdynamic
	
clean:
	rm ../object/*
