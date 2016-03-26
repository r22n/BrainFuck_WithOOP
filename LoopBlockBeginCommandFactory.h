#ifndef LOOPBLOCKBEGINCOMMANDFACTORY_H
#define LOOPBLOCKBEGINCOMMANDFACTORY_H
#include"ICommandFactory.h"
#include"LoopBlockBegin.h"


//!factory of begin loop block command
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class LoopBlockBeginCommandFactory :
        public ICommandFactory<T> {
private:
    std::vector<LoopBlockBegin<T>*>* blockStack;
public:
    //!create factory with the begin loop block stack
    /*!
     * \brief LoopBlockBeginCommandFactory
     * \param _blockStack the reference to begin loop block stack
     */
    LoopBlockBeginCommandFactory(std::vector<LoopBlockBegin<T>*>* _blockStack) {
        if(!(_blockStack!=NULL))throw "LoopBlockBeginCommandFactory: blockStack null";
        blockStack = _blockStack;
    }

    virtual~LoopBlockBeginCommandFactory(){}

    //!create begin loop block command, and push to stack specified at constructor
    /*!
     * \brief MakeCommand
     * \param _programPosition program position of the brainfuck begin loop block
     * \return the begin loop block command object
     */
    virtual ICommand<T>* MakeCommand(int _programPosition){
        if(!(_programPosition>=0))throw "LoopBlockBeginCommandFactory MakeCommand:invalid programPosition";
        LoopBlockBegin<T>* begin = new LoopBlockBegin<T>(_programPosition);
        blockStack->push_back(begin);
        return begin;
    }
};
#endif // LOOPBLOCKBEGINCOMMANDFACTORY_H
