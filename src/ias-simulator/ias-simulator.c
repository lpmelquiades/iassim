#include "headers/base.h"
#include "headers/mem.h"
#include "headers/regs-flags.h"

int main(int argc, char *argv[]){
    int memSize = atoi(argv[2]);
    int ma = atoi (argv[3]);
    int mb = atoi (argv[4]);
    int x = atoi (argv[5]);
    //FILE * hex = fopen("../../hex/mxn.hex","r");
    FILE * hex = fopen(argv[1],"r");
    if(hex == 0){
        printf("err-msg: Hex File Not Found.");
    }else{
        loadMEM(hex, memSize);
        fclose(hex);
        while(isOFF(END_FLAG)){ 
            instCycle();
        }
        printfREGS();
        printfMEM(memSize,ma,mb);
    }
    return 0;
}

