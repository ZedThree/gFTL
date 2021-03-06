!--------------------------------------------------------------------
! Copyright © 2017 United States Government as represented by the   |
! Administrator of the National Aeronautics and Space               |
! Administration. No copyright is claimed in the United States      |
! under Title 17, U.S. Code. All Other Rights Reserved.             |
!                                                                   |
! Licensed under the Apache License, Version 2.0.                   |
!--------------------------------------------------------------------

#include "templates/tmplbase.inc"
      private

! Main container
#ifdef _set
#  define __set _set
#else
#  define __set set
#endif

#ifdef _iterator
#  define __siterator _iterator
#else
#  define __siterator __QUOTE(__set)__QUOTE(Iterator)
#endif
      public :: __set
      public :: __siterator


! Implementation uses a vector of <_type>
#define __vector tVector
#define __container_prefix tt_

#include "templates/type_set_use_tokens.inc"
#  include "vector_decl.inc"
#include "templates/type_use_tokens_undef.inc"
#undef __vector
#undef __container_prefix

! Implementation alse uses vector of <integer(kind=SIZE_KIND)> for
! indices.
#define __vector iVector
#define __container_prefix ti_
#define __use_type integer(kind=SIZE_KIND)
#define __use_equal_defined
#define __use_less_than_defined
#  include "vector_decl.inc"
#include "templates/type_use_tokens_undef.inc"
#undef __vector
#undef __container_prefix

! set <_type>

#define __container_prefix s_
#define __iterator __siterator
#include "templates/type_set_use_tokens.inc"
#include "altSet_decl.inc"
#include "templates/type_use_tokens_undef.inc"
#undef __iterator
#undef __container_prefix

#include "unused.inc"
#include "error_codes.inc"

      contains


! vector <_type>
#define __vector tVector
#define __container_prefix tt_
#include "templates/type_set_use_tokens.inc"
#include "vector_impl.inc"
#include "templates/type_use_tokens_undef.inc"
#undef __vector
#undef __container_prefix

! set <_type>
#define __container_prefix s_
#define __iterator __siterator
#include "templates/type_set_use_tokens.inc"
#include "altSet_impl.inc"
#include "templates/type_use_tokens_undef.inc"
#undef __iterator
#undef __container_prefix


! vector <integer(kind=SIZE_KIND)>
#define __vector iVector
#define __container_prefix ti_
#define __use_type integer(kind=SIZE_KIND)
#define __use_equal_defined
#define __use_less_than_defined

#  include "vector_impl.inc"
#include "templates/type_use_tokens_undef.inc"
#undef __vector
#undef __container_prefix

#undef __set
#include "templates/tmpltail.inc"
#include "templates/all_macros_undefs.inc"

