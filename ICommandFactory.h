#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include"ICommand.h"

//!factory of any brainfuck interpreter command object
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class ICommandFactory {
public:
    virtual~ICommandFactory(){}

    //!create command
    /*!
     * \brief MakeCommand
     * \param _programPosition the program position as the source codes
     * \return the command object
     */
    virtual ICommand<int>* MakeCommand(int _programPosition)=0;
};


#endif // COMMANDFACTORY_H
