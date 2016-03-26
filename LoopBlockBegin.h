#ifndef ILOOPBLOCKBEGIN_H
#define ILOOPBLOCKBEGIN_H
#include"ICommand.h"

//!brainfuck begin loop block command
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class LoopBlockBegin :
        public ICommand<T> {
private:
    int programPosition;
public:
    //!create the begin loop block
    /*!
     * \brief LoopBlockBegin
     * \param _programPosition the position of program
     */
    LoopBlockBegin(int _programPosition) {
        if(!(_programPosition >= 0))throw "LoopBlockBegin: programPosition must be bigger than 0";
        programPosition = _programPosition;
    }
    //!do nothing
    virtual void Execute(IContext<T> *_context){}

    //!get the position of program counter
    /*!
     * \brief GetPosition
     * \return the position will be execute this command
     */
    virtual int GetPosition(){return programPosition;}
};


#endif // ILOOPBLOCKBEGIN_H
