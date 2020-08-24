#include "dos.h"

char *host = NULL;
char *port = "80";
int s_count = 50;
int t_count = 20;
int s_time = 300000;

ARG_LIST options[] =
		{
			{"-dns", "endereço ip ou domínio do alvo.", H},
			{"-p", "porta para a conexão. padrão: 80", P},
			{"-sc", "quantidade de sockets. padrão: 50", SC},
			{"-tc", "quantidade de threads para conexão simultânea. padrão: 20", TC},
			{"-sleep", "intervelo entre os ataques em milissegundos. padrão: 3000", S},	
		};

int show_banner(char **argv){

printf(GREEN

" DDDDDDDDDDDDD                            SSSSSSSSSSSSSSS\n"
" D::::::::::::DDD                       SS:::::::::::::::S\n"
" D:::::::::::::::DD                    S:::::SSSSSS::::::S\n"
" DDD:::::DDDDD:::::D                   S:::::S     SSSSSSS\n"
"   D:::::D    D:::::D    ooooooooooo   S:::::S                        cccccccccccccccc\n"
"   D:::::D     D:::::D oo:::::::::::oo S:::::S                      cc:::::::::::::::c\n"
"   D:::::D     D:::::Do:::::::::::::::o S::::SSSS                  c:::::::::::::::::c\n"
"   D:::::D     D:::::Do:::::ooooo:::::o  SS::::::SSSSS            c:::::::cccccc:::::c\n"
"   D:::::D     D:::::Do::::o     o::::o    SSS::::::::SS          c::::::c     ccccccc\n"
"   D:::::D     D:::::Do::::o     o::::o       SSSSSS::::S         c:::::c\n"
"   D:::::D     D:::::Do::::o     o::::o            S:::::S        c:::::c\n"
"   D:::::D    D:::::D o::::o     o::::o            S:::::S        c::::::c     ccccccc\n"
" DDD:::::DDDDD:::::D  o:::::ooooo:::::oSSSSSSS     S:::::S        c:::::::cccccc:::::c\n"
" D:::::::::::::::DD   o:::::::::::::::oS::::::SSSSSS:::::S ......  c:::::::::::::::::c\n"
" D::::::::::::DDD      oo:::::::::::oo S:::::::::::::::SS  ::::::   cc:::::::::::::::c\n"
" DDDDDDDDDDDDD           ooooooooooo    SSSSSSSSSSSSSSS    ::::::     cccccccccccccccc\n\n"
" - criado por ksx1777 21/06/2020\n"
" [*] como usar: %s -h www.exemplo.com\n"

RESET, argv[0]);

	return 0;
}

int show_args(void){
	printf(" [*] lista dos comandos disponíveis abaixo.\n\n");
	for(int i = 0; i < 5; i++){
		printf(" \"%s\" - %s\n", options[i].argname, options[i].arghelp);
	}
	return 0;
}

int parse_args(int argc, char **argv){
	int arg = 0;
	/* pequeno looping para procurar os comandos digitados */
	for(int j = 0; j < argc; j++){
		arg = j + 1;
		for(int i = 0; i < 5; i++){
			if((strcmp(argv[j], options[i].argname) == 0) && (arg != argc)){
				if(argv[arg][0] == '-'){
					printf(RED" [!] erro: o argumento \"%s\" não pode receber um valor nulo.\n"RESET, argv[j]);
					return 1;
				}
				printf("comando %s encontrado\n", options[i].argname);
				switch(options[i].id){
					case H:
						host = argv[arg];
						break;
					case P:
						port = argv[arg];
						break;
					case SC:
						s_count = stoi(argv[arg]);
						break;
					case TC:
						t_count = stoi(argv[arg]);
						break;
					case S:
						s_time = stoi(argv[arg]) * 1000;
						break;
					default:
						break;
				}
			}
		}
	}
	if(host == NULL){
		printf(RED" [!] erro: ataque não pode iniciar porque não tem alvo.\n\n"RESET);
		show_banner(argv);
		show_args();
		return 1;
	}
	//mostrar o alvo
	printf(GREEN" [*] alvo do ataque: %s:%s\n"RESET, host, port);
	printf(GREEN" [*] quantidade de conexões por thread: %i\n"RESET, s_count);
	printf(GREEN" [*] quantidade de threads: %i\n"RESET, t_count);
	printf(GREEN" [*] tempo de intervalo entre os ataques: %0.02fs\n"RESET, (float)s_time / 1000000);
	return 0;
}
