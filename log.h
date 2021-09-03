#include <time.h>

typedef struct datastruct
{
	time_t time;
	char type;
	char * string;

} data_t;

int addmsg ( const char type, const char * msg );
void clearlog();
char * getlog();
int savelog ( char * filename );
