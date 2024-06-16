CXX = g++
CXXFLAGS = -Wall -g -Iinclude

TARGET = loadbalancer
OBJS = src/Main.o src/LoadBalancer.o src/RequestQueue.o src/WebServer.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

src/Main.o: src/Main.cpp include/LoadBalancer.h
	$(CXX) $(CXXFLAGS) -c src/Main.cpp -o src/Main.o

src/LoadBalancer.o: src/LoadBalancer.cpp include/LoadBalancer.h include/RequestQueue.h include/WebServer.h
	$(CXX) $(CXXFLAGS) -c src/LoadBalancer.cpp -o src/LoadBalancer.o

src/RequestQueue.o: src/RequestQueue.cpp include/RequestQueue.h
	$(CXX) $(CXXFLAGS) -c src/RequestQueue.cpp -o src/RequestQueue.o

src/WebServer.o: src/WebServer.cpp include/WebServer.h
	$(CXX) $(CXXFLAGS) -c src/WebServer.cpp -o src/WebServer.o

clean:
	rm -f $(OBJS) $(TARGET)

