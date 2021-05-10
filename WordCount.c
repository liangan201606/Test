#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define in 1
#define out 0
int main(int argc,char *argv[]){
	FILE *fp;
	int length;
	fp=fopen("test.txt","r");
	if(fp==NULL)
	{
		printf("can not open file");
		exit(0);
	}
	fseek(fp,00,SEEK_END);
	length=ftell(fp);
	rewind(fp);
	char str[100000],c;
	fread(str,sizeof(char),length,fp);
	int i,danci=0,space=0,chars=0,line=0,word=out;
	for(i=0;(c=str[i])!='\0';i++)
	{
		if(c==' '){
			space++;
			word=out;
		}else{
			if(word==out){
				word=in;
				danci++;
			}
		}
		if((c=str[i])=='\n'){
			line++;
		}
	}
	chars=length-space-line*2;
	line++;
	fclose(fp);
	if(strcmp(argv[1],"-c")==0)
		printf("字符数为%d",chars);
	else if(strcmp(argv[1],"-w")==0)
		printf("单词数为%d",danci);
		else
			printf("参数输入有误"); 
}

