#ifndef SCANCHAR_H
#define SCANCHAR_H
#include"ICommand.h"
#include<stdio.h>

//!the command scanning 1 character from standard in
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class ScanChar :
        public ICommand<T> {
public:
    virtual~ScanChar(){}

    //!scan 1 character from standard in, store to the cursor memory
    /*!
     * \brief Execute
     * \param _context the target context
     */
    virtual void Execute(IContext<T> *_context) {
        if(!(_context!=NULL))throw "ScanChar Execute: context null";
        char c = (char)getchar();
        _context->SetMemory(_context->GetCursorPointer(),c);
    }
};

#endif // SCANCHAR_H
