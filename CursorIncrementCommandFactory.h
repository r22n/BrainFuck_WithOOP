#ifndef CURSORINCREMENTCOMMANDFACTORY_H
#define CURSORINCREMENTCOMMANDFACTORY_H
#include"ICommandFactory.h"
#include"CursorIncrement.h"

//!factory of cursor pointer increment command
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class CursorIncrementCommandFactory :
        public ICommandFactory<T> {
public:
    virtual~CursorIncrementCommandFactory(){}

    //!create cursor pointer increment command
    /*!
     * \brief MakeCommand
     * \param _programPosition no use
     * \return the cursor pointer increment command object
     */
    virtual ICommand<T>* MakeCommand(int _programPosition){
        return new CursorIncrement<T>();
    }
};
#endif // CURSORINCREMENTCOMMANDFACTORY_H
