/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

#ifndef SE_INCL_STATICARRAY_H
#define SE_INCL_STATICARRAY_H
#ifdef PRAGMA_ONCE
  #pragma once
#endif

/*
 * Template class for array with static allocation of objects.
 */
template<class Type>
class CStaticArray {
public:
  INDEX sa_Count;      // number of objects in array
  Type *sa_Array;      // objects
public:
  /* Default constructor. */
  inline CStaticArray(void)
  {
    sa_Count=0;
    sa_Array=NULL;
  }

  /* Destructor. */
  inline ~CStaticArray(void)
  {
    // if some objects were allocated
    if (sa_Count!=0) {
      // destroy them
      Delete();
    }
  }

  void operator=(const CStaticArray<Type> &arOriginal);

  /* Create a given number of objects. */
  inline void New(INDEX iCount);
  /* Expand stack size but keep old objects. */
  inline void Expand(INDEX iNewCount);
  /* Destroy all objects. */
  inline void Delete(void)
  {
    ASSERT(this!=NULL);
    ASSERT(sa_Count!=0 && sa_Array!=NULL);
    delete[] sa_Array;
    sa_Count = 0;
    sa_Array = NULL;
  }
  /* Destroy all objects, and reset the array to initial (empty) state. */
  inline void Clear(void);

  /* Random access operator. */
  inline Type &operator[](INDEX iObject)
  {
    ASSERT(this!=NULL);
    ASSERT(iObject>=0 && iObject<sa_Count);     // check bounds
    return sa_Array[iObject];
  }

  inline const Type &operator[](INDEX iObject) const
  {
    ASSERT(this!=NULL);
    ASSERT(iObject>=0 && iObject<sa_Count);     // check bounds
    return sa_Array[iObject];
  }

  /* Get number of objects in array. */
  INDEX Count(void) const;
  /* Get index of a object from it's pointer. */
  INDEX Index(Type *ptObject);

  /* Copy all elements of another array into this one. */
  void CopyArray(const CStaticArray<Type> &arOriginal);
  /* Move all elements of another array into this one. */
  void MoveArray(CStaticArray<Type> &arOther);
};


#endif  /* include-once check. */

