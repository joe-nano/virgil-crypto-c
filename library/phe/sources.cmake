#   @license
#   -------------------------------------------------------------------------
#   Copyright (C) 2015-2018 Virgil Security Inc.
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

if(NOT TARGET phe)
    message(FATAL_ERROR "Expected target 'phe' to be defined first.")
endif()

configure_file(
        "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_platform.h.in"
        "${CMAKE_CURRENT_BINARY_DIR}/include/virgil/crypto/phe/vsce_platform.h"
        )

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_assert.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_library.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_memory.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_BINARY_DIR}/include/virgil/crypto/phe/vsce_platform.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_error_ctx.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_phe_client.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_phe_common.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_phe_server.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

set_property(
    SOURCE "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_error.h"
    PROPERTY MACOSX_PACKAGE_LOCATION "Headers"
)

target_sources(phe
    PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_assert.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_library.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_memory.h"
            "${CMAKE_CURRENT_BINARY_DIR}/include/virgil/crypto/phe/vsce_platform.h"
            "$<$<BOOL:${VSCE_ERROR_CTX}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_error_ctx.h>"
            "$<$<BOOL:${VSCE_PHE_CLIENT}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_phe_client.h>"
            "$<$<BOOL:${VSCE_PHE_CLIENT}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/private/vsce_phe_client_defs.h>"
            "$<$<BOOL:${VSCE_PHE_COMMON}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_phe_common.h>"
            "$<$<BOOL:${VSCE_PHE_HASH}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_phe_hash.h>"
            "$<$<BOOL:${VSCE_PHE_HASH}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/private/vsce_phe_hash_defs.h>"
            "$<$<BOOL:${VSCE_PHE_SERVER}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_phe_server.h>"
            "$<$<BOOL:${VSCE_PHE_SERVER}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/private/vsce_phe_server_defs.h>"
            "$<$<BOOL:${VSCE_PHE_UTILS}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_phe_utils.h>"
            "$<$<BOOL:${VSCE_PHE_UTILS}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/private/vsce_phe_utils_defs.h>"
            "$<$<BOOL:${VSCE_SIMPLE_SWU}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_simple_swu.h>"
            "$<$<BOOL:${VSCE_SIMPLE_SWU}>:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/private/vsce_simple_swu_defs.h>"
            "${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/vsce_error.h"

            "${CMAKE_CURRENT_LIST_DIR}/src/vsce_assert.c"
            "${CMAKE_CURRENT_LIST_DIR}/src/vsce_library.c"
            "${CMAKE_CURRENT_LIST_DIR}/src/vsce_memory.c"
            "$<$<BOOL:${VSCE_ERROR_CTX}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_error_ctx.c>"
            "$<$<BOOL:${VSCE_PHE_CLIENT}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_phe_client.c>"
            "$<$<BOOL:${VSCE_PHE_CLIENT}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_phe_client_defs.c>"
            "$<$<BOOL:${VSCE_PHE_COMMON}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_phe_common.c>"
            "$<$<BOOL:${VSCE_PHE_HASH}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_phe_hash.c>"
            "$<$<BOOL:${VSCE_PHE_HASH}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_phe_hash_defs.c>"
            "$<$<BOOL:${VSCE_PHE_SERVER}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_phe_server.c>"
            "$<$<BOOL:${VSCE_PHE_SERVER}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_phe_server_defs.c>"
            "$<$<BOOL:${VSCE_PHE_UTILS}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_phe_utils.c>"
            "$<$<BOOL:${VSCE_PHE_UTILS}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_phe_utils_defs.c>"
            "$<$<BOOL:${VSCE_SIMPLE_SWU}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_simple_swu.c>"
            "$<$<BOOL:${VSCE_SIMPLE_SWU}>:${CMAKE_CURRENT_LIST_DIR}/src/vsce_simple_swu_defs.c>"
            "${CMAKE_CURRENT_LIST_DIR}/src/vsce_error.c"
        )

target_include_directories(phe
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/virgil/crypto/phe/private>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/virgil/crypto/phe>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/virgil/crypto/phe/private>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/src>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )
