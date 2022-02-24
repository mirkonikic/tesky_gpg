compile:
	g++ -Wall src/tesky.cpp include/*/aarch*.cpp `wx-config --cxxflags --libs` -o bin/tesky
