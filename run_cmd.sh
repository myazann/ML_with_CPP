rm $2

g++ -std=c++17 -O0 -I.. /dlib/dlib/all/source.cpp -lstdc++fs -lpthread -lX11 -lopencv_imgcodecs $1 -o $2

./$2



 