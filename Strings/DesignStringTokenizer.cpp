/// Our Own Tokenizer

#include<bits/stdc++.h>
using namespace std;

char *mystrfunction(char *str, char delim){
    static char *input=NULL;
    if(str!=NULL){
        input=str;
    }
    if(input==NULL){
        return NULL;
    }
    static char *token= new char[strlen(input)+1];
    int i=0;
    while(input[i]!='\0'){
        if(input[i]!=delim){
            token[i]=input[i];
        }
        else{
            token[i]='\0';
            input=input+i+1;
            return token;
        }
    i++;
    }
    token[i]='\0';
    input=NULL;
return token;
}

int main(){

    char s[1000];
    cin.getline(s,1000);

    char *token=mystrfunction(s,' ');
    while(token!=NULL){
        cout<<token<<endl;
        token=mystrfunction(NULL,' ');
    }


    return 0;
}
