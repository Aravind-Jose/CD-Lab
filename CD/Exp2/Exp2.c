#include <stdio.h>
#include <string.h>
struct gr{
	char le;
	char ri[10][10];
	int len;
}gra[10],new[10];
struct fir{
	char le;
	int len;
	char fi[10];
}firs[10];
int firind=0;
int l=0;
void first(char cha,int inde){
	int i=0,j;
	for(i=0;i<l;i++){
		/*for(j=0;j<firlen;j++){
			if(new[i].le==firs[j].le){
				continue;
			}
		}*/
		if(new[i].le==cha){
			for(j=0;j<new[i].len;j++){
			if(new[i].ri[j][0]>='a' || new[i].ri[j][0]=='$'){
				firs[inde].fi[firs[inde].len]=new[i].ri[j][0];
				firs[inde].len+=1;
			}
			else{
				first(new[i].ri[j][0],inde);
			}
			}
		}
	}
}

void main(){
	int i,rii=0,ri=0,j;
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
	for(i=0;i<10;i++){
		firs[i].len=0;
	}
	for(i=0;i<l;i++){
		first(new[i].le,i);
	}
	for(i=0;i<l;i++){
		printf("fi(%c)=%s\n",new[i].le,firs[i].fi);
		
	}
	
}

/*
2
A->a|B
B->b
*/
