# introduce
this project is a simple web server with php fast cgi.

# install
```bash
git clone https://github.com/echoechoin/phpHttpd
cd bulid
cmake ..
make
```

# directory construct
directroy | introduce
-| -
build | build and test project.
debug | class LOG for debug.
event | using libevent for event listen and process http request.
request | processing http request.
config | processing http config.
response | send response.