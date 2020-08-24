#include "dos.h"

int ptc(int num, int expo){
	int res = 1;
	for(int i = 0; i < expo; i++){
		res = res * num;
	}
	return res;
}

int stoi(char *string){
	int atualnum = 0, finalnum = 0, expo = 0;
	int ssize = strlen(string);
	int ptc_res = 0;
	char nums[10] = "0123456789";
	for(int j = 0; j < ssize; j++){
		for(int i = 0; i < 10; i++){
			if((string[j] == nums[i]) && (j != ssize)){
				expo = ssize - j - 1;
				ptc_res = ptc(10, expo);
				atualnum = i * ptc_res;
			}
		}
		finalnum = finalnum + atualnum;
	}
	return finalnum;
}
