#include <iostream>
#include"Increment.h"
#include"CursorDecrement.h"
#include"CursorIncrement.h"
#include"Context.h"
#include"Decrement.h"
#include"LoopBlockBegin.h"
#include"LoopBlockEnd.h"
#include"PrintChar.h"
#include"BrainFuckInterpreterFactory.h"
using namespace std;

int main(int argc, char *argv[]){


    try{
        vector<ICommand<int>*> program;
        BrainFuckInterpreterFactory<int> compiler;

        string sources;
        cin >> sources;

        compiler.MakeInterpreter(sources,program);

        for(Context<int> context(100);
            context.GetProgramCounter() < program.size();
            context.SetProgramCounter(context.GetProgramCounter()+1)) {
            program.at(context.GetProgramCounter())->Execute(&context);
        }

        BrainFuckInterpreterFactory<int>::DisposeInterpreter(program);
    }catch(const char* msg) {
        printf(msg);
    }

    return 0;
}
