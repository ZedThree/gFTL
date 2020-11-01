changecom()
changequote(`{',`}')
module Test_{}_type()Set
   use funit
   use _type()Set_mod
   ifelse(_type(),{Foo},{use Foo_mod})

#include "_type().inc"
#include "shared/define_common_macros.inc"
#include "test_{}_type().inc"
#include "parameters/T/copy_T_to_set_T.inc"
#include "parameters/T/copy_set_T_to_internal_T.inc"
#include "parameters/T/define_derived_macros.inc"

contains

   @test
   subroutine test_empty()
     type(Set) :: s

     s = Set()
     @assert_that(s%empty(), is(true()))

     call s%insert(one)
     @assert_that(s%empty(), is(false()))
   end subroutine test_empty

   @test
   subroutine test_max_size()
      type(Set) :: s

      @assert_that(s%max_size(), is(huge(1_GFTL_SIZE_KIND)))
   end subroutine test_max_size


   @test
   subroutine test_size()
      type(Set) :: s

      @assert_that(int(s%size()), is(0))
      call s%insert(zero)
      @assert_that(int(s%size()), is(1))
      call s%insert(one)
      @assert_that(int(s%size()), is(2))
      
   end subroutine test_size

   @test
   subroutine test_size_duplicate_insert()
      type(Set) :: s

      call s%insert(zero)
      call s%insert(zero)
      @assert_that(int(s%size()), is(1))
      
   end subroutine test_size_duplicate_insert

   @test
   subroutine test_count()
      type(Set) :: s

      @assert_that(int(s%count(zero)), is(0))
      call s%insert(zero)
      @assert_that(int(s%count(zero)), is(1))

      @assert_that(int(s%count(one)), is(0))
      call s%insert(one)
      @assert_that(int(s%count(one)), is(1))
      
   end subroutine test_count

   @test
   subroutine test_find_not_found()
      type(Set) :: s
      type(SetIterator) :: iter

      iter = s%find(zero)
      @assert_that(iter == s%end(), is(true()))

   end subroutine test_find_not_found

   @test
   subroutine test_find_found()
      type(Set) :: s
      type(SetIterator) :: iter

      call s%insert(zero)
      call s%insert(one)
      iter = s%find(one)
      @assert_that(iter /= s%end(), is(true()))
      @assert_that(iter%of(), is(one))

      iter = s%find(zero)
      @assert_that(iter /= s%end(), is(true()))
      @assert_that(iter%of(), is(zero))
      

   end subroutine test_find_found


   @test
   subroutine test_insert_is_new()
      type(Set) :: s
      logical :: is_new

      call s%insert(zero, is_new=is_new)
      @assert_that(is_new,is(true()))

      call s%insert(one, is_new=is_new)
      @assert_that(is_new,is(true()))

      call s%insert(zero, is_new=is_new)
      @assert_that(is_new,is(false()))
      
   end subroutine test_insert_is_new

   @test
   subroutine test_insert_get_iterator_new()
      type(Set) :: s
      type(SetIterator) :: iter

      call s%insert(zero, iter=iter)
      @assert_that(iter%of(), is(zero))

      call s%insert(one, iter=iter)
      @assert_that(iter%of(), is(one))

      call s%insert(zero, iter=iter)
      @assert_that(iter%of(), is(zero))

      
   end subroutine test_insert_get_iterator_new

   @test
   subroutine test_insert_range()
      type(Set) :: s1, s2


      call s1%insert(zero)
      call s1%insert(one)
      call s1%insert(two)

      call s2%insert(one)
      call s2%insert(s1%begin(),s1%end())
      @assert_that(int(s2%size()), is(3))
      @assert_that(int(s2%count(zero)), is(1))
      @assert_that(int(s2%count(one)), is(1))
      @assert_that(int(s2%count(two)), is(1))
      
   end subroutine test_insert_range

   ! Almost useless test until an implementation is
   ! developed that actually uses the hint
   @test
   subroutine test_insert_with_hint()
      type(Set) :: s
      type(SetIterator) :: iter, hint

      call s%insert(zero)
      call s%insert(one)

      hint = s%find(one)
      call s%insert(hint, two, iter=iter)
      @assert_that(iter%of(), is(two))

      
   end subroutine test_insert_with_hint

#include "parameters/T/undef_derived_macros.inc"
#include "parameters/T/undef_internal.inc"
#include "parameters/T/undef_set_T.inc"
#include "shared/undef_common_macros.inc"
end module Test_{}_type()Set
