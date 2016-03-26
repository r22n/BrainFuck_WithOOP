#ifndef ICOMMAND_H
#define ICOMMAND_H

#include"IContext.h"

//!brainfuck interpreter command object interface
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class ICommand{
public:
    virtual~ICommand(){}

    //!execute any command
    /*!
     * \brief Execute
     * \param _context the target context
     */
    virtual void Execute(IContext<T>* _context)=0;
};

#endif // ICOMMAND_H
