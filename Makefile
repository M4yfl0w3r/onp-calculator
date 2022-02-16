CXX=g++ 
CXXFLAGS = -std=c++14 -Wall

onp: onp.cpp stack.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o onp onp.cpp stack.cpp main.cpp 

clean:
	rm -f *.o onp
