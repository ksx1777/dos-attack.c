#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define GREEN "\033[1;33m"
#define RED "\033[1;31m"
#define RESET "\033[1;33m"

#define H 1
#define P 2
#define SC 3
#define TC 4
#define S 5

typedef struct{
	char *argname;
	char *arghelp;
	int id;
} ARG_LIST;

//ler e identificar os argumentos passados
int parse_args(int argc, char **argv);

//mostrar banner
int show_banner(char **argv);

//mostrar todos os argumentos e como usar cada um
int show_args(void);

//funçao para calcular potenciação
int ptc(int num, int expo);

//funçao para converter string para int
int stoi(char *string);

//criar sockets
int init_sockets(char *host, char *port);

//iniciar o ataque
void attack(char *host, char *port, int sock_num);

extern char *host;
extern char *port;
extern int s_count;
extern int t_count;
extern int s_time;
extern ARG_LIST options[];
