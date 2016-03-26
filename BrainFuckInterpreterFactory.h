#ifndef BRAINFUCKINTERPRETER_H
#define BRAINFUCKINTERPRETER_H
#include"ICommand.h"
#include"ICommandFactory.h"
#include"CursorDecrementCommandFactory.h"
#include"CursorIncrementCommandFactory.h"
#include"IncrementCommandFactory.h"
#include"DecrementCommandFactory.h"
#include"LoopBlockBeginCommandFactory.h"
#include"LoopBlockEndCommandFactory.h"
#include"PrintCharCommandFactory.h"
#include"ScanCharCommandFactory.h"
#include<map>

//!interpreter-program factory of brainfuck
/*!
 * this factory makes the interpreter program from the source codes.
 * and you can add command to brainfuck language.
 * \author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class BrainFuckInterpreterFactory {
private:
    std::vector<ICommandFactory<T>*> disposes;
    std::map<char,ICommandFactory<T>*> commandFactories;
    std::vector<LoopBlockBegin<T>*> loopBlockStack;
public:
    //!create standard instruction command factory set
    /*!
     * \brief BrainFuckInterpreterFactory
     */
    BrainFuckInterpreterFactory() {
        AddCommandFactory('+',new IncrementCommandFactory<T>());
        AddCommandFactory('-',new DecrementCommandFactory<T>());
        AddCommandFactory('<',new CursorDecrementCommandFactory<T>());
        AddCommandFactory('>',new CursorIncrementCommandFactory<T>());
        AddCommandFactory('[',new LoopBlockBeginCommandFactory<T>(&loopBlockStack));
        AddCommandFactory(']',new LoopBlockEndCommandFactory<T>(&loopBlockStack));
        AddCommandFactory('.',new PrintCharCommandFactory<T>());
        AddCommandFactory(',',new ScanCharCommandFactory<T>());
    }

    //!delete command factory
    /*!
     * \brief ~BrainFuckInterpreterFactory
     */
    virtual~BrainFuckInterpreterFactory(){
        for(int i = 0 ; i < disposes.size();i++){
            ICommandFactory<T>* f = disposes.at(i);
            delete f;
        }
        disposes.clear();
        commandFactories.clear();
    }

    //!compile to the interpreter from source codes
    /*!
     * \brief MakeInterpreter
     * \param _sourceCodes the source codes of brainfuck language
     * \param _dst the container will be stored interpreter commands
     * \exception const-char* invalid operation or loop block end
     */
    virtual void MakeInterpreter(std::string& _sourceCodes,std::vector<ICommand<T>*>& _dst) {
        loopBlockStack.clear();
        for(int i = 0 ; i  < _sourceCodes.size();i++) {
            char sourceCode = _sourceCodes[i];
            ICommandFactory<T>* commandFactory = GetCommandFactory(sourceCode);
            if(!(commandFactory!=NULL))throw "BrainFuckInterpreterFactory MakeInterpreter: invalid operation";
            ICommand<T>* command = commandFactory->MakeCommand(i);
            if(!(command!=NULL))throw "BrainFuckInterpreterFactory MakeInterpreter: failed to create command";
            _dst.push_back(command);
        }
        if(!(loopBlockStack.size()==0))throw "BrainFuckInterpreterFactory MakeInterpreter: no loop block closing";
    }

    //!add command factory, creates the interpreter command
    /*!
     * \brief AddCommandFactory
     * \param _sourceCode the source code of brainfuck
     * \param _factory the factory of command
     * \warning _factory must be created by new operator
     */
    void AddCommandFactory(char _sourceCode,ICommandFactory<T>* _factory) {
        if(!(_factory!=NULL))throw "BrainFuckInterpreterFactory AddCommandFactory: factory null";
        if(!(commandFactories.find(_sourceCode)==commandFactories.end())) throw "BrainFuckInterpreterFactory AddCommandFactory: Already there is commandFactory";
        disposes.push_back(_factory);
        commandFactories[_sourceCode] = _factory;
    }

    //!get the command factory, from the related source code
    /*!
     * \brief GetCommandFactory
     * \param _sourceCode the source code
     * \return if the factory related with source code is exist, return the factory. else NULL
     */
    ICommandFactory<T>* GetCommandFactory(char _sourceCode) {
        return commandFactories[_sourceCode];
    }

    //!dispose the interpreter commands objects
    /*!
     * \brief DisposeInterpreter
     * \param _interpreter the interpreter commands program
     */
    static void DisposeInterpreter(std::vector<ICommand<T>*>& _interpreter) {
        for(int i = 0 ; i < _interpreter.size();i++) {
            ICommand<T>* c = _interpreter.at(i);
            delete c;
        }
        _interpreter.clear();
    }
};


#endif // BRAINFUCKINTERPRETER_H
