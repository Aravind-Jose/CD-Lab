#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct gr{
	char le;
	char ri[10][10];
	int len;
}gra[10],new[10];
void main(){
	char gr[10][10],inp[10],temp[10];
	int i,j,l,rii,ri;
	printf("Enter the no.\n");
	scanf("%i",&l);
	for(i=0;i<l;i++){
		scanf("%s",temp);
		new[i].le=temp[0];
		new[i].len=0;
		rii=0;
		ri=0;
		for(j=3;j<strlen(temp);j++){
			if(temp[j]!='|'){
				new[i].ri[ri][rii]=temp[j];
			}
			
			rii++;
			if(temp[j]=='|' || j==(strlen(temp)-1)){
				ri++;
				rii=0;
				new[i].len+=1;
			}
		}
	}
	for(i=0;i<l;i++){
		for(int u=0;u<new[i].len;u++){
			printf("%c->%s|\n",new[i].le,new[i].ri[u]);
		}
		printf("\n");
	}
	printf("Enter the input\n");
	scanf("%s",inp);
	strcat(inp,"$");
	printf("Stack\tInput\tAction\n");
	char st[10]={"$"};
	int fla=0;
	//printf("%s\t%s\tSHIFT\n",st,inp);
	while(1){
		printf("%s\t%s\t",st,inp);
		for(i=0;i<li;i++){
			for(j=0;j<new[i].len;j++){
				for(int u=0;u<strlen(new[i].ri[j]) && (strlen(new[i].ri[j])+1==strlen(st));u++){
					if(new[i].ri[j][u]!=st[u+1]){
					fla=0;
					break;
					}
				}
				/*if((strlen(new[i].ri[j]==1) && new[i].ri[j][0]==st[strlen(st)-1]){
					fla=1;
				}*/
				if(fla==1){
				printf("Reduce\n");
				for()
				if(new[i].ri[j][0]==new[0].le){
					printf("Succ\n");
					exit(0);
				}
				break;
				}
			}
		}
		if(fla==0){
			printf("Shift\n"){
			
			}
		}
		
	}
}
