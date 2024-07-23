# CMakeExtraUtils

[![CI Status][ci-badge]][ci-link]
[![Documentation Status][rtd-badge]][rtd-link]

![License Status][license-badge]
![CMake Status][cmake-badge]

<!-- SPHINX-START -->

Extra utilities for cmake:

- [`DynamicVersion`]
- [`PackageComps`]

## Installation

These utilities can be included using both `find_package()` and `ExternalProject`, e.g. if `CMakeExtraUtils` is already
installed on your system:

```cmake
cmake_minimum_required(VERSION 3.20)

find_package(CMakeExtraUtils REQUIRED)

include(DynamicVersion)
dynamic_version()

project(MyProject
        VERSION ${PROJECT_VERSION})
```

or if you want to download a specific version:

```cmake
cmake_minimum_required(VERSION 3.20)

FetchContet_Declare(CMakeExtraUtils
        GIT_REPOSITORY https://github.com/LecriUT/CMakeExtraUtils
        GIT_TAG v0.1.1)
FetchContent_MakeAvailable(CMakeExtraUtils)

include(DynamicVersion)
dynamic_version()

project(MyProject
        VERSION ${PROJECT_VERSION})
```

<!-- SPHINX-END -->

## TODO for v1.0

- [x] Automation:
- [x] Add simple pre-commit and `pyproject.toml` environment
- [x] Fix `DynamicVersion` to work with buildable projects
- [ ] Test coverage:
  - [x] `DynamicVersion`
  - [ ] `PackageComps`

[ci-badge]: https://github.com/LecrisUT/CmakeExtraUtils/actions/workflows/ci.yaml/badge.svg?branch=main&event=push
[ci-link]: https://github.com/LecrisUT/CmakeExtraUtils/actions/workflows/ci.yaml?query=branch%3Amain+event%3Apush
[cmake-badge]: https://img.shields.io/badge/CMake-3.25-blue?logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIGRhdGEtbmFtZT0iTGF5ZXIgMiIgdmlld0JveD0iMCAwIDU0NS41IDU0NS45Ij48cGF0aCBkPSJNNTQ2IDUzNCAyODIgOWwzOSA0MzQgMjI1IDkxeiIgZGF0YS1uYW1lPSJyZWQgcmlnaHQiIHN0eWxlPSJmaWxsOiNmMzI3MzU7c3Ryb2tlLXdpZHRoOjAiLz48cGF0aCBkPSJNNTI1IDU0NiAxNzAgNDAzIDEgNTQ2aDUyNHoiIGRhdGEtbmFtZT0iZ3JlZW4gYm90dG9tIiBzdHlsZT0ic3Ryb2tlLXdpZHRoOjA7ZmlsbDojM2VhZTJiIi8+PHBhdGggZD0iTTI2MyAwIDAgNTIybDI4OC0yNDRMMjYzIDB6IiBkYXRhLW5hbWU9ImJsdWUgbGVmdCIgc3R5bGU9ImZpbGw6IzAwNjhjNztzdHJva2Utd2lkdGg6MCIvPjxwYXRoIGQ9Im0yOTEgMjk5LTEwNSA4OSAxMTcgNDgtMTItMTM3eiIgZGF0YS1uYW1lPSJncmF5IGNlbnRlciIgc3R5bGU9ImZpbGw6I2RjZTNlYztzdHJva2Utd2lkdGg6MCIvPjwvc3ZnPg==
[license-badge]: https://img.shields.io/github/license/LecrisUT/CmakeExtraUtils
[rtd-badge]: https://img.shields.io/readthedocs/cmakeextrautils
[rtd-link]: https://cmakeextrautils.readthedocs.io/en/latest/?badge=latest
[`dynamicversion`]: cmake/DynamicVersion.md
[`packagecomps`]: cmake/PackageComps.md
