#ifndef SCANCHARCOMMANDFACTORY_H
#define SCANCHARCOMMANDFACTORY_H
#include"ICommandFactory.h"
#include"ScanChar.h"

//!factory of the command scanning 1 character from standard in
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class ScanCharCommandFactory :
        public ICommandFactory<T> {
public:
    virtual~ScanCharCommandFactory(){}

    //!create the command scanning 1 character from standard in
    /*!
     * \brief MakeCommand
     * \param _programPosition no use
     * \return the command scanning 1 character from standrad in
     */
    virtual ICommand<T>* MakeCommand(int _programPosition) {
        return new ScanChar<T>();
    }
};

#endif // SCANCHARCOMMANDFACTORY_H
