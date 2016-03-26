#ifndef LOOPBLOCKEND_H
#define LOOPBLOCKEND_H
#include"LoopBlockBegin.h"

//!brainfuck end loop block command
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class LoopBlockEnd :
        public ICommand<T> {
private:
    LoopBlockBegin<T>* pairBlock;
public:
    //!create end loop block end
    /*!
     * \brief LoopBlockEnd
     * \param _pairBlock the pair of loop block
     */
    LoopBlockEnd(LoopBlockBegin<T>* _pairBlock) {
        if(!(_pairBlock!=NULL))throw "LoopBlockEnd: pairBlock null";
        pairBlock = _pairBlock;
    }

    //!if the cursor memory value is not 0, jump to corresponding begin loop block
    /*!
     * \brief Execute
     * \param _context the target context
     */
    virtual void Execute(IContext<T> *_context) {
        if(!(_context!=NULL))throw "LoopBlockEnd Execute: context null";
        if(_context->AtMemory(_context->GetCursorPointer())!=0) {
            _context->SetProgramCounter(
                        pairBlock->GetPosition()
                        );
        }
    }

};

#endif // LOOPBLOCKEND_H
