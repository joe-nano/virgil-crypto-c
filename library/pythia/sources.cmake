#   @license
#   -------------------------------------------------------------------------
#   Copyright (C) 2015-2020 Virgil Security, Inc.
#
#   All rights reserved.
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions are
#   met:
#
#       (1) Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#
#       (2) Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in
#       the documentation and/or other materials provided with the
#       distribution.
#
#       (3) Neither the name of the copyright holder nor the names of its
#       contributors may be used to endorse or promote products derived from
#       this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
#   IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#   DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
#   INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
#   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
#   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
#   STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
#   IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#   POSSIBILITY OF SUCH DAMAGE.
#
#   Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
#   -------------------------------------------------------------------------

#   @warning
#   -------------------------------------------------------------------------
#   This file is fully generated by script 'cmake_files_codegen.gsl'.
#   It can be changed temporary for debug purposes only.
#   -------------------------------------------------------------------------
#   @end


include_guard()

if(NOT TARGET pythia)
    message(FATAL_ERROR "Expected target 'pythia' to be defined first.")
endif()

include(CheckIncludeFiles)
check_include_files(assert.h VSCP_HAVE_ASSERT_H)
check_include_files(stdatomic.h VSCP_HAVE_STDATOMIC_H)

configure_file(
        "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_platform.h.in"
        "${CMAKE_CURRENT_BINARY_DIR}/include/virgil/crypto/pythia/vscp_platform.h"
        )

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_assert.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_library.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_memory.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_BINARY_DIR}/include/virgil/crypto/pythia/vscp_platform.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_error.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_pythia.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_status.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_pythia_public.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

target_sources(pythia
    PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_assert.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_library.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_memory.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/private/vscp_atomic.h"
            "${CMAKE_CURRENT_BINARY_DIR}/include/virgil/crypto/pythia/vscp_platform.h"
            "$<$<BOOL:${VSCP_ERROR}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_error.h>"
            "$<$<BOOL:${VSCP_PYTHIA}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_pythia.h>"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_status.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/vscp_pythia_public.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/private/vscp_pythia_private.h"

            "${CMAKE_CURRENT_LIST_DIR}/src/vscp_assert.c"
            "${CMAKE_CURRENT_LIST_DIR}/src/vscp_library.c"
            "${CMAKE_CURRENT_LIST_DIR}/src/vscp_memory.c"
            "$<$<BOOL:${VSCP_ERROR}>:${CMAKE_CURRENT_LIST_DIR}/src/vscp_error.c>"
            "$<$<BOOL:${VSCP_PYTHIA}>:${CMAKE_CURRENT_LIST_DIR}/src/vscp_pythia.c>"
            "${CMAKE_CURRENT_LIST_DIR}/src/vscp_status.c"
        )

target_include_directories(pythia
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/pythia/private>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/virgil/crypto/pythia>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/virgil/crypto/pythia/private>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/src>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )
