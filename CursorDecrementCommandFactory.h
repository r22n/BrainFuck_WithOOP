#ifndef CURSORDECREMENTCOMMANDFACTORY_H
#define CURSORDECREMENTCOMMANDFACTORY_H
#include"ICommandFactory.h"
#include"CursorDecrement.h"

//!factory of cursor pointer decrement command
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class CursorDecrementCommandFactory :
        public ICommandFactory<T> {
public:
    virtual~CursorDecrementCommandFactory(){}

    //!create the cursor pointer decrement command
    /*!
     * \brief MakeCommand
     * \param _programPosition no use
     * \return the cursor pointer decrement command object
     */
    virtual ICommand<T>* MakeCommand(int _programPosition){
        return new CursorDecrement<T>();
    }
};
#endif // CURSORDECREMENTCOMMANDFACTORY_H
