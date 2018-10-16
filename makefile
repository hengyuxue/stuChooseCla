run:./RELEASE/run.o ./RELEASE/libstucou.a 
	gcc -o ./RELEASE/run ./RELEASE/run.o -L ./RELEASE/ -lstucou
./RELEASE/run.o:run.c 
	gcc -c run.c -o ./RELEASE/run.o -I ./INCLUDE
clean:
	rm -f ./RELEASE/*

