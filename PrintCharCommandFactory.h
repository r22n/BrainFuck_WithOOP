#ifndef PRINTCHARCOMMANDFACTORY_H
#define PRINTCHARCOMMANDFACTORY_H
#include"ICommandFactory.h"
#include"PrintChar.h"

//!factory of the command printing the cursor memory as the character
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class PrintCharCommandFactory :
        public ICommandFactory<T> {
public:
    virtual~PrintCharCommandFactory(){}

    //!create the printing the cursor memory value as the 1-byte character
    /*!
     * \brief MakeCommand
     * \param _programPosition no use
     * \return the printing character command object
     */
    virtual ICommand<T>* MakeCommand(int _programPosition) {
        return new PrintChar<T>();
    }
};
#endif // PRINTCHARCOMMANDFACTORY_H
