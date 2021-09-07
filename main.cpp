#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <getopt.h>
#include <chrono>
#include <sstream>
#include <cstring>
#include <sys/time.h>

#include "log.h"

using namespace std;



int main ( int argc, char **argv ){
	
	extern char *optarg;
	int op;

	const char *fileName = "logfile.text";
	int secs = 1;

	while((op = getopt( argc, argv, "ht:")) != -1 ){
		switch(op){
			case 'h':
				cout << "help message\n";
				exit( 0 );
			break;
			
			case 't':
				cout << "seconds\n";
				secs = atoi(optarg);
				exit( 1 );
			break;

			case '?':
				cout << "Invalid option\n";
				exit( 1 );
			break;

			default:
				cout << "Invalid arguments\n";
				exit( 1 );
			break;

		}









	}

	return 0;
}
