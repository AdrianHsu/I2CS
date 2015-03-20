/**
    Theme: Simple Machine for Computer Science - an overview Appendix C
    compiler: g++ 4.7.1 (C::B on win8)
    Date: 103/03/23
    Author: Yans.
*/
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

bool trace = false;

class SimpleALU{
public:
    unsigned char opcode;
    unsigned char rd,rs,rt;
    unsigned char imm; //immediate
    bool storeBackRd;
    unsigned char* memoryPort;
    unsigned char* pPC;
    unsigned char* pR0;

    bool calculate(){ // return whether halt or not (false:halt)
        storeBackRd = false;
        switch(opcode){
        case 0x1: //LOAD
            if(trace) printf("LOAD  :rd=mem[%02x](%02x)\n",imm,memoryPort[imm]);
            storeBackRd = true;
            rd = memoryPort[imm]; break;
        case 0x2: //LOAD(Direct)
            if(trace) printf("DIRECT:rd=%02x\n",imm);
            storeBackRd = true;
            rd = imm; break;
        case 0x3: //STORE
            if(trace) printf("STORE :mem[%02x]=rd(%02x)\n",imm,rd);
            memoryPort[imm] = rd; break;
        case 0x4: //MOVE, aware!!
            if(trace) printf("MOVE  :rd=rs(%02x)\n",rs);
            storeBackRd = true;
            rd = rs; break;
        case 0x5: //ADD
            if(trace) printf("ADD   :rd=rs(%02x)+rt(%02x)\n",rs,rt);
            storeBackRd = true;
            rd = rs + rt; break;
        case 0x6: //FADD, not support!!
            if(trace) printf("FADD  :not support!!\n");
            storeBackRd = true;
            rd = rs + rt; break;
        case 0x7: //OR
            if(trace) printf("OR    :rd=rs(%02x)|rt(%02x)\n",rs,rt);
            storeBackRd = true;
            rd = rs|rt; break;
        case 0x8: //AND
            if(trace) printf("AND   :rd=rs(%02x)&rt(%02x)\n",rs,rt);
            storeBackRd = true;
            rd = rs&rt; break;
        case 0x9: //XOR
            if(trace) printf("XOR   :rd=rs(%02x)^rt(%02x)\n",rs,rt);
            storeBackRd = true;
            rd = rs^rt; break;
        case 0xA: //ROTATE
            if(trace) printf("ROTATE:rd=rd(%02x)rotate(%02x)\n",rd,imm);
            storeBackRd = true;
            for(int i=0;i<imm;++i){
                if(rd&0x1){rd>>=1;rd|=0x80;}
                else rd>>=1;
            }
            break;
        case 0xB: //JUMP
            if(trace) printf("JUMP  :test jump to (%02x)?%c\n",imm,(*pR0==rd)?'y':'n');
            if(*pR0==rd) *pPC = imm; break;
        default:
        case 0xC: //HALT
            if(trace) printf("HALT\n");
            rd = memoryPort[imm];
            return false;
        }
        return true;
    }
};
class SimpleMachine{
private:
    unsigned char* memoryPort;
    unsigned char reg[16];
    unsigned char InstrReg[2];
    unsigned char PC; //program counter
    unsigned char rdID;
    SimpleALU alu;
    bool halt;

    void instrFetch(){
        if(trace) printf("PC{%02x}[IF]",PC);
        InstrReg[0] = memoryPort[PC++];
        InstrReg[1] = memoryPort[PC++];
        // MSB InstrReg[0] InstrReg[1] LSB
    }
    void decode(){
        alu.opcode = (InstrReg[0]&0xF0)>>4;
        alu.rd = reg[ InstrReg[0]&0xF];
        alu.rs = reg[(InstrReg[1]&0xF0)>>4];
        alu.rt = reg[ InstrReg[1]&0xF];
        alu.imm = InstrReg[1];
        rdID = InstrReg[0]&0xF;
        if(alu.opcode==0x4){
            rdID = InstrReg[1]&0xF;
        }
        if(trace) printf("[DE]");
    }
    void execution(){
        if(trace) printf("[EX] (%02x%02x): ",InstrReg[0],InstrReg[1]);
        halt = ! alu.calculate();
        if(alu.storeBackRd)
            reg[rdID] = alu.rd;
    }
public:
    SimpleMachine(unsigned char* mPort){
        memoryPort = mPort;
        alu.memoryPort=mPort;
        alu.pPC=&PC;
        alu.pR0=reg;
        halt = false;
    }
    void prepare(int startingPoint=0){
        PC = startingPoint;
        halt = false;
    }
    bool oneCycle(){
        if(halt) return false;
        instrFetch();
        decode();
        execution();
        return true;
    }
    void runTillHalt(int startingPoint=0,int timeout=0){
        prepare(startingPoint);
        if(timeout==0)  while( oneCycle() );
        else            for(int i=timeout;(i>0)&&oneCycle();--i)  if(i==1)printf("Stopped by timeout.\n");
    }
};

int main(int argc, char *argv[]){
    string inputFileName="memory.txt",outputFileName="memory.txt",str;
    int startingPoint = 0;
    int timeout = 0;// 0 means infinite
    for(int i=1;i<argc;++i){
        str = argv[i];
        if(str=="-o"){
            if((++i)>=argc) exit(1);
            outputFileName = argv[i];
        }else if(str=="-p"){
            if((++i)>=argc) exit(1);
            startingPoint = atoi(argv[i]);
        }else if(str=="-t"){
            if((++i)>=argc) exit(1);
            timeout = atoi(argv[i]);
        }else if(str=="-trace"){
            trace = true;
        }else{
            inputFileName = argv[i];
        }
    }

    unsigned char memory[256]; for(int i=0;i<256;++i) memory[i]=0;
    unsigned char memPtr = 0;
    unsigned short readBuf;
    char comment[128];
    FILE* pFile = fopen(inputFileName.c_str(),"r");
    if(pFile==NULL){printf("file reading error!!\n");exit(1);}
    while(  fscanf(pFile, "%hx%[^\n]\n", &readBuf,comment)>0  ){
        memory[memPtr++] = readBuf>>8;
        memory[memPtr++] = readBuf&0xFF;
        if(trace)printf("[Mem %03x]: %02x%02x\n", (memPtr-2),memory[memPtr-2],memory[memPtr-1] );
    }
    fclose (pFile);


    SimpleMachine m1(memory);
    m1.runTillHalt(startingPoint,timeout);

    pFile = fopen(outputFileName.c_str(),"w");
    if(pFile==NULL){printf("file writing error!!\n");exit(1);}
    for(int i=0;i<256;i+=2)
        fprintf(pFile, "%02x%02x\n", memory[i],memory[i+1] );
    fclose (pFile);

    return 0;
}
