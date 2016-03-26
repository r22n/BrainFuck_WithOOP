#ifndef CONTEXT_H
#define CONTEXT_H
#include"IContext.h"

//!universal memory type program context
/*!
 * the context will be used for running brainfuck interpreter, has the universal type memory and
 * cursor pointer
 * \author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class Context :
        public IContext<T> {
private:
    std::vector<T> memory;
    int cursor;
    int pc;
public:
    //!create the context has the specified max memory size
    /*!
     * \brief Context
     * \param _maxMemorySize the maximum size of memory
     */
    Context(int _maxMemorySize) {
        if(!(_maxMemorySize > 0))throw "Context: maxMemorySize must be bigger than 0";
        memory.resize(_maxMemorySize);
        cursor = 0;
        pc = 0;
    }

    virtual~Context(){}

    //!get all memory context
    /*!
     * \brief GetMemory
     * \return the const-memory
     */
    virtual const std::vector<T>& GetMemory(){return memory;}

    //!set the memory value
    /*!
     * \brief SetMemory
     * \param _ptr pointer to memory address
     * \param _value the value will be set
     */
    virtual void SetMemory(int _ptr,T _value){
        if(!(0 <= _ptr && _ptr <  memory.size() )) throw "Context SetMemory: invalid pointer";
        memory[_ptr] = _value;
    }

    //!get the memory has the specified address
    virtual T AtMemory(int _ptr){
        if(!(0 <= _ptr && _ptr < memory.size()))throw "Context AtMemory: invalid pointer";
        return memory[_ptr];
    }

    //!set the cursor pointer position
    /*!
     * \brief SetCursorPointer
     * \param _cursor the cursor position
     */
    virtual void SetCursorPointer(int _cursor){
        if(!(_cursor >= 0)) throw "Context SetCursorPointer: invalid cursor";
        cursor = _cursor;
    }

    //!get the cursor pointer position
    /*!
     * \brief GetCursorPointer
     * \return the cursor position
     */
    virtual int GetCursorPointer(){return cursor;}

    //!set the program counter
    /*!
     * \brief SetProgramCounter
     * \param _pc the program counter
     */
    virtual void SetProgramCounter(int _pc){
        if(!(_pc >= 0))throw "Context SetProgramCounter: pc must be bigger equal 0";
        pc = _pc;
    }
    //!get the program counter
    /*!
     * \brief GetProgramCounter
     * \return the program counter
     */
    virtual int GetProgramCounter(){return pc;}
};

#endif // CONTEXT_H
