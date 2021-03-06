# Orni

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/2a7358ca0dcc4022a085bc5037cfcea7)](https://app.codacy.com/gh/Dammibruh/orni?utm_source=github.com&utm_medium=referral&utm_content=Dammibruh/orni&utm_campaign=Badge_Grade)
![release](https://img.shields.io/badge/version-v0.2.3--b-red?style=flat-square)
![license](https://img.shields.io/github/license/Dammibruh/orni.svg?style=flat-square)

minimalist & lightweight web framework for modern C++ inspired from expressjs and other frameworks , thanks to [inja](https://github.com/pantor/inja) and [httpparser]( https://github.com/nekipelov/httpparser)
note orni is currently in development and have lot of bugs so don't expect high performance and efficient responses from the web server, any pull request or issue is appreciated <3
### Requirements
-   C++17

### Example


```cpp
#include <orni/orni.hpp>

int main(){
    orni::HttpServer app;
    app.Get("/", [](orni::Request& req, orni::Response& res){
        res.SendHtml("<h1>Hello from orni !</h1>");
    });
    app.run(1234);
}
```
### More examples ?
head to [examples](https://github.com/Dammibruh/orni/tree/main/examples) folder ! 

### TODO
-   [x] params
-   [x] queries
-   [ ] built-in ORM
-   [x] html template rendering
-   [ ] documentation
-   [x] cookies
-   [ ] encryption
-   [x] cookie parser
-   [x] support for forms
-   [ ] support for files and multipart data

## CMake

The project has full CMake integration.

### Compilation

To compile the project, simply do the classical cmake project setup:

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make all -j4 
```

This will build all examples.

### Installation & Integration

The project also has a functional installation target. To use this, make sure
to configure the `CMAKE_INSTALL_PREFIX` for this project, and the `CMAKE_PREFIX_PATH`
for the project that you are integrating with.

An example follows:
```shell
# Assuming we're in the current project's directory
$ mkdir ../_libs
$ mkdir build && cd build
$ cmake -DCMAKE_INSTALL_PREFIX=../../_libs ..
$ make install -j4 # Will install the library to the ../../_libs folder
$
$ cd ../../my_other_project
$ mkdir build && cd build
$ cmake -DCMAKE_PREFIX_PATH=../../_libs
$ make all -j4
```

A cmake file accompanying `my_other_project` may look something like this:
```cmake
cmake_minimum_required(VERSION 3.14)
project(my_other_project)

find_package(orni REQUIRED)

# your own project setup goes here...

target_link_libraries(my_target
    PUBLIC
        orni::orni
)
```

