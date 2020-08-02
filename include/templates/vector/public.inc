#include "parameters/T/define_derived_macros.inc"

   public :: __vector

   ! Non type-bound procedures
   public :: swap
#ifdef __T_EQ__
   public :: operator(==)
   public :: operator(/=)
#endif
#ifdef __T_LT__
   public :: operator(<)
   public :: operator(>)
   public :: operator(<=)
   public :: operator(>=)
#endif

   ! iterators
   public :: __vector_iterator
   public :: __vector_riterator
   public :: advance
   public :: begin
   public :: distance
   public :: end
   public :: next
   public :: previous
   
#include "parameters/T/undef_derived_macros.inc"
   