rm $2

g++ -std=c++17 -O0 -I.. /dlib/dlib/all/source.cpp -I /usr/include/opencv4 -lstdc++fs -lpthread -lX11 $1 -o $2

./$2



 