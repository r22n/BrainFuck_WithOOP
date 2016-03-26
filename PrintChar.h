#ifndef PRINTCHAR_H
#define PRINTCHAR_H
#include"ICommand.h"
#include<stdio.h>

//!the command printing the cursor memory as the character to standard out
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class PrintChar :
        public ICommand<T> {
public:
    virtual~PrintChar(){}

    //!print the cursor memory value as the 1-byte character to standard out
    /*!
     * \brief Execute
     * \param _context the target context
     */
    virtual void Execute(IContext<T> *_context){
        if(!(_context!=NULL))throw "PrintChar Execute: context null";
        printf("%c",(char)(_context->AtMemory(_context->GetCursorPointer())));
    }
};

#endif // PRINTCHAR_H
