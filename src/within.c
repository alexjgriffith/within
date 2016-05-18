#include "within.h"

int bound(int value, int lower, int upper){
  if(lower < upper){
    if(value > lower && value < upper)
      return 1;
  }
  else
    if(value < lower && value > upper)
      return 1;
  return 0;
}

void within(int * list , int * lower, int * upper, int * ret ,int *length,int *range){
  int i,j;
  int cap;
  for(i=0;i<(*length);i++){

    ret[i]=0;    
    for(j=0;j<(*range);j++){
      cap=bound(list[i],lower[j],upper[j]);

      if(cap>ret[i]){
	ret[i]=cap;
	break;
      }
    }
  }
}

#ifdef _RR
void R_init_myLib(DllInfo *info)
{
  R_registerRoutines(info,cMethods,NULL,NULL,NULL);
}
#endif

#ifndef _RR
#define BUF_SIZE 1024
int main(void){
  char buf[BUF_SIZE];
  char *ts;
  char * tts;
  int  s[4][1000];
  int len[4];
  int i,j=0,k;
  while(fgets(buf, sizeof(buf),stdin)){

    if(buf[strlen(buf)-1]!='\n')
      abort();
    ts=strtok(buf,"\t");
    i=0;
    while(ts){
      if(strlen(ts)==0){
	len[j]=i;
	break;
      }
      if(ts[strlen(ts)-1]=='\n'){
	ts[strlen(ts)-1]='\0';
	if(strlen(ts)==0){
	  len[j]=i;
	  break;
	}
	s[j][i]=atoi(ts);
	i++;
	len[j]=i;
	break;
      }
      else{
	s[j][i]=atoi(ts);
	i++;
      }
      ts=strtok(NULL,"\t");
    }
    if(j>2)
      break;
    j++;    
  }
  int *ret = malloc(len[0]*sizeof(int));
  within(s[0],s[1],s[2],&ret,&len[0],&len[1]);
  printf("len[0]=%d\n",len[0]);
  for(k=0;k<len[0];k++)
    printf("%d\t",ret[k]);
  printf("\n");        
  return 0;  
}
#endif
