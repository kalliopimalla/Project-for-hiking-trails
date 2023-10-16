#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h> 
#include <math.h>

#define N 500 

struct route
{
 char start[50];
 int length;
 int uphill;
 int downhill;
 int max_altitude;
 int min_altitude;
 char end[50];
};


int readFromInput(struct route A[N])
{
 int n,i;
 
 scanf("%d ",&n);
  for(i=0;i<n;i++)//Για Ν μονοπάτια
    { fgets(A[i].start,50,stdin);
      A[i].start[strcspn(A[i].start,"\n")]='\0';
      scanf("%d ",&A[i].length);
      scanf("%d ",&A[i].uphill);
      scanf("%d ",&A[i].downhill);
      scanf("%d ",&A[i].max_altitude);
      scanf("%d ",&A[i].min_altitude);
      fgets(A[i].end,50,stdin);
      A[i].end[strcspn(A[i].end,"\n")]='\0';
    }

 return n;
}

void BubbleSort(struct route A[N],int n)
{
 int i,j;
 struct route temp;
 char s[50];
 char s1[50];

 for(i=0;i<n-1;i++)
 {
   for(j=i+1;j<n;j++)
   { 
     struct route n1=A[i];
     struct route n2=A[j];

     if(n1.length<n2.length)
     {temp=A[i];
     A[i]=A[j];
     A[j]=temp;}
   }
 }
 }

void printData(struct route A[N],int n)
{
 int i;
 int estimated_time;
 BubbleSort(A,n);


for(i=0;i<n;i++)
{  
  if(strcmp(A[i].start,A[i].end)==0)
  {
  printf("From %s to %s\n",A[i].start,A[i].end);
  printf("Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");
  }
  else
  {
  printf("From %s to %s\n",A[i].start,A[i].end);
  printf("Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
  estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
  printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);

  printf("\n");

  printf("From %s to %s\n",A[i].end,A[i].start);
  printf("Uphill %d, Downhill %d\n",A[i].downhill,A[i].uphill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
  estimated_time=round((A[i].length/65.0)+(A[i].downhill/10.0));
  printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
  printf("\n");
  }
}

}
int readFromFile(struct route A[N])
{ FILE *fp;
  int n=0,i;
  char error=0;
 char s[50];
 

  fgets(s,50,stdin);
  s[strcspn(s,"\n")]='\0';

  fp=fopen(s,"r");
  if(fp!=NULL)
    { 
      
      fscanf(fp,"%d ",&n);
      for(i=0;i<n && !error;i++)
        {

    char *a;
    a=malloc(200*sizeof(char));
    fgets(a,200,fp);
    a[strcspn(a,"\n")]='\0';
    a=realloc(a,(strlen(a)+1)*sizeof(char));
    strcpy(A[i].start,a);
    free(a); 

      fscanf(fp,"%d ",&A[i].length);
      fscanf(fp,"%d ",&A[i].uphill);
      fscanf(fp,"%d ",&A[i].downhill);
      fscanf(fp,"%d ",&A[i].max_altitude);
      fscanf(fp,"%d ",&A[i].min_altitude);

    char *e;
    e=malloc(200*sizeof(char));
    fgets(e,200,fp);
    e[strcspn(e,"\n")]='\0';
    e=realloc(e,(strlen(e)+1)*sizeof(char));
    strcpy(A[i].end,e);
    free(e);
      
        }
      fclose(fp);
      return n;   
    }
    else 
    {
      printf("Error");
      return 0;
    } 
} 



void saveData(struct route A[N],int n)
{
 
 int i;
 int estimated_time;
 BubbleSort(A,n);

 char s[20];
 fgets(s,20,stdin);
 s[strcspn(s,"\n")]='\0';
 
 FILE* fp;

  fp=fopen(s,"w");
  
  if(fp!=NULL)
    {
      for(i=0;i<n;i++)
        {
      if(strcmp(A[i].start,A[i].end)==0)
  {
  fprintf(fp,"From %s to %s\n",A[i].start,A[i].end);
  fprintf(fp,"Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  fprintf(fp,"Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
 fprintf(fp,"Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 fprintf(fp,"\n");
  }
  else
  {
  fprintf(fp,"From %s to %s\n",A[i].start,A[i].end);
  fprintf(fp,"Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  fprintf(fp,"Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
  estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
  fprintf(fp,"Length %d, Estimated time %d min\n",A[i].length,estimated_time);

  fprintf(fp,"\n");

  fprintf(fp,"From %s to %s\n",A[i].end,A[i].start);
  fprintf(fp,"Uphill %d, Downhill %d\n",A[i].downhill,A[i].uphill);
  fprintf(fp,"Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
  estimated_time=round((A[i].length/65.0)+(A[i].downhill/10.0));
  fprintf(fp,"Length %d, Estimated time %d min\n",A[i].length,estimated_time);
  fprintf(fp,"\n");
  }
        }
    fclose(fp);    
    }
    
    
}

void findShort(struct route A[N],int n)
{ int i;
  int L;
  int estimated_time;

  scanf("%d",&L);
 
BubbleSort(A,n);

  for(i=0;i<n;i++)
  {if(A[i].length<=L)
  {
   if(strcmp(A[i].start,A[i].end)==0)
  {
   printf("From %s to %s\n",A[i].start,A[i].end);
  printf("Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");
  }
  else
  {
   printf("From %s to %s\n",A[i].start,A[i].end);
  printf("Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);

 printf("\n");

  printf("From %s to %s\n",A[i].end,A[i].start);
  printf("Uphill %d, Downhill %d\n",A[i].downhill,A[i].uphill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].downhill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");

}
  }}
}


void findLocation(struct route A[N],int n)
{
  int i;
  char location[50];
  int estimated_time;

  BubbleSort(A,n);

  fgets(location,50,stdin);
  location[strcspn(location,"\n")]='\0';

for(i=0;i<n;i++)
{
  if(strcmp(location,A[i].start)==0)
  {
   printf("From %s to %s\n",A[i].start,A[i].end);
  printf("Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");
  }
  else if(strcmp(location,A[i].end)==0)
  {
  printf("From %s to %s\n",A[i].end,A[i].start);
  printf("Uphill %d, Downhill %d\n",A[i].downhill,A[i].uphill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].downhill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");
  }
 
}
}


void findUpHill (struct route A[N],int n)
{

  int i;
  int estimated_time;

BubbleSort(A,n);

for(i=0;i<n;i++)
{
  if(A[i].uphill>A[i].downhill)
  {
  printf("From %s to %s\n",A[i].start,A[i].end);
  printf("Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");
  }
  else if(A[i].uphill<A[i].downhill)
  {
  printf("From %s to %s\n",A[i].end,A[i].start);
  printf("Uphill %d, Downhill %d\n",A[i].downhill,A[i].uphill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].downhill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");
  }
}

}



void findDownHill (struct route A[N],int n)
{
  int i;
  int estimated_time;

BubbleSort(A,n);

for(i=0;i<n;i++)
{
  if(A[i].uphill<A[i].downhill)
  {
  printf("From %s to %s\n",A[i].start,A[i].end);
  printf("Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");
  }
  else if(A[i].uphill>A[i].downhill)
  {
  printf("From %s to %s\n",A[i].end,A[i].start);
  printf("Uphill %d, Downhill %d\n",A[i].downhill,A[i].uphill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].downhill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");
  }
}
}



void findAltitude (struct route A[N],int n)
{ int min,max1;
  int i;
  int estimated_time;

 scanf("%d",&min);
 scanf("%d",&max1);

 BubbleSort(A,n);

for(i=0;i<n;i++)
{
  if((A[i].min_altitude>=min&&A[i].min_altitude<=max1)&&(A[i].max_altitude>=min&&A[i].max_altitude<=max1))
  {
if(strcmp(A[i].start,A[i].end)==0)
  {
  printf("From %s to %s\n",A[i].start,A[i].end);
  printf("Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");
  }
  else
  {
   printf("From %s to %s\n",A[i].start,A[i].end);
  printf("Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");

   printf("From %s to %s\n",A[i].end,A[i].start);
  printf("Uphill %d, Downhill %d\n",A[i].downhill,A[i].uphill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].downhill/10.0));
 printf("Length %d, Estimated time %d min\n",A[i].length,estimated_time);
 printf("\n");
  }
  }
}
}


void findTimely(struct route A[N],int n)
{
  int T;
  int i;
  float estimated_time;

 BubbleSort(A,n);

 scanf("%d",&T);

for(i=0;i<n;i++)
{ 

estimated_time=(A[i].length/65.0)+(A[i].uphill/10.0);

if(strcmp(A[i].start,A[i].end)==0) 
{
  if(estimated_time<=T)
    {printf("From %s to %s\n",A[i].start,A[i].end);
    printf("Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
    printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
    estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
    printf("Length %d, Estimated time %.f min\n",A[i].length,estimated_time);
    printf("\n");} 
}
else
{
if(estimated_time<=T)
{
  printf("From %s to %s\n",A[i].start,A[i].end);
  printf("Uphill %d, Downhill %d\n",A[i].uphill,A[i].downhill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].uphill/10.0));
 printf("Length %d, Estimated time %.f min\n",A[i].length,estimated_time);
 printf("\n");}

estimated_time=(A[i].length/65.0)+(A[i].downhill/10.0);

 if(estimated_time<=T)
{ printf("From %s to %s\n",A[i].end,A[i].start);
  printf("Uphill %d, Downhill %d\n",A[i].downhill,A[i].uphill);
  printf("Max altitude %d, Min altitude %d\n",A[i].max_altitude,A[i].min_altitude);
 estimated_time=round((A[i].length/65.0)+(A[i].downhill/10.0));
 printf("Length %d, Estimated time %.f min\n",A[i].length,estimated_time);
 printf("\n");}
}
}
}

