#ifndef LOOPBLOCKENDCOMMANDFACTORY_H
#define LOOPBLOCKENDCOMMANDFACTORY_H
#include"ICommandFactory.h"
#include"LoopBlockEnd.h"

//!factory of end loop block command
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class LoopBlockEndCommandFactory :
        public ICommandFactory<T> {
private:
    std::vector<LoopBlockBegin<T>*>* blockStack;
public:
    //!create factory with begin loop block stack
    /*!
     * \brief LoopBlockEndCommandFactory
     * \param _blockStack the reference to begin loop block stack
     */
    LoopBlockEndCommandFactory(std::vector<LoopBlockBegin<T>*>* _blockStack) {
        if(!(_blockStack!=NULL))throw "LoopBlockEndCommandFactory: blockStack null";
        blockStack = _blockStack;

    }

    virtual~LoopBlockEndCommandFactory(){}

    //!create end loop block command object
    /*!
     * \brief MakeCommand
     * \param _programPosition the program position of the end loop block command
     * \return end loop block command
     */
    virtual ICommand<T>* MakeCommand(int _programPosition) {
        if(!(_programPosition>=0))throw "LoopBlockEndCommandFactory MakeCommand: invalid programPosition";
        if(!(blockStack->size()>0))throw "LoopBlockEndCommandFactory MakeCommand: no begin loop block pair";
        LoopBlockBegin<T>* begin = blockStack->at(blockStack->size()-1);
        blockStack->erase(blockStack->begin()+blockStack->size()-1);

        LoopBlockEnd<T>* end = new LoopBlockEnd<T>(begin);
        return end;
    }

};
#endif // LOOPBLOCKENDCOMMANDFACTORY_H
