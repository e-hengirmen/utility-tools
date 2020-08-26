#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
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
    cout<<endl<<endl;
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
    long int size=ftell(fp),num;
    rewind(fp);
    
    int choice,fin=0;
    unsigned char uc,*uc_p;
    uc_p=&uc;
    system("clear");
    while(1){
        cout<<"choose one"<<endl
            <<"1-read next byte"<<endl
            <<"2-read last byte"<<endl
            <<"3-Go from HERE to N'th byte and read"<<endl
            <<"4-Go from START to N'th byte and read"<<endl
            <<"5-Go from END to N'th byte and read"<<endl;
        cin>>choice;
        switch(choice){
            case 2:system("clear");
            fseek(fp,-2,SEEK_CUR);
            num=ftell(fp);
            if(!num)cout<<"IT'S THE BEGINNING OF THE FILE"<<endl;
            fread(uc_p,1,1,fp);write_binary(uc);break;
            case 3:
            case 4:
            case 5:cin>>num;if(num>size)num=size;
            switch(choice){
                case 3:fseek(fp,num,SEEK_CUR);break;
                case 4:fseek(fp,num,SEEK_SET);break;
                case 5:fseek(fp,-1-num,SEEK_END);break;
            }
            case 1:system("clear");
            num=ftell(fp);
            if(!num)cout<<"IT'S THE BEGINNING OF THE FILE"<<endl;
            else if(size==num)cout<<"IT'S THE END OF THE FILE"<<endl;
            fread(uc_p,1,1,fp);write_binary(uc);break;
            default:fin=1;break;
        }
        if(fin)break;
    }

}
