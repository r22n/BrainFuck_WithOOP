#ifndef INCREMENT_H
#define INCREMENT_H
#include"ICommand.h"

//!cursor memory increment command
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class Increment :
        public ICommand<T> {
public:
    virtual~Increment(){}

    //!increment the cursor memory
    /*!
     * \brief Execute
     * \param _context the target context
     */
    virtual void Execute(IContext<T> *_context){
        if(!(_context!=NULL))throw "Increment Execute:context null";
        _context->SetMemory(
                    _context->GetCursorPointer(),
                    _context->AtMemory(_context->GetCursorPointer())+1
                    );
    }
};

#endif // INCREMENT_H
