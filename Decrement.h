#ifndef DECREMENT_H
#define DECREMENT_H
#include"ICommand.h"

//!cursor memory decrement command
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class Decrement :
        public ICommand<T> {
public:
    virtual~Decrement(){}

    //!decrement the cursor memory object
    /*!
     * \brief Execute
     * \param _context the target context
     */
    virtual void Execute(IContext<T> *_context) {
        if(!(_context!=NULL))throw "Decrement Execute: context null";
        _context->SetMemory(
                    _context->GetCursorPointer(),
                    _context->AtMemory(_context->GetCursorPointer())-1);
    }
};


#endif // DECREMENT_H
