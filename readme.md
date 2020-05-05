# introduce
this project is a simple web server with php fast-cgi.

# prerequisite
require Libevent
require Cmake

# install
```shell
git clone https://github.com/echoechoin/phpHttpd.git
rm build -rf && mkdir build && cd build
cmake ..
make
```

# directory construct
directroy | introduce
-| -
build | build and test project.
debug | class LOG for debug.
event | using libevent for event listening and processing http request.
request | processing http request.
config | processing http config.
response | send response.
