# Minimum version follows the current Ubuntu LTS and RHEL version
cmake_minimum_required(VERSION 3.25...3.30)

#[==============================================================================================[
#                                   Basic project definition                                   #
]==============================================================================================]

list(APPEND CMAKE_MESSAGE_CONTEXT CMakeExtraUtils)

# dogfooding `DynamicVersion` module in order to set the CMakeExtraUtils version
list(PREPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(DynamicVersion)
dynamic_version(PROJECT_PREFIX CMakeExtraUtils_
        FALLBACK_VERSION 0.0.0
)

project(CMakeExtraUtils
        VERSION ${PROJECT_VERSION}
        DESCRIPTION "Extra utilities for cmake"
        HOMEPAGE_URL https://github.com/LecrisUT/CmakeExtraUtils
        LANGUAGES NONE
)


#[==============================================================================================[
#                                            Options                                            #
]==============================================================================================]

option(CMAKEEXTRAUTILS_TESTS "CMakeExtraUtils: Include tests" ${PROJECT_IS_TOP_LEVEL})
option(CMAKEEXTRAUTILS_INSTALL "CMakeExtraUtils: Install project files" ${PROJECT_IS_TOP_LEVEL})

#[==============================================================================================[
#                                     Project configuration                                     #
]==============================================================================================]

if (CMAKEEXTRAUTILS_INSTALL)
    include(CMakePackageConfigHelpers)
    if (UNIX)
        include(GNUInstallDirs)
    endif ()
endif ()

#[==============================================================================================[
#                                       External packages                                       #
]==============================================================================================]

# No external dependencies

#[==============================================================================================[
#                                        Main definition                                        #
]==============================================================================================]

# Copy the module files to build directory
# This is needed to make the scripts importable by ${builddir}/CMakeExtraUtilsConfig.cmake
foreach (module IN ITEMS
        DynamicVersion
        PackageComps
)
    configure_file(
            ${PROJECT_SOURCE_DIR}/cmake/${module}.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/${module}.cmake
            COPYONLY
    )
endforeach ()

if (CMAKEEXTRAUTILS_TESTS)
    enable_testing()
    add_subdirectory(test)
endif ()

#[==============================================================================================[
#                                       Install or Export                                       #
]==============================================================================================]

# Install package files
if (CMAKEEXTRAUTILS_INSTALL)
    # Will show developer warning, but can't supress it :(
    # Package files
    write_basic_package_version_file(
            CMakeExtraUtilsConfigVersion.cmake
            VERSION ${PROJECT_VERSION}
            # TODO: Currently unstable api, change when v1.0 is released
            COMPATIBILITY SameMinorVersion
            ARCH_INDEPENDENT
    )
    configure_package_config_file(
            cmake/CMakeExtraUtilsConfig.cmake.in
            CMakeExtraUtilsConfig.cmake
            INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/CMakeExtraUtils
    )
    install(FILES
            ${CMAKE_CURRENT_BINARY_DIR}/CMakeExtraUtilsConfigVersion.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/CMakeExtraUtilsConfig.cmake
            DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/CMakeExtraUtils
    )
    # Bundled cmake files
    install(FILES
            cmake/DynamicVersion.cmake
            cmake/PackageComps.cmake
            DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/CMakeExtraUtils
    )
endif ()

# Make project available for FetchContent
if (NOT PROJECT_IS_TOP_LEVEL)
    # Propagate variables for FetchContent
    # All variables have to be consistent with CMakeExtraUtilsConfig.cmake
    return(PROPAGATE
            CMAKE_MODULE_PATH
            CMakeExtraUtils_VERSION
            CMakeExtraUtils_VERSION_MAJOR
            CMakeExtraUtils_VERSION_MINOR
            CMakeExtraUtils_VERSION_PATCH
            CMakeExtraUtils_VERSION_TWEAK
    )
endif ()
