all:mysql_demon.o mysql_master.o
	g++ -g mysql_demon.o mysql_master.o -o all -lmysqlclient

mysql_demon.o:mysql_demon.cpp
	g++ -c mysql_demon.cpp -o mysql_demon.o

mysql_master.o:mysql_master.cpp mysql_master.h
	g++ -c mysql_master.cpp -o mysql_master.o

clean:
	rm -f *o