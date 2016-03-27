#ifndef CURSORINCREMENT_H
#define CURSORINCREMENT_H
#include"ICommand.h"

//!cursor pointer increment command
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class CursorIncrement :
         public ICommand<T>{
public:
    virtual~CursorIncrement(){}
    //!increment cursor pointer
    /*!
     * \brief Execute
     * \param _context the target context
     */
    virtual void Execute(IContext<T> *_context) {
        if(!(_context!=NULL))throw "CursorIncrement Execute:context null";
        int cursor = _context->GetCursorPointer()+1;
        if(!(0 <= cursor && cursor < _context->GetMemory().size()))throw "CursorIncrement Execute:invalid cursor pointer";

        _context->SetCursorPointer(cursor);
    }
};

#endif // CURSORINCREMENT_H
