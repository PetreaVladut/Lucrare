#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;

char* generare(int p){
    char *s;
    s=(char*)calloc(25,sizeof(char));
    strcpy(s,"fisier1\0");
    for(int i=0;i<p;i++)
        strcat(s,"0\0");
        strcat(s,".txt\0");
        ofstream ceva(s);
    for(long int i=0;i<pow(10,p);i++)
        ceva<<rand()%1000<<'\n';
        return s;
}
