#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct gr{
	char le;
	char ri[10][10];
	int len;
}gra[10],new[10];
int l;
int nonter(char t){
	int i;
	for(i=0;i<l;i++){
		if(new[i].le==t){
			return 1;
		}
	}
	return 0;
}
void pars(char *inp,char  *par){
	int fl=0; 
	char te1[10],te2[10];
	if(inp[0]==par[0]){
		if(strlen(inp)==1 && strlen(par)==1){
			printf("Accept\n");
			exit(0);
		}
		printf("%s\t%s",inp+1,par+1);
		pars(inp+1,par+1);
	}
	else{
		for(i=0;i<l;i++){
			if(new[i].le==t){
				for(int j=0;j<new[i].len;j++){
					if(j==0){
					strcpy(te1,new[i].ri[0]);
					}
					else{
					strcpy(te2,new[i].ri[1]);
					}
				}
				if(strlen(te2)!=0){
					strcat(te1,par+1);
					pars(te1,inp);
					strcat(te2,par+1);
					pars(te2,inp);
				}
				fl=1;
			}
		}
		if(fl==0){
			printf("Not\n");
			exit(0);
		}	
	}
	
}
void main(){
	int i,j,ch,rii,ri;
	char temp[10];
	printf("Enter no. of lines\n");
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
	/*char inp[20];
	char par[20];
	printf("Enter the input string\n");
	scanf("%s\n",inp);
	printf("Parsing\n");
	strcpy(new[0].ri,par);
	int flag=0,iind=0,pind=0;
	while(flag==0){
		printf("%s\t%c->%s",par,new[i].le,new[i].ri);
		if(par[pind]==inp[iind]){
			pind++;
			iind++;
		}
		else{
			char te[10];
			ch=nonter(par[pind]);
			if(ch==0){
				printf("Cannot\n");
				exit(0);
			}
			for(i=0;i<l;i++){
			if(ne[i].le==par[pind]){
					strcpy(te,ne[i].rig[]); 
				}
			}
			
			//strcat();
		}
	}
	for(i=0;i<l;i++){
		printf("%s\t%c->%s",new[i].le,new[i].ri);
	}*/
	char a[10]={"hell"},b[10]={"hela"};
	pars(a,b);
	printf("Not");
}
/*
2
A->a|B
B->b

*/
