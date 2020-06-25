# John L. Carveth
# CST8234 - Assignment 1
# 2020-06-10

objects = main.o format.o io.o helper.o registration.o


main : $(objects)
	cc -o main $(objects)

clean :
	rm main $(objects)