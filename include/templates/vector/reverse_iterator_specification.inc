!--------------------------------------------------------------------
! Copyright © 2020 United States Government as represented by the   |
! Administrator of the National Aeronautics and Space               |
! Administration. No copyright is claimed in the United States      |
! under Title 17, U.S. Code. All Other Rights Reserved.             |
!                                                                   |
! Licensed under the Apache License, Version 2.0.                   |
!--------------------------------------------------------------------

   type __vector_riterator
      private

      type(__MANGLE(wrapper)), dimension(:), pointer :: elements
      integer(kind=__gftl_size_kind) :: current_index = -1 ! intentionally invalid value

   contains

!!$      procedure :: back_inserter => __MANGLE(back_inserter)
!!$      procedure :: front_inserter => __MANGLE(front_inserter)
!!$      procedure :: inserter => __MANGLE(inserter)
!!$      procedure :: make_move_iterator => __MANGLE(make_move_iterator)

      procedure :: next => __MANGLE(riter_next)
      procedure :: previous => __MANGLE(riter_previous)

      procedure :: get => __MANGLE(riter_get)
      procedure :: __MANGLE(riter_at)
      procedure :: __MANGLE(riter_at_offset_size_kind)
      procedure :: __MANGLE(riter_at_offset_default)

      generic :: at => __MANGLE(riter_at)
      generic :: at => __MANGLE(riter_at_offset_size_kind)
#ifndef __gftl_disable_index_kind_overload
      generic :: at => __MANGLE(riter_at_offset_default)
#endif


      procedure :: __MANGLE(riter_add_n_size_kind)
      procedure :: __MANGLE(riter_sub_n_size_kind)
      procedure :: __MANGLE(riter_add_n_default)
      procedure :: __MANGLE(riter_sub_n_default)
      generic :: add_n => __MANGLE(riter_add_n_default)
      generic :: sub_n => __MANGLE(riter_sub_n_default)
#ifndef  __gftl_disable_index_kind_overload
      generic :: add_n => __MANGLE(riter_add_n_size_kind)
      generic :: sub_n => __MANGLE(riter_sub_n_size_kind)
#endif

   end type __vector_riterator


   ! Arithmetic
   interface operator(+)
#ifndef  __gftl_disable_index_kind_overload
      module procedure __MANGLE(riter_a_plus_n_size_kind)
      module procedure __MANGLE(riter_n_plus_a_size_kind)
#endif
      module procedure __MANGLE(riter_n_plus_a_default)
      module procedure __MANGLE(riter_a_plus_n_default)
   end interface operator(+)
   interface operator(-)
#ifndef  __gftl_disable_index_kind_overload
      module procedure __MANGLE(riter_a_minus_n_size_kind)
#endif
      module procedure __MANGLE(riter_a_minus_n_default)
      module procedure __MANGLE(riter_a_minus_b)
   end interface operator(-)


   ! Relational operators
   interface operator(==)
      module procedure __MANGLE(riter_equal)
   end interface operator(==)
   interface operator(/=)
      module procedure __MANGLE(riter_not_equal)
   end interface operator(/=)

   interface operator (<)
      module procedure __MANGLE(riter_less)
   end interface operator (<)
   interface operator (<=)
      module procedure __MANGLE(riter_less_equal)
   end interface operator (<=)
   interface operator (>)
      module procedure __MANGLE(riter_greater)
   end interface operator (>)
   interface operator (>=)
      module procedure __MANGLE(riter_greater_equal)
   end interface operator (>=)

   interface advance
#ifndef  __gftl_disable_index_kind_overload
      module procedure __MANGLE(riter_advance_size_kind)
#endif
      module procedure __MANGLE(riter_advance_default)
   end interface advance
   interface distance
      module procedure __MANGLE(riter_distance)
   end interface distance
   interface next
      module procedure __MANGLE(riter_next_f)
   end interface next
   interface previous
      module procedure __MANGLE(riter_previous_f)
   end interface previous