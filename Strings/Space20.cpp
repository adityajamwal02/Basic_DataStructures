#include<bits/stdc++.h>
using namespace std;

void replace_String(string &input){
    int countSpace=0;
    for(int i=0;i<input.size();i++){
        if(input[i]==' '){
            countSpace+=1;
        }
    }
    int idx=input.size()+2*countSpace;
    input[idx]='\0';
    for(int i=input.size()-1;i>=0;i--){
        if(input[i]==' '){
            input[idx-1]='0';
            input[idx-2]='2';
            input[idx-3]='%';
            idx=idx-3;
        }else{
            input[idx-1]=input[i];
            idx--;
        }
    }
}
int main(){

    string input;
    getline(cin, input);
    replace_String(input);
    cout<<input<<endl;

    return 0;
}
