checkHeaders:
	g++ cpp/headers/zCore/zCore.h -Icpp --std=c++17 -Wall


main:
	g++ exampleExec/main.cpp -Icpp -Icpp/headers/zCore --std=c++17 -c 



