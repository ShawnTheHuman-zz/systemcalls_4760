
#include <chrono>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cerrno>
#include "log.h"


using namespace std;


typedef struct list_struct {
	data_t item;
	struct list_struct *next;

} log_t;

static log_t *headptr = NULL;
static log_t *tailptr = NULL;

int addmsg ( const char type, const char * msg ){
	
	data_t data;
	
	data.type = type;
	data.string = msg;
	
	auto time = chrono::system_clock::to_time_t(chrono::system_clock::now());

	data.time = ctime(&time);


	log_t *newlog = new log_t;

	

	if ( newlog == NULL ){
		perror("ERROR: unable to allocate memory");
		errno = ENOMEM;
		return -1;
	}else{

		newlog->item = data;
		newlog->next = NULL;
		
		if(headptr == NULL){

			headptr = newlog;
			tailptr = newlog;
		}

		return 0;
	}

	return 0;
} 

void clearlog(void){
	log_t *temp;

	while( headptr != NULL ){
		temp = headptr;
		headptr = headptr->next;
		delete temp;
	}

	headptr = NULL;

}

char * getlog(void){
	
	log_t *temp = headptr;
	char* message = new char[99];
	
	if( message == NULL ){
		perror("ERROR: unable to retrieve log\n");
		errno = ENOMEM;
		return NULL;
	}else{
		strcpy(message, "");
		while( temp != NULL){
			strcat(message, (temp->item).string);
			strcat(message, "\n");
			temp = temp->next;
		}
		return message;
	}
	
	return NULL;
}


int savelog ( const char * filename ){
	
	ofstream f;
	f.open(filename, ofstream::out | ofstream::app );

	if(!f){
		perror("ERROR: Unable to open file\n");
		errno = ENOENT;
		return -1;
	}else{
		f << getlog();
		f.close();
		return 0;

	}
	
	return 0;
}
