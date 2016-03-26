#ifndef INCREMENTCOMMANDFACTORY_H
#define INCREMENTCOMMANDFACTORY_H
#include"ICommandFactory.h"
#include"Increment.h"


//!factory of the cursor memory increment command
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class IncrementCommandFactory :
        public ICommandFactory<T> {
public:
    virtual~IncrementCommandFactory(){}

    //!create the cursor memory increment command object
    /*!
     * \brief MakeCommand
     * \param _programPosition no use
     * \return cursor memory increment command object
     */
    virtual ICommand<T>* MakeCommand(int _programPosition){
        return new Increment<T>();
    }
};


#endif // INCREMENTCOMMANDFACTORY_H
