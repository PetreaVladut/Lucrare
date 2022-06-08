#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

char* generare(int p, int c){
    char *s;
    s=(char*)calloc(25,sizeof(char));
    strcpy(s,"fisier1\0");
    for(int i=0;i<p;i++)
        strcat(s,"0\0");
        strcat(s,".txt\0");
        ofstream ceva(s);
                    vector<int> a;
            for(long int i=0;i<pow(10,p);i++)
                a.push_back(rand()%1000);
        if(c==2)
            sort(a.begin(),a.end());
        if(c==3)
            sort(a.begin(),a.end(),greater<int>());
        for(long int i=0;i<pow(10,p);i++)
        ceva<<a[i]<<'\n';
        return s;
}
