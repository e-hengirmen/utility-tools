#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

unsigned const char control=0b10000000;

void write_binary(unsigned char c){
    for(int i=0;i<8;i++){
        if(control&c){
            cout<<1;
        }
        else cout<<0;
        c<<=1;
    }
}

int main(int argc,char *argv[]){
    if(argc==1){
        cout<<"Missing file name"<<endl<<"try './read_binary {{file_name}}'"<<endl;
        return 0;
    }
    FILE* fp=fopen(argv[1],"rb");
    if(fp==NULL){
        cout<<"File does not exist"<<endl;
        return 0; 
    }
    fseek(fp,0,SEEK_END);
    long int size=ftell(fp);
    rewind(fp);
    for(long int i=0;i<size;i++){
        unsigned char a;
        fread(&a,1,1,fp);
        write_binary(a);
        if(i%8==7){
            cout<<endl;
        }
        else cout<<" ";
    }

}
