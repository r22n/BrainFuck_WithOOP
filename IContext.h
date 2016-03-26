#ifndef ICONTEXT_H
#define ICONTEXT_H
#include<vector>

//!any brainfuck program context interface
/*!
 *\author n.ryouta\n
 * Copyright (c) 2016 n. ryouta\n
 * Released under the MIT license\n
 * http://opensource.org/licenses/mit-license.php
 */
template<class T>
class IContext {
public:
    virtual~IContext(){}

    //!get const-type universal memory
    /*!
     * \brief GetMemory
     * \return the reference of the const-type memory
     */
    virtual const std::vector<T>& GetMemory()=0;

    //!set the memory value
    /*!
     * \brief SetMemory
     * \param _ptr the pointer to memory
     * \param _value the value
     */
    virtual void SetMemory(int _ptr,T _value)=0;

    //!get the memory value
    /*!
     * \brief AtMemory
     * \param _ptr the pointer to memory
     * \return the memory value
     */
    virtual T AtMemory(int _ptr)=0;

    //!set the cursor pointer
    /*!
     * \brief SetCursorPointer
     * \param _cursor the cursor pointer
     */
    virtual void SetCursorPointer(int _cursor)=0;

    //!get the cursor pointer
    /*!
     * \brief GetCursorPointer
     * \return the cursor pointer
     */
    virtual int GetCursorPointer()=0;

    //!set the program counter
    /*!
     * \brief SetProgramCounter
     * \param _pc the program counter
     */
    virtual void SetProgramCounter(int _pc)=0;

    //!get the program counter
    /*!
     * \brief GetProgramCounter
     * \return the program counter
     */
    virtual int GetProgramCounter()=0;

};

#endif // ICONTEXT_H
