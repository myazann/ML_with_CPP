rm $2

g++ -std=c++17 -O0 -I .. dlib/dlib/all/source.cpp -lpthread -lX11 $1 -o $2

./$2