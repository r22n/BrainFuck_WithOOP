#ifndef CURSORDECREMENT_H
#define CURSORDECREMENT_H
#include"ICommand.h"

//!the command decrements cursor pointer position
/*!
 * \author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class CursorDecrement :
         public ICommand<T> {
public:
    virtual~CursorDecrement(){}

    //!decrement cursor position
    /*!
     * \brief Execute
     * \param _context the target context
     */
    virtual void Execute(IContext<T> *_context){
        if(!(_context!=NULL))throw "CursorDecrement Execute:context null";
        _context->SetCursorPointer(_context->GetCursorPointer()-1);
    }
};

#endif // CURSORDECREMENT_H
