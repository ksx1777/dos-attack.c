# dos-attack.c
um projeto meu de ataque DoS criado para o sistema operacioanl Linux. No projeto eu usei "forks" para criar outros processos, para enviar várias requisições simultaneas, mas você pode usar alterar para poder usar "threads" também.

# para compilar, execute o comando abaixo:
gcc dos.c stoi.c args.c dos.h -o ataquedos
