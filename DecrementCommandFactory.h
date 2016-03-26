#ifndef DECREMENTCOMMANDFACTORY_H
#define DECREMENTCOMMANDFACTORY_H
#include"ICommandFactory.h"
#include"Decrement.h"

//!factory of cursor memory decrement command
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class DecrementCommandFactory :
        public ICommandFactory<T> {
public:
    virtual~DecrementCommandFactory(){}

    //!create the cursor memory decrement command
    /*!
     * \brief MakeCommand
     * \param _programPosition no use
     * \return the cursor memory decrement command object
     */
    virtual ICommand<T>* MakeCommand(int _programPosition){
        return new Decrement<T>();
    }
};
#endif // DECREMENTCOMMANDFACTORY_H
